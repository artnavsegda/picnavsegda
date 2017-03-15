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
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F97J60
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
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

// CONFIG1L
#pragma config WDT = OFF    // Watchdog Timer Enable bit->WDT disabled (control is placed on SWDTEN bit)
#pragma config STVR = ON    // Stack Overflow/Underflow Reset Enable bit->Reset on stack overflow/underflow enabled
#pragma config XINST = OFF    // Extended Instruction Set Enable bit->Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
#pragma config DEBUG = OFF    // Background Debugger Enable bit->Background debugger disabled; RB6 and RB7 configured as general purpose I/O pins

// CONFIG1H
#pragma config CP0 = OFF    // Code Protection bit->Program memory is not code-protected

// CONFIG2L
#pragma config FOSC = ECPLL    // Oscillator Selection bits->EC oscillator, PLL enabled and under software control, CLKO function on OSC2
#pragma config FOSC2 = ON    // Default/Reset System Clock Select bit->Clock selected by FOSC1:FOSC0 as system clock is enabled when OSCCON<1:0> = 00
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor enabled
#pragma config IESO = ON    // Two-Speed Start-up (Internal/External Oscillator Switchover) Control bit->Two-Speed Start-up enabled

// CONFIG2H
#pragma config WDTPS = 32768    // Watchdog Timer Postscaler Select bits->1:32768

// CONFIG3L
#pragma config EASHFT = ON    // External Address Bus Shift Enable bit->Address shifting enabled; address on external bus is offset to start at 000000h
#pragma config MODE = MM    // External Memory Bus->Microcontroller mode, external bus disabled
#pragma config BW = 16    // Data Bus Width Select bit->16-Bit Data Width mode
#pragma config WAIT = OFF    // External Bus Wait Enable bit->Wait states for operations on external memory bus disabled

// CONFIG3H
#pragma config CCP2MX = ON    // ECCP2 MUX bit->ECCP2/P2A is multiplexed with RC1
#pragma config ECCPMX = ON    // ECCP MUX bit->ECCP1 outputs (P1B/P1C) are multiplexed with RE6 and RE5; ECCP3 outputs (P3B/P3C) are multiplexed with RE4 and RE3
#pragma config ETHLED = ON    // Ethernet LED Enable bit->RA0/RA1 are multiplexed with LEDA/LEDB when Ethernet module is enabled and function as I/O when Ethernet is disabled

#include "mcc.h"

void SYSTEM_Initialize(void)
{

    INTERRUPT_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    SPI1_Initialize();
    TMR1_Initialize();
    Network_Init();
}

void OSCILLATOR_Initialize(void)
{
    // SCS Primary_or_INTOSC; OSTS intosc; IDLEN disabled; 
    OSCCON = 0x00;
    // PLLEN disabled; PPST0 disabled; PPRE divide_by_3; PPST1 divide_by_3; 
    OSCTUNE = 0x00;
    // Set the secondary oscillator
    
}


/**
 End of File
*/
