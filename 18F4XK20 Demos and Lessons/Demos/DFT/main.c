/** C O N F I G U R A T I O N   B I T S **************************************/

#pragma config IESO=OFF, FCMEN=OFF, FOSC=INTIO67, PWRT=OFF, BOREN=OFF, WDTEN=OFF
#pragma config WDTPS=32768, MCLRE=ON, LPT1OSC=OFF, PBADEN=OFF, CCP2MX=PORTBE
#pragma config STVREN=OFF, LVP=OFF, XINST=OFF, DEBUG=OFF, CP0=OFF, CP1=OFF
#pragma config CP2=OFF, CP3=OFF, CPB=OFF, CPD=OFF, WRT0=OFF, WRT1=OFF
#pragma config WRT2=OFF, WRT3=OFF, WRTB=OFF, WRTC=OFF, WRTD=OFF, EBTR0=OFF
#pragma config EBTR1=OFF, EBTR2=OFF, EBTR3=OFF, EBTRB=OFF

/** I N C L U D E S **********************************************************/

#include <p18f46k20.h>
#include "oled_interface.h"
#include "oled.h"
#include "oled_cmd.h"
#include "stdio.h"



/** V A R I A B L E S ********************************************************/


#pragma udata 
unsigned char imageNumber;

unsigned int vin,vout;
unsigned int iin,iout;
unsigned int pin,pout;
unsigned int sum;
unsigned long eff;
	unsigned char test[] = {0xF0};

#pragma udata analyzer_vars=0x100 	// Place analyzer C variables in Bank 1, starting at 0x100
	
unsigned char buffer_index, start_dft,  result_index;
unsigned long magnitude[16], max_result, magnitude_divisor;	// (16) 32-bit I Squared + Q Squared (frequency magnitude result)

#pragma udata dft_vars=0x300	// Place DFT assembly variables in bank 3, location 0x300

unsigned char 		FTABLE[32];		// (32 entry) 8-bit sine table used for convolution	
unsigned short long IBIN[16];		// (16) 24-bit Imaginary frequency sum bins
unsigned short long	QBIN[16];		// (16) 24-bit Real frequency sum bins
unsigned char		INBUFFER[32];	// (32) 8-bit samples, stored here from A/D
unsigned char 		BINCOUNT; 		// Bin counter variable
unsigned char		MSB_TEMP;		// MSB 24-bit product for 2's complement addition
unsigned char 			outputLevel;

extern void dft (void);						// DFT assembly routine call entry definition
extern void init_sine_table (void);			// Sine table assembly intitialization call entry definition

/** P R I V A T E  P R O T O T Y P E S ***************************************/

static void InitializeSystem(void);
static void InterruptHandler(void);
void InitializeOled(void);
void drawmagnitudeplot(void);
void put_number(char *s, unsigned int v);

void initOutput(void);
void setCCP(unsigned char level);
void soundOutput(void);


/** V E C T O R  R E M A P P I N G *******************************************/

/** D E C L A R A T I O N S **************************************************/

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

/******************************************************************************
 * Function:        static void InitializeSystem(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is responsible for configuring the hardware
 *					settings.                 
 *
 * Note:            None
 *****************************************************************************/
static void InitializeSystem(void)
{
	// Setup oscillator
	OSCCON = 0b01110000;
	OSCTUNEbits.PLLEN = 1; 					// turn on the PLL
	
	// Setup I/O Ports.
	
	TRISA = 0;								// TRISA outputs
	LATA = 0b11110000;						// drive PORTA pins low

	oled_res = 1;							// do not reset LCD yet
	oled_cs = 1;							// do not select the LCD

	TRISB = 0b11001111;
	WPUB = 0b00001111;
	INTCON2bits.RBPU = 0; 					// turn on weak pull ups for RB0-RB3

	LATC = 0b00101000;
	TRISC = 0b00000100;

	TRISD = 0;								// TRISD is LED output
	LATD = 0;								// turn off LEDS

	TRISE = 0b00000111;

	// Setup analog functionality
	ANSEL = 0x00;							// set pins digital
	ANSELH = 0x00;

	ANSELbits.ANS7=1;						// ANS7 is microphone input
	

	ADCON1=0;								// Reference Vdd and Vss
	ADCON2=0b00001110;						// LEFT, AN7, 2 Tad, Fosc/64
	ADCON0=0b00011101;						// turn on ADC

	// Setup TMR2
	T2CON = 0b00000100;						// 1:256 scaling
	PR2 = 0xFF;
	T0CON = 0x80;
	// Configure MSSP for SPI master mode
	SSPCON1 = 0b00110010;					// clock idle high, Clk /64
	SSPSTAT = 0b00000000;
	

	// Setup TMR1
	TMR1H = 0xF3;
	TMR1L = 0x7F;						// Sample at 5 kHz, preload 0xF37F, 16Mhz clock
	TMR1H=0xf9;
	TMR1L=0xbf;
	T1CON = 0b00000001;					// 16 bit RW, 1:1, timer 1 on

	// Setup Interrupts
	PIE1bits.TMR1IE = 1;				// Enable TMR1 Interrupts	
	INTCONbits.PEIE = 1; 				// Enable Peripheral Interurpts
	INTCONbits.GIE = 1;					// enable global interrupts


} // end InitializeSystem


