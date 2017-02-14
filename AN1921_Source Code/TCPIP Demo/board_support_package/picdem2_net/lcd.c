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

/*
 *	LCD interface example
 *	Uses routines from delay.c
 *	This code will interface to a standard LCD controller
 *	like the Hitachi HD44780. It uses it in 4 bit mode, with
 *	the hardware connected as follows (the standard 14 pin 
 *	LCD connector is used):
 *	
 *	PORTC bits 0-3 are connected to the LCD data bits 4-7 (high nibble)
 *	PORTC bit 5 is connected to the LCD RS input (register select)
 *	PORTA bit 2 is connected to the LCD EN bit (enable)
 *	
 *	To use these routines, set up the port I/O (TRISA, TRISB) then
 *	call lcd_init(), then other routines as required.
 *	
 */

#include <xc.h>
#include "lcd_hw.h"
#include "hardware.h"


/*
 * 	Clear and home the LCD
 */

void lcd_clear(void)
{
	lcd_write_ctrl(0x1);
        __delay_ms(10);
        lcd_write_ctrl(0x06);
        lcd_write_ctrl(0x0F);
}

/* write one character to the LCD */
void lcd_putch(char c)
{
    if(c >= ' ' && c < 127) // ignore non-printable characters
    {
        lcd_write_data(c);
    }
    lcd_busy();
}

/* write a string of chars to the LCD */
void lcd_puts(const char * s)
{
    while(*s)
        lcd_putch(*s++);
}

/*
 * Go to the specified position
 */

void lcd_goto1(unsigned char pos)
{
    lcd_write_ctrl(0x80+pos);
    lcd_busy();
}

void lcd_goto2(unsigned char pos)
{
    lcd_write_ctrl(0xC0+pos);
    lcd_busy();
}
	
/* initialise the LCD - put into 4 bit mode */

void lcd_init(void)
{
    volatile int x,y;
    // power up delay
    lcd_init_pins();
    
    __delay_ms(10);
    __delay_ms(10);
    __delay_ms(10);
    __delay_ms(10);


    lcd_write_ctrl(0x03);
    __delay_ms(4);
    lcd_write_ctrl(0x03);
    __delay_ms(4);
    lcd_write_ctrl(0x03);

    // Use 8-bit mode with two lines
    lcd_write_ctrl(0x38);

    lcd_busy();
    lcd_write_ctrl(0x0C);	// display ON, Cursor OFF, No Blink
    lcd_busy();
    lcd_write_ctrl(0x01);	// characters printed left to right, no shift
    lcd_busy();

    // Clear the display
    lcd_write_ctrl(0x01);
    __delay_ms(2);
}
