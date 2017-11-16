/**
  @Generated MPLAB(c) Code Configurator Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.26
        Device            :  PIC24FJ128GB410
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.30
        MPLAB             :  MPLAB X 3.45
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

// Configuration bits: selected in the GUI

// FSEC
#pragma config BWRP = OFF    // Boot Segment Write Protect->Boot segment may be written
#pragma config BSS = OFF    // Boot segment Protect->No Protection (other than BWRP)
#pragma config BSEN = OFF    // Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF    // General Segment Write Protect->Writes to program memory are allowed
#pragma config GSS = OFF    // General Segment Code Protect->Code protection is disabled
#pragma config CWRP = OFF    // Configuration Segment Program Write Protection bit->Configuration Segment may be written
#pragma config CSS = DIS    // Configuration Segment Code Protection Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = DISABLE    // Alternate Interrupt Vector Table Disable bit->Disable AIVT

// FOSCSEL
#pragma config FNOSC = FRC    // Oscillator Select->Fast RC Oscillator (FRC)
#pragma config PLLMODE = DISABLED    // Frequency Multiplier Select Bits->No PLL used; PLLEN bit is not available
#pragma config IESO = ON    // Internal External Switchover->Start up device with FRC, then switch to user-selected oscillator source

// FOSC
#pragma config POSCMOD = NONE    // Primary Oscillator Select->Primary Oscillator disabled
#pragma config OSCIOFCN = ON    // OSCO Pin Configuration->OSCO/CLKO/RC15 functions as port I/O (RC15)
#pragma config SOSCSEL = OFF    // SOSC Power Selection Configuration bits->Digital (SCLKI) mode
#pragma config PLLSS = PLL_PRI    // PLL Secondary Selection Configuration bit->PLL is fed by the Primary oscillator
#pragma config IOL1WAY = ON    // IOLOCK One-Way Set Enable->Once set the IOLOCK bit cannot be cleared
#pragma config FCKSM = CSDCMD    // Clock Switching and Monitor Selection->Clock switching and Fail-Safe Clock Monitor are disabled

// FWDT
#pragma config WDTPS = PS32768    // Watchdog Timer Postscaler->1:32768
#pragma config FWPSA = PR128    // WDT Prescaler->Prescaler ratio of 1:128
#pragma config FWDTEN = OFF    // Watchdog Timer Enable->Watchdog Timer is disabled
#pragma config WINDIS = OFF    // Windowed Watchdog Timer Disable bit->Standard Watchdog Timer enabled (Windowed-mode is disabled)
#pragma config WDTWIN = PS25_0    // Watchdog Window Select bits->Watch Dog Timer Window Width is 25 percent
#pragma config WDTCMX = WDTCLK    // WDT Clock Source Select bits->WDT clock source is determined by the WDTCLK Configuration bits
#pragma config WDTCLK = LPRC    // WDT Clock Source Select bits->WDT uses LPRC

// FPOR
#pragma config BOREN = ON    // Brown-out Reset Enable bits->Brown-out Reset Enable
#pragma config LPCFG = OFF    // Low power regulator control->Disabled

// FICD
#pragma config ICS = PGx2    // Emulator Pin Placement Select bits->Emulator functions are shared with PGEC2/PGED2
#pragma config JTAGEN = OFF    // JTAG Port Enable->JTAG port is disabled
#pragma config BTSWP = OFF    // BOOTSWP Instruction Enable bit->BOOTSWP instruction is disabled

// FDS
#pragma config DSWDTPS = DSWDTPS1F    // Deep Sleep Watchdog Timer Postscale Select bits->1:68,719,476,736 (25.7 days)
#pragma config DSWDTOSC = LPRC    // DSWDT Reference Clock Select bit->DSWDT uses Low Power RC Oscillator (LPRC)
#pragma config DSBOREN = ON    // Deep Sleep Zero-Power BOR Enable bit->Deep Sleep BOR enabled in Deep Sleep
#pragma config DSWDTEN = ON    // Deep Sleep Watchdog Timer Enable bit->DSWDT enabled
#pragma config DSSWEN = ON    // Deep Sleep Software Control Select Bit->Deep Sleep enabled and controlled by the DSEN bit

// FDEVOPT1
#pragma config ALTCMPI = DISABLE    // Alternate Comparator Input Enable bit->C1INC, C2INC, and C3INC are on their standard pin locations
#pragma config TMPRPIN = OFF    // Tamper Pin Enable bit->TMPRN pin function is disabled
#pragma config TMPRWIPE = OFF    // RAM Based Entryption Key Wipe Enable bit->Cryptographic Engine Key RAM is not erased onTMPR pin events
#pragma config ALTVREF = ALTVREFDIS    // Alternate VREF location Enable->VREF is on a default pin (VREF+ on RA10 and VREF- on RA9)

// FBOOT
#pragma config BTMODE = SINGLE    // Boot Mode Select bits->Device is in Single Boot (legacy) mode

#include "mcc.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    INTERRUPT_Initialize();
    SPI1_Initialize();
    UART1_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // CF no clock failure; NOSC FRC; SOSCEN disabled; POSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active; 
    __builtin_write_OSCCONL((uint8_t) (0x0000 & 0x00FF));
    // CPDIV 1:1; PLLEN disabled; RCDIV FRC/2; DOZE 1:8; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3100;
    // STOR disabled; STORPOL Interrupt when STOR is 1; STSIDL disabled; STLPOL Interrupt when STLOCK is 1; STLOCK disabled; STSRC SOSC; STEN disabled; TUN Center frequency; 
    OSCTUN = 0x0000;
    // ROEN disabled; ROSEL FOSC; ROSIDL disabled; ROSWEN disabled; ROOUT disabled; ROSLP disabled; 
    REFOCONL = 0x0000;
    // RODIV 0; 
    REFOCONH = 0x0000;
    // ROTRIM 0; 
    REFOTRIML = 0x0000;
}

/**
 End of File
*/