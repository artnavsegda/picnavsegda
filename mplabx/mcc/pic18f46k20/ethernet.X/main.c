/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F46K20
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/TCPIPLibrary/syslog.h"
#include "mcc_generated_files/TCPIPLibrary/tcpv4.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "modbus.h"

/*******************************************************************************/
                            /* TCP Demo */
/*******************************************************************************/

//Implement an echo server over TCP
void DEMO_TCP_EchoServer(void)
{
    // create the socket for the TCP Server
    static tcpTCB_t modbusTCB;

    // create the TX and RX Server's buffers
    static mbframestruct datamodbus;
    static mbframestruct datamodbus;

    uint16_t rxLen, txLen, i;
    socketState_t socket_state;

    socket_state = TCP_SocketPoll(&modbusTCB);

    switch(socket_state)
    {
        case NOT_A_SOCKET:
            // Inserting and initializing the socket
            TCP_SocketInit(&modbusTCB);
            break;
        case SOCKET_CLOSED:
            //configure the local port
            TCP_Bind(&modbusTCB, 502);
            // add receive buffer
            TCP_InsertRxBuffer(&modbusTCB, (unsigned char *)&datamodbus, sizeof(datamodbus));
            // start the server
            TCP_Listen(&modbusTCB);
            break;
        case SOCKET_CONNECTED:
            // check if the buffer was sent, if yes we can send another buffer
            if(TCP_SendDone(&modbusTCB))
            {
                // check to see  if there are any received data
                rxLen = TCP_GetRxLength(&modbusTCB);
                if(rxLen > 0)
                {
                    rxLen = TCP_GetReceivedData(&modbusTCB);

                    //simulate some buffer processing
                    //for(i = 0; i < rxLen; i++)
                    //{
                    //    txdatamodbus[i] = rxdatamodbus[i];
                    //}

                    txLen = modbus(&datamodbus);
                    //send data back to the source
                    TCP_Send(&modbusTCB, (unsigned char *)&datamodbus, txLen);
                    // reuse the RX buffer
                    TCP_InsertRxBuffer(&modbusTCB, (unsigned char *)&datamodbus, sizeof(datamodbus));
                }
            }
            break;
        default:
            // we should not end up here
            break;
    }
}

/*
                         Main application
 */
void main(void)
{
    __delay_ms(500); // reserve delay
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("hello ethernet world\r\n");
    
    while (1)
    {
        // Add your application code
        Network_Manage();
        DEMO_TCP_EchoServer();
    }
}
/**
 End of File
*/