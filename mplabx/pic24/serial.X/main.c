/*
 * File:   main.c
 * Author: artnavsegda
 *
 * Created on December 2, 2017, 8:45 AM
 */

#include "xc.h"
#include "PPS.h"
#include "uart.h"
#define FCY 8000000
#include <libpic30.h> 
#include <stdio.h>

int main(void)
{
    int i = 0;
    
    iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U1TX);    //Assing U1TX to pin RP18
    
    OpenUART1(UART_EN,UART_TX_ENABLE,25);
    
    printf("Hello world\r\n");
    
    while (1)
    {
        printf("%d\r\n",i++);
        __delay_ms(1000);
    }
    
    return 0;
}
