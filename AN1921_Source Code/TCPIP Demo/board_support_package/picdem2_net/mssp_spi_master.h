/**
  Master SPI API Header File
	
  Company:
    Microchip Technology Inc.

  File Name:
    mssp_spi_master.h

  Summary:
    Header file for the Master SPI driver.

  Description:
    This header file provides APIs for the Master SPI driver.

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


#ifndef MSSP_SPI_MASTER_H
#define	MSSP_SPI_MASTER_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

/**
  @Summary
    Initializes the SPI

  @Description
    This routine initializes the SPI.
    This routine must be called before any other SPI routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void spi_init(void);

/**
  @Summary
    Data exchange over the SPI

  @Description
    This routine send/receive 8bits of data over the SPI.

  @Param
    Data to be sent.

  @Returns
    Received data.
*/
char SPI_ExchangeByte(char);

#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif

#endif	/* MSSP_SPI_MASTER_H */

