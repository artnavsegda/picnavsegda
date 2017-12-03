/*******************************************************************************
  PADC1 Generated Driver File

  Company:
    Microchip Technology Inc.

  File Name:
    padc1.c

  Summary:
    This is the generated driver implementation file for the PADC1 driver using MPLAB(c) Code Configurator

  Description:
    This source file provides implementations for driver APIs for PADC1.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.26
        Device            :  PIC24FJ128GC010
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.30
        MPLAB             :  MPLAB X 3.45
*******************************************************************************/

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

#include <xc.h>
#include "padc1.h"


/**
  Prototype:        void PADC1_Initialize(void)
  Input:            none
  Output:           none
  Description:      PADC1_Initialize is an
                    initialization routine that takes inputs from the GUI.
  Comment:          
  Usage:            PADC1_Initialize();
*/
void PADC1_Initialize(void)
{
    // ADSLP disabled; ADSIDL disabled; PWRLVL Low-Power mode; PUMPEN disabled; FORM Integer, Raw Data; ADCAL disabled; ADON enabled; 
    ADCON1 = (0x8000 | 0x01) & 0x7FFF; //Full power mode, Enable ADC later

    // NVCFG0 AVSS; PVCFG AVDD; REFPUMP disabled; BUFORG enabled; 
    ADCON2 = (0x0400 | 0x0300);
    ADCON2bits.BUFORG = 1;  // Result buffer organized as indexed mode

    // BUFOE disabled; BUFSTBY Normal; BUFEN disabled; BUFSIDL disabled; BUFSLP disabled; BUFREF 1.2 V; 
    BUFCON1 = 0x0000;   

    // SLEN3 disabled; SLEN2 disabled; SLEN1 disabled; ADRC FOSC/2; SLEN0 disabled; ADCS 32; 
    ADCON3 = 0x001F;
        
    //Set Sample lists

    // MULCHEN One at a time; CTMEN disabled; CM Matching is disabled; SLINT Interrupt after auto-scan completion on match; WM All conversion results saved; SAMC 15 tad; ASEN enabled; 
    ADL0CONH = 0xA00F;
    ADL0CONHbits.SLINT = 0x01; //interrupt after autoscan completion
    // THSRC Buffer register; SLTSRC Manual Trigger:Single Trigger; SLEN enabled; SLENCLR disabled; SLSIZE 7; SAMP disabled; 
    ADL0CONL = (0x8006 & 0x7FFF) | 0x4000;  // open manual switch and Enable sample list later
    
    //Set table registers
    // DIFF disabled; UCTMU disabled; ADCH AN22; 
    ADTBL5 =  0x16;
    // UCTMU disabled; ADCH AN19; DIFF disabled; 
    ADTBL0 =  0x13;
    // UCTMU disabled; ADCH AN23; DIFF disabled; 
    ADTBL4 =  0x17;
    // UCTMU disabled; ADCH AN12; DIFF disabled; 
    ADTBL2 =  0xc;
    // UCTMU disabled; ADCH AN28; DIFF disabled; 
    ADTBL3 =  0x1c;
    // UCTMU disabled; ADCH AN21; DIFF disabled; 
    ADTBL1 =  0x15;
    // DIFF disabled; UCTMU disabled; ADCH AN5; 
    ADTBL6 =  0x5;

    // Set table pointer registers
    ADL0PTR =0;
    ADL1PTR =0;
    ADL2PTR =0;
    ADL3PTR =0;

    // TBLSEL ADTBL0; COUNT 0; 
    ACCONL = 0x0000;
    // ACIE disabled; ACEN disabled; 
    ACCONH = 0x0000; 

    
    //Enable ADC
    ADCON1bits.ADON = 1; 
        
    //Poll the ADREADY bit
    while(!(PADC1_IsReadyForConversion()));
    
    // Start calibration   
    ADCON1bits.ADCAL = 1; 
        
    //Poll the ADREADY bit
    while(!(PADC1_IsReadyForConversion()));

    //Set ADC timer register
    // ADTMRPR 0; 
    ADTMRPR = 0x0000;

   //Enable sample list

    ADL0CONLbits.SLEN = 1; // Enable Sample list 1
    ADL0CONLbits.SAMP = 0; // Close sample switch
}

bool PADC1_IsReadyForConversion(void)
{
    return(ADSTATHbits.ADREADY);
}

bool PADC1_IsBusyInConversion(void)
{
    return(ADSTATHbits.ADBUSY);
}

void PADC1_SampleList0ManualConversionStart(void)
{
    ADL0CONLbits.SAMP = 1;
    ADL0CONLbits.SAMP = 0;
}

void PADC1_SampleList1ManualConversionStart(void)
{
    ADL1CONLbits.SAMP = 1;
    ADL1CONLbits.SAMP = 0;
}

