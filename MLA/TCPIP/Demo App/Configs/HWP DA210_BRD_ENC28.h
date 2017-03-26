 /*********************************************************************
 *
 *	Hardware specific definitions for:
 *    - PIC24FJ256DA210 Development Board
 *    - PIC24FJ256DA210
 *    - Ethernet PICtail Plus (ENC28J60)
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    Compiler.h
 * Processor:       PIC24F, PIC24H, dsPIC30F, dsPIC33F
 * Compiler:        Microchip C30 v3.24 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2010 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder		09/16/2010	Regenerated for specific boards
 ********************************************************************/
#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#include "Compiler.h"

// Define a macro describing this hardware set up (used in other files)
#define PIC24FJ256GA702_DEV_BOARD

// Set configuration fuses (but only in MainDemo.c where THIS_IS_STACK_APPLICATION is defined)
#if defined(THIS_IS_STACK_APPLICATION)
    #pragma config BWRP = OFF    // Boot Segment Write-Protect bit->Boot Segment may be written
    #pragma config BSS = DISABLED    // Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
    #pragma config BSEN = OFF    // Boot Segment Control bit->No Boot Segment
    #pragma config GWRP = OFF    // General Segment Write-Protect bit->General Segment may be written
    #pragma config GSS = DISABLED    // General Segment Code-Protect Level bits->No Protection (other than GWRP)
    #pragma config CWRP = OFF    // Configuration Segment Write-Protect bit->Configuration Segment may be written
    #pragma config CSS = DISABLED    // Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
    #pragma config AIVTDIS = OFF    // Alternate Interrupt Vector Table bit->Disabled AIVT

    // FOSCSEL
    #pragma config FNOSC = FRC    // Oscillator Source Selection->Internal Fast RC (FRC)
    #pragma config PLLMODE = DISABLED    // PLL Mode Selection->No PLL used; PLLEN bit is not available
    #pragma config IESO = ON    // Two-speed Oscillator Start-up Enable bit->Start up device with FRC, then switch to user-selected oscillator source

    // FOSC
    #pragma config POSCMD = NONE    // Primary Oscillator Mode Select bits->Primary Oscillator disabled
    #pragma config OSCIOFCN = OFF    // OSC2 Pin Function bit->OSC2 is clock output
    #pragma config SOSCSEL = ON    // SOSC Power Selection Configuration bits->SOSC is used in crystal (SOSCI/SOSCO) mode
    #pragma config PLLSS = PLL_PRI    // PLL Secondary Selection Configuration bit->PLL is fed by the Primary oscillator
    #pragma config IOL1WAY = ON    // Peripheral pin select configuration bit->Allow only one reconfiguration
    #pragma config FCKSM = CSDCMD    // Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are disabled

    // FWDT
    #pragma config WDTPS = PS32768    // Watchdog Timer Postscaler bits->1:32768
    #pragma config FWPSA = PR128    // Watchdog Timer Prescaler bit->1:128
    #pragma config FWDTEN = OFF    // Watchdog Timer Enable bits->WDT and SWDTEN disabled
    #pragma config WINDIS = OFF    // Watchdog Timer Window Enable bit->Watchdog Timer in Non-Window mode
    #pragma config WDTWIN = WIN25    // Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
    #pragma config WDTCMX = WDTCLK    // WDT MUX Source Select bits->WDT clock source is determined by the WDTCLK Configuration bits
    #pragma config WDTCLK = LPRC    // WDT Clock Source Select bits->WDT uses LPRC

    // FPOR
    #pragma config BOREN = ON    // Brown Out Enable bit->Brown Out Enable Bit
    #pragma config LPCFG = OFF    // Low power regulator control->No Retention Sleep
    #pragma config DNVPEN = ENABLE    // Downside Voltage Protection Enable bit->Downside protection enabled using ZPBOR when BOR is inactive

    // FICD
    #pragma config ICS = NONE    // ICD Communication Channel Select bits->Reserved, do not use
    #pragma config JTAGEN = OFF    // JTAG Enable bit->JTAG is disabled

    // FDEVOPT1
    #pragma config ALTCMPI = DISABLE    // Alternate Comparator Input Enable bit->C1INC, C2INC, and C3INC are on their standard pin locations
    #pragma config TMPRPIN = OFF    // Tamper Pin Enable bit->TMPRN pin function is disabled
    #pragma config SOSCHP = ON    // SOSC High Power Enable bit (valid only when SOSCSEL = 1->Enable SOSC high power mode (default)
    #pragma config ALTI2C1 = ALTI2CEN    // Alternate I2C pin Location->SDA1 and SCL1 on RB9 and RB8
#endif


// Clock frequency values
// These directly influence timed events using the Tick module.  They also are used for UART and SPI baud rate generation.
#define GetSystemClock()		(8000000ul)			// Hz
#define GetInstructionClock()	(GetSystemClock()/2)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	(GetSystemClock()/2)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.


// Hardware I/O pin mappings

#define UARTTX_TRIS			(TRISBbits.TRISB3)
#define UARTTX_IO			(PORTBbits.RB3)
#define UARTRX_TRIS			(TRISBbits.TRISB0)
#define UARTRX_IO			(PORTBbits.RB0)

