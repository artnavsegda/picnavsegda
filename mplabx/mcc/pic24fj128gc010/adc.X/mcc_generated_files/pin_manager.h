/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.1
        Device            :  PIC24FJ128GC010
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.30
        MPLAB             :  MPLAB X 3.45

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA6, high using LATA6.

  @Description
    Sets the GPIO pin, RA6, high using LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA6 high (1)
    SINUS_RECT_SetHigh();
    </code>

*/
#define SINUS_RECT_SetHigh()          _LATA6 = 1
/**
  @Summary
    Sets the GPIO pin, RA6, low using LATA6.

  @Description
    Sets the GPIO pin, RA6, low using LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA6 low (0)
    SINUS_RECT_SetLow();
    </code>

*/
#define SINUS_RECT_SetLow()           _LATA6 = 0
/**
  @Summary
    Toggles the GPIO pin, RA6, using LATA6.

  @Description
    Toggles the GPIO pin, RA6, using LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA6
    SINUS_RECT_Toggle();
    </code>

*/
#define SINUS_RECT_Toggle()           _LATA6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA6.

  @Description
    Reads the value of the GPIO pin, RA6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA6
    postValue = SINUS_RECT_GetValue();
    </code>

*/
#define SINUS_RECT_GetValue()         _RA6
/**
  @Summary
    Configures the GPIO pin, RA6, as an input.

  @Description
    Configures the GPIO pin, RA6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA6 as an input
    SINUS_RECT_SetDigitalInput();
    </code>

*/
#define SINUS_RECT_SetDigitalInput()  _TRISA6 = 1
/**
  @Summary
    Configures the GPIO pin, RA6, as an output.

  @Description
    Configures the GPIO pin, RA6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA6 as an output
    SINUS_RECT_SetDigitalOutput();
    </code>

*/
#define SINUS_RECT_SetDigitalOutput() _TRISA6 = 0
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    PELTIER_V_SetHigh();
    </code>

*/
#define PELTIER_V_SetHigh()          _LATA7 = 1
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    PELTIER_V_SetLow();
    </code>

*/
#define PELTIER_V_SetLow()           _LATA7 = 0
/**
  @Summary
    Toggles the GPIO pin, RA7, using LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    PELTIER_V_Toggle();
    </code>

*/
#define PELTIER_V_Toggle()           _LATA7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = PELTIER_V_GetValue();
    </code>

*/
#define PELTIER_V_GetValue()         _RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    PELTIER_V_SetDigitalInput();
    </code>

*/
#define PELTIER_V_SetDigitalInput()  _TRISA7 = 1
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    PELTIER_V_SetDigitalOutput();
    </code>

*/
#define PELTIER_V_SetDigitalOutput() _TRISA7 = 0
/**
  @Summary
    Sets the GPIO pin, RB12, high using LATB12.

  @Description
    Sets the GPIO pin, RB12, high using LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB12 high (1)
    PMT_I_SetHigh();
    </code>

*/
#define PMT_I_SetHigh()          _LATB12 = 1
/**
  @Summary
    Sets the GPIO pin, RB12, low using LATB12.

  @Description
    Sets the GPIO pin, RB12, low using LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB12 low (0)
    PMT_I_SetLow();
    </code>

*/
#define PMT_I_SetLow()           _LATB12 = 0
/**
  @Summary
    Toggles the GPIO pin, RB12, using LATB12.

  @Description
    Toggles the GPIO pin, RB12, using LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB12
    PMT_I_Toggle();
    </code>

*/
#define PMT_I_Toggle()           _LATB12 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB12.

  @Description
    Reads the value of the GPIO pin, RB12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB12
    postValue = PMT_I_GetValue();
    </code>

