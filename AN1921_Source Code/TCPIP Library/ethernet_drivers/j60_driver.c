/**
  PIC18FxxJ60 Ethernet driver
	
  Company:
    Microchip Technology Inc.

  File Name:
    j60_driver.c

  Summary:
    This is the Ethernet driver implementation for PIC18FxxJ60 family devices.

  Description:
    This file provides the Ethernet driver API implementation for 
    the PIC18Fx7J60 family devices.

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
#include <stdio.h>
#include <stdbool.h>
#include "ethernet_driver.h"
#include "mac_address.h"
#include "hardware.h"
#include "syslog.h"

#include "led_driver.h"

// Note this driver is half duplex because the HW cannot automatically negotiate full-duplex
// If full duplex is desired, both ends of the link must be manuall configured.
// the "out of box" experience dictates half duplex mode.

volatile ethernetDriver_t ethData;

// adjust these parameters for the MAC...
#define RAMSIZE (8192)
#define MAX_TX_PACKET (1518)

// typical memory map for the MAC buffers
#define TXSTART (RAMSIZE - MAX_TX_PACKET)
#define TXEND	(RAMSIZE-1)
#define RXSTART (0)
#define RXEND	(TXSTART - 2)

//#define ETH_packetReady() eth_data.pktReady
//#define ETH_linkCheck() eth_data.up
//#define ETH_linkChanged() eth_data.linkChange

// Define a temporary register for passing data to inline assembly
// This is to work around the 110110 LSB errata and to control RDPTR WRPTR update counts
uint16_t errataTemp @ 0xE7E;

inline uint8_t ETH_EdataRead()
{
    asm("movff EDATA,_errataTemp");
    return (uint8_t) errataTemp;
}

inline void ETH_EdataWrite(uint8_t d)
{
    asm("movff WREG,EDATA");
}

static uint16_t nextPacketPointer;
static receiveStatusVector_t rxPacketStatusVector;

// PHY Read and Write Helper functions
typedef enum{ PHCON1 = 0, PHSTAT1=0x01, PHCON2=0x10, PHSTAT2=0x11, PHIE=0x12, PHIR=0x13, PHLCON=0x14} phyRegister_t;
typedef enum{ READ_FAIL = -3, WRITE_FAIL = -2, BUSY_TIMEOUT = -1, NOERROR = 0} phyError_t;

phyError_t PHY_Write(phyRegister_t reg, uint16_t data);
int32_t PHY_Read(phyRegister_t reg);

/**
 * Initialize Ethernet Controller
 */
