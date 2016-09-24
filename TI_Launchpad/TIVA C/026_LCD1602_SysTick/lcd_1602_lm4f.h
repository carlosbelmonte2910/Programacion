/***********************************
*
* www.fatihinanc.com
* 
* Muhammed Fatih ÝNANÇ
* 09.12.2012
*
* LM4F120 için 2x16 LCD Kütüphanesi
* Stellaris LaunchPad
*
***********************************/
/*

RS -> PB0
EN -> PB1

D4 -> PD0
D5 -> PD1
D6 -> PD2
D7 -> PD3

*/

//#define delay_us(x)     systick_delay_us(x)
//#define delay_ms(x)     systick_delay_ms(x)

#define LCD_DATA        GPIO_PORTD_DATA_R
#define LCD_CONTROL     GPIO_PORTB_DATA_R
#define	EN_ACKAPA()     LCD_EN(1),LCD_EN(0)

#define	LCD_RS(x)       ( (x) ? (LCD_CONTROL |= 0x01) : (LCD_CONTROL &= ~0x01) )
#define LCD_EN(x)       ( (x) ? (LCD_CONTROL |= 0x02) : (LCD_CONTROL &= ~0x02) )


void lcd_komut  (unsigned char);
void lcd_temizle(void);
void lcd_puts   (const char*);
void lcd_goto   (char,char);
void lcd_init   (void);
void lcd_putch  (char);
