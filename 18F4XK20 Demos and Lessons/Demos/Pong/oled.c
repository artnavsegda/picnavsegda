#include <p18f46k20.h>
#include "oled.h"
#include "oled_cmd.h"
#include "oled_interface.h"
#include "font.h"




// VRAM needed for SPI interface because there is no way to read
// the data from the display.
// If a parallel interface is used, the vram can be eliminated
// and the plot functions changed to use the read/modify/write to
// the display ram.

#pragma udata OLEDDATA_0
unsigned char vram_0[128];

#pragma udata OLEDDATA_1
unsigned char vram_1[128];

#pragma udata OLEDDATA_2
unsigned char vram_2[128];

#pragma udata OLEDDATA_3
unsigned char vram_3[128];

#pragma udata OLEDDATA_4
unsigned char vram_4[128];

#pragma udata OLEDDATA_5
unsigned char vram_5[128];

#pragma udata OLEDDATA_6
unsigned char vram_6[128];

#pragma udata OLEDDATA_7
unsigned char vram_7[128];

unsigned char *vram[8] = {vram_0, vram_1, vram_2, vram_3,
	                      vram_4, vram_5, vram_6, vram_7};

unsigned char c_row_1x; // current row counter for 8pixel high font.  values 0-7 are allowed
unsigned char c_col_1x; // current column counter for 5 pixel wide font. Values 0-15 are allowed

unsigned char c_row_2x; // current row counter for 16 pixel high font.  Values 0-3 are allowed
unsigned char c_col_2x; // current column counter for 5 pixel wide font.  Values 0-15 are allowed

unsigned char Convert1xto2x(unsigned char uplow, unsigned char byte);
char is_printable(char c);

void oled_init(void)
{	
	int temp;
	oled_cs = 1;
	oled_res = 0;
	oled_reset();
	SetDisplayOnOff(OFF);			// send display off command
	oled_clear();					// clear oled ram
	oled_refresh();					// send data to clear screen

	DCDCOnOff(ON);					// sendCommand(0xAD);
									// sendCommand(0x8B);

	SetSegmentReMap(1);				// sendCommand(0xA1);

	SetCOMHWConfig(ALTERNATE);		// sendCommand(0xDA);
									// sendCommand(0x12);
	
	SetCOMScan(1);					// sendCommand(0xC8);

	SetMultiplexRatio(0x3F);		// sendCommand(0xA8);
									// sendCommand(0x3F);

	SetVCOMDeselectLevel(0x23);		// sendCommand(0xDB);
									// sendCommand(0x23);

	SetPrechargePeriod(0x22);		// sendCommand(0xD9);
									// sendCommand(0x22);


	SetDisplayClockDivider(0xA0);	// sendCommand(0xD5);
									// sendCommand(0xA0);

	SetDisplayOffset(0);			// sendCommand(0xD3);
									// sendCommand(0x00);

	SetDisplayStartLine(0);			// sendCommand(0x40)


	SetContrastControlRegister(0x5C);// sendCommand(0x81)
									// sendCommand(0x60);


	SetDisplayOnOff(ON);
	SetInverse(OFF);				// sendCommand(0xA6);

	SetLowerColumnAddress(2);		// sendCommand(0x02)
	SetHigherColumnAddress(0);		// sendCommand(0x10)
	EntireDisplayOnOff(OFF);			// sendCommand(0xA4);
	SetBrightness(0x80);


}

void oled_clear()
{
	unsigned char x,y;
	unsigned char *p;
	for(y = 0 ; y < 8 ; y ++)
	{
		p = vram[y];
		for(x = 0; x < 128; x ++)
		{
			p[x] = 0;
		}
	}
	c_row_1x = 0;
	c_col_1x = 0;
	c_row_2x = 0;
	c_col_2x = 0;
}

void oled_draw_row(char r, unsigned char *d)
// d is a pointer to 128 bytes
// r is the row number
{
	char c;
	SetPageAddress(r);
	SetLowerColumnAddress(2);
	SetHigherColumnAddress(0);
	oled_SendData(d,128);
}

void oled_scroll_left()
{
}

void oled_refresh()
// copy the data from the VRAM buffer in the micro to the display 1 row at a time
{
	unsigned char z;
		
	for( z = 0; z < 8; z ++)
	{
		oled_draw_row(z,vram[z]);
	}
}

void oled_scroll_right()
{
}

void oled_SetBrightness(char b)
{
	SetBrightness(b);
}

void oled_off()
{
	SetDisplayOnOff(OFF);
}

void oled_on()
{
	SetDisplayOnOff(ON);
}