/********************************************************************
* Function:    		InterruptHandler    
* 
* PreCondition: 	None
*
* Input:        	None
*
* Output:     	 	None
*
* Side Effects: 	None
*
* Overview:			
*
* Note:        		None
*******************************************************************/
#pragma interruptlow InterruptHandler
#pragma interrupt	InterruptHandler

void InterruptHandler(void) { 
	
	if (PIR1bits.TMR1IF && PIE1bits.TMR1IE){ //5 Khz sampling


		PIR1bits.TMR1IF = 0;			// clear interrupt flag
		TMR1H = 0xF3;
		TMR1L = TMR1L + 0x7F;			// 5 khz interrupt

		ADCON0bits.GO_DONE = 1;		// Start A/D conversion
		
		while(ADCON0bits.GO_DONE); 	// Spin lock and wait for A/D conversion to complete
		ADCON0bits.GO_DONE = 1;		// Start A/D conversion
		while(ADCON0bits.GO_DONE); 	// Spin lock and wait for A/D conversion to complete
		setCCP(ADRESH);
		INBUFFER[buffer_index] = ADRESH;	// Store A/D result into next location in INBUFFER location
		if (INBUFFER[buffer_index] < 1){
			INBUFFER[buffer_index] = 2;
		}// ensure no zeros
		buffer_index++;				// Point to next buffer location
		if(buffer_index == 32){		// Once you hit the end of the buffer:
			buffer_index = 0;		// 	- Reset the buffer index to zero
			start_dft = 1;			//	- Set a flag bit to run the DFT on the new buffer data	
			sum = 0;
			for (buffer_index = 0; buffer_index < 32; buffer_index++){
				sum = sum + INBUFFER[buffer_index];
			}
			if (sum < 3550){
				start_dft = 0;
			}
			buffer_index = 0;	
			
		} //endif buffer_index == 32

	} //endif PIR1bits.TMR1IF && PIE1bits.TMR1IE
	
	
	if (INTCONbits.INT0IF)
	{
		INTCONbits.INT0IF = 0;

	} // endif INTCONbits.INT0IF
	
	if (INTCON3bits.INT1IF)
	{
		INTCON3bits.INT1IF = 0;
	} // endif INTCON3bits.INT1IF
	
} // end InterruptHandler


/******************************************************************************
 * Function:        void main(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Main program entry point.
 *
 * Note:            None
 *****************************************************************************/