*/
#define PMT_I_GetValue()         _RB12
/**
  @Summary
    Configures the GPIO pin, RB12, as an input.

  @Description
    Configures the GPIO pin, RB12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB12 as an input
    PMT_I_SetDigitalInput();
    </code>

*/
#define PMT_I_SetDigitalInput()  _TRISB12 = 1
/**
  @Summary
    Configures the GPIO pin, RB12, as an output.

  @Description
    Configures the GPIO pin, RB12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB12 as an output
    PMT_I_SetDigitalOutput();
    </code>

*/
#define PMT_I_SetDigitalOutput() _TRISB12 = 0
/**
  @Summary
    Sets the GPIO pin, RB5, high using LATB5.

  @Description
    Sets the GPIO pin, RB5, high using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 high (1)
    POTEN_SetHigh();
    </code>

*/
#define POTEN_SetHigh()          _LATB5 = 1
/**
  @Summary
    Sets the GPIO pin, RB5, low using LATB5.

  @Description
    Sets the GPIO pin, RB5, low using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 low (0)
    POTEN_SetLow();
    </code>

*/
#define POTEN_SetLow()           _LATB5 = 0
/**
  @Summary
    Toggles the GPIO pin, RB5, using LATB5.

  @Description
    Toggles the GPIO pin, RB5, using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB5
    POTEN_Toggle();
    </code>

*/
#define POTEN_Toggle()           _LATB5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB5.

  @Description
    Reads the value of the GPIO pin, RB5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB5
    postValue = POTEN_GetValue();
    </code>

*/
#define POTEN_GetValue()         _RB5
/**
  @Summary
    Configures the GPIO pin, RB5, as an input.

  @Description
    Configures the GPIO pin, RB5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an input
    POTEN_SetDigitalInput();
    </code>

*/
#define POTEN_SetDigitalInput()  _TRISB5 = 1
/**
  @Summary
    Configures the GPIO pin, RB5, as an output.

  @Description
    Configures the GPIO pin, RB5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an output
    POTEN_SetDigitalOutput();
    </code>

*/
#define POTEN_SetDigitalOutput() _TRISB5 = 0
/**
  @Summary
    Sets the GPIO pin, RD14, high using LATD14.

  @Description
    Sets the GPIO pin, RD14, high using LATD14.

  @Preconditions
    The RD14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD14 high (1)
    PMT_VOLT_SetHigh();
    </code>

*/
#define PMT_VOLT_SetHigh()          _LATD14 = 1
/**
  @Summary
    Sets the GPIO pin, RD14, low using LATD14.

  @Description
    Sets the GPIO pin, RD14, low using LATD14.

  @Preconditions
    The RD14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD14 low (0)
    PMT_VOLT_SetLow();
    </code>

*/
#define PMT_VOLT_SetLow()           _LATD14 = 0
/**
  @Summary
    Toggles the GPIO pin, RD14, using LATD14.

  @Description
    Toggles the GPIO pin, RD14, using LATD14.

  @Preconditions
    The RD14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD14
    PMT_VOLT_Toggle();
    </code>

*/
#define PMT_VOLT_Toggle()           _LATD14 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD14.

  @Description
    Reads the value of the GPIO pin, RD14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD14
    postValue = PMT_VOLT_GetValue();
    </code>

*/
#define PMT_VOLT_GetValue()         _RD14
/**
  @Summary
    Configures the GPIO pin, RD14, as an input.

  @Description
    Configures the GPIO pin, RD14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD14 as an input
    PMT_VOLT_SetDigitalInput();
    </code>

*/
#define PMT_VOLT_SetDigitalInput()  _TRISD14 = 1
/**
  @Summary
    Configures the GPIO pin, RD14, as an output.

  @Description
    Configures the GPIO pin, RD14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD14 as an output
    PMT_VOLT_SetDigitalOutput();
    </code>

*/
#define PMT_VOLT_SetDigitalOutput() _TRISD14 = 0
/**
  @Summary
    Sets the GPIO pin, RE9, high using LATE9.

  @Description
    Sets the GPIO pin, RE9, high using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE9 high (1)
    LAMP_CURRENT_SENSE_SetHigh();
    </code>

*/
#define LAMP_CURRENT_SENSE_SetHigh()          _LATE9 = 1
/**
  @Summary
    Sets the GPIO pin, RE9, low using LATE9.

  @Description
    Sets the GPIO pin, RE9, low using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE9 low (0)
    LAMP_CURRENT_SENSE_SetLow();
    </code>

*/
#define LAMP_CURRENT_SENSE_SetLow()           _LATE9 = 0
/**
  @Summary
    Toggles the GPIO pin, RE9, using LATE9.

  @Description
    Toggles the GPIO pin, RE9, using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE9
    LAMP_CURRENT_SENSE_Toggle();
    </code>

*/
#define LAMP_CURRENT_SENSE_Toggle()           _LATE9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE9.

  @Description
    Reads the value of the GPIO pin, RE9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE9
    postValue = LAMP_CURRENT_SENSE_GetValue();
    </code>

