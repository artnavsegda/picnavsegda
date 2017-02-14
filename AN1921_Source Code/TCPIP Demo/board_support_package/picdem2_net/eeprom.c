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

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "eeprom.h"


void eeprom_init()
{
    TRISDbits.TRISD7 = 0; //EEPROM CS   - o/p
//    LATDbits.LATD7   = 1;
    TRISCbits.TRISC3 = 0; //EEPROM SCK1 - o/p   
    TRISCbits.TRISC4 = 1; //EEPROM SDI1 - i/p    
    TRISCbits.TRISC5 = 0; //EEPROM SDO1 - o/p  

    EEPROM_NCS_HIGH(); //Init CS to High
}

uint8_t read_status_register()
{
     uint8_t ret;

    EEPROM_NCS_LOW();
    EEPROM_25LC256_WRITE(rdsr_inst);                // Read Status Register
    ret = EEPROM_25LC256_READ();
    EEPROM_NCS_HIGH();

    return ret;
}

void write_latch(uint8_t latch_wr)
{
    EEPROM_NCS_LOW();                       //CS low
    EEPROM_25LC256_WRITE(latch_wr);                 // Set or Reset the write enable latch
    EEPROM_NCS_HIGH();
}

uint8_t read_EEPROM8(uint16_t address)
{
   uint8_t data, stat_reg;

    write_latch(wrdi_inst);                 //Reset the write enable latch
    do
    {
        stat_reg = read_status_register();  //Read Status Register
    }while((stat_reg == STAT_WIP));

    if(!(stat_reg & STAT_WIP))
    {
        EEPROM_NCS_LOW();                   //CS low
        EEPROM_25LC256_WRITE(read_inst);            //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to read data from memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB

        data = EEPROM_25LC256_READ();                //Read the data
        EEPROM_NCS_HIGH();                  //CS high

        write_latch(wren_inst);             //Set the write enable latch

        return data;
    }
    return 0;
}

uint16_t read_EEPROM16(uint16_t address)
{
     uint8_t stat_reg;
     uint16_t data;

    write_latch(wrdi_inst);                 //Reset the write enable latch
    do
    {
        stat_reg = read_status_register();  //Read Status Register
    }while((stat_reg == STAT_WIP));

    if(!(stat_reg & STAT_WIP))
    {
        EEPROM_NCS_LOW();                   //CS low
        EEPROM_25LC256_WRITE(read_inst);            //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to read data from memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB

        ((uint8_t *)&data)[1]= EEPROM_25LC256_READ(); //Read the data
        ((uint8_t *)&data)[0]= EEPROM_25LC256_READ();
        EEPROM_NCS_HIGH();                  //CS high

        write_latch(wren_inst);             //Set the write enable latch

        return data;
    }
    return 0;
}

uint32_t read_EEPROM32(uint16_t address)
{
     uint8_t stat_reg;
     uint32_t data;

    write_latch(wrdi_inst);                 //Reset the write enable latch
    do
    {
        stat_reg = read_status_register();  //Read Status Register
    }while((stat_reg == STAT_WIP));

    if(!(stat_reg & STAT_WIP))
    {
        EEPROM_NCS_LOW();                   //CS low
        EEPROM_25LC256_WRITE(read_inst);            //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to read data from memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB

        ((uint8_t *)&data)[3]= EEPROM_25LC256_READ(); //Read the data
        ((uint8_t *)&data)[2]= EEPROM_25LC256_READ();
        ((uint8_t *)&data)[1]= EEPROM_25LC256_READ();
        ((uint8_t *)&data)[0]= EEPROM_25LC256_READ();
        EEPROM_NCS_HIGH();                  //CS high

        write_latch(wren_inst);             //Set the write enable latch

        return data;
    }
    return 0;
}

