#include "uart.h"
#define THIS_IS_STACK_APPLICATION
#define USE_AND_OR /* To enable AND_OR mask setting */
#include "TCPIP Stack/TCPIP.h"
#include "main.h"
#include "setbaud.h"

APP_CONFIG AppConfig;
BYTE AN0String[8];

static void InitializeBoard(void)
{
    // UART
#if defined(STACK_USE_UART)
    UARTTX_TRIS = 0;
    UARTRX_TRIS = 1;
    UMODE = UART_EN;            // Set UARTEN.  Note: this must be done before setting UTXEN
    USTA = UART_TX_ENABLE;        // UTXEN set
    UBRG = CLOSEST_UBRG_VALUE;
#endif 

#if defined(ENC_CS_TRIS)
    ENC_CS_IO = 1;
    ENC_CS_TRIS = 0;
#endif
    
#if defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GB210__)
    __builtin_write_OSCCONL(OSCCON & 0xBF);  // Unlock PPS
    
    // Configure SPI1 PPS pins (ENC28J60/ENCX24J600/MRF24W or other PICtail Plus cards)
    RPOR0bits.RP0R = 8;         // Assign RP0 to SCK1 (output)
    RPOR7bits.RP15R = 7;        // Assign RP15 to SDO1 (output)
    RPINR20bits.SDI1R = 23;     // Assign RP23 to SDI1 (input)
   
    // Configure UART2 PPS pins
    RPINR19bits.U2RXR = 10;     // Assign RF4/RP10 to U2RX (input)
    RPOR8bits.RP17R = 5;        // Assign RF5/RP17 to U2TX (output)
    
    // Configure INT1 PPS pin (MRF24W Wi-Fi PICtail Plus interrupt signal when in SPI slot 1)
    RPINR0bits.INT1R = 33;    // Assign RE8/RPI33 to INT1 (input)

    // Configure INT3 PPS pin (MRF24W Wi-Fi PICtail Plus interrupt signal when in SPI slot 2)
    RPINR1bits.INT3R = 40;    // Assign RC3/RPI40 to INT3 (input)

    __builtin_write_OSCCONL(OSCCON | 0x40); // Lock PPS
#endif
}

static void InitAppConfig(void)
{
    memset((void*)&AppConfig, 0x00, sizeof(AppConfig));
    AppConfig.Flags.bIsDHCPEnabled = FALSE;
    AppConfig.Flags.bInConfigMode = TRUE;

    AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2<<8ul | MY_DEFAULT_IP_ADDR_BYTE3<<16ul | MY_DEFAULT_IP_ADDR_BYTE4<<24ul;
    AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
    AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2<<8ul | MY_DEFAULT_MASK_BYTE3<<16ul | MY_DEFAULT_MASK_BYTE4<<24ul;
    AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
    AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2<<8ul | MY_DEFAULT_GATE_BYTE3<<16ul | MY_DEFAULT_GATE_BYTE4<<24ul;
    AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2<<8ul  | MY_DEFAULT_PRIMARY_DNS_BYTE3<<16ul  | MY_DEFAULT_PRIMARY_DNS_BYTE4<<24ul;
    AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  | MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul;

    memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*)MY_DEFAULT_HOST_NAME, 16);
    FormatNetBIOSName(AppConfig.NetBIOSName);
    
}

int main(void)
{
    InitializeBoard();
    InitAppConfig();
    StackInit();
    
    while(1)
    {
        StackTask();
        StackApplications();
        
        #if defined(STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)
        GenericTCPClient();
        #endif

        #if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)
        GenericTCPServer();
        #endif

        #if defined(STACK_USE_BERKELEY_API)
        BerkeleyTCPClientDemo();
        BerkeleyTCPServerDemo();
        BerkeleyUDPClientDemo();
        #endif
    }
    
    return 0;
}