void main(void)
{	

	InitializeSystem();
	initOutput();
	TRISD = 0;

	
	init_sine_table();
	oled_init();

	SetLowerColumnAddress(0);
	SetHigherColumnAddress(0);
	SetPageAddress(0);
	oled_SendData_2(0, 0xFF);
	SetLowerColumnAddress(0);
	SetHigherColumnAddress(0);
	SetPageAddress(1);
	oled_SendData_2(0, 0xFF);
	SetLowerColumnAddress(0);
	SetHigherColumnAddress(0);
	SetPageAddress(2);
	oled_SendData_2(0, 0xFF);
	SetLowerColumnAddress(0);
	SetHigherColumnAddress(0);
	SetPageAddress(3);
	oled_SendData_2(0, 0xFF);



	while(1){
	if(start_dft){								// Check if INBUFFER is full, loop back if INBUFFER is not full
		INTCONbits.GIE = 0;					// Turn off interrupts and stop sampling when displaying
		dft();									// Execute DFT algorithm
		result_index = 0;						// Reset index pointer to zero
		max_result = 0;							// Reset maximum result to zero
		while(result_index != 16){				// Loop until index reaches 16
			magnitude[result_index] = (unsigned long)(IBIN[result_index]>>8) * (unsigned long)(IBIN[result_index]>>8) +  (unsigned long)(QBIN[result_index]>>8) * (unsigned long)(QBIN[result_index]>>8);
			if(magnitude[result_index] > max_result)
					max_result = magnitude[result_index]; // Update max_result if latest bin result is greater than last max_result
			result_index++;						// Increment index pointer
		}
//		if(max_result > 64){
			result_index = 0;					// Reset index pointer to zero
			magnitude_divisor = 512; // Set divisor to be 1/32th of max_result
			while(result_index != 16){			// Loop until index reaches 16
				magnitude[result_index] /= magnitude_divisor;	// Scale result by dividing by magnitude_divisor
				result_index++;					// Increment index pointer
				}
//			}				
		result_index = 0;						// Reset index pointer to zero

		drawmagnitudeplot();					//  draws magnitude plot of FFT
								
	
		INTCONbits.GIE = 1;		// Turn interrupts back on
		start_dft = 0;				// Clear start_dft flag bit and return to top of loop
		}			
	}
} // end main


void drawmagnitudeplot(void){
	unsigned char countx,rowx;

	for (rowx = 0; rowx < 7; rowx++){
		SetLowerColumnAddress(0);
		SetHigherColumnAddress(0);
		SetPageAddress(7-rowx);
		oled_SendCommand_2(0xA1,4);
	
		
		for (countx = 0; countx < 16; countx++){
			if (magnitude[countx] >= 8){
				oled_SendData_2(0xFF,8);
				magnitude[countx] = magnitude[countx] - 8;
			}//end if magnitude[count]>=8
			else{
					switch (magnitude[countx]){
						case 7:
							oled_SendData_2(254, 8);
							magnitude[countx] = 0;
							break;
						case 6:
							oled_SendData_2(252, 8);
							magnitude[countx] = 0;
							break;
						case 5:
							oled_SendData_2(248, 8);
							magnitude[countx] = 0;
							break;
						case 4:
							oled_SendData_2(240, 8);
							magnitude[countx] = 0;
							break;
						case 3:
							oled_SendData_2(224, 8);
							magnitude[countx] = 0;
							break;
						case 2:
							oled_SendData_2(192, 8);
							magnitude[countx] = 0;
							break;
						case 1:
							oled_SendData_2(128, 8);
							magnitude[countx] = 0;
							break;
						default:
							oled_SendData_2(0, 8);
							magnitude[countx] = 0;
							break;
					} //end switch
				
			} // end else
		} // end for count
	}//end for row
}



void initOutput(void){
	
	TRISCbits.TRISC2 = 1;				// disable PWM pin output drivers
	PSTRCON = 0b00000001;				// Steer PWM to P1A (RC2)
	PR2 = 0xff;							// set PWM period
	CCP1CON = 0b00001100;				// Single Mode
										// CCP1M<3:2> = 11, P1M<1:0> = 00
	outputLevel = 0;					// Intialize output level to 0
	setCCP(outputLevel);				// set CCPR1L and DC1B bits
	
	PIR1bits.TMR2IF = 0;				// clear timer2 interrupt flag
	T2CON = 0b00000100;					// No timer 2 prescale, turn on Timer 2
	
	while(!PIR1bits.TMR2IF );			// wait until Timer 2 overflows
	TRISCbits.TRISC2 = 0;				// enable CCP1 pin output driver
	
	
	

}//end initOutput

void setCCP(unsigned char level){

	CCPR1L = level;		
	CCP1CONbits.DC1B1 = 0;
	CCP1CONbits.DC1B0 = 0;			

}//end setCCP


void soundOutput(void){

	// set up Timer 1 interrupts
		PIR1bits.TMR1IF = 0;
		TMR1H = 0xF8;
		TMR1L = 0x30;
		T1CON = 0b00000001;					// 16 bit RW, 1:1, timer 1 on
}
/** EOF main.c ***************************************************************/
