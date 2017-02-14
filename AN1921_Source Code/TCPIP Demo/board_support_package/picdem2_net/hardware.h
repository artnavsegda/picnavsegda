/**
  Hardware specific API Header File
	
  Company:
    Microchip Technology Inc.

  File Name:
    hardware.h

  Summary:
    Header file for initializing the hardware.

  Description:
     This header file provides APIs for initializing the hardware on PICDEM2 .net
     board.

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

#ifndef HARDWARE_H
#define	HARDWARE_H

#include <xc.h>

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif


#define _XTAL_FREQ          41666667UL    //41.6667MHz

#ifdef USE_ENC28J60_SPI
#define ETH_NCS_HIGH() do{LATD3 = 1;} while(0)
#define ETH_NCS_LOW()  do{LATD3 = 0;} while(0)
        
#define ETH_IRQ PORTBbits.RB0         
#endif        
        
#ifdef USE_ENCx24J600_SPI        

#define ETH_SPI
        
#define ETH_NCS_HIGH() do{LATB3 = 1;} while(0)
#define ETH_NCS_LOW()  do{LATB3 = 0;} while(0)
        
#define ETH_IRQ PORTBbits.RB2         
#endif
        
#define link_led(a)         do{LATJ0 = a;}while(0)
#define tx_led(a)           do{LATJ1 = a;}while(0)
#define rx_led(a)           do{LATJ2 = a;}while(0)
#define txerr_led(a)        do{LATJ3 = a;}while(0)
#define rxerr_led(a)        do{LATJ4 = a;}while(0)
#define pktcnt_led(a)       do{LATJ5 = a;}while(0)


// 25LC256 I/O pins
#define EEPROM_CS_TRIS		(TRISDbits.TRISD7)
#define EEPROM_CS_IO		(LATDbits.LATD7)
#define EEPROM_SCK_TRIS		(TRISCbits.TRISC3)
#define EEPROM_SDI_TRIS		(TRISCbits.TRISC4)
#define EEPROM_SDO_TRIS		(TRISCbits.TRISC5)
#define EEPROM_SPI_IF		(PIR1bits.SSP1IF)
#define EEPROM_SSPBUF		(SSP1BUF)
#define EEPROM_SPICON1		(SSP1CON1)
#define EEPROM_SPICON1bits	(SSP1CON1bits)
#define EEPROM_SPICON2		(SSP1CON2)
#define EEPROM_SPISTAT		(SSP1STAT)
#define EEPROM_SPISTATbits	(SSP1STATbits)


void initHW(void);

#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
#endif	/* HARDWARE_H */

