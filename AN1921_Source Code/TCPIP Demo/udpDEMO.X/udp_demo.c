#include <xc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adc.h"
#include "udpv4.h"
#include "ipv4.h"
#include "led_driver.h"
#include "lcd.h"
#include "adc.h"
#include "udp_demo.h"
#include "udpv4_port_handler_table.h"


/******************************************************************************************************/
                                          /* UDP Demo */
/******************************************************************************************************/



static uint32_t claim_dest_ip = 0;
static uint8_t claim = 0;
static uint8_t idle_pkt_received = 0;
static uint8_t  pot_init = 0;
static uint16_t pot_initial_adcResult;


#define COMMAND 'C'
#define POTENTIOMETER 'P'
#define TEMPERATURE 'T'
#define LISTEN 'L'

#define DEST_PORT 65531

typedef struct {   
   char command;
   char action;
}type_cmd;

type_cmd data;
type_cmd idle_packet;

/* Check whether IP is connected or not */
bit DEMO_UDP_ClaimIPCheck()
{
    bool ret;
    if(claim == 1)
    {
        ret = true;
    }
    else if(claim == 0)
    {
        ret = false;
    }
    return ret;
}

/* Set claim if IP is connected or disconnected */
void DEMO_UDP_SetClaimIP(uint8_t claim_ip)
{
    claim = claim_ip;
}


/* Check every 1sec if IP is connected or disconnected */
void DEMO_UDP_IPLockTimer(void)
{

    if(!idle_pkt_received)
    {
        DEMO_UDP_SetClaimIP(0);
    }
    else
    {
        DEMO_UDP_SetClaimIP(1);
        idle_pkt_received = 0;

    }
}

// Read the Temperature reading from ADC

uint16_t DEMO_UDP_MeasureTemp(void)
{
    adc_result_t adcResult;
    adcResult = ADC_GetConversion(channel_AN3);

    return  adcResult;

}

void DEMO_UDP_IdlePkt(int length)
{
    //this function gets called by the UDP Port handler for port 65531

    UDP_ReadBlock(&idle_packet,sizeof(idle_packet));
    if(idle_packet.command== COMMAND)
    {
        switch(idle_packet.action){
            case 'I':       //Receive Idle packets
                idle_pkt_received =1;
                break;
        }
    }
}


