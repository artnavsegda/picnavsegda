#include "xc.h"
#include "config.h"

int main(void)
{
    uint8_t _data;
    __C30_UART=1; // Divert printf output to UART1
    int i = 0;
    
    iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U1TX);    //Assing U1TX to pin RP18
    iPPSOutput(OUT_PIN_PPS_RP23,OUT_FN_PPS_SS1OUT);
    iPPSInput(IN_FN_PPS_SDI1,IN_PIN_PPS_RP20);
    iPPSOutput(OUT_PIN_PPS_RP6,OUT_FN_PPS_SDO1);
    iPPSOutput(OUT_PIN_PPS_RP2,OUT_FN_PPS_SCK1OUT);
    
    
    OpenUART1(UART_EN,UART_TX_ENABLE,CLOSEST_UBRG_VALUE);
    printf("MCU started\r\n");
    
    OpenSPI1(SPI_MODE16_ON |SPI_SMP_ON | MASTER_ENABLE_ON | SEC_PRESCAL_7_1, FRAME_ENABLE_OFF,SPI_ENABLE);
    printf("SPI open\r\n");
    
    while(_RD1);
    _LATD2 = 0;
    WriteSPI1(0x10|0); while(SPI1_Tx_Buf_Full);
    WriteSPI1(0x0); while(SPI1_Tx_Buf_Full);
    if (DataRdySPI1()) _data = ReadSPI1(0xFF);
    _LATD2 = 1;
    printf("chip id %d\n\r",_data >> 4);
    
    while (1)
    {
        printf("%d\r\n",i++);
        __delay_ms(1000);
    }
    
    return 0;
}