// ENC28J60 I/O pins
#define ENC_CS_TRIS			(TRISBbits.TRISB6)
#define ENC_CS_IO			(LATBbits.LATB6)
//#define ENC_RST_TRIS		(TRISCbits.TRISC13)	// Not connected by default.  It is okay to leave this pin completely unconnected, in which case this macro should simply be left undefined.
//#define ENC_RST_IO			(LATCbits.LATC13)
// SPI SCK, SDI, SDO pins are automatically controlled by the 
// PIC24 SPI module, but Peripheral Pin Select must be configured correctly.
// MISO = RB0 (RP0); MOSI = RB1 (RP1); SCK = RD8 (RP2)
#define ENC_SPI_IF			(IFS0bits.SPI1IF)
#define ENC_SSPBUF			(SPI1BUFL)
#define ENC_SPISTAT			(SPI1STATL)
#define ENC_SPISTATbits		(SPI1STATLbits)
#define ENC_SPICON1			(SPI1CON1L)
#define ENC_SPICON1bits		(SPI1CON1Lbits)
#define ENC_SPICON2			(SPI1CON2L)


//// ENC624J600 Interface Configuration
//// Comment out ENC100_INTERFACE_MODE if you don't have an ENC624J600 or 
//// ENC424J600.  Otherwise, choose the correct setting for the interface you 
//// are using.  Legal values are:
////  - Commented out: No ENC424J600/624J600 present or used.  All other 
////                   ENC100_* macros are ignored.
////	- 0: SPI mode using CS, SCK, SI, and SO pins
////  - 1: 8-bit demultiplexed PSP Mode 1 with RD and WR pins
////  - 2: 8-bit demultiplexed PSP Mode 2 with R/Wbar and EN pins
////  - 3: 16-bit demultiplexed PSP Mode 3 with RD, WRL, and WRH pins
////  - 4: 16-bit demultiplexed PSP Mode 4 with R/Wbar, B0SEL, and B1SEL pins
////  - 5: 8-bit multiplexed PSP Mode 5 with RD and WR pins
////  - 6: 8-bit multiplexed PSP Mode 6 with R/Wbar and EN pins
////  - 9: 16-bit multiplexed PSP Mode 9 with AL, RD, WRL, and WRH pins
////  - 10: 16-bit multiplexed PSP Mode 10 with AL, R/Wbar, B0SEL, and B1SEL 
////        pins
//#define ENC100_INTERFACE_MODE			0
//
//// If using a parallel interface, direct RAM addressing can be used (if all 
//// addresses wires are connected), or a reduced number of pins can be used 
//// for indirect addressing.  If using an SPI interface or PSP Mode 9 or 10 
//// (multiplexed 16-bit modes), which require all address lines to always be 
//// connected, then this option is ignored. Comment out or uncomment this 
//// macro to match your hardware connections.
//#define ENC100_PSP_USE_INDIRECT_RAM_ADDRESSING
//
//// ENC424J600/624J600 parallel indirect address remapping macro function.
//// This section translates SFR and RAM addresses presented to the 
//// ReadMemory() and WriteMemory() APIs in ENCX24J600.c to the actual 
//// addresses that must be presented on the parallel interface.  This macro 
//// must be modified to match your hardware if you are using an indirect PSP 
//// addressing mode (ENC100_PSP_USE_INDIRECT_RAM_ADDRESSING is defined) and 
//// have some of your address lines tied off to Vdd.  If you are using the 
//// SPI interface, then this section can be ignored or deleted.
//#if (ENC100_INTERFACE_MODE == 1) || (ENC100_INTERFACE_MODE == 2) || (ENC100_INTERFACE_MODE == 5) || (ENC100_INTERFACE_MODE == 6) // 8-bit PSP
//	#define ENC100_TRANSLATE_TO_PIN_ADDR(a)		((((a)&0x0100)<<6) | ((a)&0x00FF))
//#elif (ENC100_INTERFACE_MODE == 3) || (ENC100_INTERFACE_MODE == 4) // 16-bit PSP
//	#define ENC100_TRANSLATE_TO_PIN_ADDR(a)		(a)
//#endif
//
//// Auto-crossover pins on Fast 100Mbps Ethernet PICtail/PICtail Plus.  If 
//// your circuit doesn't have such a feature, delete these two defines.
//#define ENC100_MDIX_TRIS				(TRISBbits.TRISB5)
//#define ENC100_MDIX_IO					(LATBbits.LATB5)
//
//// ENC624J600 I/O control and status pins
//// If a pin is not required for your selected ENC100_INTERFACE_MODE 
//// interface selection (ex: WRH/B1SEL for PSP modes 1, 2, 5, and 6), then 
//// you can ignore, delete, or put anything for the pin definition.  Also, 
//// the INT and POR pins are entirely optional.  If not connected, comment 
//// them out.
//#define ENC100_INT_TRIS					(TRISAbits.TRISA15)		// INT signal is optional and currently unused in the Microchip TCP/IP Stack.  Leave this pin disconnected and comment out this pin definition if you don't want it.
//#define ENC100_INT_IO					(PORTAbits.RA15)
//#if (ENC100_INTERFACE_MODE >= 1)	// Parallel mode
//	// PSP control signal pinout
//	#define ENC100_CS_TRIS				(TRISGbits.TRISG8)	// CS is optional in PSP mode.  If you are not sharing the parallel bus with another device, tie CS to Vdd and comment out this pin definition.
//	#define ENC100_CS_IO				(LATGbits.LATG8)
//	#define ENC100_POR_TRIS				(TRISEbits.TRISE9)	// POR signal is optional.  If your application doesn't have a power disconnect feature, comment out this pin definition.
//	#define ENC100_POR_IO				(LATEbits.LATE9)
//	#define ENC100_SO_WR_B0SEL_EN_TRIS	(TRISDbits.TRISD4)
//	#define ENC100_SO_WR_B0SEL_EN_IO	(LATDbits.LATD4)
//	#define ENC100_SI_RD_RW_TRIS		(TRISDbits.TRISD5)
//	#define ENC100_SI_RD_RW_IO			(LATDbits.LATD5)
//	#define ENC100_SCK_AL_TRIS			(TRISBbits.TRISB15)
//	#define ENC100_SCK_AL_IO			(LATBbits.LATB15)
//	#undef LED1_TRIS
//	#undef LED1_IO
//	#undef LED2_TRIS
//	#undef LED2_IO
//	#undef LED_GET
//	#undef LED_PUT
//	#define LED1_TRIS					(((unsigned char*)&NVMKEY)[1])	// No such LED, map to dummy register.  This is required with the Fast 100Mbps Ethernet PICtail Plus in parallel mode because this RE9 signal also controls the POR (SHDN) signal.
//	#define LED1_IO						(((unsigned char*)&NVMKEY)[1])
//	#define LED2_TRIS					(((unsigned char*)&NVMKEY)[1])	// No such LED, map to dummy register.  This is required with the Fast 100Mbps Ethernet PICtail Plus in parallel mode because this RG8 signal also controls the CS signal.
//	#define LED2_IO						(((unsigned char*)&NVMKEY)[1])
//	#define LED_GET()					LED0_IO
//	#define LED_PUT(a)					(LED0_IO = (a) & 0x1)
//#else
//	// SPI pinout
//	#define ENC100_CS_TRIS				(TRISGbits.TRISG6)	// CS is mandatory when using the SPI interface
//	#define ENC100_CS_IO				(LATGbits.LATG6)
//	#define ENC100_POR_TRIS				(TRISCbits.TRISC13)	// POR signal is optional.  If your application doesn't have a power disconnect feature, comment out this pin definition.
//	#define ENC100_POR_IO				(LATCbits.LATC13)
//	#define ENC100_SO_WR_B0SEL_EN_TRIS	(TRISBbits.TRISB0)	// SO is ENCX24J600 Serial Out, which needs to connect to the PIC SDI pin for SPI mode
//	#define ENC100_SO_WR_B0SEL_EN_IO	(PORTBbits.RB0)
//	#define ENC100_SI_RD_RW_TRIS		(TRISBbits.TRISB1)	// SI is ENCX24J600 Serial In, which needs to connect to the PIC SDO pin for SPI mode
//	#define ENC100_SI_RD_RW_IO			(LATBbits.LATB1)
//	#define ENC100_SCK_AL_TRIS			(TRISDbits.TRISD8)
//#endif
//
//
//// ENC624J600 SPI SFR register selection (controls which SPI peripheral to 
//// use on PICs with multiple SPI peripherals).  If a parallel interface is 
//// used (ENC100_INTERFACE_MODE is >= 1), then the SPI is not used and this 
//// section can be ignored or deleted.
//#define ENC100_ISR_ENABLE		(IEC1bits.INT2IE)
//#define ENC100_ISR_FLAG			(IFS1bits.INT2IF)
//#define ENC100_ISR_POLARITY		(INTCON2bits.INT2EP)
//#define ENC100_ISR_PRIORITY		(IPC7bits.INT2IP)
//#define ENC100_SPI_ENABLE		(ENC100_SPISTATbits.SPIEN)
//#define ENC100_SPI_IF			(IFS0bits.SPI1IF)
//#define ENC100_SSPBUF			(SPI1BUF)
//#define ENC100_SPISTAT			(SPI1STAT)
//#define ENC100_SPISTATbits		(SPI1STATbits)
//#define ENC100_SPICON1			(SPI1CON1)
//#define ENC100_SPICON1bits		(SPI1CON1bits)
//#define ENC100_SPICON2			(SPI1CON2)
//
//// ENC624J600 Bit Bang PSP I/O macros and pin configuration for address and 
//// data.  If using the SPI interface (ENC100_INTERFACE_MODE is 0) then this 
//// section is not used and can be ignored or deleted.  The Enhanced PMP 
//// module available on the PIC24FJ256DA210 family will not work with the 
//// ENC424J600/624J600, so bit bang mode must be used if parallel access is 
//// desired.
//#define ENC100_BIT_BANG_PMP
//#if defined(ENC100_BIT_BANG_PMP)
//	#if ENC100_INTERFACE_MODE == 1 || ENC100_INTERFACE_MODE == 2	// Dumultiplexed 8-bit address/data modes
//		#if defined(ENC100_PSP_USE_INDIRECT_RAM_ADDRESSING)	// Only ENC624J600 address pins A0-A8 connected (A9-A14 tied to Vdd)
//			// AD0-AD7: "PMD0-PMD7" -> RE0-RE7
//			// A0: "PMA0" -> RB15
//			// A1: "PMA1" -> RB14
//			// A2: "PMA2" -> RG9
//			// A3: "PMA3" -> RA4
//			// A4: "PMA4" -> RA3
//			// A5: "PMA5" -> RF12
//			// A6: "PMA6" -> RA10
//			// A7: "PMA7" -> RA9
//			// A8: "PMA14_TO_P104" "PMA14" -> RD11
//			// RD: "PMRD/RD5" -> RD5
//			// WR: "PMWR/RD4 -> RD4
//			// CS: "AN19/RG8_TO_P72" "AN19/RG8" -> RG8
//			#define ENC100_INIT_PSP_BIT_BANG()	do{ANSA &= 0xF9E7; ANSB &= 0x3FFF; ANSG &= 0xFCFF;} while(0)		// RE0-RE7, RF12, RD11, RD4, RD5 (AD0-AD7, A5, A8, WR, RD) pins are already digital only pins.
//			#define ENC100_SET_ADDR_TRIS_OUT()	do{TRISA &= 0xF9E7; TRISB &= 0x3FFF; TRISFbits.TRISF12 = 0; TRISGbits.TRISG9 = 0; TRISDbits.TRISD11 = 0;}while(0)
//			#define ENC100_SET_ADDR_IO(a)		do{unsigned short _SetMacro = (a); LATBbits.LATB15 = 0; LATBbits.LATB14 = 0; LATGbits.LATG9 = 0; LATA &= 0xF9E7; LATFbits.LATF12 = 0; LATDbits.LATD11 = 0; if(_SetMacro & 0x0001) LATBbits.LATB15 = 1; if(_SetMacro & 0x0002) LATBbits.LATB14 = 1; if(_SetMacro & 0x0004) LATGbits.LATG9 = 1; if(_SetMacro & 0x0008) LATAbits.LATA4 = 1; if(_SetMacro & 0x0010) LATAbits.LATA3 = 1; if(_SetMacro & 0x0020) LATFbits.LATF12 = 1; if(_SetMacro & 0x0040) LATAbits.LATA10 = 1; if(_SetMacro & 0x0080) LATAbits.LATA9 = 1; if(_SetMacro & 0x4000) LATDbits.LATD11 = 1;}while(0)
//			#define ENC100_SET_AD_TRIS_IN()		(((volatile unsigned char*)&TRISE)[0] = 0xFF)
//			#define ENC100_SET_AD_TRIS_OUT()	(((volatile unsigned char*)&TRISE)[0] = 0x00)
//			#define ENC100_GET_AD_IO()			(((volatile unsigned char*)&PORTE)[0])
//			#define ENC100_SET_AD_IO(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//		#else 	// All ENC624J600 address pins A0-A14 connected
//			// AD0-AD7: "PMD0-PMD7" -> RE0-RE7
//			// A0: "PMA0" -> RB15
//			// A1: "PMA1" -> RB14
//			// A2: "PMA2" -> RG9
//			// A3: "PMA3" -> RA4
//			// A4: "PMA4" -> RA3
//			// A5: "PMA5" -> RF12
//			// A6: "PMA6" -> RA10
//			// A7: "PMA7" -> RA9
//			// A8: "PMA8" -> RF5
//			// A9: "PMA9" -> RF4
//			// A10: "PMA10" -> RB13
//			// A11: "PMA11" -> RB12
//			// A12: "PMA12" -> RB11
//			// A13: "PMA13" -> RB10
//			// A14: "PMA14_TO_P104" "PMA14" -> RD11
//			// RD: "PMRD/RD5" -> RD5
//			// WR: "PMWR/RD4 -> RD4
//			// CS: "AN19/RG8_TO_P72" "AN19/RG8" -> RG8
//			#define ENC100_INIT_PSP_BIT_BANG()	do{ANSA &= 0xF9E7; ANSB &= 0x03FF; ANSG &= 0xFCFF;} while(0)		// RE0-RE7, RF12, RD11, RD4, RD5 (AD0-AD7, A5, A14, WR, RD) pins are already digital only pins.
//			#define ENC100_SET_ADDR_TRIS_OUT()	do{TRISA &= 0xF9E7; TRISB &= 0x03FF; TRISF &= 0xEFCF; TRISGbits.TRISG9 = 0; TRISDbits.TRISD11 = 0;}while(0)
//			#define ENC100_SET_ADDR_IO(a)		do{unsigned short _SetMacro = (a); LATA &= 0xF9E7; LATB &= 0x03FF; LATF &= 0xEFCF; LATGbits.LATG9 = 0; LATDbits.LATD11 = 0; if(_SetMacro & 0x0001) LATBbits.LATB15 = 1; if(_SetMacro & 0x0002) LATBbits.LATB14 = 1; if(_SetMacro & 0x0004) LATGbits.LATG9 = 1; if(_SetMacro & 0x0008) LATAbits.LATA4 = 1; if(_SetMacro & 0x0010) LATAbits.LATA3 = 1; if(_SetMacro & 0x0020) LATFbits.LATF12 = 1; if(_SetMacro & 0x0040) LATAbits.LATA10 = 1; if(_SetMacro & 0x0080) LATAbits.LATA9 = 1; if(_SetMacro & 0x0100) LATFbits.LATF5 = 1; if(_SetMacro & 0x0200) LATFbits.LATF4 = 1; if(_SetMacro & 0x0400) LATBbits.LATB13 = 1; if(_SetMacro & 0x0800) LATBbits.LATB12 = 1; if(_SetMacro & 0x1000) LATBbits.LATB11 = 1; if(_SetMacro & 0x2000) LATBbits.LATB10 = 1; if(_SetMacro & 0x4000) LATDbits.LATD11 = 1;}while(0)
//			#define ENC100_SET_AD_TRIS_IN()		(((volatile unsigned char*)&TRISE)[0] = 0xFF)
//			#define ENC100_SET_AD_TRIS_OUT()	(((volatile unsigned char*)&TRISE)[0] = 0x00)
//			#define ENC100_GET_AD_IO()			(((volatile unsigned char*)&PORTE)[0])
//			#define ENC100_SET_AD_IO(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//		#endif
//	#elif ENC100_INTERFACE_MODE == 3 || ENC100_INTERFACE_MODE == 4	// Dumultiplexed 16-bit address/data modes
//		#if defined(ENC100_PSP_USE_INDIRECT_RAM_ADDRESSING)	// Only ENC624J600 address pins A0-A7 connected (A8-A13 tied to Vdd)
//			// A0: "PMA0" -> RB15
//			// A1: "PMA1" -> RB14
//			// A2: "PMA2" -> RG9
//			// A3: "PMA3" -> RA4
//			// A4: "PMA4" -> RA3
//			// A5: "PMA5" -> RF12
//			// A6: "PMA6" -> RA10
//			// A7: "PMA7" -> RA9
//			// AD0-AD7: "PMD0-PMD7" -> RE0-RE7
//			// AD8: "PMD8" -> RG0
//			// AD9: "PMD9" -> RG1
//			// AD10: "RC13_PMD10_TO_P30" "RC13" -> RC13
//			// AD11: "PMBE1_PMD11_TO_P28" "PMBE1" -> RA15
//			// AD12: "PMD12" -> RD12
//			// AD13: "PMD13" -> RD13
//			// AD14: "PMD14" -> RD6
//			// AD15: "PMD15" -> RD7
//			// RD: "PMRD/RD5" -> RD5
//			// WRL & WRH: "PMWR/RD4 -> RD4
//			// CS: "AN19/RG8_TO_P72" "AN19/RG8" -> RG8
//			#define ENC100_INIT_PSP_BIT_BANG()	do{ANSA &= 0x79E7; ANSB &= 0x3FFF; ANSD &= 0xCF0F; ANSG &= 0xFCFC;}while(0)
//			#define ENC100_SET_ADDR_TRIS_OUT()	do{TRISA &= 0xF9E7; TRISBbits.TRISB15 = 0; TRISBbits.TRISB14 = 0; TRISFbits.TRISF12 = 0; TRISGbits.TRISG9 = 0;}while(0)
//			#define ENC100_SET_ADDR_IO(a)		do{unsigned short _wSetMacro = (a); LATA &= 0xF9E7; LATBbits.LATB15 = 0; LATBbits.LATB14 = 0; LATFbits.LATF12 = 0; LATGbits.LATG9 = 0; if(_wSetMacro & 0x0001) LATBbits.LATB15 = 1; if(_wSetMacro & 0x0002) LATBbits.LATB14 = 1; if(_wSetMacro & 0x0004) LATGbits.LATG9 = 1; if(_wSetMacro & 0x0008) LATAbits.LATA4 = 1; if(_wSetMacro & 0x0010) LATAbits.LATA3 = 1; if(_wSetMacro & 0x0020) LATFbits.LATF12 = 1; if(_wSetMacro & 0x0040) LATAbits.LATA10 = 1; if(_wSetMacro & 0x0080) LATAbits.LATA9 = 1;}while(0)
//			#define ENC100_WRH_B1SEL_TRIS		ENC100_SO_WR_B0SEL_EN_TRIS
//			#define ENC100_WRH_B1SEL_IO			ENC100_SO_WR_B0SEL_EN_IO
//			#define ENC100_SET_AD_TRIS_IN()		do{((volatile unsigned char*)&TRISE)[0] = 0xFF; TRISAbits.TRISA15 = 1; TRISCbits.TRISC13 = 1; TRISD |= 0x30C0; TRISGbits.TRISG0 = 1; TRISGbits.TRISG1 = 1;}while(0)
//			#define ENC100_SET_AD_TRIS_OUT()	do{((volatile unsigned char*)&TRISE)[0] = 0x00; TRISAbits.TRISA15 = 0; TRISCbits.TRISC13 = 0; TRISD &= 0xCF3F; TRISGbits.TRISG0 = 0; TRISGbits.TRISG1 = 0;}while(0)
//			#define ENC100_GET_AD_IOH()			(PORTGbits.RG0 | (PORTGbits.RG1<<1) | (PORTCbits.RC13<<2) | (PORTAbits.RA15<<3) | (PORTDbits.RD12<<4) | (PORTDbits.RD13<<5) | (PORTDbits.RD6<<6) | (PORTDbits.RD7<<7))
//			#define ENC100_GET_AD_IOL()			(((volatile unsigned char*)&PORTE)[0])
//			#define ENC100_SET_AD_IO(data)		do{unsigned short _wSetMacro = (data); ((volatile unsigned char*)&LATE)[0] = ((unsigned char*)&_wSetMacro)[0]; LATG &= 0xFFFC; LATCbits.LATC13 = 0; LATAbits.LATA15 = 0; LATD &= 0xCF3F; if(_wSetMacro & 0x0100) LATGbits.LATG0 = 1; if(_wSetMacro & 0x0200) LATGbits.LATG1 = 1; if(_wSetMacro & 0x0400) LATCbits.LATC13 = 1; if(_wSetMacro & 0x0800) LATAbits.LATA15 = 1; if(_wSetMacro & 0x1000) LATDbits.LATD12 = 1; if(_wSetMacro & 0x2000) LATDbits.LATD13 = 1; if(_wSetMacro & 0x4000) LATDbits.LATD6 = 1; if(_wSetMacro & 0x8000) LATDbits.LATD7 = 1;}while(0)
//			#define ENC100_SET_AD_IOL(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//		#else 	// All ENC624J600 address pins A0-A13 connected
//			// A0: "PMA0" -> RB15
//			// A1: "PMA1" -> RB14
//			// A2: "PMA2" -> RG9
//			// A3: "PMA3" -> RA4
//			// A4: "PMA4" -> RA3
//			// A5: "PMA5" -> RF12
//			// A6: "PMA6" -> RA10
//			// A7: "PMA7" -> RA9
//			// A8: "PMA8" -> RF5
//			// A9: "PMA9" -> RF4
//			// A10: "PMA10" -> RB13
//			// A11: "PMA11" -> RB12
//			// A12: "PMA12" -> RB11
//			// A13: "PMA13" -> RB10
//			// AD0-AD7: "PMD0-PMD7" -> RE0-RE7
//			// AD8: "PMD8" -> RG0
//			// AD9: "PMD9" -> RG1
//			// AD10: "RC13_PMD10_TO_P30" "RC13" -> RC13
//			// AD11: "PMBE1_PMD11_TO_P28" "PMBE1" -> RA15
//			// AD12: "PMD12" -> RD12
//			// AD13: "PMD13" -> RD13
//			// AD14: "PMD14" -> RD6
//			// AD15: "PMD15" -> RD7
//			// RD: "PMRD/RD5" -> RD5
//			// WRL & WRH: "PMWR/RD4 -> RD4
//			// CS: "AN19/RG8_TO_P72" "AN19/RG8" -> RG8
//			#define ENC100_INIT_PSP_BIT_BANG()	do{ANSA &= 0x79E7; ANSB &= 0x03FF; ANSD &= 0xCF0F; ANSG &= 0xFCFC;}while(0)
//			#define ENC100_SET_ADDR_TRIS_OUT()	do{TRISA &= 0xF9E7; TRISB &= 0x03FF; TRISF &= 0xEFCF; TRISGbits.TRISG9 = 0;}while(0)
//			#define ENC100_SET_ADDR_IO(a)		do{unsigned short _wSetMacro = (a); LATA &= 0xF9E7; LATB &= 0x03FF; LATF &= 0xEFCF; LATGbits.LATG9 = 0; if(_wSetMacro & 0x0001) LATBbits.LATB15 = 1; if(_wSetMacro & 0x0002) LATBbits.LATB14 = 1; if(_wSetMacro & 0x0004) LATGbits.LATG9 = 1; if(_wSetMacro & 0x0008) LATAbits.LATA4 = 1; if(_wSetMacro & 0x0010) LATAbits.LATA3 = 1; if(_wSetMacro & 0x0020) LATFbits.LATF12 = 1; if(_wSetMacro & 0x0040) LATAbits.LATA10 = 1; if(_wSetMacro & 0x0080) LATAbits.LATA9 = 1; if(_wSetMacro & 0x0100) LATFbits.LATF5 = 1; if(_wSetMacro & 0x0200) LATFbits.LATF4 = 1; if(_wSetMacro & 0x0400) LATBbits.LATB13 = 1; if(_wSetMacro & 0x0800) LATBbits.LATB12 = 1; if(_wSetMacro & 0x1000) LATBbits.LATB11 = 1; if(_wSetMacro & 0x2000) LATBbits.LATB10 = 1;}while(0)
//			#define ENC100_WRH_B1SEL_TRIS		ENC100_SO_WR_B0SEL_EN_TRIS
//			#define ENC100_WRH_B1SEL_IO			ENC100_SO_WR_B0SEL_EN_IO
//			#define ENC100_SET_AD_TRIS_IN()		do{((volatile unsigned char*)&TRISE)[0] = 0xFF; TRISAbits.TRISA15 = 1; TRISCbits.TRISC13 = 1; TRISD |= 0x30C0; TRISGbits.TRISG0 = 1; TRISGbits.TRISG1 = 1;}while(0)
//			#define ENC100_SET_AD_TRIS_OUT()	do{((volatile unsigned char*)&TRISE)[0] = 0x00; TRISAbits.TRISA15 = 0; TRISCbits.TRISC13 = 0; TRISD &= 0xCF3F; TRISGbits.TRISG0 = 0; TRISGbits.TRISG1 = 0;}while(0)
//			#define ENC100_GET_AD_IOH()			(PORTGbits.RG0 | (PORTGbits.RG1<<1) | (PORTCbits.RC13<<2) | (PORTAbits.RA15<<3) | (PORTDbits.RD12<<4) | (PORTDbits.RD13<<5) | (PORTDbits.RD6<<6) | (PORTDbits.RD7<<7))
//			#define ENC100_GET_AD_IOL()			(((volatile unsigned char*)&PORTE)[0])
//			#define ENC100_SET_AD_IO(data)		do{unsigned short _wSetMacro = (data); ((volatile unsigned char*)&LATE)[0] = ((unsigned char*)&_wSetMacro)[0]; LATG &= 0xFFFC; LATCbits.LATC13 = 0; LATAbits.LATA15 = 0; LATD &= 0xCF3F; if(_wSetMacro & 0x0100) LATGbits.LATG0 = 1; if(_wSetMacro & 0x0200) LATGbits.LATG1 = 1; if(_wSetMacro & 0x0400) LATCbits.LATC13 = 1; if(_wSetMacro & 0x0800) LATAbits.LATA15 = 1; if(_wSetMacro & 0x1000) LATDbits.LATD12 = 1; if(_wSetMacro & 0x2000) LATDbits.LATD13 = 1; if(_wSetMacro & 0x4000) LATDbits.LATD6 = 1; if(_wSetMacro & 0x8000) LATDbits.LATD7 = 1;}while(0)
//			#define ENC100_SET_AD_IOL(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//		#endif
//	#elif ENC100_INTERFACE_MODE == 5 || ENC100_INTERFACE_MODE == 6	// Mutliplexed 8-bit address/data modes
//		#if defined(ENC100_PSP_USE_INDIRECT_RAM_ADDRESSING)	// Only ENCX24J600 address pins AD0-AD8 connected (AD9-AD14 tied to Vdd)
//			#define ENC100_INIT_PSP_BIT_BANG()	do{ANSB &= 0x7FFF; ANSG &= 0xFEFF;} while(0)		// RE0-RE7, RD11, RD4, RD5 (AD0-AD7, AD8, WR, RD) pins are already digital only pins.  RB15, RG8 (AL, CS) needs to be made digital only.
//			#define ENC100_SET_AD_TRIS_IN()		do{((volatile unsigned char*)&TRISE)[0] = 0xFF;}while(0)
//			#define ENC100_SET_AD_TRIS_OUT()	do{((volatile unsigned char*)&TRISE)[0] = 0x00; TRISDbits.TRISD11 = 0;}while(0)
//			#define ENC100_GET_AD_IO()			(((volatile unsigned char*)&PORTE)[0])
//			#define ENC100_SET_AD_IO(data)		do{unsigned short _wSetMacro = (data); ((volatile unsigned char*)&LATE)[0] = (unsigned char)_wSetMacro; LATDbits.LATD11 = 0; if(_wSetMacro & 0x4000) LATDbits.LATD11 = 1;}while(0)
//			#define ENC100_SET_AD_IOL(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//		#else 	// All ENCX24J600 address pins AD0-AD14 connected
//			// AD0-AD7: "PMD0-PMD7" -> RE0-RE7
//			// AD8: "PMA8" -> RF5
//			// AD9: "PMA9" -> RF4
//			// AD10: "PMA10" -> RB13
//			// AD11: "PMA11" -> RB12
//			// AD12: "PMA12" -> RB11
//			// AD13: "PMA13" -> RB10
//			// AD14: "PMA14_TO_P104" "PMA14" -> RD11
//			// RD: "PMRD/RD5" -> RD5
//			// WR: "PMWR/RD4 -> RD4
//			// AL: "PMA0" -> RB15
//			// CS: "AN19/RG8_TO_P72" "AN19/RG8" -> RG8
//			#define ENC100_INIT_PSP_BIT_BANG()	do{ANSB &= 0x43FF; ANSG &= 0xFEFF;} while(0) // Set pins as digital I/Os (not analog).  RD11, RD5, RD4, RE0-RE7, RF4, RF5 are all digital-only pins and therefore no writes to ANSD, ANSE, or ANSF are needed.
//			#define ENC100_SET_AD_TRIS_IN()		do{((volatile unsigned char*)&TRISE)[0] = 0xFF;}while(0)
//			#define ENC100_SET_AD_TRIS_OUT()	do{((volatile unsigned char*)&TRISE)[0] = 0x00; TRISFbits.TRISF5 = 0; TRISFbits.TRISF4 = 0; TRISB &= 0x43FF; TRISDbits.TRISD11 = 0;}while(0)
//			#define ENC100_GET_AD_IO()			(((volatile unsigned char*)&PORTE)[0])
//			#define ENC100_SET_AD_IO(data)		do{unsigned short _wSetMacro = (data); ((volatile unsigned char*)&LATE)[0] = (unsigned char)_wSetMacro; LATFbits.LATF5 = 0; LATFbits.LATF4 = 0; LATB &= 0x43FF; LATDbits.LATD11 = 0; if(_wSetMacro & 0x0100) LATFbits.LATF5 = 1; if(_wSetMacro & 0x0200) LATFbits.LATF4 = 1; if(_wSetMacro & 0x0400) LATBbits.LATB13 = 1; if(_wSetMacro & 0x0800) LATBbits.LATB12 = 1; if(_wSetMacro & 0x1000) LATBbits.LATB11 = 1;  if(_wSetMacro & 0x2000) LATBbits.LATB10 = 1; if(_wSetMacro & 0x4000) LATDbits.LATD11 = 1;}while(0)
//			#define ENC100_SET_AD_IOL(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//		#endif
//	#elif ENC100_INTERFACE_MODE == 9 || ENC100_INTERFACE_MODE == 10	// Mutliplexed 16-bit address/data modes
//		// All ENC624J600 adddress/data pins AD0-AD15 connected (required for 16-bit data, so there is no differentiation for indirect versus direct addressing mode)
//		// This pinout is awful for doing 16-bit bit-bang operations.  The Fast 100Mbps Ethernet PICtail Plus hardware is wired for PMP hardware support, which requires this pinout.  However, if you are designing a custom board, you can simplify these read/write operations dramatically if you wire things more logically by putting all 16 I/O pins, in order, on PORTB or PORTD.  Such a change would enhance performance.
//		// AD0-AD7: "PMD0-PMD7" -> RE0-RE7
//		// AD8: "PMD8" -> RG0
//		// AD9: "PMD9" -> RG1
//		// AD10: "RC13_PMD10_TO_P30" "RC13" -> RC13
//		// AD11: "PMBE1_PMD11_TO_P28" "PMBE1" -> RA15
//		// AD12: "PMD12" -> RD12
//		// AD13: "PMD13" -> RD13
//		// AD14: "PMD14" -> RD6
//		// AD15: "PMD15" -> RD7
//		// RD: "PMRD/RD5" -> RD5
//		// WRL & WRH: "PMWR/RD4 -> RD4
//		// AL: "PMA0" -> RB15
//		// CS: "AN19/RG8_TO_P72" "AN19/RG8" -> RG8
//		#define ENC100_INIT_PSP_BIT_BANG()	do{ANSBbits.ANSB15 = 0; ANSCbits.ANSC13 = 0; ANSD &= 0xCF0F; ANSGbits.ANSG8 = 0;}while(0)	// Set pins as digital I/Os (not analog).  RA15 and RE0-RE7 are all digital-only pins and therefore no writes to ANSA or ANSE are needed.
//		#define ENC100_WRH_B1SEL_TRIS		ENC100_SO_WR_B0SEL_EN_TRIS
//		#define ENC100_WRH_B1SEL_IO			ENC100_SO_WR_B0SEL_EN_IO
//		#define ENC100_SET_AD_TRIS_IN()		do{((volatile unsigned char*)&TRISE)[0] = 0xFF; TRISAbits.TRISA15 = 1; TRISCbits.TRISC13 = 1; TRISD |= 0x30C0; TRISGbits.TRISG0 = 1; TRISGbits.TRISG1 = 1;}while(0)
//		#define ENC100_SET_AD_TRIS_OUT()	do{((volatile unsigned char*)&TRISE)[0] = 0x00; TRISAbits.TRISA15 = 0; TRISCbits.TRISC13 = 0; TRISD &= 0xCF3F; TRISGbits.TRISG0 = 0; TRISGbits.TRISG1 = 0;}while(0)
//		#define ENC100_GET_AD_IOH()			(PORTGbits.RG0 | (PORTGbits.RG1<<1) | (PORTCbits.RC13<<2) | (PORTAbits.RA15<<3) | (PORTDbits.RD12<<4) | (PORTDbits.RD13<<5) | (PORTDbits.RD6<<6) | (PORTDbits.RD7<<7))
//		#define ENC100_GET_AD_IOL()			(((volatile unsigned char*)&PORTE)[0])
//		#define ENC100_SET_AD_IO(data)		do{unsigned short _wSetMacro = (data); ((volatile unsigned char*)&LATE)[0] = ((unsigned char*)&_wSetMacro)[0]; LATG &= 0xFFFC; LATCbits.LATC13 = 0; LATAbits.LATA15 = 0; LATD &= 0xCF3F; if(_wSetMacro & 0x0100) LATGbits.LATG0 = 1; if(_wSetMacro & 0x0200) LATGbits.LATG1 = 1; if(_wSetMacro & 0x0400) LATCbits.LATC13 = 1; if(_wSetMacro & 0x0800) LATAbits.LATA15 = 1; if(_wSetMacro & 0x1000) LATDbits.LATD12 = 1; if(_wSetMacro & 0x2000) LATDbits.LATD13 = 1; if(_wSetMacro & 0x4000) LATDbits.LATD6 = 1; if(_wSetMacro & 0x8000) LATDbits.LATD7 = 1;}while(0)
//		#define ENC100_SET_AD_IOL(data)		(((volatile unsigned char*)&LATE)[0] = (unsigned char)(data))
//	#endif
//#endif


