
#include <p18f46K20.h>
#include "oled_interface.h"
#include "oled.h" 

#pragma config IESO=OFF, FCMEN=OFF, FOSC=INTIO67, PWRT=OFF, BOREN=OFF, WDTEN=OFF
#pragma config WDTPS=32768, MCLRE=ON, LPT1OSC=OFF, PBADEN=OFF, CCP2MX=PORTBE
#pragma config STVREN=OFF, LVP=OFF, XINST=OFF, DEBUG=OFF, CP0=OFF, CP1=OFF
#pragma config CP2=OFF, CP3=OFF, CPB=OFF, CPD=OFF, WRT0=OFF, WRT1=OFF
#pragma config WRT2=OFF, WRT3=OFF, WRTB=OFF, WRTC=OFF, WRTD=OFF, EBTR0=OFF
#pragma config EBTR1=OFF, EBTR2=OFF, EBTR3=OFF, EBTRB=OFF

#define LED0 LATDbits.LATD0
#define LED1 LATDbits.LATD1
#define LED2 LATDbits.LATD2
#define LED3 LATDbits.LATD3
#define LED4 LATDbits.LATD4
#define LED5 LATDbits.LATD5
#define LED6 LATDbits.LATD6
#define LED7 LATDbits.LATD7

#define SW1	LATBbits.LATB0
#define	SW2 LATBbits.LATB1
#define	SW3 LATBbits.LATB2
#define	SW4 LATBbits.LATB3




unsigned char hello[7];
unsigned char world[7];
unsigned int delay;


/** D E C L A R A T I O N S **************************************************/
void InterruptHandler(void);
void InitializeSystem(void);



#pragma code high_vector=0x08

void high_interrupt (void)
{
	_asm GOTO InterruptHandler _endasm
}

#pragma code low_vector=0x18
void low_interrupt (void)
{
	_asm GOTO InterruptHandler _endasm
}

#pragma code


#pragma interruptlow InterruptHandler
#pragma interrupt	InterruptHandler

void InterruptHandler(void) { 
	

	
} // end InterruptHandler


void main(void){

	char temp;

	InitializeSystem();


	delay = 30000;
	while(delay--);


	oled_init();
	oled_clear();
	oled_refresh();

	oled_putc_2x('\n');
	oled_putc_2x('\t');
	oled_putc_2x('\t');


	oled_putc_2x('H');
	oled_putc_2x('e');
	oled_putc_2x('l');
	oled_putc_2x('l');
	oled_putc_2x('o');

	oled_putc_2x('\n');


	oled_putc_2x('\t');
	oled_putc_2x('\t');
	oled_putc_2x('\t');

	oled_putc_2x('W');
	oled_putc_2x('o');
	oled_putc_2x('r');
	oled_putc_2x('l');
	oled_putc_2x('d');
	
	oled_refresh();

	while(1){							// main loop
	}

}




void InitializeSystem(void)
{

	OSCCON = 0b01110000;
	OSCTUNEbits.PLLEN = 0; 					// turn off the PLL

	// Setup I/O Ports.
	
	TRISA = 0;								// TRISA outputs
	LATA = 0b11110000;						// drive PORTA pins low

	oled_res = 1;							// do not reset LCD yet
	oled_cs = 1;							// do not select the LCD

	TRISB = 0b11001111;


	LATC = 0b00101000;
	TRISC = 0b00000000;

	TRISD = 0;								// TRISD is LED output
	LATD = 0;								// turn off LEDS

	TRISE = 0b00000111;

	//configure buttons
	WPUB = 0b00001111;
	INTCON2bits.RBPU = 0; 					// turn on weak pull ups for RB0-RB3

	INTCONbits.INT0IF = 0;					// clear RB0 INT
	INTCONbits.INT0IE = 1;					// enable RB0 INT
	INTCON2bits.INTEDG0 = 0;				// interrupt on falling edge 

	INTCON3bits.INT1IF = 0;					// clear RB1 INT
	INTCON3bits.INT1IE = 1;					// enable RB1 INT	
	INTCON2bits.INTEDG1 = 0;				// interrupt on falling edge

	INTCON3bits.INT2IF = 0;					// clear RB2 INT
	INTCON3bits.INT2IE = 1;					// enable RB2 INT
	INTCON2bits.INTEDG2 = 0;				// interrupt on falling edge

	
	// Setup analog functionality
	ANSEL = 0x00;							// all pins digital
	ANSELH = 0x00;
	
	ANSELbits.ANS6=1;						// RE2 is a temperature input


	ADCON1=0;								// Reference Vdd and Vss
	ADCON2=0b10001100;						// right, AN6, 2 Tad, Fosc/64
	ADCON0=0b00011101;						// turn on ADC


	// Setup TMR1
	// Configure Timer 1
	T1CON 	= 0b00001111;

		
	// Setup TMR2
	T2CON = 0b00000100;						// 1:1 prescaler
	PR2 = 0xFF;
	T0CON = 0x80;

	// Configure MSSP for SPI master mode
	SSPCON1 = 0b00110010;					// clock idle high, Clk /64

	SSPSTAT = 0b00000000;

	PIR1bits.TMR1IF = 0; 
	PIE1bits.TMR1IE = 1; 

	INTCONbits.PEIE = 1; 
	INTCONbits.GIE = 0; 

} // end InitializeSystem

