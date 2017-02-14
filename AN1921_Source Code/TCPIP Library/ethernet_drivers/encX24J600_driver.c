/**
  ENC424j600/ENC624J600 Ethernet Driver
	
  Company:
    Microchip Technology Inc.

  File Name:
    encX24J600_driver.c

  Summary:
    This is the Ethernet driver implementation for ENCx24J600 family devices.

  Description:
    This file provides the Ethernet driver API implementation for
    the ENCx24J600 family devices.

 */

/*

©  [2015] Microchip Technology Inc. and its subsidiaries.  You may use this software 
and any derivatives exclusively with Microchip products. 
  
THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, 
IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF 
NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS 
INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE 
IN ANY APPLICATION. 

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL 
OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED 
TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY 
OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S 
TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED 
THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS. 

*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "hardware.h"
#include "encX24J600_types.h"
#include "ethernet_driver.h"
#include "network.h"

#if defined ETH_SPI
#include "encX24J600_spi.h"
#endif


volatile ethernetDriver_t ethData;
uint16_t TXPacketSize;

inline static void waitForDMA(void);

mac48Address_t ethMAC;

static uint16_t nextPacketPointer;

/**
 * Send System Reset
 */
void ETH_SendSystemReset(void)
{
    do
    {
        // wait until I can talk to the device.
        do
        {
            ENCx24_Write( XJ600_EUDASTL , 0x1234 );
        } while(0x1234 != ENCx24_Read(XJ600_EUDASTL));

        // reset it to assure that it is in a fresh state.
        ENCx24_BFS(XJ600_ECON2L, ECON2_ETHRST);
    
        while((ENCx24_Read(XJ600_ESTATL) & (ESTAT_CLKRDY | ESTAT_RSTDONE | ESTAT_PHYRDY)) != (ESTAT_CLKRDY | ESTAT_RSTDONE | ESTAT_PHYRDY));
        __delay_ms(1);
        
    }while(0x0 != ENCx24_Read(XJ600_EUDASTL));        

    __delay_ms(1);
    
    // all set...
}

/**
 * Ethernet Initialization
 */

