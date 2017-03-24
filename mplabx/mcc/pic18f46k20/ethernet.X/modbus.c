#include <xc.h>
#include <stddef.h>
#include "mcc_generated_files/TCPIPLibrary/network.h"
#include "modbus.h"

unsigned int table[200] = {0x0000, 0x0000}; //= {0xDEAD, 0xBEEF};
unsigned char bctable[200] = {0,0,0,0,0,0,0,0,0,0,0,0};

unsigned int modbus(mbframestruct *askframe)
{
        int amount = 200;
        int i;
        int firstrequest = 0;
        int requestnumber = 0;
        switch (askframe->pdu.fncode)
        {
                case 1:
                case 2:
                        firstrequest = byteSwap16(askframe->pdu.values.askreadregs.firstreg);
                        requestnumber = byteSwap16(askframe->pdu.values.askreadregs.regnumber);
                        askframe->pdu.values.reqreadcoils.bytestofollow = requestnumber / 8;
                        if ((requestnumber % 8)>0)
                           askframe->pdu.values.reqreadcoils.bytestofollow++;
                        askframe->length = byteSwap16(askframe->pdu.values.reqreadcoils.bytestofollow + 3);
                        for (i = 0; i < askframe->pdu.values.reqreadcoils.bytestofollow; i++)
                                askframe->pdu.values.reqreadcoils.coils[i] = 0;
                        for (i = 0; i < requestnumber; i++)
                                if (firstrequest+i < amount)
                                        if (bctable[firstrequest+i] != 0)
                                                askframe->pdu.values.reqreadcoils.coils[i/8] = askframe->pdu.values.reqreadcoils.coils[i/8] | (0x01 << i%8);
                break;
                case 3:
                case 4:
                        firstrequest = byteSwap16(askframe->pdu.values.askreadregs.firstreg);
                        requestnumber = byteSwap16(askframe->pdu.values.askreadregs.regnumber);
                        askframe->pdu.values.reqreadholdings.bytestofollow = requestnumber * 2;
                        askframe->length = byteSwap16(askframe->pdu.values.reqreadholdings.bytestofollow + 3);
                        for (i = 0; i < requestnumber;i++)
                                if(firstrequest+i < amount) // if requested register within allocated range
                                        askframe->pdu.values.reqreadholdings.registers[i] = byteSwap16(table[firstrequest+i]);
                                else
                                        askframe->pdu.values.reqreadholdings.registers[i] = byteSwap16(0x0000); // fill up with zeroes
                break;
                case 5:
                        if (byteSwap16(askframe->pdu.values.writereg.regaddress) < amount)
                                if (askframe->pdu.values.writereg.regvalue == 0)
                                        bctable[byteSwap16(askframe->pdu.values.writereg.regaddress)] = 0;
                                else
                                        bctable[byteSwap16(askframe->pdu.values.writereg.regaddress)] = 1;
                break;
                case 6:
                        if (byteSwap16(askframe->pdu.values.writereg.regaddress) < amount)
                                table[byteSwap16(askframe->pdu.values.writereg.regaddress)] = byteSwap16(askframe->pdu.values.writereg.regvalue);
                break;
                case 15:
                        for (i = 0; i < byteSwap16(askframe->pdu.values.writemulticoil.regnumber);i++)
                                if (byteSwap16(askframe->pdu.values.writemulticoil.firstreg)+i < amount)
                                        if (askframe->pdu.values.writemulticoil.coils == 0)
                                                bctable[byteSwap16(askframe->pdu.values.writemulticoil.firstreg)+i] = 0;
                                        else
                                                bctable[byteSwap16(askframe->pdu.values.writemulticoil.firstreg)+i] = 1;
                break;
                case 16:
                        for (i = 0; i < byteSwap16(askframe->pdu.values.writemultireg.regnumber);i++)
                                if (byteSwap16(askframe->pdu.values.writemultireg.firstreg)+i < amount)
                                        table[byteSwap16(askframe->pdu.values.writemultireg.firstreg)+i] = byteSwap16(askframe->pdu.values.writemultireg.registers[i]);
                        askframe->length = byteSwap16(6);
                default:
                break;
        }

        return byteSwap16(askframe->length) + 6;
}
