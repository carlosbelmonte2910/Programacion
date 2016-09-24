/***********************************
*
* www.fatihinanc.com
* 
* Muhammed Fatih �NAN�
* 09.12.2012
*
* LM4F120 i�in 2x16 LCD K�t�phanesi
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

#define delay_us(x)     systick_delay_us(x)
#define delay_ms(x)     systick_delay_ms(x)

#define LCD_DATA        GPIO_PORTD_DATA_R
#define LCD_CONTROL     GPIO_PORTB_DATA_R
#define	EN_ACKAPA()     LCD_EN(1),LCD_EN(0)

#define	LCD_RS(x)       ( (x) ? (LCD_CONTROL |= 0x01) : (LCD_CONTROL &= ~0x01) )
#define LCD_EN(x)       ( (x) ? (LCD_CONTROL |= 0x02) : (LCD_CONTROL &= ~0x02) )


void lcd_komut  (unsigned char); // LCD ye komut g�ndermeye yarar
void lcd_temizle(void);          // LCD ekran� temizler
void lcd_puts   (const char*);   // LCD ye string ifade yazar
void lcd_goto   (char,char);     // LCD de sat�r ve st�n olarak istenilen yere gider
void lcd_init   (void);          // LCD ba�lang�� ayarlar� yap�l�r
void lcd_putch  (char);          // LCD ye tek karakter yazmak i�in kullan�l�r.