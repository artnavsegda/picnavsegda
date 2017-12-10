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
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.26
        Device            :  PIC24FJ128GB410
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.30
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

/*
                         Main application
 */

void ads1256config()
{
	while(_RD1);
	_LATD2 = 0;
	SPI1_Exchange8bit(0x50|0);
	SPI1_Exchange8bit(0x03);
	SPI1_Exchange8bit(0x00);
	SPI1_Exchange8bit(0x08);
	SPI1_Exchange8bit(0x00);
	SPI1_Exchange8bit(0x03);
	_LATD2 = 1;
}

int main(void)
{
    uint32_t result = 0;
    // initialize the device
    SYSTEM_Initialize();
    printf("MCU started\n\r");
    
    while(_RD1);
    _LATD2 = 0;
    SPI1_Exchange8bit(0x10|0);
    SPI1_Exchange8bit(0x0);
    uint8_t _data = SPI1_Exchange8bit(0xFF);
    _LATD2 = 1;
    printf("chip id %d\n\r",_data >> 4);
    
    ads1256config();

    while (1)
    {
        _LATE3 = _RG1; // LAMP_ENABLE = ASWITCH
        _LATE2 = _RE0; // PELTIER_ENABLE = BSWITCH
        if (_RD1 == 0)
        {
            _LATD2 = 0;
            SPI1_Exchange8bit(0x01);
			((char *)&result)[2] = SPI1_Exchange8bit(0xFF);
			((char *)&result)[1] = SPI1_Exchange8bit(0xFF);
            ((char *)&result)[0] = SPI1_Exchange8bit(0xFF);
            _LATD2 = 1;
            printf("%lu\r\n",result);
        }
    }

    return -1;
}
/**
 End of File
*/