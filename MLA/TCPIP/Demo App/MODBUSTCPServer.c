/*********************************************************************
 *
 *	MODBUS TCP Server Example Application
 *      Module for Microchip TCP/IP Stack
 *      -Implements an MODBUS Server over TCP on port 502
 *
 *********************************************************************
 * FileName:        MODBUSTCPServer.c
 * Dependencies:    TCP
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.05 or higher
 *					Microchip C30 v3.12 or higher
 *					Microchip C18 v3.30 or higher
 *					
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2009 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date    	Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Parthiv Pandya     10/1/13           Original
 * 
 *                                  
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *   
 *
 ********************************************************************/
#define __MODBUSTCPSERVER_C

#include "TCPIPConfig.h"

#if defined(STACK_USE_MODBUS_TCP_SERVER)

#include "TCPIP Stack/TCPIP.h"
#include "MODBUSTCPServer.h"


char ReadByteReverse = 1;           //If a modbus client requires to reverse the byte order for HOLDING REGISTER
char InputByteReverse = 1;
char WriteByteReverse = 0;

static BYTE iLlegal_Function;
BYTE MODBUS_RX[MODBUS_RX_BUFFER_SIZE];                //MODBUS TCP buffer
BYTE MODBUS_TX[MODBUS_TX_BUFFER_SIZE];          //Buffer to transfer MODBUS response
WORD_VAL1 COIL;
BYTE COIL_REG[COIL_SIZE];                       //Saves addresses and value for coils
_MODBUS_COMMAND MODBUS_COMMAND;

WORD HOLDING_REG[HOLDING_REG_SIZE] =
                        {
                        0x0000,     //0
                        0x0001,     //1
                        0x0002,     //2
                        0x0003,     //3
                        0x0004,     //4
                        0x0005,     //5
                        0x0006,     //6
                        0x0007,     //7
                        0x0008,     //8
                        0x0009,     //9
                        0x0009,     //10
                        0x0008,     //11
                        0x0007,     //12
                        0x0007,     //13
                        0x0006,     //14
                        0x0005,     //15
                        0x0004,     //16
                        0x0003,     //17
                        0x0002,     //18
                        0x0001,     //19
                        0x0025,     //20
                        0x0035,     //21
                        0x0036,     //22
                        0x9957,     //23
                        0x7890      //24
                       };

    // Copy potentiometer and temperature sensor results in to Input register
WORD    INPUT_REG[INPUT_REG_SIZE] =
                        {
                        0x0001,     //0
                        0x0000,     //1
                        0x0000,     //2
                        0x0003,     //3
                        0x0004,     //4
                        0x0005,     //5
                        0x0006,     //6
                        0x0007,     //7
                        0x0008,     //8
                        0x0009,     //9
                        0x0009,     //10
                        0x0008,     //11
                        0x0007,     //12
                        0x0007,     //13
                        0x0006,     //14
                        0x0005,     //15
                        0x0004,     //16
                        0x0003,     //17
                        0x0002,     //18
                        0x0001      //19
                        };
/*****************************************************************************
  Function:
	void MODBUSTCPServer(void)

  Summary:
	Implements a MODBUS_RX TCP Server.

  Precondition:
	TCP is initialized.

 *   Parameters:
	None

  Returns:
  	None
  ***************************************************************************/
