/**
  Descriptive File Name
	
  Company:
    Microchip Technology Inc.

  File Name:
    hardware.c

  Summary:
    Brief Description of the file (will placed in a table if using Doc-o-Matic)

  Description:
    This section is for a description of the file.  It should be in complete
    sentences describing the purpose of this file.

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
#include <stdio.h>
#include "rtcc.h"
#include "uart.h"
#include "mssp_spi_master.h"
#include "eeprom.h"
#include "adc.h"

void initHW(void)
{
    // SCS FOSC; OSTS intosc; IRCF 16MHz_HFINTOSC/4; IDLEN disabled; 
    OSCCON = 0x70;
    // INTSRC disabled; PLLEN disabled; TUN 0; 
    OSCTUNE = 0x00;
    
    /**
    LATx registers
    */   
    LATE = 0x00;    
    LATD = 0x02;    
    LATA = 0x00;    
    LATB = 0x00;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISE = 0x07;
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0x97;
    TRISD = 0xF5;

    // LED's
/*    TRISJ = 0; // PORTJ is all the LED's
    LATJ = 0;

    TRISDbits.TRISD3 = 0;
    LATDbits.LATD3   = 1;
    
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 1;
    TRISCbits.TRISC5 = 0;
    
    TRISA = 0b11111100;// RA0, RA1 are Ethernet LED's*/

    // Enable internal PORTB pull-ups
//    RBPU = 0;
    
#ifdef USE_ENCx24J600_SPI
    // Enable internal PORTB pull-ups
    RBPU = 0;

    TRISBbits.TRISB2 = 1;

    // Crossover switch
    TRISBbits.TRISB4 = 0;
    LATBbits.LATB4 = 0;

    // ENCx24J600 Chip select
    TRISBbits.TRISB3 = 0;
    LATBbits.LATB3 = 0;
    
#else

#ifdef USE_ENC28J60_SPI

#warning "Make sure that jumper JP9 from PICDEM.net 2 Board is connected"    
#warning "Button RB0 cannot be used in this case"    

#endif
    
    // Buttons
    TRISB = 0x0F; // Port B <0:3> are the buttons

#endif
    
    // Timers
    // timer 1 configured in RTCC.C
    rtcc_init();

      //SPI
    SPI_Initialize();

    // UART to Debug
    uart_init();
    
    printf("\r\n\r\nStarting printf output\r\n");

    //EEPROM
//    eeprom_init();

    printf("Adc init: ");
    ADC_Initialize();
    printf("done \r\n");
    
}
