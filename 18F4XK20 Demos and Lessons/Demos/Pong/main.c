
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

unsigned char curPos[2]={64, 32};			// current ball position
signed char	vel[2]={2, -1};							//  velocity of ball {xvel, yvel}
unsigned char leftPos=32, rightPos=32;							// right and left bar position
signed char reflection, leftWins=0, rightWins=0;						// offset from center of paddle during reflection

/** D E C L A R A T I O N S **************************************************/
void InterruptHandler(void);
void InitializeSystem(void);
void drawScreen(void);
void getButtons(void);
void updatePosition(void);
void playerWins(unsigned char player);


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

	int delay;

	InitializeSystem();


	delay = 30000;
	while(delay--);


	oled_init();
	oled_clear();





	while(1){
		getButtons();			// check for button presses
		updatePosition();		// update position of ball and paddles
		drawScreen();			// redraw screen
		oled_refresh();			// refresh display
	}
	
}




void InitializeSystem(void)
{

	OSCCON = 0b01110000;
	OSCTUNEbits.PLLEN = 0; 					// turn on the PLL

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


	INTCONbits.PEIE = 1; 
	INTCONbits.GIE = 0; 

} // end InitializeSystem

void drawScreen(void){
	// clear old display
	oled_clear();
	

	// draw  first
	putpixel_vram(curPos[0], curPos[1]-1, 1);
	putpixel_vram(curPos[0], curPos[1], 1);
	putpixel_vram(curPos[0], curPos[1]+1, 1);

	putpixel_vram(curPos[0]+1, curPos[1]-1, 1);
	putpixel_vram(curPos[0]+1, curPos[1], 1);
	putpixel_vram(curPos[0]+1, curPos[1]+1, 1);

	putpixel_vram(curPos[0]-1, curPos[1]-1, 1);
	putpixel_vram(curPos[0]-1, curPos[1], 1);
	putpixel_vram(curPos[0]-1, curPos[1]+1, 1);

	putpixel_vram(curPos[0]+2, curPos[1], 1);
	putpixel_vram(curPos[0]-2, curPos[1], 1);

	putpixel_vram(curPos[0], curPos[1]+2, 1);
	putpixel_vram(curPos[0], curPos[1]-2, 1);


	// draw left bar
	
	putpixel_vram(0, leftPos-6,1);
	putpixel_vram(0, leftPos-5,1);
	putpixel_vram(0, leftPos-4,1);
	putpixel_vram(0, leftPos-3,1);
	putpixel_vram(0, leftPos-2,1);
	putpixel_vram(0, leftPos-1,1);
	putpixel_vram(0, leftPos,1);
	putpixel_vram(0, leftPos+1,1);
	putpixel_vram(0, leftPos+2,1);
	putpixel_vram(0, leftPos+3,1);
	putpixel_vram(0, leftPos+4,1);
	putpixel_vram(0, leftPos+5,1);
	putpixel_vram(0, leftPos+6,1);
	
	putpixel_vram(1, leftPos-6,1);
	putpixel_vram(1, leftPos-5,1);
	putpixel_vram(1, leftPos-4,1);
	putpixel_vram(1, leftPos-3,1);
	putpixel_vram(1, leftPos-2,1);
	putpixel_vram(1, leftPos-1,1);
	putpixel_vram(1, leftPos,1);
	putpixel_vram(1, leftPos+1,1);
	putpixel_vram(1, leftPos+2,1);
	putpixel_vram(1, leftPos+3,1);
	putpixel_vram(1, leftPos+4,1);
	putpixel_vram(1, leftPos+5,1);
	putpixel_vram(1, leftPos+6,1);

	putpixel_vram(2, leftPos-6,1);
	putpixel_vram(2, leftPos-5,1);
	putpixel_vram(2, leftPos-4,1);
	putpixel_vram(2, leftPos-3,1);
	putpixel_vram(2, leftPos-2,1);
	putpixel_vram(2, leftPos-1,1);
	putpixel_vram(2, leftPos,1);
	putpixel_vram(2, leftPos+1,1);
	putpixel_vram(2, leftPos+2,1);
	putpixel_vram(2, leftPos+3,1);
	putpixel_vram(2, leftPos+4,1);
	putpixel_vram(2, leftPos+5,1);
	putpixel_vram(2, leftPos+6,1);

	putpixel_vram(3, leftPos-6,1);
	putpixel_vram(3, leftPos-5,1);
	putpixel_vram(3, leftPos-4,1);
	putpixel_vram(3, leftPos-3,1);
	putpixel_vram(3, leftPos-2,1);
	putpixel_vram(3, leftPos-1,1);
	putpixel_vram(3, leftPos,1);
	putpixel_vram(3, leftPos+1,1);
	putpixel_vram(3, leftPos+2,1);
	putpixel_vram(3, leftPos+3,1);
	putpixel_vram(3, leftPos+4,1);
	putpixel_vram(3, leftPos+5,1);
	putpixel_vram(3, leftPos+6,1);

	// draw right bar

	putpixel_vram(127, rightPos-6,1);
	putpixel_vram(127, rightPos-5,1);
	putpixel_vram(127, rightPos-4,1);
	putpixel_vram(127, rightPos-3,1);
	putpixel_vram(127, rightPos-2,1);
	putpixel_vram(127, rightPos-1,1);
	putpixel_vram(127, rightPos,1);
	putpixel_vram(127, rightPos+1,1);
	putpixel_vram(127, rightPos+2,1);
	putpixel_vram(127, rightPos+3,1);
	putpixel_vram(127, rightPos+4,1);
	putpixel_vram(127, rightPos+5,1);
	putpixel_vram(127, rightPos+6,1);
	
	putpixel_vram(126, rightPos-6,1);
	putpixel_vram(126, rightPos-5,1);
	putpixel_vram(126, rightPos-4,1);
	putpixel_vram(126, rightPos-3,1);
	putpixel_vram(126, rightPos-2,1);
	putpixel_vram(126, rightPos-1,1);
	putpixel_vram(126, rightPos,1);
	putpixel_vram(126, rightPos+1,1);
	putpixel_vram(126, rightPos+2,1);
	putpixel_vram(126, rightPos+3,1);
	putpixel_vram(126, rightPos+4,1);
	putpixel_vram(126, rightPos+5,1);
	putpixel_vram(126, rightPos+6,1);

	putpixel_vram(125, rightPos-6,1);
	putpixel_vram(125, rightPos-5,1);
	putpixel_vram(125, rightPos-4,1);
	putpixel_vram(125, rightPos-3,1);
	putpixel_vram(125, rightPos-2,1);
	putpixel_vram(125, rightPos-1,1);
	putpixel_vram(125, rightPos,1);
	putpixel_vram(125, rightPos+1,1);
	putpixel_vram(125, rightPos+2,1);
	putpixel_vram(125, rightPos+3,1);
	putpixel_vram(125, rightPos+4,1);
	putpixel_vram(125, rightPos+5,1);
	putpixel_vram(125, rightPos+6,1);

	putpixel_vram(124, rightPos-6,1);
	putpixel_vram(124, rightPos-5,1);
	putpixel_vram(124, rightPos-4,1);
	putpixel_vram(124, rightPos-3,1);
	putpixel_vram(124, rightPos-2,1);
	putpixel_vram(124, rightPos-1,1);
	putpixel_vram(124, rightPos,1);
	putpixel_vram(124, rightPos+1,1);
	putpixel_vram(124, rightPos+2,1);
	putpixel_vram(124, rightPos+3,1);
	putpixel_vram(124, rightPos+4,1);
	putpixel_vram(124, rightPos+5,1);
	putpixel_vram(124, rightPos+6,1);


}

