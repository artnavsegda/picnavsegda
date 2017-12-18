/*******************************************************************************
  PADC1 Generated Driver API Header File

  Company:
    Microchip Technology Inc.

  File Name:
    padc1.h

  Summary:
    This is the generated header file for the PADC1 driver using MPLAB(c) Code Configurator

  Description:
    This header file provides APIs for driver for PADC1.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.26
        Device            :  PIC24FJ128GC010
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.30
        MPLAB             :  MPLAB X 3.45
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

#ifndef PADC1_H
#define PADC1_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: constant
*/
#define PADC1_ACC_NUM_SAMPLES         0

/**
  Section: Data Types
*/

/** ADC Channel Definition
 
 @Summary 
   This structure defines the data to be set for Sample List.
 
 @Description
   This structure is used to set the sample list during runtime.

 */
typedef struct{
    uint8_t trigger_src;
    uint8_t slsize;
    uint8_t chargetime;
    bool  autoscan;  
}PADC1_SAMPLELISTCONFIG;

/**
  Section: Interface Routines
*/

/**
  @Summary
    Initializes hardware and data for the given instance of the ADC module

  @Description
    This routine initializes hardware for the instance of the ADC module,
    using the hardware initialization given data.  It also initializes all
    necessary internal data.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
    uint16_t sl0ResultBuffer[2];;
    uint8_t tableregindex;
    uint8_t slsize;

    tableregindex = 0;
    slsize = 2;

    PADC1_Initialize(void);

    while(1)
    {
        if( PADC1_SampleList1ConversionResultBufferGet(sl0ResultBuffer, tableregindex, slsize))
        {
            PADC1_Tasks();
        }
    }
    </code>
*/
void PADC1_Initialize(void);

/**
  @Summary:
   This function checks the ADC is ready for conversion

  @Description:
    This function checks the ADC is ready for conversion

  @Parameters:
    None.

  @Returns:
    Returns ADC ready status
    True - ADC is ready
    False - ADC not ready
  
  @Example 
   Refer to the example of void PADC1_Initialize(void)
*/
bool PADC1_IsReadyForConversion(void);

/**
  @Summary:
   This function checks the if the ADC is busy in conversion

  @Description:
    This function checks the if the ADC is busy in conversion

  @Parameters:
    None.

  @Returns:
    Returns ADC ready status
    True - ADC is ready
    False - ADC not

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)  
*/
bool PADC1_IsBusyInConversion(void);

/**
  @Summary:
   This function configures Sample List0

  @Description:
    This function configures Sample List0. It sets the trigger source, buffer
    write mode, auto or sequential mode and also enables Sample list.

  @Parameters:
  PADC1_SAMPLELISTCONFIG *samplelistconfig - pointer to structure PADC1_SAMPLELISTCONFIG

  @Precondition: ADTBLn registers should be set before this function is called.

  @Returns:
    None.

  @Example 
    <code>
    PADC1_SAMPLELISTCONFIG slconfig;
    uint16_t sl0ResultBuffer[2];;
    uint8_t tableregindex;
    uint8_t slsize;
    uint8_t adcChannel1 = 0; // AN0/AN1
    uint8_t adcChannel2 = 1; // AN2

    tableregindex = 0;
    slsize = 2;
  
    //Disable sample list
    PADC1_SampleList0Disable();
    
    PADC1_SetADCChannel( tableregindex, adcChannel1, true );
    PADC1_SetADCChannel( tableregindex, adcChannel2,false );

    // set up values for sample list
    slconfig.trigger_src =0; //manual
    slconfig.chargetime =5;
    slconfig.autoscan = true;
    slconfig.slsize = 2;
    //set the values for sample list and enable the list
    PADC1_SampleList0Setup(&slconfig);
    PADC1_SampleList0ManualConversionStart();
    while(1)
    {
        if( PADC1_SampleList1ConversionResultBufferGet(sl0ResultBuffer, tableregindex, slsize))
        {
            PADC1_Tasks();
        }
    }
    </code>
*/
void PADC1_SampleList0Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig);

