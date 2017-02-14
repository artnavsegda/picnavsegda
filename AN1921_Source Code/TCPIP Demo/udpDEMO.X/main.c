/**
  Main file for implementing the UDP Demo functionality
	
  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    UDP Demo

  Description:
    This is the main file containing the UDP protocol Demo.

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
#include "lcd.h"
#include "syslog.h"
#include "tcpip_config.h"
#include "network.h"
#include "ipv4.h"
#include "udpv4.h"
#include "ethernet_driver.h"
#include "led_driver.h"
#include "tcpv4.h"
#include "udp_demo.h"

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

void main(void)
{
    time_t t;
    unsigned long ip, old_ip;
    char str[32];
    bool no_ip_display = true;
    time_t ip_timer;    

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
    
    time(&ip_timer);
    ip_timer += 1;    
    
    while(1)
    {
        time_t now_p;
        time(&now_p);
        Network_Manage();
        time(&t);
        
        ip = IPV4_GetMyIP();
        // make sure we update the IP if we get another one from the DHCP server
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
        if(now_p >= ip_timer)
        {
            DEMO_UDP_IPLockTimer(); //check whether IP is claimed or released
            DEMO_UDP_Send();
            ip_timer += 1;
        }
    }

    return;
}
