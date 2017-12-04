#define THIS_IS_STACK_APPLICATION
#include "TCPIP Stack/TCPIP.h"
#include "main.h"

APP_CONFIG AppConfig;
BYTE AN0String[8];

static void InitializeBoard(void)
{
    // UART
    #if defined(STACK_USE_UART)

        #if defined(__PIC24E__) || defined(__dsPIC33E__)
            #if defined (ENC_CS_IO) || defined (WF_CS_IO)   // UART to be used in case of ENC28J60 or MRF24W
                __builtin_write_OSCCONL(OSCCON & 0xbf);
                RPOR9bits.RP101R = 3; //Map U2TX to RF5
                RPINR19bits.U2RXR = 0;
                RPINR19bits.U2RXR = 0x64; //Map U2RX to RF4
                __builtin_write_OSCCONL(OSCCON | 0x40);
            #endif
            #if(ENC100_INTERFACE_MODE == 0)                 // UART to be used only in case of SPI interface with ENC624Jxxx
                    __builtin_write_OSCCONL(OSCCON & 0xbf);
                RPOR9bits.RP101R = 3; //Map U2TX to RF5
                RPINR19bits.U2RXR = 0;
                RPINR19bits.U2RXR = 0x64; //Map U2RX to RF4
                __builtin_write_OSCCONL(OSCCON | 0x40);

            #endif
        #endif

        UARTTX_TRIS = 0;
        UARTRX_TRIS = 1;
        UMODE = 0x8000;            // Set UARTEN.  Note: this must be done before setting UTXEN

        #if defined(__C30__)
            USTA = 0x0400;        // UTXEN set
            #define CLOSEST_UBRG_VALUE ((GetPeripheralClock()+8ul*BAUD_RATE)/16/BAUD_RATE-1)
            #define BAUD_ACTUAL (GetPeripheralClock()/16/(CLOSEST_UBRG_VALUE+1))
        #else    //defined(__C32__)
            USTA = 0x00001400;        // RXEN set, TXEN set
            #define CLOSEST_UBRG_VALUE ((GetPeripheralClock()+8ul*BAUD_RATE)/16/BAUD_RATE-1)
            #define BAUD_ACTUAL (GetPeripheralClock()/16/(CLOSEST_UBRG_VALUE+1))
        #endif
    
        #define BAUD_ERROR ((BAUD_ACTUAL > BAUD_RATE) ? BAUD_ACTUAL-BAUD_RATE : BAUD_RATE-BAUD_ACTUAL)
        #define BAUD_ERROR_PRECENT    ((BAUD_ERROR*100+BAUD_RATE/2)/BAUD_RATE)
        #if (BAUD_ERROR_PRECENT > 3)
            #warning UART frequency error is worse than 3%
        #elif (BAUD_ERROR_PRECENT > 2)
            #warning UART frequency error is worse than 2%
        #endif
    
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