void ETH_Init(void)
{
    const mac48Address_t *mac;
    uint16_t phycon1_value;
    
    // initialize the driver variables
    ethData.error = false; // no error
    ethData.up = false; // no link
    ethData.linkChange = false;
    ethData.bufferBusy = false; // transmit data buffer is free
    ethData.saveRDPT = 0;
    // Initialize RX tracking variables and other control state flags
    nextPacketPointer = RXSTART;

    // Enable Ethernet
    ECON2 = 0xA0; // AUTOINC, ETHEN
    
    // wait for phy ready (can take 1ms)
    while(!ESTATbits.PHYRDY);

#if(1)
    // initialize the MAC for Full Duplex
    MACON1  = 0b00001101; NOP(); // Full duplex value (with flow control)
    MACON3  = 0b10110011; NOP(); // Byte stuffing for short packets, Normal frames and headers.  Full duplex
    MACON4  = 0b00000000; NOP(); // Full Duplex - Ignored
    MABBIPG = 0x15;       NOP(); // correct gap for full duplex
    MAIPG   = 0x0012;     NOP(); // correct gap for full duplex
    phycon1_value = 0x0100;      // setup for full duplex in the phy

#else
    // Intialize the MAC for Half Duplex
    MACON1  = 0x01;       NOP(); // Half duplex value (no flow control)
    MACON3  = 0b10110010; NOP();
    MACON4  = 0b01000000; NOP(); // Half Duplex - Wait forever for access to the wire
    MABBIPG = 0x12;       NOP(); // correct gap for half duplex
    MAIPG   = 0x0C12;     NOP(); // correct gap for half duplex
    EFLOCON = 0x00;              // half duplex flow control off.
    phycon1_value = 0x0000;   // PHY is half duplex
#endif


    // Set up TX/RX buffer addresses
    ETXST = TXSTART; 
    ETXND = TXEND; 
    ERXST = RXSTART;
    ERXND = RXEND;

    // Setup EDATA Pointers
    ERDPT = RXSTART;
    EWRPT = TXSTART;

    // Setup RXRDRDPT to a dummy value for the first packet
    ERXRDPT = -1;

    MAMXFL  = MAX_TX_PACKET;

    // Setup MAC address to MADDR registers
    mac = MAC_getAddress();
    MAADR1  = mac->mac_array[0]; NOP();
    MAADR2  = mac->mac_array[1]; NOP();
    MAADR3  = mac->mac_array[2]; NOP();
    MAADR4  = mac->mac_array[3]; NOP();
    MAADR5  = mac->mac_array[4]; NOP();
    MAADR6  = mac->mac_array[5]; NOP();

    // Configure the receive filter
//    ERXFCON = 0b10101001; //UCEN,OR,CRCEN,MPEN,BCEN (unicast,crc,magic packet,broadcast)
    ERXFCON = 0b10101011; //UCEN,OR,CRCEN,MPEN,BCEN (unicast,crc,magic packet,multicast,broadcast)

    // RXEN enabled
    ECON1=0x04;  

    // Configure Phy registers
    PHY_Write(PHCON1, phycon1_value);   // PHY is full duplex
    PHY_Write(PHCON2, 0x0110); // Do not transmit loopback
    PHY_Write(PHLCON, 0b01110101001010); // LED control - LEDA = TX/RX, LEDB = Link, Stretched LED

    // Check for a preexisting link
    ETH_CheckLinkUp();

    // configure ETHERNET IRQ's
    EIE = 0b01011001;
    PHY_Write(PHIE,0x0012);

    /* Required if driver running in interrupt driven*/
    IPR2bits.ETHIP = 0;  // ethernet is low priority. (big buffers)
    PIE2bits.ETHIE = 1;  // enable the HW interrupt.

}
/**
 * Check for the Link Status
 * @return SUCCESS if link found else return LINK_NOT_FOUND if link is not present.
 */
inline uint32_t ETH_readLinkStatus(void)
{
    return (PHY_Read(PHSTAT2));
}

bool ETH_CheckLinkUp()
{
    uint32_t value;
    // check for a preexisting link
    value = ETH_readLinkStatus();
    if(value & 0x0400)
    {
        ethData.up = true;
        return true;
    }
    else
    return false;
}

/**
 * Ethernet Event Handler
 */
void ETH_EventHandler(void)
{
    // check for the IRQ Flag
        PIR2bits.ETHIF = 0;
        if(EPKTCNT >= 3)
//            led_set(7);

       if (EIRbits.LINKIF) // something about the link changed.... update the link parameters
        {
            PHY_Read(PHIR); // clear the link irq

            ethData.linkChange = true;
            ethData.up = false;

            // recheck for the link state.
            if(ETH_CheckLinkUp())
            {
//                led_set(6);
            }
        }

        if(EIRbits.RXERIF) // buffer overflow
        {
//            led_set(5);
            EIRbits.RXERIF = 0;
        }

        if (EIRbits.TXERIF)
        {
//            led_set(4);
            EIRbits.TXERIF = 0;
        }

        if(EIRbits.TXIF) // finished sending a packet
        {
//            led_set(3);
            EIRbits.TXIF = 0;
            ethData.bufferBusy = false;
        }

        if (EIRbits.PKTIF) // Packet receive buffer has at least 1 unprocessed packet
        {
            if(ethData.pktReady == false)
            {
//                led_set(2);
                ethData.pktReady = true;
                EIEbits.PKTIE = 0; // turn off the packet interrupt until this one is handled.
            }
        }
    }