/**
  @Summary:
   This function configures Sample List1

  @Description:
    This function configures Sample List1. It sets the trigger source, buffer
    write mode, auto or sequential mode and also enables Sample list.

  @Parameters:
  PADC1_SAMPLELISTCONFIG *samplelistconfig - pointer to structure PADC1_SAMPLELISTCONFIG

  @Precondition: ADTBLn registers should be set before this function is called.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList1Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig);

/**
  @Summary:
   This function configures Sample List2

  @Description:
    This function configures Sample List2. It sets the trigger source, buffer
    write mode, auto or sequential modeand also enables Sample list.

  @Parameters:
  PADC1_SAMPLELISTCONFIG *samplelistconfig - pointer to structure PADC1_SAMPLELISTCONFIG

  @Precondition: ADTBLn registers should be set before this function is called.

  @Returns:
    None.
  
  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList2Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig);

/**
  @Summary:
   This function configures Sample List3

  @Description:
    This function configures Sample List3. It sets the trigger source, buffer
    write mode, auto or sequential mode and also enables Sample list.

  @Parameters:
  PADC1_SAMPLELISTCONFIG *samplelistconfig - pointer to structure PADC1_SAMPLELISTCONFIG

  @Precondition: ADTBLn registers should be set before this function is called.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig) 
*/
void PADC1_SampleList3Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig);


/**
  @Summary:
   This function triggers Manual analog conversion for Sample List0

  @Description:
    This function triggers Manual analog conversion for Sample List0

  @Parameters:
    None.

  @Returns:
    None
  
 @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList0ManualConversionStart(void);

/**
  @Summary:
   This function triggers Manual analog conversion for Sample List1

  @Description:
    This function triggers Manual analog conversion for Sample List1

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList1ManualConversionStart(void);

/**
  @Summary:
   This function triggers Manual analog conversion for Sample List2

  @Description:
    This function triggers Manual analog conversion for Sample List2

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)

*/
void PADC1_SampleList2ManualConversionStart(void);

/**
  @Summary:
   This function triggers Manual analog conversion for Sample List3

  @Description:
    This function triggers Manual analog conversion for Sample List3

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)

*/
void PADC1_SampleList3ManualConversionStart(void);

/**
  @Summary:
   Disables Sample list

  @Description:
    Disables Sample list

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList0Disable(void);

/**
  @Summary:
   Disables Sample list

  @Description:
    Disables Sample list

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList1Disable(void);

/**
  Function:
 void PADC1_SampleList2Disable(void)

  @Summary:
   Disables Sample list

  @Description:
    Disables Sample list

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList2Disable(void);

/**
  @Summary:
   Disables Sample list

  @Description:
    Disables Sample list

  @Parameters:
    None.

  @Returns:
    None.

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SampleList3Disable(void);

/**
  @Summary:
  Set analog channel for one table register.

  @Description:
  Analog channel is set for table register.

  @Parameters:
   uint8_t tableRegIndex - table register index
   uint8_t adcChannel - adc input channel value
   bool diffEnable   - true- differential channel
                       false - single ended channel

  @Returns:
   None

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
void PADC1_SetADCChannel( uint8_t tableRegIndex, uint8_t adcChannel, bool diffEnable );

/**
  @Summary:
  Read the conversion result data for Sample List1

  @Description:
  This function should be called periodically to read the conversion result.
  Application should check the return status to get the valid conversion data.

  @Parameters:
    uint16_t *buffer - Pointer to application buffer where the result data
                       will be stored
    int tableRegIndex - Sample list0 starting table register number
    int slSize      - Number of entries to read in Sample list0.

  @Returns: true - conversion result is valid for sample list 0
           false - conversion result is invalid for sample list 0

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
bool PADC1_SampleList0ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize);

/**
 @Summary:
  Read the conversion result data for Sample List 1

  @Description:
  This function should be called periodically to read the conversion result.
  Application should check the return status to get the valid conversion data.

  @Parameters:
    uint16_t *buffer - Pointer to application buffer where the result data
                       will be stored
    int tableRegIndex - Sample list1 starting table register number
    int slSize      - Number of entries to read in Sample list 1.

  @Returns: true - conversion result is valid for sample list 1
           false - conversion result  invalid for sample list 1

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
bool PADC1_SampleList1ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize);

/**
  @Summary:
  Read the conversion result data for Sample List 2

  @Description:
  This function should be called periodically to read the conversion result.
  Application should check the return status to get the valid conversion data.

  @Parameters:
    uint16_t *buffer - Pointer to application buffer where the result data
                       will be stored
    int tableRegIndex - Sample list0 starting table register number
    int slSize      - Number of entries to read in Sample list 2.

  @Returns: true - conversion result is valid for sample list 2
           false - conversion result  invalid for sample list 2

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
bool PADC1_SampleList2ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize);

/**
  @Summary:
  Read the conversion result data for Sample List 3

  @Description:
  This function should be called periodically to read the conversion result.
  Application should check the return status to get the valid conversion data.

  @Parameters:
    uint16_t *buffer - Pointer to application buffer where the result data
                       will be stored
    int tableRegIndex - Sample list3 starting table register number
    int slSize      - Number of entries to read in Sample list 3.

  @Returns: true - conversion result is valid for sample list 3
           false - conversion result  invalid for sample list 3

  @Example 
    Refer to the example of PADC1_SampleList0Setup(PADC1PADC1_SAMPLELISTCONFIG *samplelistconfig)
*/
bool PADC1_SampleList3ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize);

