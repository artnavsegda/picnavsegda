/**
  Led Driver
	
  Company:
    Microchip Technology Inc.

  File Name:
    led_driver.c

  Summary:
    LED Driver

  Description:
    Simple implementation of a LED driver.

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
#include "hardware.h"

typedef struct
{
    uint8_t value;
    uint8_t count;
}led_t;

#define LEDCOUNT 8
#define LEDPORT LATJ

led_t led_values[LEDCOUNT];

void LED_Init(void)
{
    uint8_t x = 0;
    for(x = 0; x < LEDCOUNT; x++)
    {
        led_values[x].value = 0;
    }
}

void LED_Set(uint8_t ledIdx)
{
    led_values[ledIdx].value = 255;
}

void LED_Irq(void) // run me at about 1ms
{
    uint8_t x;
    uint8_t output;
    output = 0;
    for(x = 0; x < LEDCOUNT; x++)
    {
        if(led_values[x].value)
        {
            led_values[x].value --; // decay the PWM
            led_values[x].count ++;
            led_values[x].count &= 0x0F;

            if(led_values[x].count < led_values[x].value>>4)
            {
                output |= 1<<x;
            }
        }
    }
    LEDPORT = output;
}