void ETH_Init(void)
{
    uint16_t phcon1_val;
    
	// Power cycle the ENCx24J600 device
    LATBbits.LATB5 = 0;
    TRISBbits.TRISB5 = 0;
    __delay_ms(10);

    // If the INT/SPISEL signal is connected, force it to the correct state 
    // for latching SPI or PSP mode.
    PORTBbits.RB2 = 1;
    TRISBbits.TRISB2 = 0;

    // Turn on power and wait for interface latching to occur
    LATBbits.LATB5 = 1;
    __delay_us(400);
		
    // Tri-state interrupt GPIO so that we don't cause bus contention.
    TRISBbits.TRISB2 = 1;

    ETH_NCS_HIGH();

    ethData.error = false; // no error
    ethData.up = false; // no link
    ethData.linkChange = false;
    ethData.bufferBusy = false; // transmit data buffer is free
    ethData.saveRDPT = 0;

    ETH_SendSystemReset();
    
    // Initialize RX tracking variables and other control state flags
    nextPacketPointer = RXSTART;
    
    // Set up TX/RX buffer addresses
    ENCx24_Write(XJ600_ETXSTL,   TXSTART);
    ENCx24_Write(XJ600_ERXSTL,   RXSTART);
    ENCx24_Write(XJ600_ERXTAILL, RAMSIZE - 2);
    ENCx24_Write(XJ600_EUDASTL,TXEND + 1);
    ENCx24_Write(XJ600_EUDANDL,TXEND + 1);
    
    phcon1_val = ENCx24_PhyRead(PHCON1);
    phcon1_val &= PHCON1_PWAKE;
    ENCx24_PHYWrite(PHCON1, phcon1_val);

    // Set PHY Auto-negotiation to support 10BaseT Half duplex,
    // 10BaseT Full duplex, 100BaseTX Half Duplex, 100BaseTX Full Duplex,
    // and symmetric PAUSE capability
    //ADPAUS=1;AD10FD=1;AD10=1;AD100FD=1;AD100=1;ADIEEE=1;
    //PHANA=0b 0000 0101 1110 0001
    ENCx24_PHYWrite(PHANA,0x05E1);

    // wait until it's internal clock is ready and Phy link established.
    while((ENCx24_Read(XJ600_ESTATL)&0X1100)!=0x1100)
    {
        __delay_us(256);
    }

    // configure the filter
    //UCEN   = 1;  // allow unicast   (enables IP & ICMP)
    //BCEN   = 1;  // allow broadcast (enables the ARP responses)
    //RUNTEN = 1;  // disallow runts
    //CRCEN  = 1;  // disallow bad CRC
    //ERXFCON = 0b 0000 0000 0101 1011

    //MCEN   = 1;  // allow multicast
    //    ENCx24_Write(XJ600_ERXFCONL, 0x005B);

    //MCEN   = 0;  // filter out multicast
    ENCx24_Write(XJ600_ERXFCONL, 0x0059);

    // enable packet receive interrupts
    //INTIE = 1; // master interrupt flag
    //PKTIE = 1; // receive packet interrupts
    //LNKIE = 1; // link changed interrupts
    //TXIE  = 1; // sent packet interrupts
    //PCFULIE = 1;//packet counter full interrupt
    //RXABTIE = 1;//Receive abort enable interrupt
    //EIE = 0b 1000 1000 0100 1011
    ENCx24_Write(XJ600_EIEL,0x884B);

    // Enable RX packet reception
    ENCx24_BFS(XJ600_ECON1L,ECON1_RXEN);

#ifdef ETH_SPI
    //Choose bank 0
    ETH_WRITE8(b0sel_inst);
#endif
    ETH_GetMAC((uint8_t *)&ethMAC);
    
    // Check for a preexisting link
    ETH_CheckLinkUp();

}

/**
 * Check for the Link Status
 * @return SUCCESS if link found else return LINK_NOT_FOUND if link is not present.
 */
inline uint32_t ETH_readLinkStatus(void)
{
    return (ENCx24_Read(XJ600_ESTATL));
}

bool ETH_CheckLinkUp()
{
    uint32_t value;
    bool ret = false;
    // check for a preexisting link
    value = ETH_readLinkStatus();
    if(value & 0x0100)
    {
        ethData.up = true;
        ret = true;
    }
    return ret;
}

/**
 * Ethernet Event Handler Routine
 */
void ETH_EventHandler(void)
{
    uint16_t eirVal,estatVal,mabbipgVal,macon2Val;

    estatVal = ENCx24_Read(XJ600_ESTATL);
    // MAC is sending an interrupt
    // what is the interrupt
    eirVal = ENCx24_Read(XJ600_EIRL);

    if (eirVal !=0 )
    {
        if (eirVal & EIR_LINKIF) // something about the link changed.... update the link parameters
        {
            ethData.linkChange = true;
            macon2Val = ENCx24_Read(XJ600_MACON2L);

            ethData.up = false;
            if(estatVal & ESTAT_PHYLINK)
            {
                ethData.up = true;
            }

            // Update MAC duplex settings to match PHY duplex setting
            if (estatVal & ESTAT_PHYDPX)
            {
                // Switching to full duplex
                mabbipgVal = 0x15;
                macon2Val |= MACON2_FULDPX_ON;
            }
            else
            {
                // Switching to half duplex
                mabbipgVal = 0x12;
                macon2Val |= MACON2_FULDPX_OFF;
            }
            ENCx24_Write(XJ600_MABBIPGL,mabbipgVal);
            ENCx24_Write(XJ600_MACON2L, macon2Val);
        }
        if(eirVal & EIR_TXIF)
        {
            ethData.bufferBusy = false;// finished sending a packet
        }
        if((eirVal & EIR_RXABTIF )|| (eirVal & EIR_PCFULIF)) // buffer overflow
        {
            ETH_ResetReceiver();
        }
        // check if there are any received frames
        if(estatVal & ESTAT_PKTCNT || eirVal & EIR_PKTIF) // received a packet
        {
             if(ethData.pktReady == false)
             {
                 ethData.pktReady = true;
             }
        }
        ENCx24_BFC(XJ600_EIRL,eirVal); // write the EIR value back to clear any of the interrupts
    }        
}

