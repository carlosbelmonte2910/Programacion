#ifndef LCD_H_
#define LCD_H_

#define LCDPORT                  GPIO_PORTB_BASE
#define LCDPORTENABLE    SYSCTL_PERIPH_GPIOB
#define RS                               GPIO_PIN_0
#define E                                GPIO_PIN_1
#define D4                               GPIO_PIN_4
#define D5                               GPIO_PIN_5
#define D6                               GPIO_PIN_6
#define D7                               GPIO_PIN_7

void Lcd_comando(unsigned char);//Se utiliza para enviar comandos a la pantalla LCD.
void Lcd_desactivar(void);//Desactiva la pantalla LCD
void Lcd_mensajes(char*);//Print de los mensajes
void Lcd_Goto(char,char);//Env�a el cursor a la ubicaci�n deseada
void Lcd_init(void);//Ajuste iniciales
void Lcd_Putch(unsigned char);//Un car�cter que imprime

#endif /* LCD_H_ */