*/
#define LAMP_CURRENT_SENSE_GetValue()         _RE9
/**
  @Summary
    Configures the GPIO pin, RE9, as an input.

  @Description
    Configures the GPIO pin, RE9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE9 as an input
    LAMP_CURRENT_SENSE_SetDigitalInput();
    </code>

*/
#define LAMP_CURRENT_SENSE_SetDigitalInput()  _TRISE9 = 1
/**
  @Summary
    Configures the GPIO pin, RE9, as an output.

  @Description
    Configures the GPIO pin, RE9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE9 as an output
    LAMP_CURRENT_SENSE_SetDigitalOutput();
    </code>

*/
#define LAMP_CURRENT_SENSE_SetDigitalOutput() _TRISE9 = 0
/**
  @Summary
    Sets the GPIO pin, RF1, high using LATF1.

  @Description
    Sets the GPIO pin, RF1, high using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF1 high (1)
    TXEN_SetHigh();
    </code>

*/
#define TXEN_SetHigh()          _LATF1 = 1
/**
  @Summary
    Sets the GPIO pin, RF1, low using LATF1.

  @Description
    Sets the GPIO pin, RF1, low using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF1 low (0)
    TXEN_SetLow();
    </code>

*/
#define TXEN_SetLow()           _LATF1 = 0
/**
  @Summary
    Toggles the GPIO pin, RF1, using LATF1.

  @Description
    Toggles the GPIO pin, RF1, using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF1
    TXEN_Toggle();
    </code>

*/
#define TXEN_Toggle()           _LATF1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF1.

  @Description
    Reads the value of the GPIO pin, RF1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF1
    postValue = TXEN_GetValue();
    </code>

*/
#define TXEN_GetValue()         _RF1
/**
  @Summary
    Configures the GPIO pin, RF1, as an input.

  @Description
    Configures the GPIO pin, RF1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF1 as an input
    TXEN_SetDigitalInput();
    </code>

*/
#define TXEN_SetDigitalInput()  _TRISF1 = 1
/**
  @Summary
    Configures the GPIO pin, RF1, as an output.

  @Description
    Configures the GPIO pin, RF1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF1 as an output
    TXEN_SetDigitalOutput();
    </code>

*/
#define TXEN_SetDigitalOutput() _TRISF1 = 0
/**
  @Summary
    Sets the GPIO pin, RG8, high using LATG8.

  @Description
    Sets the GPIO pin, RG8, high using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 high (1)
    T_PELTIER_SetHigh();
    </code>

*/
#define T_PELTIER_SetHigh()          _LATG8 = 1
/**
  @Summary
    Sets the GPIO pin, RG8, low using LATG8.

  @Description
    Sets the GPIO pin, RG8, low using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 low (0)
    T_PELTIER_SetLow();
    </code>

*/
#define T_PELTIER_SetLow()           _LATG8 = 0
/**
  @Summary
    Toggles the GPIO pin, RG8, using LATG8.

  @Description
    Toggles the GPIO pin, RG8, using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG8
    T_PELTIER_Toggle();
    </code>

*/
#define T_PELTIER_Toggle()           _LATG8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG8.

  @Description
    Reads the value of the GPIO pin, RG8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG8
    postValue = T_PELTIER_GetValue();
    </code>

*/
#define T_PELTIER_GetValue()         _RG8
/**
  @Summary
    Configures the GPIO pin, RG8, as an input.

  @Description
    Configures the GPIO pin, RG8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an input
    T_PELTIER_SetDigitalInput();
    </code>

*/
#define T_PELTIER_SetDigitalInput()  _TRISG8 = 1
/**
  @Summary
    Configures the GPIO pin, RG8, as an output.

  @Description
    Configures the GPIO pin, RG8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an output
    T_PELTIER_SetDigitalOutput();
    </code>

*/
#define T_PELTIER_SetDigitalOutput() _TRISG8 = 0

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC24FJ128GC010
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize(void);

#endif