/*
 *  Set the RX Read Pointer to the beginning of the next unprocessed packet
 * and read the information related to the received packet 
 */

void ETH_NextPacketUpdate()
{
    ETH_SetRXptr(nextPacketPointer);

    ETH_NCS_LOW();
    ETH_WRITE8(rrxdata_inst);
    ((char *) &nextPacketPointer)[0] = ETH_READ8();
    ((char *) &nextPacketPointer)[1] = ETH_READ8();
    ((char *) &rxPacketStatusVector)[0] = ETH_READ8();
    ((char *) &rxPacketStatusVector)[1] = ETH_READ8();
    ((char *) &rxPacketStatusVector)[2] = ETH_READ8();
    ((char *) &rxPacketStatusVector)[3] = ETH_READ8();
    ((char *) &rxPacketStatusVector)[4] = ETH_READ8();
    ((char *) &rxPacketStatusVector)[5] = ETH_READ8();

    ETH_NCS_HIGH();

    rxPacketStatusVector.ByteCount -= 4; // I don't care about the frame checksum at the end.
                                         // the checksum is 4 bytes.. so my payload is the byte count less 4.
}

/**
 * Reset Receive Buffer
 */
void ETH_ResetReceiver(void)
{
    ENCx24_BFS(XJ600_ECON2L, ECON2_RXRST);
    ENCx24_BFC(XJ600_ECON2L, ECON2_RXRST);

    ENCx24_BFC(XJ600_ECON1L, ECON1_RXEN);

    // Initialize RX tracking variables and other control state flags
    nextPacketPointer = RXSTART;

    // Set up RX buffer addresses
    ENCx24_Write(XJ600_ERXSTL, RXSTART);
    ENCx24_Write(XJ600_ERXTAILL, RAMSIZE - 2);

    // Enable RX packet reception
    ENCx24_BFS(XJ600_ECON1L, ECON1_RXEN);
}

/**
 * Clears number of bytes (length) from the RX buffer
 * @param length
 */
void ETH_Dump(uint16_t length)
{
    uint16_t newRXTail;
    length = (rxPacketStatusVector.ByteCount <= length) ? rxPacketStatusVector.ByteCount : length;
    if(length)
    {
        newRXTail = ENCx24_Read(XJ600_ERXRDPTL);
        newRXTail += length;
        //Write new RX tail
        ENCx24_Write(XJ600_ERXRDPTL, newRXTail);
    }
    rxPacketStatusVector.ByteCount -= length;
}

/**
 * Clears all bytes from the RX buffer
 */
void ETH_Flush(void)
{
    uint16_t newRXTail = nextPacketPointer - 2;
 
    //Special situation if nextPacketPointer is exactly RXSTART
    if (nextPacketPointer == RXSTART)
        newRXTail = RAMSIZE - 2;

    //Packet Decrement
    ETH_SetPktDec();
    ethData.pktReady = false; // IRQ line should remain low if PKTCNT is != 0

    //Write new RX tail
    ENCx24_Write(XJ600_ERXTAILL, newRXTail);
}

/* Ethernet Write Functions */
/* The Ethernet system needs a variety of ways to write to the MAC */
/* By making separate functions at the driver level, the upper layers get smaller */

/**
 * start a packet.
 * If the Ethernet transmitter is idle, then start a packet.  Return is true if the packet was started.
 * @return true if packet started.  false if transmitter is busy
 * */