//// MRF24WB0M Wi-Fi I/O pins
//#define WF_CS_TRIS			(TRISGbits.TRISG8)
//#define WF_CS_IO			(LATGbits.LATG8)
//#define WF_SDI_TRIS			(TRISBbits.TRISB1)
//#define WF_SCK_TRIS			(TRISDbits.TRISD8)
//#define WF_SDO_TRIS			(TRISBbits.TRISB0)
//#define WF_RESET_TRIS		(TRISAbits.TRISA15)
//#define WF_RESET_IO			(LATAbits.LATA15)
//#define WF_INT_TRIS			(TRISEbits.TRISE9)  // INT1
//#define WF_INT_IO			(PORTEbits.RE9)
//#define WF_HIBERNATE_TRIS	(TRISAbits.TRISA7)
//#define WF_HIBERNATE_IO		(LATAbits.LATA7)
//#define WF_INT_EDGE			(INTCON2bits.INT1EP)
//#define WF_INT_IE			(IEC1bits.INT1IE)
//#define WF_INT_IF			(IFS1bits.INT1IF)
//#define WF_SSPBUF			(SPI1BUF)
//#define WF_SPISTAT			(SPI1STAT)
//#define WF_SPISTATbits		(SPI1STATbits)
//#define WF_SPICON1			(SPI1CON1)
//#define WF_SPICON1bits		(SPI1CON1bits)
//#define WF_SPICON2			(SPI1CON2)
//#define WF_SPI_IE			(IEC0bits.SPI1IE)
////#define WF_SPI_IP			(IPC2bits.SPI1IP)
//#define WF_SPI_IF			(IFS0bits.SPI1IF)


// Select which UART the STACK_USE_UART and STACK_USE_UART2TCP_BRIDGE 
// options will use.  You can change these to U1BRG, U1MODE, etc. if you 
// want to use the UART1 module instead of UART2.
#define UBRG				U2BRG
#define UMODE				U2MODE
#define USTA				U2STA
#define BusyUART()			BusyUART2()
#define CloseUART()			CloseUART2()
#define ConfigIntUART(a)	ConfigIntUART2(a)
#define DataRdyUART()		DataRdyUART2()
#define OpenUART(a,b,c)		OpenUART2(a,b,c)
#define ReadUART()			ReadUART2()
#define WriteUART(a)		WriteUART2(a)
#define getsUART(a,b,c)		getsUART2(a,b,c)
#define putsUART(a)			putsUART2((unsigned int*)a)
#define getcUART()			getcUART2()
#define putcUART(a)			do{while(BusyUART()); WriteUART(a); while(BusyUART()); }while(0)
#define putrsUART(a)		putrsUART2(a)


#endif // #ifndef HARDWARE_PROFILE_H