void DEMO_UDP_Recv(int length)
{
    uint8_t message;
    uint16_t destPort;
    uint32_t dest_ip;
    uint32_t local_ip;
    char str[32], str1[16], str2[16];
    uint8_t str_len;
    uint16_t temperature;
    bool started = false;

    UDP_ReadBlock(&data,sizeof(data));
    if(data.command== COMMAND)
    {
        switch(data.action){               

                    case 'C':      //Connect 
                    if(!DEMO_UDP_ClaimIPCheck())
                    {
                        DEMO_UDP_SetClaimIP(1);
                        destPort = UDP_GetDestPort();
                        dest_ip = UDP_GetDestIP();
                        claim_dest_ip = dest_ip;
                        message = 1;
                        started = UDP_Start(claim_dest_ip,65533,destPort);
                        if(started==SUCCESS)
                        {
                            UDP_Write8(message);
                            UDP_Send();
                        }
                        else
                        {
                            DEMO_UDP_SetClaimIP(0);
                        }
                        pot_init = 1;
                    }
                    break;

                    case 'R':           //Release IP
                    destPort=UDP_GetDestPort();
                    dest_ip = UDP_GetDestIP();
                    local_ip = ipv4Address;
                    if(DEMO_UDP_ClaimIPCheck())
                    {
                        DEMO_UDP_SetClaimIP(0);
                    }

                   started = UDP_Start(claim_dest_ip,65533,destPort);
                   if(started==SUCCESS)
                   {
                       UDP_WriteBlock(&local_ip, sizeof(local_ip));
                       UDP_Send();
                   }
                   PORTJ = 0;
                   pot_init = 0;
                   lcd_clear();
                   break;
                    /*  Case '1' represents to Toggles Led 1 (D1)  */
                case '1':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             if(PORTJbits.RJ0 == 0)
                             {
                                 PORTJbits.RJ0=1;
                             }
                             else
                             {
                                 PORTJbits.RJ0=0;
                             }
                         }
                     }
                    break;


                /*  Case '2' represents to Toggles Led 2 (D2)  */
                case '2':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                        dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                            if(PORTJbits.RJ1 == 0)
                             {
                                 PORTJbits.RJ1=1;
                             }
                             else
                             {
                                 PORTJbits.RJ1=0;
                             }
                         }
                     }
                    break;


               /*  Case '3' represents to Toggles Led 1 (D3)  */
                case '3':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                            if(PORTJbits.RJ2 == 0)
                             {
                                 PORTJbits.RJ2=1;
                             }
                             else
                             {
                                 PORTJbits.RJ2=0;
                             }
                         }
                     }
                    break;


                /*  Case '4' represents to Toggles Led 4 (D4)  */
                case '4':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             if(PORTJbits.RJ3 == 0)
                             {
                                 PORTJbits.RJ3=1;
                             }
                             else
                             {
                                 PORTJbits.RJ3=0;
                             }
                         }
                     }
                    break;


                /*  Case '5' represents to Toggles Led 5 (D5)  */
                case '5':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             if(PORTJbits.RJ4 == 0)
                             {
                                 PORTJbits.RJ4=1;
                             }
                             else
                             {
                                 PORTJbits.RJ4=0;
                             }
                         }
                     }
                    break;


                /*  Case '6' represents to Toggles Led 6 (D6)  */
                case '6':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             if(PORTJbits.RJ5 == 0)
                             {
                                 PORTJbits.RJ5=1;
                             }
                             else
                             {
                                 PORTJbits.RJ5=0;
                             }
                         }
                     }
                    break;


                /*  Case '7' represents to Toggles Led 7 (D7)  */
                case '7':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             if(PORTJbits.RJ6 == 0)
                             {
                                 PORTJbits.RJ6=1;
                             }
                             else
                             {
                                 PORTJbits.RJ6=0;
                             }
                         }
                     }
                    break;


                /*  Case '8' represents to Toggles Led 8 (D8)  */
                case '8':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                            if(PORTJbits.RJ7 == 0)
                             {
                                 PORTJbits.RJ7=1;
                             }
                             else
                             {
                                 PORTJbits.RJ7=0;
                             }
                         }
                     }
                     break;

                     case 'D':
                     if(DEMO_UDP_ClaimIPCheck())
                     {
                         lcd_clear();
                         memset(str,0,sizeof(str));
                         memset(str1,0,sizeof(str1));
                         memset(str2,0,sizeof(str2));
                         dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             str_len = UDP_Read8();
                             if(str_len > 16)
                             {
                                 UDP_ReadBlock(&str1,16);
                                 lcd_goto1(0);
                                 lcd_puts(str1);
                                 str_len-= 16;
                                 UDP_ReadBlock(&str2,str_len);   
                                 lcd_goto2(0);
                                 lcd_puts(str2);
                             }
                             else
                             {
                                 UDP_ReadBlock(&str,str_len);
                                 lcd_goto1(0);
                                 lcd_puts(str);
                             }
                         }
                     }
                     break;
                     case 'T':               //Send Tempearure Reading
                    if(DEMO_UDP_ClaimIPCheck())
                    {
                        dest_ip = UDP_GetDestIP();
                         if(claim_dest_ip == dest_ip)
                         {
                             destPort=UDP_GetDestPort();
                             temperature = DEMO_UDP_MeasureTemp();
                             started = UDP_Start(claim_dest_ip,65533,destPort);
                             if(started==SUCCESS)
                             {                                 
                                 UDP_Write16(temperature);
                                 UDP_Send();
                             }
                         }
                    }
                    break;

         }
    }
}


void DEMO_UDP_Send()
{
    bool started = false;
    adc_result_t pot_adcResult;

     if(!DEMO_UDP_ClaimIPCheck())
     {         
         started = UDP_Start(0xFFFFFFFF,65533,65531);
         if(started==SUCCESS)
         {
             UDP_Write8(LISTEN);            
             UDP_Send();
         }
     }

    if(pot_init)
    {
        pot_adcResult = ADC_GetConversion(channel_AN2); //Read Potentiometer value from ADC (channel 0)

         if(((pot_adcResult > (pot_initial_adcResult + 100)) || (pot_adcResult <(pot_initial_adcResult - 100))) && pot_adcResult > 100) // Start UDP only when there is a difference in previous UDP packet
         {
             started = UDP_Start(claim_dest_ip,65533,DEST_PORT);
             if(started==SUCCESS)
             {
                 UDP_Write8(POTENTIOMETER);
                 UDP_Write32(pot_adcResult);
                 UDP_Send();
             }
             pot_initial_adcResult = pot_adcResult;
         }
    }
}