void oled_reset()
{
	int temp;
	temp = 35530;
	while(temp--);
	
	oled_res = 0;
	temp = 35530;
	while(temp--);
	oled_res = 1;
	
}

void putpixel_vram(unsigned char x,unsigned char y,unsigned char color)
{
	unsigned char *p;
	char m = 0x01 << (y%8);

	p = &vram[y/8][x];

	if(color)
		*p |=  m;
	else
		*p &= ~m;
}

char getpixel_vram(unsigned char x, unsigned char y)
{
	
	return (vram[y/8][x]) & (0x01 << (y%8));
}

char is_printable(char c)
{
	return( (0x20 <= c) && (c <= 0x7E));
}

void oled_puts_1x(char *s)
{
	while(*s)
		oled_putc_1x(*s++);
}

void oled_puts_2x(char *s)
{
	while(*s)
		oled_putc_2x(*s++);
}

void oled_putc_1x(char c)
{
		if(is_printable(c)) // all printable characters
		{
			if(c_col_1x < 128)
			{
				oled_WriteChar1x(c,c_row_1x,c_col_1x);
				c_col_1x += 6;
			}
		}
		else if( c == '\n' || c == '\r') // carraige return or line feed
		{
			for( ; c_col_1x < 128; c_col_1x++)
				vram[c_row_1x][c_col_1x] = 0x00; // destroy the line
			c_row_1x +=1;
			c_col_1x = 0;
		}
		else if(c == '\t') // tab
		{
			oled_putc_1x(' ');
			oled_putc_1x(' ');
			oled_putc_1x(' ');
		}
		if( c_row_1x >= 8)
			c_row_1x = 0;
}

void oled_putc_2x(char c)
{
		if(is_printable(c)) // all printable characters
		{
			if(c_col_1x < 128 && c_row_1x < 7)
			{
				oled_WriteChar2x(c,c_row_1x,c_col_1x);
				c_col_1x += 6;
			}
		}
		else if( c == '\n' || c == '\r') // carraige return or line feed
		{
			for( ; c_col_1x < 128; c_col_1x++)
				vram[c_row_1x][c_col_1x] = 0x00; // destroy the line
			c_row_1x +=2;
			c_col_1x = 0;
		}
		else if(c == '\t') // tab
		{
			oled_putc_1x(' ');
			oled_putc_1x(' ');
			oled_putc_1x(' ');
		}
		if( c_row_1x == 8)
			c_row_1x = 0;
}

void oled_WriteChar1x(char letter, unsigned char page, unsigned char column)
{
	unsigned char *p,x;
	letter -= ' ';					// Adjust character to table that starts at 0x20

	p = &vram[page][column];
	
	for( x = 0; x + column < 128 && x < 5 ; x ++)
	{
		*p ++ = g_pucFont[letter][x];
	}
	*p= 0;
}

void oled_WriteChar2x(char letter, unsigned char page, unsigned char column)
{
	unsigned char *p1,*p2,x;
	letter -= ' ';					// Adjust character to table that starts at 0x20

	p1 = &vram[page][column];
	p2 = &vram[page+1][column];
	
	for( x = 0; x + column < 128 && x < 5 ; x ++)
	{
		*p1 ++ = Convert1xto2x(0,g_pucFont[letter][x]);
		*p2 ++ = Convert1xto2x(1,g_pucFont[letter][x]);
	}
	*p1 = 0;
	*p2 = 0;
}

unsigned char Convert1xto2x(unsigned char uplow, unsigned char byte)
{
	unsigned char result;

	result = 0;
	if(uplow)
	{
		if(byte&0x10)
		{
			result |= 0x01;
			result |= 0x02;
		}
		if(byte&0x20)
		{
			result |= 0x04;
			result |= 0x08;
		}
		if(byte&0x40)
		{
			result |= 0x10;
			result |= 0x20;
		}
		if(byte&0x80)
		{
			result |= 0x40;
			result |= 0x80;
		}
	}
	else
	{
		if(byte&0x01)
		{
			result |= 0x01;
			result |= 0x02;
		}
		if(byte&0x02)
		{
			result |= 0x04;
			result |= 0x08;
		}
		if(byte&0x04)
		{
			result |= 0x10;
			result |= 0x20;
		}
		if(byte&0x08)
		{
			result |= 0x40;
			result |= 0x80;
		}
	}
	return result;
}

void oled_ScreenSaver(unsigned char enable)
{
	if(enable == 1)
	{
		SetupHorizontalScroll(0x01,0x00,0x00,0x07);
		ActivateHorizontalScroll();
	}
	else
		DeactivateHorizontalScroll();
	return;
}

void oled_plotbar(unsigned char r, unsigned char c, unsigned char v)
{
	vram[r][c] = v;
}