void getButtons(void){
	if(PORTBbits.RB0 == 0){//if SW1 pressed
		leftPos--;
		leftPos--;
	}
	if(PORTBbits.RB1 == 0){//if SW2 pressed'
		leftPos++;
		leftPos++;
	}
	if(PORTBbits.RB2 == 0){//if SW3 pressed'
		rightPos--;
		rightPos--;
	}

	if(PORTBbits.RB3 == 0){//if SW4 pressed'
		rightPos++;
		rightPos++;
	}

	if (leftPos<7)
		leftPos = 7;
	if (leftPos>56)
		leftPos = 56;

	if (rightPos<7)
		rightPos = 7;
	if (rightPos>56)
		rightPos = 56;

}

void updatePosition(void){

	if(curPos[0] >= 122){ //if ball collides with paddle
		reflection = curPos[1] - rightPos;
		switch(reflection){
			case -6:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;
			case -5:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;
			case -4:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case -3:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case -2:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case -1:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case 0:	
				if (vel[1] <0){ //if ball is moving straight, dont change y
					vel[1] = vel[1];
				}
				else vel[1] = vel[1];
				vel[0] = -vel[0];
				break;
			case 1:	
				if (vel[1] >0){ //if ball is moving down, let it continue, add a little y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case 2:	
				if (vel[1] >0){ //if ball is moving down, let it continue, add a little y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case 3:	
				if (vel[1] >0){ //if ball is moving down, let it continue, add a little y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case 4:	
				if (vel[1] >0){ //if ball is moving down, let it continue, add a little y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case 5:	
				if (vel[1] >0){ //if ball is moving down, let it continue, add a little y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;
			case 6:	
				if (vel[1] >0){ //if ball is moving down, let it continue, add a little y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;

			default:// doesn't hit on the paddle means player 1 wins
				playerWins(1);
				break;
			}

	}

	if(curPos[0] <= 7){ //if ball collides with paddle

		reflection = curPos[1] - leftPos;
		switch(reflection){
			case -6:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;
			case -5:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;
			case -4:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case -3:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case -2:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case -1:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case 0:	
				if (vel[1] <0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1];
				}
				else vel[1] = vel[1];
				vel[0] = -vel[0];
				break;
			case 1:	
				if (vel[1] >0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case 2:	
				if (vel[1] >0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 1;
				}
				else vel[1] = vel[1] - 1;
				vel[0] = -vel[0];
				break;
			case 3:	
				if (vel[1] >0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case 4:	
				if (vel[1] >0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 2;
				}
				else vel[1] = vel[1] - 2;
				vel[0] = -vel[0];
				break;
			case 5:	
				if (vel[1] >0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;
			case 6:	
				if (vel[1] >0){ //if ball is moving upwards, let it continue, add lot of y 
					vel[1] = vel[1] + 3;
				}
				else vel[1] = vel[1] - 3;
				vel[0] = -vel[0];
				break;

			default:// doesn't hit on the paddle means player 2 wins
				playerWins(2);
				break;
			}


	}

	// next check to see if we hit the top or bottom walls
	if (curPos[1]<=3 || curPos[1] >=61){
		vel[1] = -vel[1];
		if (curPos[1] < 3)
			curPos[1] = 3;		// make sure we dont get stuck changing signs
		if (curPos[1] > 61)
			curPos[1] = 61;		// make sure we dont get stuck changing signs
	}

	if(vel[1]>4)
		vel[1] = 4;
	if(vel[1]<-4)
		vel[1] = -4;

	// determine new position
	curPos[0] = curPos[0] + vel[0];
	curPos[1] = curPos[1] + vel[1];
	

}

void playerWins(unsigned char player){
	int delay,delay1;
	if(player == 1){
		leftWins++;
		vel[0] = -2;						// initialize direction for p1 win
		vel[1] = 1;
	}
	if(player == 2){
		rightWins++;
		vel[0] = 2;							// initialize direction for p2 win
		vel[1]= - 1;
	}


	oled_WriteChar1x(leftWins + 0x30, 7, 8);
	oled_WriteChar1x(rightWins + 0x30, 7, 110);		// display scores

	oled_refresh();	

	if (leftWins == 5 || rightWins==5){		// first to 5 wins
		SetInverse(1);
		leftWins = 0;
		rightWins = 0;
	}

	delay = 30000;
	while(delay--){
		delay1 = 10;
		while(delay1--);
	}
	
	while (PORTBbits.RB0 && PORTBbits.RB1 && PORTBbits.RB2 && PORTBbits.RB3);//wait for a button press
	
	curPos[0] = 64;							// reset variables
	curPos[1] = 32;

	leftPos = 32;
	rightPos = 32;

	SetInverse(0);
	

}