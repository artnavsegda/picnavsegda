/**
  RTCC API Header File
	
  Company:
    Microchip Technology Inc.

  File Name:
    rtcc.h

  Summary:
    Header file for the RTCC driver.

  Description:
    This header file provides APIs for the RTCC driver.

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


#ifndef RTCC_H
#define RTCC_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

#include <time.h>
#include <stdint.h>

#define TICKS_PER_SECOND (1UL)
#define RTC_RELOAD 32768UL

extern volatile time_t deviceTime;

/**
  @Summary
    Initializes the RTCC

  @Description
    This routine initializes the RTCC.
    This routine must be called before any other RTCC routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void    rtcc_init(void);
void    rtcc_handler(void);
void    rtcc_set(time_t *);

volatile time_t localTime;

/* implement the time(&t) function for the standard libraries */
/* time.h does not implement time as it is application dependent */
time_t  time(time_t *t);

#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif

#endif /* RTCC_H */
