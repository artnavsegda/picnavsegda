/**
  Main file for implementing the Demo functionality

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    Brief Description of the file (will placed in a table if using Doc-o-Matic)

  Description:
    This section is for a description of the file.  It should be in complete
    sentences describing the purpose of this file.

 */

/*

©  [2015] Microchip Technology Inc. and its subsidiaries.  You may use this software
and any derivatives exclusively with Microchip products.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS,
IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF
NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS
INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE
IN ANY APPLICATION.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL
OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED
TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY
OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S
TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED
THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS.

*/

#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "hardware.h"
#include "../board_support_package/picdem2_net/adc.h"
#include "../board_support_package/picdem2_net/rtcc.h"
#include "lcd.h"
#include "syslog.h"
#include "tcpip_config.h"
#include "network.h"
#include "ipv4.h"
#include "udpv4.h"
#include "ethernet_driver.h"
#include "led_driver.h"
#include "tcpv4.h"


void interrupt high_priority high_isr(void)
{
    rtcc_handler();
}

void interrupt low_priority low_isr(void)
{
#ifdef USE_ENCx97J60
    ETH_EventHandler();
#else
    NOP();
#endif
}


/*******************************************************************************
                            TCP Client Demo Initializations
/*******************************************************************************/

//keep remote IP address/Port Number for the TCP Client Demo
sockaddr_in_t remoteSocket;

void DEMO_TCP_Client(void)
{
    // create the socket for the TCP Client
    static tcpTCB_t port60TCB;

    //// create the TX and RX Client's buffers
    static uint8_t rxdataPort60[50];
    static uint8_t txdataPort60[80];

    static time_t t_client, t_clientOld;
    
    uint16_t rx_len;
    socketState_t socketState;
    rx_len = 0;
    uint16_t temperature, pot;
    char strTmp[17];
    uint8_t ledNr;

    socketState = TCP_SocketPoll(&port60TCB);

    time(&t_client);

    switch(socketState)
    {
        case NOT_A_SOCKET:
            // Inserting and initializing the socket
            TCP_SocketInit(&port60TCB);
            break;
        case SOCKET_CLOSED:
            // if the socket is closed we will try to connect again
            if(t_client >= t_clientOld)
            {
                // try to connect once at 2 seconds
                t_clientOld = t_client + 2;
                TCP_InsertRxBuffer(&port60TCB, rxdataPort60, sizeof(rxdataPort60));
                TCP_Connect(&port60TCB, &remoteSocket);
            }
            break;
        case SOCKET_CONNECTED:
            // implement an echo client over TCP
            // check if the previous buffer was sent
            if (TCP_SendDone(&port60TCB))
            {
                rx_len = TCP_GetReceivedData(&port60TCB);
                // handle the incoming data
                if(rx_len > 0)
                {
                    // check for "led x on/off" command
                    if (rx_len > 16) {
                        rxdataPort60[16] = 0;
                    } else {
                        rxdataPort60[rx_len] = 0;
                    }

                    ledNr = rxdataPort60[4];
                    if((ledNr >= '0') && (ledNr < '8')) {
                        ledNr = ledNr - '0';
                    }

                    if(rxdataPort60[0] == 'l' && rxdataPort60[1] == 'e' && rxdataPort60[2] == 'd') {
                        if(rxdataPort60[6] == 'o' && rxdataPort60[7] == 'n') {
                                PORTJ = PORTJ | (1 << ledNr);
                        }else {
                            if(rxdataPort60[6] == 'o' && rxdataPort60[7] == 'f' && rxdataPort60[8] == 'f') {
                                    PORTJ = PORTJ & (~(1 << ledNr));
                            }
                        }
                    } else {
                        // printing on LCD the fist 8 characters
                        memset(strTmp,' ',sizeof(strTmp));
                        lcd_goto2(0);
                        lcd_puts(strTmp);
                        sprintf(strTmp,"%s",rxdataPort60);
                        lcd_goto2(0);
                        lcd_puts(strTmp);
                    }

                    // reuse the RX buffer
                    TCP_InsertRxBuffer(&port60TCB, rxdataPort60, sizeof(rxdataPort60));
                }

                if(t_client >= t_clientOld)
                {
                    // send board status message only once at 2 seconds
                    t_clientOld = t_client + 2;
                    temperature = ADC_GetConversion(channel_AN3);
                    pot = ADC_GetConversion(channel_AN2);
                    sprintf(txdataPort60,"Temperature: 0x%3x; LED: 0x%1x; Buttons: 0x%1x; Pot: 0x%3x \n", temperature, PORTJ, (PORTB & 0x0F), pot);
                    //send data back to the source
                    TCP_Send(&port60TCB, txdataPort60, strlen(txdataPort60));
                }
            }
            break;
        default:
            // we should not end up here
            break;
    }
}

void main(void)
{
    unsigned long ip, old_ip;
    char str[32];
    bool no_ip_display = true;

    initHW();
    Network_Init();
    SYSLOG_Init();

    // enable the high priority interrupts
    IPEN = 1;
    GIEH = 1;
    GIEL = 1;

    SYSLOG_Write("Waiting for Link");
    Network_WaitForLink();
    SYSLOG_Write("Link started");

    //-----------------------------------
    // setup the Server IP Address and Port number:
    remoteSocket.addr.s_addr = MAKE_IPV4_ADDRESS(10,14,5,141);
    remoteSocket.port = 60;
    //-----------------------------------

    while(1)
    {
        time_t now_p;
        time(&now_p);
        Network_Manage();
        ip = IPV4_GetMyIP();
        // make sure we update the IP if we get another from DHCP
        if((no_ip_display) || (old_ip != ip))
        {
            old_ip = ip;
            memset(str,0,sizeof(str));
            sprintf(str,"%d.%d.%d.%d",((char*)&ip)[3],((char*)&ip)[2],((char*)&ip)[1],((char*)&ip)[0]);
            lcd_goto1(0);
            lcd_puts(str);
            SYSLOG_Write(str);
            no_ip_display = false;
        }
        DEMO_TCP_Client();
    }
    return;
}
