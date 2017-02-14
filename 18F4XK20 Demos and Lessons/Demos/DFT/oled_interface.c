// OLED Interface
#include <p18f46k20.h> // add CPU specific include

#include "oled_interface.h"
#define NOP 0xE3

int temp; 

void oled_SendCommand(unsigned char *d,unsigned char c)
{
	unsigned char x;
	CHIP_SELECT();
	COMMAND_SELECT();
	for(x = 0; x < c; x++)
	{
		WRITE(*d++);

	}
	WRITE(NOP);
	Nop();
	Nop();
	CHIP_UNSELECT();

}

void oled_SendCommand_2(unsigned char d,unsigned char c)
{
	unsigned char x;
	CHIP_SELECT();
	COMMAND_SELECT();
	for(x = 0; x < c; x++)
	{
		WRITE(d);
	}
	WRITE(NOP);
	Nop();
	Nop();
	CHIP_UNSELECT();
}

void oled_SendData(unsigned char *d,unsigned char c)
{
	unsigned char x;
	CHIP_SELECT();
	DATA_SELECT();
	for(x = 0; x < c; x++)
	{
		WRITE(*d++);
	}
	COMMAND_SELECT();
	WRITE(NOP);
	Nop();
	Nop();
	CHIP_UNSELECT();
}
void oled_SendData_2(unsigned char d,unsigned char c)
{
	unsigned char x;
	CHIP_SELECT();
	DATA_SELECT();
	for(x = 0; x < c; x++)
	{
		WRITE(d);
	}
	COMMAND_SELECT();
	WRITE(NOP);
	Nop();
	Nop();
	CHIP_UNSELECT();
}

void write_spi(char c)
{
	unsigned char temp;
	
	temp = SSPBUF;
	PIR1bits.SSPIF = 0;

	SSPBUF = c;
	while(!PIR1bits.SSPIF);

	temp = SSPBUF;
	PIR1bits.SSPIF = 0;
}

void write_i2c(char c)
{

}

void write_parallel(char c)
{
}

char read_parallel()
{
	return 0;
}
