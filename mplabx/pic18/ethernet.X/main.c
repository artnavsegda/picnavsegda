#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "hardware.h"
#include "syslog.h"
#include "tcpip_config.h"
#include "network.h"
#include "ipv4.h"
#include "udpv4.h"
#include "ethernet_driver.h"
#include "tcpv4.h"
#include "rtcc.h"


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

/*******************************************************************************/
                            /* TCP Demo */
/*******************************************************************************/

//Implement an echo server over TCP
void DEMO_TCP_EchoServer(void)
{
    // create the socket for the TCP Server
    static tcpTCB_t port7TCB;

    // create the TX and RX Server's buffers
    static uint8_t rxdataPort7[20];
    static uint8_t txdataPort7[20];

    uint16_t rxLen, txLen, i;
    socketState_t socket_state;

    socket_state = TCP_SocketPoll(&port7TCB);

    switch(socket_state)
    {
        case NOT_A_SOCKET:
            // Inserting and initializing the socket
            TCP_SocketInit(&port7TCB);
            break;
        case SOCKET_CLOSED:
            //configure the local port
            TCP_Bind(&port7TCB, 7);
            // add receive buffer
            TCP_InsertRxBuffer(&port7TCB, rxdataPort7, sizeof(rxdataPort7));
            // start the server
            TCP_Listen(&port7TCB);
            break;
        case SOCKET_CONNECTED:
            // check if the buffer was sent, if yes we can send another buffer
            if(TCP_SendDone(&port7TCB))
            {
                // check to see  if there are any received data
                rxLen = TCP_GetRxLength(&port7TCB);
                if(rxLen > 0)
                {
                    rxLen = TCP_GetReceivedData(&port7TCB);

                    //simulate some buffer processing
                    for(i = 0; i < rxLen; i++)
                    {
                        txdataPort7[i] = rxdataPort7[i];
                    }

                    // reuse the RX buffer
                    TCP_InsertRxBuffer(&port7TCB, rxdataPort7, sizeof(rxdataPort7));
                    txLen = rxLen;
                    //send data back to the source
                    TCP_Send(&port7TCB, txdataPort7, txLen);
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
    time_t t;
    unsigned long ip, old_ip;
    char str[32];
    bool no_ip_display = true;

    Network_Init();
    SYSLOG_Init();

    // enable the high priority interrupts
    IPEN = 1;
    GIEH = 1;
    GIEL = 1;

    SYSLOG_Write("Waiting for Link");
    Network_WaitForLink();
    SYSLOG_Write("Link started");

    while(1)
    {
        Network_Manage();
        time(&t);

        ip = IPV4_GetMyIP();
        // make sure we update the IP if we get another from DHCP
        if((no_ip_display) || (old_ip != ip))
        {
            old_ip = ip;
            memset(str,0,sizeof(str));
            sprintf(str,"%d.%d.%d.%d",((char*)&ip)[3],((char*)&ip)[2],((char*)&ip)[1],((char*)&ip)[0]);
            SYSLOG_Write(str);
            no_ip_display = false;
        }
        DEMO_TCP_EchoServer();
    }
    return;
}
