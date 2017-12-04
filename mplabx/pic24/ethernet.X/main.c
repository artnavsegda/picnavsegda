#define THIS_IS_STACK_APPLICATION
#include "TCPIP Stack/TCPIP.h"
#include "main.h"

APP_CONFIG AppConfig;
BYTE AN0String[8];

static void InitializeBoard(void)
{
#if defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GB210__)
    __builtin_write_OSCCONL(OSCCON & 0xBF);  // Unlock PPS
    
    // Configure SPI1 PPS pins (ENC28J60/ENCX24J600/MRF24W or other PICtail Plus cards)
    RPOR0bits.RP0R = 8;         // Assign RP0 to SCK1 (output)
    RPOR7bits.RP15R = 7;        // Assign RP15 to SDO1 (output)
    RPINR20bits.SDI1R = 23;     // Assign RP23 to SDI1 (input)

    // Configure SPI2 PPS pins (25LC256 EEPROM on Explorer 16)
    RPOR10bits.RP21R = 11;      // Assign RG6/RP21 to SCK2 (output)
    RPOR9bits.RP19R = 10;       // Assign RG8/RP19 to SDO2 (output)
    RPINR22bits.SDI2R = 26;     // Assign RG7/RP26 to SDI2 (input)
    
    // Configure UART2 PPS pins (MAX3232 on Explorer 16)
    #if !defined(ENC100_INTERFACE_MODE) || (ENC100_INTERFACE_MODE == 0) || defined(ENC100_PSP_USE_INDIRECT_RAM_ADDRESSING)
    RPINR19bits.U2RXR = 10;     // Assign RF4/RP10 to U2RX (input)
    RPOR8bits.RP17R = 5;        // Assign RF5/RP17 to U2TX (output)
    #endif
    
    // Configure INT1 PPS pin (MRF24W Wi-Fi PICtail Plus interrupt signal when in SPI slot 1)
    RPINR0bits.INT1R = 33;    // Assign RE8/RPI33 to INT1 (input)

    // Configure INT3 PPS pin (MRF24W Wi-Fi PICtail Plus interrupt signal when in SPI slot 2)
    RPINR1bits.INT3R = 40;    // Assign RC3/RPI40 to INT3 (input)

    __builtin_write_OSCCONL(OSCCON | 0x40); // Lock PPS
#endif
}

int main(void)
{
    InitializeBoard();
    
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
