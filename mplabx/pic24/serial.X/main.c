#pragma config FNOSC = FRC              // Initial Oscillator Select (Fast RC Oscillator (FRC))

#include "xc.h"
#include "PPS.h"
#include "uart.h"
#define FCY 4000000
#include <libpic30.h> 
#include <stdio.h>
#define BAUD_RATE (9600) // bps
#include "setbaud.h"

int main(void)
{
    __C30_UART=1; // Divert printf output to UART1
    int i = 0;
    
    iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U1TX);    //Assing U1TX to pin RP18
    
#if defined(__PIC24FJ256GB110__)
    OpenUART1(UART_EN,UART_TX_ENABLE,CLOSEST_UBRG_VALUE);
#elif defined(__PIC24FJ128GC010__)
    U1MODE = (0x8008 & ~(1<<15));
    U1STA = 0x0000;
    U1BRG = 0x0067;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1; 
#endif
    
    printf("Hello world\r\n");
    
    while (1)
    {
        printf("%d\r\n",i++);
        __delay_ms(1000);
    }
    
    return 0;
}