error_msg ETH_WriteStart(const mac48Address_t *destMAC, uint16_t type)
{
    TXPacketSize = 0;
    if(ethData.bufferBusy)
    {
        return BUFFER_BUSY;
    }
    if((ENCx24_Read(XJ600_ECON1L) & 0x02))    
    {
        return TX_LOGIC_NOT_IDLE;
    }
    // Set the Window Write Pointer to the beginning of the transmit buffer
    ENCx24_Write(XJ600_EGPWRPTL, TXSTART);
    // TXPacketSize = 0;
    ETH_WriteBlock((char *)destMAC,6);  // destination
    ETH_WriteBlock((char *)&ethMAC,6);   // source
    ETH_Write16(type);
    ethData.bufferBusy = true;

    return SUCCESS;
}

// Tell the MAC to SEND NOW!
/**
 * Start the Transmission
 * @return
 */
error_msg ETH_Send(void)
{
    // wait for any transmissions to finish
    ENCx24_Write(XJ600_ETXLENL, TXPacketSize);
    if (!ethData.up)
    {
        return LINK_NOT_FOUND;
    }
    if(!ethData.bufferBusy)
    {
        return BUFFER_BUSY;
    }
    ETH_Set_TXRTS();
    ethData.bufferBusy = false;

    return SUCCESS;
}

/**
 * Copy the data from RX Buffer to the TX Buffer using DMA setup
 * This is used for ICMP ECHO to eliminate the need to extract the arbitrary payload
 * @param len
 */
error_msg ETH_Copy(uint16_t len)
{
    uint16_t txBufferAddress;

    // setup DMA to copy length bytes from RX buffer to TX buffer
    // this is used for ICMP ECHO to eliminate the need to extract the arbitrary payload
    // Wait until module is idle
    waitForDMA();

    if((ENCx24_Read(XJ600_ECON1L) & 0x20) == 0)
    {
        txBufferAddress = ENCx24_Read(XJ600_EGPWRPTL); // Current Window Write Pointer (the TX Buffer)
        ENCx24_Write(XJ600_EDMASTL, ethData.saveRDPT);
        ENCx24_Write(XJ600_EDMALENL,len);
        ENCx24_Write(XJ600_EDMADSTL, txBufferAddress);

        // Clear DMANOCS to select a checksum operation
        ENCx24_BFC(XJ600_ECON1L, 0x0004);
        // Set DMACPY to select a copy operation
        // Set DMACSSD to use a custom seed
        // Set DMAST to start the DMA operation
        ENCx24_BFS(XJ600_ECON1L,   0b0000000000111000);
        waitForDMA();

        // clean up the source and destination window pointers
        txBufferAddress += len;

        ENCx24_Write(XJ600_EGPWRPTL, txBufferAddress);

        TXPacketSize += len; // fix the packet length

        return SUCCESS;
    }
    RESET();
    return DMA_TIMEOUT;
}

/**
 * Reads MAC address of device
 */
void ETH_GetMAC(uint8_t * macAddr)
{
    // Get MAC address
    *macAddr++ = ETH_MACRead8(XJ600_MAADR1L);
    *macAddr++ = ETH_MACRead8(XJ600_MAADR1H);
    *macAddr++ = ETH_MACRead8(XJ600_MAADR2L);
    *macAddr++ = ETH_MACRead8(XJ600_MAADR2H);
    *macAddr++ = ETH_MACRead8(XJ600_MAADR3L);
    *macAddr++ = ETH_MACRead8(XJ600_MAADR3H);
}

/**
 * Write MAC address of device
 */
void ETH_SetMAC(uint8_t * macAddr)
{
    ETH_MACWrite8(XJ600_MAADR1L, *macAddr++ );
    ETH_MACWrite8(XJ600_MAADR1H, *macAddr++ );
    ETH_MACWrite8(XJ600_MAADR2L, *macAddr++ );
    ETH_MACWrite8(XJ600_MAADR2H, *macAddr++ );
    ETH_MACWrite8(XJ600_MAADR3L, *macAddr++ );
    ETH_MACWrite8(XJ600_MAADR3H, *macAddr++ );
}