void ETH_NextPacketUpdate()
{

    ERDPT = nextPacketPointer;

    // Extract the packet status data
    // NOP's needed to meet Tcy timing spec for > 20 Mhz operation
    ((char *) &nextPacketPointer)[0]    = ETH_EdataRead();
    ((char *) &nextPacketPointer)[1]    = ETH_EdataRead();
    ((char *) &rxPacketStatusVector)[0] = ETH_EdataRead();
    ((char *) &rxPacketStatusVector)[1] = ETH_EdataRead();
    ((char *) &rxPacketStatusVector)[2] = ETH_EdataRead();
    ((char *) &rxPacketStatusVector)[3] = ETH_EdataRead();

    // the checksum is 4 bytes.. so my payload is the byte count less 4.
    rxPacketStatusVector.byteCount -= 4; // I don't care about the frame checksum at the end.    
}

void ETH_ResetReceiver(void)
{
    ECON1 = RXRST;
}

void ETH_SendSystemReset(void)
{
     RESET(); 
}

/**
 * Waits for the PHY to be free
 * @return NOERROR if PHY is free else returns BUSY_TIMEOUT
 */
inline phyError_t PHY_WaitForBusy(void)
{
    phyError_t ret = NOERROR;
    uint8_t timeout;

    for(timeout = 0; timeout < 10;timeout++) NOP();
    timeout = 90;
    while(MISTATbits.BUSY && --timeout) NOP(); // wait for the PHY to be free.

    if(timeout == 0) ret = BUSY_TIMEOUT;
    return ret;
}

/**
 * Write PHY registers
 * @param reg
 * @param data
 * @return NOERROR if PHY is free else BUSY_TIMEOUT if PHY is busy
 */
phyError_t PHY_Write(phyRegister_t reg, uint16_t data)
{
    uint8_t GIESave;
    // Write the register address
    MIREGADR = reg;

    // Write the data through the MIIM interface
    // Order is important: write low byte first, high byte last
    //
    // Due to a silicon problem, you cannot access any register with LSb address
    // bits of 0x16 between your write to MIWRL and MIWRH or else the value in
    // MIWRL will be corrupted.  This inline assembly prevents this by copying
    // the value to PRODH:PRODL first, which is at fixed locations of
    // 0xFF4:0xFF3.  These addresses have LSb address bits of 0x14 and 0x13.
    // Interrupts must be disabled to prevent arbitrary ISR code from accessing
    // memory with LSb bits of 0x16 and corrupting the MIWRL value.
    errataTemp = data;
    GIESave = INTCON;
    INTCON = 0;
    MIWR = errataTemp;
    INTCON = GIESave;				// Restore GIEH and GIEL value

    // Wait until the PHY register has been written
    // This operation requires 10.24us
    return PHY_WaitForBusy();
}

/**
 * Read PHY registers
 * @param reg
 * @return
 */

int32_t PHY_Read(phyRegister_t reg)
{
    int32_t ret = NOERROR;
    if(PHY_WaitForBusy() == NOERROR)
    {
        MIREGADR = reg;
        MICMD = 0;
        MICMDbits.MIIRD = 1;
        NOP(); NOP(); // specified 2 Tcy before Busy bit is set.
        if(PHY_WaitForBusy() == BUSY_TIMEOUT)
        {
            ret = READ_FAIL;
        }
        else
        {
            MICMDbits.MIIRD = 0;
            ret = MIRD;
        }
    }
    else
    {
        ret = BUSY_TIMEOUT;
    }
    return ret;
}

/**
 * Read 1 byte of data from the RX buffer
 * @return
 */
uint8_t ETH_Read8(void)
{
    uint8_t ret = 0;
    if(rxPacketStatusVector.byteCount >= sizeof(ret))
    {
        ret = ETH_EdataRead();
        rxPacketStatusVector.byteCount -= sizeof(ret);
        ethData.error = 0;
    }
    else
    {
        ethData.error = 1;
    }
    return ret;
}
/**
 * Read 2 bytes of data from RX buffer
 * @return
 */
