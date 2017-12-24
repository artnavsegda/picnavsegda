/*******************************************************************************
  SDADC1 Generated Driver API Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sdadc1.h

  Summary:
    This is the generated header file for the SDADC1 driver using MPLAB(c) Code Configurator

  Description:
    This header file provides APIs for driver for SDADC1.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.35
        Device            :  PIC24FJ128GC010
        Version           :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.31
        MPLAB             :  MPLAB X 3.60
*******************************************************************************/

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

#ifndef SDADC1_H
#define SDADC1_H
/**
  Section: Included Files
*/
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
/**
  Section: Data Types
*/

/** SD ADC Channel Definition
 
 @Summary 
   Defines the channels available for conversion
 
 @Description
   This data type defines the channels that are available for the module to use.
 
 Remarks:
   None
 */
typedef enum
{
    SDADC1_CH_REFERENCE = 0x3,
    SDADC1_CH1_SINGLE = 0x2,
    SDADC1_CH1_DIFFERENTIAL = 0x1,
    SDADC1_CH0_DIFFERENTIAL = 0x0
}SDADC1_CHANNEL;

/**
  Section: Interface Routines
*/
/**
  @Summary
    Initializes hardware and data for the given instance of the Sigma Delta ADC Module.

  @Description
    This routine initializes hardware for the instance of the SD ADC Module,
    using the hardware initialization data given in the UI.  It also performs Calibration of the module.
   
  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
    float fResult;
    bool bConversionComplete;
	
    SDADC1_Initialize();
    while (1)
    {
		bConversionComplete = SDADC1_IsConversionComplete();
        if(true == bConversionComplete)
        {
            fResult = SDADC1_ConversionResultGet();
        }
    }
    </code>
*/
void SDADC1_Initialize(void);
/**
  @Summary
    Selects the SD ADC channel for conversion.

  @Description
    This routine selects the specified channel for Conversion, by
    using the channel enumeration passed as a parameter.
   
  @Param
    eChannel: Selects channel for conversion, see SDADC1_CHANNEL.
    for options available for channel selection. 

  @Returns
    None
 
  @Example 
    <code>
    float fResult;
    bool bConversionComplete;
	
    SDADC1_ChannelSelect(SDADC1_CH1_SINGLE);
	bConversionComplete = SDADC1_IsConversionComplete();
	if(true == bConversionComplete)
	{
		fResult = SDADC1_ConversionResultGet();
	}
    </code>
*/
void SDADC1_ChannelSelect(SDADC1_CHANNEL eChannel);
/**
  @Summary
    Returns the status of conversion.

  @Description
    This routine reads the register flags and returns the status of converion.
   
  @Param
    None

  @Returns
    true - Conversion complete and new data is available for reading.
	false - Conversion not yet complete.
 
  @Example 
    refer to the example of initializer routine above.
*/
bool SDADC1_IsConversionComplete(void);
/**
  @Summary
    Returns the raw result for the channel selected earlier.

  @Description
    This routine returns the raw value after conversion by SD ADC.
	If the conversion is complete, it immediately returns the raw result.
	If the conversion is not complete, it waits till the conversion is completed
	and then returns the raw result.
   
  @Param
    None

  @Returns
    Signed 16-bit result.
 
  @Example 
    <code>
    int16_t i16Result;
    bool bConversionComplete;

	bConversionComplete = SDADC1_IsConversionComplete();
	if(true == bConversionComplete)
	{
		i16Result = SDADC1_ConversionRawResultGet();
	}
    </code>
*/
int16_t SDADC1_ConversionRawResultGet(void);
/**
  @Summary
    Returns the calibrated result for the channel selected earlier.

  @Description
    This routine returns the calibrated result value after conversion by SD ADC.
	If the conversion is complete, it immediately returns the calibrated result.
	If the conversion is not complete, it waits till the conversion is completed
	and then returns the calibrated result.
	The calibration values used here are computed during the initialization of the SD ADC.
   
  @Param
    None

  @Returns
    floating point calibrated result.
 
  @Example 
    refer to the example of initializer routine above.
*/
float SDADC1_ConversionResultGet(void);

#ifdef __cplusplus  // Provide C++ Compatibility
}
#endif
#endif  // SDADC1.h