/**
  @Summary:
  Read the accumulation conversion result data

  @Description:
  This function should be called periodically to read the accumulation result.
  Application should check the return status to get the valid accumulation result.

  @Parameters:
    uint32_t *accBuffer - Pointer to application buffer where the accumulation
                         result will be stored

  @Returns: true - conversion result is valid for sample list 3
           false - conversion result  invalid for sample list 3

  @Example
  <code>
  uint32_t accbuffer=0;
  while(!PADC1_SampleList0IsConversionDone());
  if(PADC1_AccumulationResultGet(&accbuffer))
  {
    //process accumulated data
  }
  </code>    
*/
bool PADC1_AccumulationResultGet(uint32_t *accBuffer);

/**
  @Summary:
  Returns sample list0 conversion result status

  @Description:
  This function should be called periodically to read the sample list0
  conversion result status. This function returns SL3IF flag status.

  @Parameters:
   none

  @Returns: true - SL0IF flag set
           false - SL0IF flag clear

  @Example 
    Refer to the example of PADC1_SampleList0IsConversionDone(void)
*/
bool PADC1_SampleList0IsConversionDone(void);
/**
  @Summary:
  Returns sample list1 conversion result status

  @Description:
  This function should be called periodically to read the sample list1
  conversion result status. This function returns SL1IF flag status.

  @Parameters:
   none

  @Returns: true - SL1IF flag set
           false - SL1IF flag clear

  @Example 
    Refer to the example of PADC1_SampleList0IsConversionDone(void)
*/
bool PADC1_SampleList1IsConversionDone(void);

/**
  @Summary:
  Returns sample list2 conversion result status

  @Description:
  This function should be called periodically to read the sample list3
  conversion result status. This function returns SL2IF flag status.

  @Parameters:
   none

  @Returns: true - SL2IF flag set
           false - SL2IF flag clear

  @Example 
    Refer to the example of PADC1_SampleList0IsConversionDone(void)
*/
bool PADC1_SampleList2IsConversionDone(void);

/**
  @Summary:
  Returns sample list3 conversion result status

  @Description:
  This function should be called periodically to read the sample list3
  conversion result status. This function returns SL3IF flag status.

  @Parameters:
   none
 
  @Returns: true - SL3IF flag set
           false - SL3IF flag clear

  @Example 
    Refer to the example of PADC1_SampleList0IsConversionDone(void)
*/
bool PADC1_SampleList3IsConversionDone(void);

/**
  @Summary:
  Returns the accumulation interrupt status ACIF flag

  @Description:
  This function should be called periodically to read the
  the accumulation interrupt status flag

  @Parameters:
  none

  @Returns: true - ACIF flag set
           false - ACIF flag clear

  @Example 
    Refer to the example of PADC1_SampleList0IsConversionDone(void)
*/
bool PADC1_IsAccumulationDone(void);

/**
  @Summary:
   Polling function to check the interrupt flag

  @Description:
   This is a polling function for ADC conversion complete.
   Check sample list interrupt flag to know which sample list triggered
   ADC interrupt

  @Parameters:
    None.

  @Returns:
    None
  
  @Example 
    Refer to the example of void PADC1_Initialize0()
*/
void PADC1_Tasks( void );

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // PADC1.h
    
/**
 End of File
*/