void MODBUSTCPServer(void)
{
    WORD w;
    WORD wMaxGet;

	static TCP_SOCKET	MySocket;
    static enum _MODBUSTCPServerState
    {
            SM_HOME = 0,
            SM_RECEIVEDATA,
    } MODBUSTCPServerState = SM_HOME;

    switch(MODBUSTCPServerState)
    {
            case SM_HOME:
                    // Allocate a socket for this server to listen and accept connections on
                    MySocket = TCPOpen(0, TCP_OPEN_SERVER, MODBUS_PORT, TCP_PURPOSE_MODBUS_TCP_SERVER);
                    if(MySocket == INVALID_SOCKET)
                            return;

                    MODBUSTCPServerState = SM_RECEIVEDATA;
                    break;

            case SM_RECEIVEDATA:
                    // See if anyone is connected to us
                    if(!TCPIsConnected(MySocket))
                            return;

                    // Figure out how many bytes have been received and how many we can transmit.
                    wMaxGet = TCPIsGetReady(MySocket);	// Get TCP RX FIFO byte count
                    if(wMaxGet!=0)
                    {
                        TCPGetArray(MySocket, &MODBUS_RX[0], wMaxGet);
                        ProcessReceivedMessage();

                        switch (MODBUS_COMMAND.FunctionCode)
                        {
                            case ReadHoldingRegister:

                                //Assemble the data
                                readHoldingRegister();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X83))
                                {
                                    w = 0x09 + MODBUS_TX[8];
                                }

                                else w = 9;

                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;

                            case WriteMultipleRegister:

                                //Assemble the data
                                writeHoldingRegister();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X90))
                                {
                                    w = 12;
                                }

                                else w = 9;
                                
                                
                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;

                            case ReadInputRegister:

                                readInputRegister();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X84))
                                {
                                    w = 0x09 + MODBUS_TX[8];
                                }

                                else w = 9;

                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;

                            case WriteSingleCoil:

                                //Assemble the data
                                writeSingleCoil();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X85))
                                {
                                    w = 0x09 + MODBUS_TX[8];
                                }

                                else w = 12;

                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;
                        }

                    }
                    // If the client requested a function which is not supported by this server
                    if(iLlegal_Function)
                    {
                        TCPPutArray(MySocket, MODBUS_TX, 9);
                        iLlegal_Function = 0;
                    }

                    break;
            }
}

#endif //#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)


/*****************************************************************************
  Function:
	void ProcessReceivedMessage(void)

  Summary:
        Decodes Modbus commands. 
        Also, tests if this server supports the requested Modbus command

 *   Parameters:
	None

  Returns:
  	None
  ***************************************************************************/

//Function Definition
void ProcessReceivedMessage(void)
{

    //Transaction Identifier
    MODBUS_COMMAND.TransactionID.v[1] = MODBUS_RX[0];
    MODBUS_COMMAND.TransactionID.v[0] = MODBUS_RX[1];
    //Protocol Identifier
    MODBUS_COMMAND.ProtocolID.v[1] = MODBUS_RX[2];
    MODBUS_COMMAND.ProtocolID.v[0] = MODBUS_RX[3];
    //Number of bytes to receive
    MODBUS_COMMAND.Length = MODBUS_RX[5];
    //Unit Identifier
    MODBUS_COMMAND.UnitID = MODBUS_RX[6];
    //Function code
    MODBUS_COMMAND.FunctionCode = MODBUS_RX[7];
    //Address
    MODBUS_COMMAND.StartAddress.v[1] = MODBUS_RX[8];
    MODBUS_COMMAND.StartAddress.v[0] = MODBUS_RX[9];
    //Number of Register or Quantity
    MODBUS_COMMAND.NumberOfRegister.v[1] = MODBUS_RX[10];
    MODBUS_COMMAND.NumberOfRegister.v[0] = MODBUS_RX[11];

     //Verify the function code
    if(!((MODBUS_COMMAND.FunctionCode == ReadHoldingRegister)      ||
            (MODBUS_COMMAND.FunctionCode == WriteMultipleRegister) ||
            (MODBUS_COMMAND.FunctionCode == ReadInputRegister)     ||
            (MODBUS_COMMAND.FunctionCode == WriteSingleCoil)))
    {
        ModbusError(Illegal_Function_Code);
        memcpy(MODBUS_TX, MODBUS_RX, 9);
        iLlegal_Function = 1;
        return;
    }
}


/*****************************************************************************
  Function:
	void readHoldingRegister(void

  Summary:
        Implements read holding registers command. 

 *   Parameters:
	None

  Returns:
  	None
  ***************************************************************************/