/**
 * Wait for DMA
 */
inline static void waitForDMA(void)
{
    uint16_t econ1_val;
    do
    {
        econ1_val = ENCx24_Read(XJ600_ECON1L);
    } while ( econ1_val & ECON1_DMAST );
}


/**
 * Compute Hardware Transmit Checksum
 * @param position
 * @param length
 * @param seed
 * @return
 */
// do the checksum in the HW
 uint16_t ETH_TxComputeChecksum(uint16_t position, uint16_t length, uint16_t seed)
{
    uint16_t econ1Val;
    uint32_t cksm;
    // Wait until module is idle
    waitForDMA();

    // Clear DMACPY to prevent a copy operation
    // Clear DMANOCS to select a checksum operation
    // Clear DMACSSD to use the default seed of 0000h
    econ1Val = 0;
    //econ1.DMACPY = 1; econ1.DMANOCS = 1; econ1.DMACSSD = 1;
    //0x001C
    econ1Val = 0x001C;
    ENCx24_BFC(XJ600_ECON1L, econ1Val);

    // Set EDMAST to source address
    ENCx24_Write(XJ600_EDMASTL, position);
    // Set EDMALEN to length
    ENCx24_Write(XJ600_EDMALENL, length);

    econ1Val = ECON1_DMAST;
    //If we have a seed, now it's time
    if (seed)
    {
        econ1Val |= ECON1_DMACSSD;
        seed=~(seed);
        seed = htons(seed);
        ENCx24_Write(XJ600_EDMACSL, seed);
    }
    // Initiate operation
    ENCx24_BFS(XJ600_ECON1L, econ1Val);
    // Wait until done
    waitForDMA();
    cksm = ENCx24_Read(XJ600_EDMACSL);
    return cksm;
}

 /**
  * Compute Hardware Receive Checksum
  * @param len
  * @param seed
  * @return
  */
uint16_t ETH_RxComputeChecksum(uint16_t len, uint16_t seed)
{
    uint16_t econ1Val;
    uint16_t cksm;
    uint16_t rxPtr;
    // Wait until module is idle
    waitForDMA();

    // Clear DMACPY to prevent a copy operation
    // Clear DMANOCS to select a checksum operation
    // Clear DMACSSD to use the default seed of 0000h
    econ1Val = 0;
    //econ1.DMACPY = 1; econ1.DMANOCS = 1; econ1.DMACSSD = 1;
    //0x001C
    econ1Val = 0x001C;
    ENCx24_BFC(XJ600_ECON1L, econ1Val);

    rxPtr = ENCx24_Read(XJ600_ERXRDPTL);

    // Set EDMAST to source address
    ENCx24_Write(XJ600_EDMASTL, rxPtr);
    // Set EDMALEN to length
    ENCx24_Write(XJ600_EDMALENL, len);

    econ1Val = ECON1_DMAST;
    if (seed)
    {
        econ1Val |= ECON1_DMACSSD;
        seed=~(seed);
        seed = htons(seed);
        ENCx24_Write(XJ600_EDMACSL, seed);
    }    
    
    // Initiate operation
    ENCx24_BFS(XJ600_ECON1L, econ1Val);
    // Wait until done
    waitForDMA();
    cksm = ENCx24_Read(XJ600_EDMACSL);

    ENCx24_Write(XJ600_ERXRDPTL, rxPtr);

    return cksm;
}

/**
 * Save the Read Pointer
 */
void ETH_SaveRDPT(void)
{
   ethData.saveRDPT = ENCx24_Read(XJ600_ERXRDPTL);
}

void ETH_ResetByteCount(void)
{
    ethData.saveWRPT = ENCx24_Read(XJ600_EGPWRPTL);
}

uint16_t ETH_GetByteCount(void)
{
    uint16_t wPtr;

    wPtr = ENCx24_Read(XJ600_EGPWRPTL);

    return (wPtr - ethData.saveWRPT);
}

