#include <xc.h>
#include "PPS.h"
#include <stdio.h>
#define FCY 8000000
#include <libpic30.h> 

// PIC24FJ128GC010 CONFIGURATION SETTINGS

_CONFIG4(PLLDIV_DIV2 & IOL1WAY_OFF)
_CONFIG3(BOREN_OFF)
_CONFIG2(POSCMD_HS & FNOSC_FRC & FCKSM_CSECME)
_CONFIG1(FWDTEN_WDT_SW & ICS_PGx2)
        
// The ADC conversion result. 
volatile unsigned int channel_2;
volatile unsigned int channel_38;

int main()
{
    iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U1TX);
    
    U1MODE = (0x8008 & ~(1<<15));
    U1STA = 0x0000;
    U1BRG = 0x0067;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1; 
    
    printf("MCU started\r\n");    
    
    // ANALOG INPUTS CONFIGURATION
    // 2 analog inputs will be sampled.
    TRISBbits.TRISB2 = 1;                    // AN2(RB2)
    ANSBbits.ANSB2 = 1;
    TRISAbits.TRISA14 = 1;                   // AN38(RA14)
    ANSAbits.ANSA14 = 1;
    
    // GLOBAL SETTINGS
    ADCON1=0;
    ADCON2=0;
    ADCON3=0;
    // Configure the A/D voltage references.
    ADCON2bits.PVCFG = 0;                    // Vref+ = AVdd
    ADCON2bits.NVCFG = 0;                    // Vref- = AVss
    // Configure the A/D clock.
    ADCON3bits.ADRC = 0;                     // Conversion clock derived from system clock.
    ADCON3bits.ADCS = 15;                    // Divide system clock by 16(TAD = 1uS @ 16 MIPS).
    // Configure buffer storage settings and interrupt generation.
    ADCON1bits.FORM = 0;                     // Output format is unsigned integer.
    ADCON2bits.BUFORG = 1;                   // Result buffer is an indexed buffer.
    // Configure power-saving.
    ADCON1bits.PWRLVL = 0;                   // Low power, reduced frequency operation.
    
    // Sample List SETTINGS
    ADL0CONL = 0;
    ADL0CONH = 0;
    ADL0CONLbits.SLSIZE = 2-1;               // Sample list length: 2 channels.
    // Sampling settings.
    ADL0CONHbits.ASEN = 1;                   // Enable auto-scan.
    ADL0CONHbits.SLINT = 1;                  // Interrupt after auto-scan completion.
    ADL0CONHbits.SAMC = 15;                  // Sample time is 15 TAD.
    ADL0CONLbits.SLTSRC = 0;                 // Single trigger generated when SAMP is cleared.
    ADL0PTR = 0;                              // Start from the first list entry.
    // Threshod compare settings.
    ADL0CONHbits.CM = 0;                     // Disable threshold compare.
    // Channels selection.
    ADTBL0bits.ADCH = 2;                     // Channel #2.
    ADTBL1bits.ADCH = 38;                    // Channel #38.
    
    // ENABLE A/D
    ADCON1bits.ADON = 1;                  // Enable A/D.
    while(ADSTATHbits.ADREADY == 0);      // Wait for ready flag set.
    ADL0CONLbits.SAMP = 1;            // Close sample switch.
    ADL0CONLbits.SLEN = 1;                // Enable sample list.
    
    // CONVERSION
    while(1)
    {
        IFS0bits.AD1IF = 0;               // Start conversion.
            ADL0CONLbits.SAMP = 0;            // Wait for the result.
        while(IFS0bits.AD1IF == 0);
        ADL0CONLbits.SAMP = 1;            // Close the sample switch.
        channel_2 = ADRES0;           // Read result for the channel #2.
        channel_38 = ADRES1;          // Read result for the channel #38.
        
        printf("%d %d\r\n",channel_2,channel_38);
        
        __delay_ms(1000);
    }
    
}