//Reply with Holding register value
void readHoldingRegister(void)
{
    char a;

    //Verify that the data can be sent
    if((MODBUS_COMMAND.StartAddress.Val > ((int)HOLDING_REG_SIZE - 1)) ||
        ((MODBUS_COMMAND.StartAddress.Val - 1 + MODBUS_COMMAND.NumberOfRegister.Val) > (int)HOLDING_REG_SIZE))
    {
        ModbusError(Illegal_Data_Address);
        return;
    }

    //Assemble the data to be sent
    
    //Function code
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = (char)MODBUS_COMMAND.NumberOfRegister.Val*2;
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X3 + MODBUS_RX[8];

    //change the byte order of HOLDING_REG
    if (ReadByteReverse)
    {
       for(a=0; a<sizeof(HOLDING_REG); a++)
        {
            HOLDING_REG[a] = (WORD)((HOLDING_REG[a] & 0xFF) << 8 | (HOLDING_REG[a] & 0xFF00) >> 8);
        }
       ReadByteReverse = 0;
    }

    //Copy MODBUS_RX and HOLdING_REG into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 9);
    memcpy(MODBUS_TX + 9,
            HOLDING_REG + MODBUS_COMMAND.StartAddress.v[1] + MODBUS_COMMAND.StartAddress.v[0],
            sizeof(HOLDING_REG));
}


void writeHoldingRegister(void)
{
    char a;

    //Verify that the data can be sent
    if((MODBUS_COMMAND.StartAddress.Val > ((int)HOLDING_REG_SIZE - 1)) ||
        ((MODBUS_COMMAND.StartAddress.Val - 1 + MODBUS_COMMAND.NumberOfRegister.Val) > (int)HOLDING_REG_SIZE))
    {
        ModbusError(Illegal_Data_Address);
        return;
    }

    //Assemble the data to be sent
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = 0x00; //Byte Count
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X6;


    //Copy MODBUS_RX into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 12);

    a = MODBUS_RX[12];
    //Write multiple register values into HOLDING_REG
    memcpy(HOLDING_REG + MODBUS_COMMAND.StartAddress.v[1] + MODBUS_COMMAND.StartAddress.v[0], MODBUS_RX + 13, a);//sizeof(MODBUS_RX));

    //change the byte order of HOLDING_REG
    if (WriteByteReverse)
    {
       for(a=0; a<sizeof(HOLDING_REG); a++)
        {
            HOLDING_REG[a] = (WORD)((HOLDING_REG[a] & 0xFF) << 8 | (HOLDING_REG[a] & 0xFF00) >> 8);
        }
       WriteByteReverse = 0;
    }


}


//Read Input register
void readInputRegister(void)
{
    char a;

    //Verify that the data can be sent
    if((MODBUS_COMMAND.StartAddress.Val > ((int)INPUT_REG_SIZE - 1)) ||
        ((MODBUS_COMMAND.StartAddress.Val - 1 + MODBUS_COMMAND.NumberOfRegister.Val) > (int)INPUT_REG_SIZE))
    {
        ModbusError(Illegal_Data_Address);
        return;
    }

    //Assemble the data to be sent
    //Function code
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = (char)MODBUS_COMMAND.NumberOfRegister.Val*2;
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X3 + MODBUS_RX[8];

    //change the byte order of INPUT_REG
    if (InputByteReverse)
    {
        for(a=0; a<sizeof(INPUT_REG); a++)
        {
            INPUT_REG[a] = (WORD)((INPUT_REG[a] & 0xFF) << 8 | (INPUT_REG[a] & 0xFF00) >> 8);
        }
       InputByteReverse = 0;
    }

    //Copy MODBUS_RX and HOLEING_REG into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 9);
    memcpy(MODBUS_TX + 9,
            INPUT_REG + MODBUS_COMMAND.StartAddress.v[1] + MODBUS_COMMAND.StartAddress.v[0],
            sizeof(INPUT_REG));
}

//Write single coil
void writeSingleCoil(void)
{

    BYTE *ptCoil;      // Pointer to save Coil value, ON/OFF
    int i;
    
    //Assemble the data to be sent
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = 0x00; //Byte Count
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X6;

    //Copy MODBUS_RX into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 12);

    COIL.Addr = MODBUS_RX[9];
    COIL.Val = MODBUS_RX[10];
    
}



//Modbus Error
void ModbusError(unsigned char ExceptionCode)
{

    MODBUS_RX[4]=0X00;
    MODBUS_RX[5]=0X03;
    MODBUS_RX[MODBUS_FunctionCode]+=0X80;
    MODBUS_RX[MODBUS_ExceptionCode]=ExceptionCode;

     //Copy MODBUS_RX into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 9);

}