uint16_t ETH_Read16(void)
{
    uint16_t ret = 0;
    if(rxPacketStatusVector.byteCount >= sizeof(ret))
    {
        ((uint8_t *)&ret)[1] = ETH_EdataRead();
        ((uint8_t *)&ret)[0] = ETH_EdataRead();
        rxPacketStatusVector.byteCount -= sizeof(ret);
        ethData.error = 0;
    }
    else
    {
        ethData.error = 1;
    }
    return ret;
}

/**
 * Read 2 bytes of data from the RX buffer
 * @return
 */
uint32_t ETH_Read32(void)
{
    uint32_t ret = 0;
    if(rxPacketStatusVector.byteCount >= sizeof(ret))
    {
        ((uint8_t *)&ret)[3] = ETH_EdataRead();
        ((uint8_t *)&ret)[2] = ETH_EdataRead();
        ((uint8_t *)&ret)[1] = ETH_EdataRead();
        ((uint8_t *)&ret)[0] = ETH_EdataRead();;
        rxPacketStatusVector.byteCount -= sizeof(ret);
        ethData.error = 0;
    }
    else
    {
        ethData.error = 1;
    }
    return ret;
}

/**
 * Read a block of data from RX buffer
 * @param buffer
 * @param length
 * @return
 */
uint16_t ETH_ReadBlock(void *buffer, uint16_t length)
{
    uint16_t len = 0;
    char *p = buffer;
    while(rxPacketStatusVector.byteCount && length)
    {
        *p++ = ETH_EdataRead();
        len ++;
        length --;
        rxPacketStatusVector.byteCount --;
        ethData.error = 0;
    }
    return len;
}

/**
 * Writes 1 byte of data to the TX buffer
 * @param data
 */

void ETH_Write8(uint8_t data)
{
    ETH_EdataWrite(data);
}

/**
 * Writes the 2 bytes of data to the TX buffer
 * @param data
 */
void ETH_Write16(uint16_t data)
{
    ETH_EdataWrite(data >> 8);
    ETH_EdataWrite(data);
}

/**
 * Writes the 3 bytes of data to the TX buffer
 * @param data
 */
void ETH_Write24(uint24_t data)
{
    ETH_EdataWrite(data >> 16);
    ETH_EdataWrite(data >>  8);
    ETH_EdataWrite(data);
}

/**
 * Writes the 4 bytes of data to the TX buffer
 * @param data
 */
void ETH_Write32(uint32_t data)
{
    ETH_EdataWrite(data >> 24);
    ETH_EdataWrite(data >> 16);
    ETH_EdataWrite(data >>  8);
    ETH_EdataWrite(data);
}

/**
 * Writes a block of data to the TX buffer
 * @param buffer
 * @param length
 * @return
 */
uint16_t ETH_WriteBlock(void *buffer, uint16_t length)
{
    char *p = buffer;
    while(length-- && (EWRPT < TXEND))
    {
        ETH_EdataWrite(*p++);
    }
    return length;
}


/**
 * If the ethernet transmitter is idle, then start a packet.  Return is SUCCESS if the packet was started.
 * @param dest_mac
 * @param type
 * @return If the ethernet transmitter is idle, then start a packet.  Return is SUCCESS if the packet was started.
 */
error_msg ETH_WriteStart(const mac48Address_t *dest_mac, uint16_t type)
{
    if(ethData.bufferBusy)
    {
        return BUFFER_BUSY;
    }

    if(ECON1bits.TXRTS)
    {
        return TX_LOGIC_NOT_IDLE;
    }
    ETXST = TXSTART; 
    EWRPT = TXSTART; 

    ETH_ResetByteCount();

    ETH_EdataWrite(0x06); // first byte is the transmit command override
    ETH_EdataWrite(dest_mac->mac_array[0]);
    ETH_EdataWrite(dest_mac->mac_array[1]);
    ETH_EdataWrite(dest_mac->mac_array[2]);
    ETH_EdataWrite(dest_mac->mac_array[3]);
    ETH_EdataWrite(dest_mac->mac_array[4]);
    ETH_EdataWrite(dest_mac->mac_array[5]);
    // write MY mac address into the ethernet packet
    ETH_EdataWrite(MAADR1);
    ETH_EdataWrite(MAADR2);
    ETH_EdataWrite(MAADR3);
    ETH_EdataWrite(MAADR4);
    ETH_EdataWrite(MAADR5);
    ETH_EdataWrite(MAADR6);
    ETH_EdataWrite(((char *)&type)[1]);
    ETH_EdataWrite(((char *)&type)[0]);

    ethData.bufferBusy = true;
    return SUCCESS;
}

