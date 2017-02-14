#include "oled.h"
#include "oled_interface.h"


#define ON 1
#define OFF 0
#define ALTERNATE 1
#define SEQUENTIAL 0

void SetLowerColumnAddress(char x)
{
	unsigned char d[] = {x & 0x0F};
	oled_SendCommand(d,sizeof(d));
}

void SetHigherColumnAddress(char x)
{
	unsigned char d[] = {0x10 | (x & 0x0F)};
	oled_SendCommand(d,sizeof(d));
}

void SetupHorizontalScroll(char a,char b,char c,char e)
{
	unsigned char d[] = {0x26, a & 0x07, b & 0x07, c & 0x03, e & 0x07};
	oled_SendCommand(d,sizeof(d));
}

void ActivateHorizontalScroll()
{
	unsigned char d[] = {0x2F};
	oled_SendCommand(d,sizeof(d));
}

void DeactivateHorizontalScroll()
{
	unsigned char d[] = {0x2E};
	oled_SendCommand(d,sizeof(d));
}

void SetDisplayStartLine(char x)
{
	unsigned char d[] = {0x40 | (x & 0x3F)};
	oled_SendCommand(d,sizeof(d));
}

void SetContrastControlRegister(char a)
{
	unsigned char d[] = {0x81, a};
	oled_SendCommand(d,sizeof(d));
}

void SetBrightness(char a)
{
	unsigned char d[] = {0x82,a};
	oled_SendCommand(d,sizeof(d));
}

void SetLUT(char x,char a,char b,char c)
{
	unsigned char d[] = {0x91,x & 0x3F, a & 0x3F, b & 0x3f, c & 0x3f};
	oled_SendCommand(d,sizeof(d));
}

void SetBankColorA(char a,char b,char c,char e)
{
	unsigned char d[] = {0x92, a, b, c, e};
	oled_SendCommand(d,sizeof(d));
}

void SetBankColorB(char a,char b,char c,char e)
{
	unsigned char d[] = {0x93, a, b, c, e};
	oled_SendCommand(d,sizeof(d));
}

void SetSegmentReMap(char x)
{
	unsigned char d[] = {0xA0 | (x & 0x01) };
	oled_SendCommand(d,sizeof(d));
}

void EntireDisplayOnOff(char x)
{
	unsigned char d[] = {0xA4 | (x & 0x01) };
	oled_SendCommand(d,sizeof(d));
}

void SetInverse(char x)
{
	unsigned char d[] = {0xA6 | (x & 0x01) };
	oled_SendCommand(d,sizeof(d));
}

void SetMultiplexRatio(char a)
{
	unsigned char d[] = {0xA8, a & 0x3f };
	oled_SendCommand(d,sizeof(d));
}

void DCDCOnOff(char x)
{
	unsigned char d[] = {0xAD, 0x8A | (x & 0x01) };
	oled_SendCommand(d,sizeof(d));
}

void SetDisplayOnOff(char x)
{
	unsigned char d[] = {0xAE | (x & 0x01) };
	oled_SendCommand(d,sizeof(d));
}

void SetPageAddress(char x)
{
	unsigned char d[] = {0xB0 | (x & 0x0F) };
	oled_SendCommand(d,sizeof(d));
}

void SetCOMScan(char x)
{
	unsigned char d[] = {0xC0};
	if(x)
		d[0] = 0xC8 ;
	oled_SendCommand(d,sizeof(d));
}

void SetDisplayOffset(char a)
{
	unsigned char d[] = {0xD3, a & 0x3F };
	oled_SendCommand(d,sizeof(d));
}

void SetDisplayClockDivider(char a)
{
	unsigned char d[] = {0xD5, a };
	oled_SendCommand(d,sizeof(d));
}

void SetAreaColorPowerMode(char c,char p)
{
	unsigned char d[] = {0xD8, 00};
	if(c)
		d[1] |= 0x30;
	if(p)
		d[1] |= 0x05;
		
	oled_SendCommand(d,sizeof(d));
}

void SetPrechargePeriod(char a)
{
	unsigned char d[] = {0xD9,a};
	oled_SendCommand(d,sizeof(d));
}

void SetCOMHWConfig(char x)
{
	unsigned char d[] = {0xDA,0x02};
	if(x)
		d[1] |= 0x10;
	oled_SendCommand(d,sizeof(d));
}

void SetVCOMDeselectLevel(char a)
{
	unsigned char d[] = {0xDB, a & 0x7F};
	oled_SendCommand(d,sizeof(d));
}
