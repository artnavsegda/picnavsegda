/**
  Descriptive File Name
	
  Company:
    Microchip Technology Inc.

  File Name:
    file_template_source.c

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


#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "rtcc.h"
#include <XC.h>

volatile time_t deviceTime;

/****************************************************************************
  Function:
    void rtcc_init(void)

  Summary:
    Initialize the clock calendar driver.

  Description:
    This function configured the basics of a software driven RTCC peripheral.
    It relies upon a periodic TMR1 event to provide time keeping.
    The Timer 1 clock provides a steady 100kHz time base.
    0x8000 counts in the TMR1 register will provide a 1HZ tick.
    CLOCKS_PER_SEC is configured for 1 and all is well.
 
  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    The C stdlib functions understand UNIX time but they need a UNIX time counter.
    UNIX time is the number of seconds elapsed since Midnight Jan 1, 1970
  ***************************************************************************/
void rtcc_init(void)
{
    TMR1CS = 1;     // External Clock
    T1OSCEN = 1;    // enable crystal driver
    T1CKPS0 = 0;    // no pre scaler
    T1CKPS1 = 0;
    T1SYNC = 1;     // synchronize the T1
    TMR1ON = 1;

    TMR1 = RTC_RELOAD;
    deviceTime = 1293861600; // Jan 1 2011
    localTime  = 1293861600 + 2208988800; //From RFC 868 - the time  2,208,988,800 corresponds to 00:00  1 Jan 1970 GMT

    TMR1IP = 1; // High Priority
    TMR1IE = 1; // Interrupt Enable

}

/****************************************************************************
  Function:
    void rtcc_handler(void) (TMR1 version)

  Summary:
    maintain device_time (seconds) using the LCDIF flag/interrupt.

  Description:
    This function decrements seconds_counter until 0 and then increments device_time.
    seconds_counter reloads with CLOCK_PER_SEC.
    This version of the function uses Timer 1 as the time base.
    Timer 1 is reloaded with 0x8000 to cause TMR1IF to overflow every second.
 
  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    TMR1IF is not looked at or modified because there could be other tasks running
    on this interrupt.
  ***************************************************************************/

void rtcc_handler(void)
{
    if(TMR1IE && TMR1IF)
    {
        TMR1IF = 0;
        TMR1ON = 0;
        TMR1 = RTC_RELOAD;
        TMR1ON = 1;
        deviceTime++;
        localTime++;
    }
}


/****************************************************************************
  Function:
    void rtcc_set(time_t time)

  Summary:
    set the device time to the passed unix time value.

  Description:
    Update the device time with the passed unix time.
    Interrupts are disabled for the copy.
    Interrupt state is restored to the original state on exit.
    
  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    
  ***************************************************************************/

void rtcc_set(time_t *t)
{
    bool gie_val;
    gie_val = GIE;
    GIE = 0;
    deviceTime = *t;
    GIE = gie_val;
}

/****************************************************************************
  Function:
    time_t time(time_t *t)

  Summary:
    return the current device time.

  Description:
    This function retrieves the device time as either a return value or 
    filling in a variable passed by reference.  Interrupts are disabled
    during the copy and restored on exit.
 
  Precondition:
    None

  Parameters:
    time_t *t : A time_t pointer for the current time.

  Returns:
    time_t value of the current time.

  Remarks:
    This function is a prerequisit to supporting the standard C time libraries.
  ***************************************************************************/

/* implement the time(&t) function for the standard libraries */

/* time.h does not implement time as it is application dependent */
time_t time(time_t *t)
{
    bool   gie_val;
    time_t  the_time;
    
    gie_val = GIE;
    GIE = 0;
    the_time = deviceTime;
    GIE = gie_val;

    if(t)
    {
        *t = the_time;
    }

    return (the_time);
}
