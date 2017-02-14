/**
  EEPROM API Header File
	
  Company:
    Microchip Technology Inc.

  File Name:
    eeprom.h

  Summary:
    Header file for the EEPROM driver.

  Description:
    This header file provides APIs for the EEPROM driver.

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

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif


#include "mssp_spi_master.h"

#define EEPROM_25LC256_READ()   SPI_ExchangeByte(0)
#define EEPROM_25LC256_WRITE(a) SPI_ExchangeByte(a)

#define EEPROM_NCS_HIGH() do{LATD7 = 1;} while(0)
#define EEPROM_NCS_LOW()  do{LATD7 = 0;} while(0)

#define STAT_WIP 0x01 // Status Register - Write-In-Process (Read-only)
#define STAT_WEL 0x02 // Status Register - Write Enable Latch (Read-only)
#define STAT_BP0 0x04 // Status Register - Block Protection (Writable/Readable)
#define STAT_BP1 0x08 // Status Register - Block Protection (Writable/Readable)



typedef enum
{
    read_inst  =  0b00000011,
    write_inst =  0b00000010,
    wrdi_inst  =  0b00000100,
    wren_inst  =  0b00000110,
    rdsr_inst  =  0b00000101,
    wrsr_inst  =  0b00000001
}eeprom_instruction_name;

/**
  @Summary
    Initializes the EEPROM interface

  @Description
    This routine will initializes the EEPROM interface.
    This routine must be called before any other EEPROM routine is called.
    This routine should only be called once during system initialization.
  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void eeprom_init();

/**
  @Summary
    Reading the EEPROM status

  @Description
    This routine will read the EEPROM status.

  @Param
    None

  @Returns
    Status 
*/
uint8_t read_status_register(void);

/**
  @Summary
    Write the latch

  @Description
    This routine will write the EEPROM latch.

  @Param
    latch to write

  @Returns
    Status 
*/
void write_latch(uint8_t latch_wr);

/**
  @Summary
    Read 8 bits from EEPROM

  @Description
    This routine will read 8 bits from EEPROM.

  @Param
    EEPROM address of the location to be read.

  @Returns
    Read value
*/
uint8_t read_EEPROM8(uint16_t address);

/**
  @Summary
    Read 16 bits from EEPROM

  @Description
    This routine will read 16 bits from EEPROM.

  @Param
    EEPROM address of the location to be read.

  @Returns
    Read value
*/
uint16_t read_EEPROM16(uint16_t address);

/**
  @Summary
    Read 32 bits from EEPROM

  @Description
    This routine will read 32 bits from EEPROM.

  @Param
    EEPROM address of the location to be read.

  @Returns
    Read value
*/
uint32_t read_EEPROM32(uint16_t address);

/**
  @Summary
    Read a block of data from EEPROM

  @Description
    This routine will read a block of data EEPROM.

  @Param
    EEPROM address of the location to be read.
    Pointer to save the read data.
    Length of the data block.

  @Returns
    None
*/
void read_EEPROMBlock(uint16_t address, uint8_t *data, uint16_t len);

/**
  @Summary
    Write 8bits of data to EEPROM

  @Description
    This routine will write 8bits of data to EEPROM.

  @Param
    EEPROM address of the location to be written.
    Data to be written.

  @Returns
    None
*/
void write_EEPROM8(uint16_t address, uint8_t data);

/**
  @Summary
    Write 16bits of data to EEPROM

  @Description
    This routine will write 16bits of data to EEPROM.

  @Param
    EEPROM address of the location to be written.
    Data to be written.

  @Returns
    None
*/
void write_EEPROM16(uint16_t address, uint16_t data);

/**
  @Summary
    Write 32bits of data to EEPROM

  @Description
    This routine will write 32bits of data to EEPROM.

  @Param
    EEPROM address of the location to be written.
    Data to be written.

  @Returns
    None
*/
void write_EEPROM32(uint16_t address, uint32_t data);

/**
  @Summary
    Write a block of data to EEPROM

  @Description
    This routine will write a block of data to EEPROM.

  @Param
    EEPROM address of the location to be written.
    Pointer to the data block.
    Length of the data block.

  @Returns
    None
*/
void write_EEPROMBlock(uint16_t address, uint8_t *data, uint16_t len);

#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
#endif	/* EEPROM_H */