void read_EEPROMBlock(uint16_t address, uint8_t *data, uint16_t len)
{
     uint8_t stat_reg;
     

    write_latch(wrdi_inst);                 //Reset the write enable latch
    do
    {
        stat_reg = read_status_register();  //Read Status Register
    }while((stat_reg == STAT_WIP));

    if(!(stat_reg & STAT_WIP))
    {
        EEPROM_NCS_LOW();                   //CS low
        EEPROM_25LC256_WRITE(read_inst);            //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to read data from memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB

        while(len--)
        {
            *data++ = EEPROM_25LC256_READ();         //Read the data
        }
        EEPROM_NCS_HIGH();                  //CS high

        write_latch(wren_inst);             //Set the write enable latch        
    }
   
}

void write_EEPROM8(uint16_t address, uint8_t data)
{
    uint8_t stat_reg;

    write_latch(wren_inst);                  //Set the write enable latch

    do{
        stat_reg = read_status_register();  //Read Status Register
    }while(stat_reg != STAT_WEL);

    if(stat_reg & STAT_WEL)
    {
        EEPROM_NCS_LOW();
        EEPROM_25LC256_WRITE(write_inst);           //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to write data to memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB
        EEPROM_25LC256_WRITE(data);                 //Write Data
        EEPROM_NCS_HIGH();                  //CS high
    }
    write_latch(wrdi_inst);                 //Reset the write enable latch

}

void write_EEPROM16(uint16_t address, uint16_t data)
{
    uint8_t stat_reg;

    write_latch(wren_inst);                  //Set the write enable latch

    do{
        stat_reg = read_status_register();  //Read Status Register
    }while(stat_reg != STAT_WEL);

    if(stat_reg & STAT_WEL)
    {
        EEPROM_NCS_LOW();
        EEPROM_25LC256_WRITE(write_inst);           //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to write data to memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB
        EEPROM_25LC256_WRITE(((uint8_t*) &data)[1]);                 //Write Data
        EEPROM_25LC256_WRITE(((uint8_t*) &data)[0]);
        EEPROM_NCS_HIGH();                  //CS high
    }
    write_latch(wrdi_inst);                 //Reset the write enable latch

}

void write_EEPROM32(uint16_t address, uint32_t data)
{
    uint8_t stat_reg;

    write_latch(wren_inst);                  //Set the write enable latch

    do{
        stat_reg = read_status_register();  //Read Status Register
    }while(stat_reg != STAT_WEL);

    if(stat_reg & STAT_WEL)
    {
        EEPROM_NCS_LOW();
        EEPROM_25LC256_WRITE(write_inst);           //Write Read instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to write data to memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB
        EEPROM_25LC256_WRITE(((uint8_t*) &data)[3]);                 //Write Data
        EEPROM_25LC256_WRITE(((uint8_t*) &data)[2]);
        EEPROM_25LC256_WRITE(((uint8_t*) &data)[1]);                 //Write Data
        EEPROM_25LC256_WRITE(((uint8_t*) &data)[0]);
        EEPROM_NCS_HIGH();                  //CS high
    }
    write_latch(wrdi_inst);                 //Reset the write enable latch

}

void write_EEPROMBlock(uint16_t address, uint8_t *data, uint16_t len)
{
    uint8_t stat_reg;
    

    write_latch(wren_inst);                  //Set the write enable latch

    do{
        stat_reg = read_status_register();  //Read Status Register
    }while(stat_reg != STAT_WEL);

    if(stat_reg & STAT_WEL)
    {
        EEPROM_NCS_LOW();
        EEPROM_25LC256_WRITE(write_inst);           //Write Write instruction
        EEPROM_25LC256_WRITE(address>>8);           //Write the address to write data to memory - MSB
        EEPROM_25LC256_WRITE(address);              //LSB
        while(len--)
        {
            EEPROM_25LC256_WRITE(*data++);                 //Write Data
        }
        EEPROM_NCS_HIGH();                  //CS high
    }
    write_latch(wrdi_inst);                 //Reset the write enable latch

}