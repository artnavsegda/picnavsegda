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
        Device            :  PIC24FJ128GC010
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
#define FCY     (_XTAL_FREQ/2)
#include <libpic30.h>
#include "modbus.h"

#define DEVICEID 50

mbframestruct askmbframe, reqmbframe;

/*
                         Main application
 */

#define byteswap(toswap) asm("swap %0" : "+r"(toswap))

int Swap(int number)
{
    byteswap(number);
    return number;
}

int main(void)
{
    uint8_t buffer[10];
    int numread, i;
    
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(100);
    printf("MCU started\r\n");
   

    while (1)
    {
        numread = UART2_ReadBuffer((uint8_t *)&askmbframe,10);
        if (numread > 0)
        {
            //UART2_WriteBuffer(buffer,number);
            printf("Recieved %d bytes to the buffer\r\n",numread);
            for (i=0; i<numread;i++)
                printf("0x%02X ",buffer[i]);
            printf("\r\n");
            printf("Unit id: %u\r\n", askmbframe.unitid);
            printf("Function code: %d\r\n", askmbframe.fncode);
            for (i=0; i<((numread-2)/2)-1;i++)
                printf("%u ",Swap(askmbframe.data.words[i]));
            printf("\r\n");
            printf("recieved CRC 0x%04X\n\r",askmbframe.data.words[((numread-2)/2)-1]);
            
            if (askmbframe.unitid == DEVICEID)
            {
                printf("device id matches\r\n");
                UART2_WriteBuffer(buffer,numread);
            }
            else
                printf("device id mismatch\n");
        }
        __delay_ms(100);
    }

    return -1;
}
/**
 End of File
*/