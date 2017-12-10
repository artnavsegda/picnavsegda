// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_CONFIG_H
#define	XC_CONFIG_H

#pragma config POSCMOD = XT    // Primary Oscillator Select->XT oscillator mode selected
#pragma config FNOSC = PRI    // Oscillator Select->Primary oscillator (XT, HS, EC)

#define USE_AND_OR /* To enable AND_OR mask setting */

#define BAUD_RATE (9600) // bps

#define _XTAL_FREQ              8000000UL

#define GetSystemClock()		(_XTAL_FREQ)			// Hz
#define GetInstructionClock()	(GetSystemClock()/2)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	(GetSystemClock()/2)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.
#define FCY                     (_XTAL_FREQ/2)

#include <xc.h>
#include <PPS.h>
#include <uart.h>
#include <spi.h>
#include <libpic30.h> 
#include <stdio.h>
#include "setbaud.h"

#endif	/* XC_CONFIG_H */

