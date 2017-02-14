#define SPI
void oled_init(void);
void oled_clear(void);
void oled_draw_row(char, unsigned char *);

void oled_off(void);
void oled_on(void);
void oled_reset(void);
void oled_refresh(void);
void putpixel_vram(unsigned char x,unsigned char y,unsigned char color);
void oled_putc_1x(char);
void oled_putc_2x(char);
void oled_WriteChar1x(char, unsigned char, unsigned char);
void oled_WriteChar2x(char, unsigned char, unsigned char);
void oled_puts_1x(char *s);
void oled_puts_2x(char *s);
void oled_plotbar(unsigned char r, unsigned char c, unsigned char v);
void oled_ScreenSaver(unsigned char enable);
void oled_SetBrightness(char b);
