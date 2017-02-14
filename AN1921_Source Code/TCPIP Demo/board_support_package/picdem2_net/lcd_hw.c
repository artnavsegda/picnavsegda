/**
  Descriptive File Name
	
  Company:
    Microchip Technology Inc.

  File Name:
    file_template_source.c

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
#include "lcd_hw.h"
#include "hardware.h"

#define lcd_data LATE
#define lcd_e  LATH0
#define lcd_rw LATH1
#define lcd_rs LATH2

void lcd_init_pins(void)
{
	TRISE = 0; // data pins are port e
	TRISH = 0x00; // RW, RS and E are Port H <0:2>
        LATE = 0;
        LATH = 0;
}


void lcd_write_ctrl(char c)
{
        lcd_rw = 0;
        lcd_rs = 0;        

         __delay_us(50);
	lcd_data = c;       
        lcd_e = 1;
	__delay_us(50);
	lcd_e = 0;
}

void lcd_write_data(char d)
{
        lcd_rw = 0;
        lcd_rs = 1;
	lcd_data = d;
        __delay_us(1);
        lcd_e = 1;
	__delay_us(1);
	lcd_e = 0;
}

void lcd_busy(void) // just kill time for now
{
    __delay_us(50);
}
