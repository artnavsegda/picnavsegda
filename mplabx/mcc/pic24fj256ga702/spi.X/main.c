/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.25
        Device            :  PIC24FJ256GA702
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.26
        MPLAB             :  MPLAB X 3.45
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#define FCY _XTAL_FREQ
#include <libpic30.h>

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(100);
    SPI1_Exchange8bitBuffer("\xFF\xFF\xFF\xFF\xFF",5,NULL);
    __delay_ms(10);
    SPI1_Exchange8bitBuffer("\x20\x0C\x10\x04",4,NULL);
    __delay_ms(10);
    SPI1_Exchange8bitBuffer("\x60\x18\x3A\x00",4,NULL);
    __delay_ms(10);
    SPI1_Exchange8bitBuffer("\x70\x89\x78\xD7",4,NULL);
    __delay_ms(10);
    
    uint8_t adcdata[2];

    while (1)
    {
        // Add your application code
        SPI1_Exchange8bit(0x38);
        SPI1_Exchange8bitBuffer(NULL,2,adcdata);
        printf("adcdata %x %x\r\n",adcdata[0],adcdata[1]);
        __delay_ms(100);
    }

    return -1;
}
/**
 End of File
*/