void PADC1_SampleList2ManualConversionStart(void)
{
    ADL2CONLbits.SAMP = 1;
    ADL2CONLbits.SAMP = 0;
}

void PADC1_SampleList3ManualConversionStart(void)
{
    ADL3CONLbits.SAMP = 1;
    ADL3CONLbits.SAMP = 0;
}

void PADC1_SampleList0Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
    //threshold compare,CTMU ,Multichannel disabled
   ADL0CONHbits.ASEN = samplelistconfig->autoscan; //sequential scan
   ADL0CONHbits.SLINT = samplelistconfig->autoscan; //auto or sequential scan;
   ADL0CONHbits.SAMC = samplelistconfig->chargetime;
   ADL0CONHbits.WM = 0;
   ADL0CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL0CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL0PTR = 0;
   //enable sample list
   ADL0CONLbits.SLEN = 1; 
}

void PADC1_SampleList1Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
    //threshold compare,CTMU ,Multichannel disabled
   ADL1CONHbits.ASEN = samplelistconfig->autoscan; //auto or sequential scan
   ADL1CONHbits.SLINT = (samplelistconfig->autoscan)?1:2;
   ADL1CONHbits.SAMC = samplelistconfig->chargetime;
   ADL1CONHbits.WM = 0;
   ADL1CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL1CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL1PTR = 0;
   //enable sample list
   ADL1CONLbits.SLEN = 1;
}

void PADC1_SampleList2Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
     //threshold compare,CTMU ,Multichannel disabled
   ADL2CONHbits.ASEN = samplelistconfig->autoscan; //auto or sequential scan
   ADL2CONHbits.SLINT = (samplelistconfig->autoscan)?1:2;
   ADL2CONHbits.SAMC = samplelistconfig->chargetime;
   ADL2CONHbits.WM = 0;
   ADL2CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL2CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL2PTR = 0;
   //enable sample list
   ADL2CONLbits.SLEN = 1;
}

void PADC1_SampleList3Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
    //threshold compare,CTMU ,Multichannel disabled
   ADL3CONHbits.ASEN = samplelistconfig->autoscan; //auto or sequential scan
   ADL3CONHbits.SLINT = 1;
   ADL3CONHbits.SAMC = samplelistconfig->chargetime;
   ADL3CONHbits.WM = 0;
   ADL3CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL3CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL3PTR = 0;
   //enable sample list
   ADL3CONLbits.SLEN = 1;
}

void PADC1_SampleList0Disable(void)
{
    ADL0CONLbits.SLEN = 0;
}

void PADC1_SampleList1Disable(void)
{
    ADL1CONLbits.SLEN = 0;
}

void PADC1_SampleList2Disable(void)
{
    ADL2CONLbits.SLEN = 0;
}

void PADC1_SampleList3Disable(void)
{
    ADL3CONLbits.SLEN = 0;
}        

void PADC1_SetADCChannel( uint8_t tableRegIndex, uint8_t adcChannel, bool diffEnable )
{
    uint16_t *tablereg;
    tablereg = (uint16_t *)&ADTBL0 + tableRegIndex;
    *tablereg = adcChannel + (diffEnable << 14);
}

bool PADC1_SampleList0ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL0IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL0STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList1ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL1IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL1STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList2ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL2IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL2STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList3ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL3IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL3STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_AccumulationResultGet(uint32_t *accBuffer)
{
    bool dataValid = false;
    if(ADSTATLbits.ACCIF != 0)
    {
       *accBuffer = ACRESH; // Read result from accumulator.
       *accBuffer <<= 16;
       *accBuffer |= ACRESL;
       
       //Reload accumlator values
       ACRESL = 0; // Set initial value for the accumulator.
       ACRESH = 0;
       ACCONLbits.COUNT = (uint8_t)PADC1_ACC_NUM_SAMPLES; // Accumulate samples again.
       ACCONHbits.ACEN = 1; // Reenable accumulator.
       ADSTATLbits.ACCIF = 0; // Reset accumulator interrupt flag.
       dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList0IsConversionDone(void)
{
   return(ADSTATLbits.SL0IF);
}

bool PADC1_SampleList1IsConversionDone(void)
{
   return(ADSTATLbits.SL1IF);
}

bool PADC1_SampleList2IsConversionDone(void)
{
   return(ADSTATLbits.SL2IF);
}

bool PADC1_SampleList3IsConversionDone(void)
{
   return(ADSTATLbits.SL3IF);
}

bool PADC1_IsAccumulationDone(void)
{
   return(ADSTATLbits.ACCIF);
}

void PADC1_Tasks( void )
{
    if(IFS0bits.AD1IF)
    {
        IFS0bits.AD1IF = 0;
    }
}