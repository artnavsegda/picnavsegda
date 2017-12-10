#include "config.h"

int main(void)
{
    __C30_UART=1; // Divert printf output to UART1
    int i = 0;
    
    iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U1TX);    //Assing U1TX to pin RP18
    OpenUART1(UART_EN,UART_TX_ENABLE,CLOSEST_UBRG_VALUE);
    printf("Hello world\r\n");
    
    while (1)
    {
        printf("%d\r\n",i++);
        __delay_ms(1000);
    }
    
    return 0;
}
