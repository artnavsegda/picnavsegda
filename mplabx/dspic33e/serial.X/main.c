#pragma config FNOSC = FRC              // Initial Oscillator Source Selection Bits (Internal Fast RC (FRC))

#define FCY 4000000 // FOSC/2
#define BAUDRATE 9600
#define BRGVAL ((FCY/BAUDRATE)/16)-1

#include "xc.h"
#include "uart.h"
#include <libpic30.h> 
#include <stdio.h>

int main(void)
{
    __C30_UART=1; // Divert printf output to UART1
    int i = 0;
    
    OpenUART1(UART_EN & UART_IDLE_CON & UART_IrDA_DISABLE & UART_MODE_SIMPLEX & UART_UEN_00 & UART_DIS_WAKE & UART_EN_LOOPBACK & UART_EN_ABAUD & UART_BRGH_SIXTEEN & UART_NO_PAR_8BIT & UART_1STOPBIT, UART_INT_TX_BUF_EMPTY & UART_TX_ENABLE & UART_INT_RX_3_4_FUL & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR & UART_IrDA_POL_INV_ZERO & UART_SYNC_BREAK_DISABLED, BRGVAL);
    
    printf("Hello world\r\n");
    
    while (1)
    {
        printf("%d\r\n",i++);
        __delay_ms(1000);
    }
    
    
    return 0;
}

