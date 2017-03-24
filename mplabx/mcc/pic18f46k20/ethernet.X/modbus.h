typedef struct  {
        unsigned int firstreg;
        unsigned int regnumber;
}askreadregstruct;

typedef struct  {
        unsigned char bytestofollow;
        unsigned char coils[256];
}reqreadcoilsstruct;

typedef struct  {
        unsigned char bytestofollow;
        unsigned int registers[128];
}reqreadwordstruct;

typedef struct  {
        unsigned int regaddress;
        unsigned int regvalue;
}writeregstruct;

typedef struct  {
        unsigned int firstreg;
        unsigned int regnumber;
        unsigned char bytestofollow;
        unsigned char coils[256];
}writemulticoilstruct;

typedef struct  {
        unsigned int firstreg;
        unsigned int regnumber;
        unsigned char bytestofollow;
        unsigned int registers[128];
}writemultiregstruct;

typedef union  {
        askreadregstruct askreadregs;
        reqreadcoilsstruct reqreadcoils;
        reqreadwordstruct reqreadholdings;
        writeregstruct writereg;
        writemulticoilstruct writemulticoil;
        writemultiregstruct writemultireg;
        unsigned int words[128];
        unsigned char bytes[256];
}pdudataunion;

typedef struct  {
        unsigned char unitid;
        unsigned char fncode;
        pdudataunion values;
}pduframestruct;

typedef struct  {
        unsigned int tsid;
        unsigned int protoid;
        unsigned int length;
        pduframestruct pdu;
}mbframestruct;

unsigned int modbus(mbframestruct *askframe);