/**
 * Start the Transmission
 * @return
 */
error_msg ETH_Send(void)
{
    uint16_t packetEnd;

    packetEnd = EWRPT - 1;

    if(!ethData.up)
    {
        return LINK_NOT_FOUND;
    }
    if(!ethData.bufferBusy)
    {
        return BUFFER_BUSY;
    }
    ETXST = TXSTART;
    ETXND = packetEnd;
    NOP(); NOP();
    ECON1bits.TXRTS = 1; // start sending

    return SUCCESS;
}


/**
 * Insert data in between of the TX Buffer
 * @param data
 * @param len
 * @param offset
 */
void ETH_Insert(uint8_t *data, uint16_t len, uint16_t offset)
{
    uint16_t current_tx_ptr = EWRPT;
    EWRPT = TXSTART + offset + 1; // we need +1 here because of SFD.
    while(len--)
    {
        ETH_EdataWrite(*data++);
    }
    EWRPT = current_tx_ptr;
}

/**
 * Clears number of bytes (length) from the RX buffer
 * @param length
 */
void ETH_Dump(uint16_t length)
{
    length = (rxPacketStatusVector.byteCount <= length) ? rxPacketStatusVector.byteCount : length;
    if (length)
    {
        //Write new RX tail
        ERDPT += length;
        rxPacketStatusVector.byteCount -= length;
    }
}

/**
 *  Clears all bytes from the RX buffer
 */
void ETH_Flush(void)
{
    ethData.pktReady = false;
    // Need to decrement the packet counter
    ECON2 = ECON2 | 0x40; // PKTDEC

    // Set the RX Packet Limit to the beginning of the next unprocessed packet
    // ERXRDPT = nextPacketPointer;
    // RX Read pointer must be an odd address.
    // The nextPacketPointer is ALWAYS even from the HW.
    if (((nextPacketPointer - 1) < ERXST) ||
        ((nextPacketPointer - 1) > ERXND))
        ERXRDPT = ERXND;
    else
        ERXRDPT = nextPacketPointer - 1;

    EIEbits.PKTIE = 1; // turn on the packet interrupt to get the next one.
}

//#define ETH_SIMPLE_COPY

#ifdef ETH_SIMPLE_COPY
// This is a dummy buffer copy but it will save us in case DMA doesn't work
error_msg ETH_Copy(uint16_t len)
{
    uint16_t tmp_len;

    ERDPT  = ethData.saveRDPT; // setup the source pointer from the current read pointer
    tmp_len  = len;

    while(tmp_len--)
    {
        asm("movff EDATA,_errataTemp");
        asm("movff _errataTemp,EDATA");
    }
    return 1;
}
#else
/**
 * Copy the data from RX Buffer to the TX Buffer using DMA setup
 * @param len
 * @return
 */
