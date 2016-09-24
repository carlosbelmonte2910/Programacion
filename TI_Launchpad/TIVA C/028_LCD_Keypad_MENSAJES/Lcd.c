#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "systick.h"
#include "Lcd.h"

void Lcd_init() {

	SysCtlPeripheralEnable(LCDPORTENABLE);//Se habilita el portB
	GPIOPinTypeGPIOOutput(LCDPORT, 0xFF);//el puerto como salida

	delay_us(500);

	GPIOPinWrite(LCDPORT, RS,  0x00 );//Seleccionamos registro de instrucciones, indicamos al LCD que lo que hay en el bus de datos (pines desde 7 a 14) es una instrucción
	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7,  0x30 );//Funcion Set: se configura para mandar los datos por un bus de 8bits
	GPIOPinWrite(LCDPORT, E, 0x02);//Se habilita el modulo LCD
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);//Se deshabilita el modulo LCD

	delay_us(500);

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7,  0x30 );
	GPIOPinWrite(LCDPORT, E, 0x02);
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);

	delay_us(500);

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7,  0x30 );
	GPIOPinWrite(LCDPORT, E, 0x02);
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);

	delay_us(500);

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7,  0x20 );//Funcion Set: se configura para mandar los datos por un bus de 8bits
	GPIOPinWrite(LCDPORT, E, 0x02);
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);

	delay_us(500);

	Lcd_comando(0x28);//Funcion SET: Bus de 4bits, 4lineas, matriz de 5x8puntos
	Lcd_comando(0xC0);//Set DDRAM address
	Lcd_comando(0x06);//Entry Mode set: establece la direccion de movimiento del cursor
	Lcd_comando(0x80);//Set DDRAM address: Los datos a almacenar en DDRAM pueden ser enviados después de esta instrucción
	Lcd_comando(0x28);//Funcion SET: Bus de 4bits, 4lineas, matriz de 5x8puntos
	Lcd_comando(0x0C);//Display ON/OFF: D(1) el mensaje se hace visible,C(0) el cursor es invisible, B(0) no parpadea
	Lcd_desactivar();

}
void Lcd_comando(unsigned char c) {

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (c & 0xf0) );//Se hace una operacion AND entre el comando y F0, se envia el nibble mas alto primero
	GPIOPinWrite(LCDPORT, RS, 0x00);//Seleccionamos registro de instrucciones
	GPIOPinWrite(LCDPORT, E, 0x02);//Se habilita el modulo LCD
	delay_us(500);
	GPIOPinWrite(LCDPORT, E, 0x00);//Se deshabilita el modulo LCD

	delay_us(500);

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (c & 0x0f) << 4 );//Se hace una operacion AND entre el comando y 0F, se envia el nibble mas bajo despues de enviar el primero
	GPIOPinWrite(LCDPORT, RS, 0x00);//Seleccionamos registro de instrucciones
	GPIOPinWrite(LCDPORT, E, 0x02);//Se habilita el modulo LCD
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);//Se deshabilita el modulo LCD

	delay_us(500);

}

void Lcd_Putch(unsigned char d) {

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (d & 0xf0) );//Se hace una operacion AND entre la letra (ASCII) y F0, se envia el nibble mas alto primero
	GPIOPinWrite(LCDPORT, RS, 0x01);//Seleccionamos registro de datos
	GPIOPinWrite(LCDPORT, E, 0x02);//Se habilita el modulo LCD
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);//Se deshabilita el modulo LCD

	delay_us(500);

	GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (d & 0x0f) << 4 );//Se hace una operacion AND entre la letra (ASCII) y 0F, se envia el nibble mas bajo despues de enviar el primero
	GPIOPinWrite(LCDPORT, RS, 0x01);//Seleccionamos registro de datos
	GPIOPinWrite(LCDPORT, E, 0x02);//Se habilita el modulo LCD
	delay_us(10);
	GPIOPinWrite(LCDPORT, E, 0x00);//Se deshabilita el modulo LCD

	delay_us(500);

}
void Lcd_Goto(char x, char y){
	if(x==1){
		Lcd_comando(0x80+((y-1)%20));}//FILA 1

	if(x==2){
		Lcd_comando(0xC0+((y-1)%20));}//FILA 2

	if(x==3){
		Lcd_comando(0x94+((y-1)%20));}//FILA 3

	if(x==4){
		Lcd_comando(0xD4+((y-1)%20));}//FILA 4
}

void Lcd_desactivar(void){
	Lcd_comando(0x01);//Clear Display: Borra todo en pantalla
	delay_us(10);
}

void Lcd_mensajes( char* s){

	while(*s)
		Lcd_Putch(*s++);//Se suman los caracteres uno a uno
}

void mensajes(int w){
	if(w==0){Lcd_mensajes("Molienda Normal     ");}
	if(w==1){Lcd_mensajes("Falta de cana       ");}
	if(w==2){Lcd_mensajes("Falla Usina SIEMENS ");}
	if(w==3){Lcd_mensajes("Falla Usina MARELLI ");}
	if(w==4){Lcd_mensajes("Falla en Caldera 1  ");}
	if(w==5){Lcd_mensajes("Falla en Caldera 2  ");}
	if(w==6){Lcd_mensajes("Falla en Caldera 3  ");}
	if(w==7){Lcd_mensajes("Falla en Caldera 4  ");}
	if(w==8){Lcd_mensajes("Baja presion vapor  ");}
	if(w==9){Lcd_mensajes("Falta de gas        ");}
   if(w==10){Lcd_mensajes("Atascamiento Molino1");}
   if(w==11){Lcd_mensajes("Atascamiento Molino2");}
   if(w==12){Lcd_mensajes("Atascamiento Molino3");}
   if(w==13){Lcd_mensajes("Falla en Encaladora ");}
   if(w==14){Lcd_mensajes("Falla Horno Azufre  ");}
   if(w==15){Lcd_mensajes("Rotura Cinta Bagacer");}
   if(w==16){Lcd_mensajes("Fallas en Centrifuga");}
   if(w==17){Lcd_mensajes("Filtro Cachaza Atasc");}
   if(w==18){Lcd_mensajes("Falla en Calentador ");}
   if(w==19){Lcd_mensajes("Falla Cristalizador ");}
   if(w==20){Lcd_mensajes("Falla Tolva Azucar  ");}
}
