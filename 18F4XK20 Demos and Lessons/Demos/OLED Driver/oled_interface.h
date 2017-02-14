// OLED Interface

#define SPI

#define oled_res	LATAbits.LATA4
#define oled_c		LATAbits.LATA5
#define oled_cs		LATAbits.LATA7

#define CHIP_SELECT()    oled_cs = 0
#define COMMAND_SELECT() oled_c = 0
#define DATA_SELECT()    oled_c = 1
#define CHIP_UNSELECT()  oled_cs = 1

#ifdef SPI
#define WRITE(d) write_spi(d)
#endif
#ifdef I2C
#define WRITE(d) write_i2c(d)
#endif
#ifdef PARALLEL// Parallel
#define WRITE(d) write_parallel(d)
#endif

void oled_SendCommand(unsigned char *d,unsigned char c);
void oled_SendCommand_2(unsigned char d,unsigned char c);

void oled_SendData(unsigned char *d,unsigned char c);
void oled_SendData_2(unsigned char d,unsigned char c);
void write_spi(char);
void write_i2c(char);
void write_parallel(char);
char read_parallel(void);
