// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MODBUS_H
#define	XC_MODBUS_H

typedef struct  {
        unsigned short firstreg;
        unsigned short regnumber;
}askreadregstruct;

typedef struct  {
        unsigned short regaddress;
        unsigned short regvalue;
}writeregstruct;

typedef struct  {
        unsigned char bytestofollow;
        unsigned char bytes[254];
}reqreadstruct;

typedef struct  {
        unsigned short firstreg;
        unsigned short regnumber;
        unsigned char bytestofollow;
        unsigned char coils[256];
}writemulticoilstruct;

typedef struct  {
        unsigned short firstreg;
        unsigned short regnumber;
        unsigned char bytestofollow;
        unsigned short registers[127];
}writemultiregstruct;

typedef union  {
        askreadregstruct askreadregs;
        reqreadstruct reqread;
        writeregstruct writereg;
        writemulticoilstruct writemulticoil;
        writemultiregstruct writemultireg;
        unsigned short words[127];
        unsigned char bytes[254];
}pdudataunion;

typedef struct  {
        unsigned char unitid;
        unsigned char fncode;
        pdudataunion data;
        unsigned short checksum;
}mbframestruct;

#endif	/* XC_MODBUS_H */