error_msg ETH_Copy(uint16_t len)
{
    uint16_t timer;
    uint16_t tmp_len;

    timer = 2 * len;
    while(ECON1bits.DMAST!=0 && --timer) NOP(); // sit here until DMA is free
    if(ECON1bits.DMAST==0)
    {
        EDMADST = EWRPT; // setup the destination start pointer
        EDMAST  = ethData.saveRDPT; // setup the source pointer from the current read pointer

        tmp_len  = ethData.saveRDPT + len; // J60 DMA uses an end pointer to mark the finish

        if (tmp_len > (RXEND) )
        {
            tmp_len = tmp_len - (RXEND);
            EDMAND = RXSTART + tmp_len;
            // update the write pointer to the last location in TX buffer
        }else
        {
            EDMAND = tmp_len;
        }

        ECON1bits.CSUMEN = 0; // copy mode
        ECON1bits.DMAST  = 1; // start dma
        /* sometimes it takes longer to complete if there is heavy network traffic */
        timer = 40 * len;
        while(ECON1bits.DMAST!=0 && --timer) NOP(); // sit here until DMA is free
        if(ECON1bits.DMAST == 0)
        {
            EWRPT += len;
            return SUCCESS;
        }
    }
    // if we are here. the DMA timed out.
    SYSLOG_Write("DMA TIMEOUT!!!");
    RESET(); // reboot for now
    return DMA_TIMEOUT;
}
#endif

static uint16_t ETH_ComputeChecksum(uint16_t len, uint16_t seed)
{
    uint32_t cksm;
    uint16_t v;

    cksm = seed;
    
    while(len > 1)
    {
        v = 0;
        ((char *)&v)[1] = ETH_EdataRead();
        ((char *)&v)[0] = ETH_EdataRead();
        cksm += v;
        len -= 2;
    }

    if(len)
    {
        v = 0;
        ((char *)&v)[1] = ETH_EdataRead();
        ((char *)&v)[0] = 0;
        cksm += v;
    }
    
    // wrap the checksum
    while(cksm >> 16)
    {
        cksm = (cksm & 0x0FFFF) + (cksm>>16);
    }

    // invert the number.
    cksm = ~cksm;

    // Return the resulting checksum
    return cksm;
}

/**
 * Calculate the TX Checksum - Software Checksum
 * @param position
 * @param len
 * @param seed
 * @return
 */
uint16_t ETH_TxComputeChecksum(uint16_t position, uint16_t len, uint16_t seed)
{
    uint16_t rxptr;
    uint32_t cksm;

    // Save the read pointer starting address
    rxptr = ERDPT;

    // position the read pointer for the checksum
    ERDPT = TXSTART + position + 1; // we need +1 here because of SFD.

    cksm = ETH_ComputeChecksum( len, seed);
    
    // Restore old read pointer location
    ERDPT = rxptr;

    cksm = ((cksm & 0xFF00) >> 8) | ((cksm & 0x00FF) << 8);
    // Return the resulting checksum
    return cksm;
}

/**
 * Calculate RX checksum - Software checksum
 * @param len
 * @param seed
 * @return
 */
uint16_t ETH_RxComputeChecksum(uint16_t len, uint16_t seed)
{
    uint16_t rxptr;
    uint32_t cksm;

    // Save the read pointer starting address
    rxptr = ERDPT;

    cksm = ETH_ComputeChecksum( len, seed);
    
    // Restore old read pointer location
    ERDPT = rxptr;
    
    // Return the resulting checksum
    return ((cksm & 0xFF00) >> 8) | ((cksm & 0x00FF) << 8);
}

/**
 * Get the MAC address
 * @param mac
 */
void ETH_GetMAC(uint8_t *mac)
{
    *mac++ = MAADR1;
    *mac++ = MAADR2;
    *mac++ = MAADR3;
    *mac++ = MAADR4;
    *mac++ = MAADR5;
    *mac = MAADR6;
}

/**
 * Set the MAC address
 * @param mac
 */

void ETH_SetMAC(uint8_t *mac)
{
    MAADR1 = *mac++;
    MAADR2 = *mac++;
    MAADR3 = *mac++;
    MAADR4 = *mac++;
    MAADR5 = *mac++;
    MAADR6 = *mac;
}


void ETH_SaveRDPT(void)
{
    ethData.saveRDPT = ERDPT;
}

void ETH_ResetByteCount(void)
{
    ethData.saveWRPT = EWRPT;
}

//uint16_t ETH_GetByteCount(void)
//{
//    return (EWRPT - ethData.saveWRPT);
//}

uint16_t ETH_GetByteCount(void)
{
    uint16_t val;
    val = EWRPT - ethData.saveWRPT;
    return val ;
}
