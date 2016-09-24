/*
 * USART.c
 *
 *  Created on: 03/04/2015
 *      Author: Carlos  Belmonte
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "KS0108.h"
#include "a_play.h"
#include "systick.h"

void UartInit(void){
	/*Habilitar los periféricos UART2 y GPIOD (los pines UART están en el Puerto D)*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	/*Configurar los pines para el receptor y transmisor utilizando GPIOPinConfigure*/
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	/*Inicialice los parámetros para UART: 115200, 8-1-N*/
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	UARTFIFOLevelSet(UART0_BASE, UART_FIFO_TX4_8, UART_FIFO_RX4_8); //set FIFO level to 8 characters
	UARTFIFOEnable(UART0_BASE); //enable FIFOs

	IntMasterEnable();
	IntEnable(INT_UART0);
	UARTIntEnable(UART0_BASE, UART_INT_TX| UART_INT_RX | UART_INT_RT);
}

void UARTIntHandler(void)
{
	uint32_t ui32Status;
	unsigned char received_character;
	ui32Status = UARTIntStatus(UART0_BASE, true); //obtener el estado de la interrupción
	UARTIntClear(UART0_BASE, ui32Status); //borrar las interrupciones afirmadas

	while(UARTCharsAvail(UART0_BASE)) //bucle mientras que hay caracteres
	{
		received_character = UARTCharGetNonBlocking(UART0_BASE);
		if(received_character == 0x55){
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_1, 0);
			GLCD_ClearScreen();
			mensajes1(0);
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);}

		else{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_1, 0);
			GLCD_ClearScreen();
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
			while(received_character != 0x55){
				received_character = UARTCharGetNonBlocking(UART0_BASE);
				GLCD_Bitmap(A, 89, 0, 13, 16);
				GLCD_Bitmap(T, 102, 0, 13, 16);
				GLCD_Bitmap(E, 115, 0, 13, 16);
				GLCD_Bitmap(N, 0, 0, 13, 16);
				GLCD_Bitmap(C, 13, 0, 13, 16);
				GLCD_Bitmap(I, 26, 0, 13, 16);
				GLCD_Bitmap(O, 39, 0, 13, 16);
				GLCD_Bitmap(N, 52, 0, 13, 16);
				GLCD_Bitmap(alerta1, 64, 0, 24, 24);
				delay_ms(200);
				GLCD_Bitmap(alerta2, 64, 0, 24, 24);
				delay_ms(200);
				GLCD_GoTo(90,2);
				GLCD_WriteString("Fallas");
				GLCD_GoTo(4,2);
				GLCD_WriteString("detectadas");
				GLCD_Bitmap(linea_inf, 0, 3, 64, 8);
				GLCD_Bitmap(linea_inf, 64, 3, 64, 8);
				GLCD_Bitmap(linea_sup, 0, 5, 64, 8);
				GLCD_Bitmap(linea_sup, 64, 5, 64, 8);
				GLCD_GoTo(64,6);
				GLCD_WriteString("Hora de la");
				GLCD_GoTo(64,7);
				GLCD_WriteString("falla:");
				GLCD_Bitmap(num0, 2, 6, 13, 16);
				GLCD_Bitmap(num3, 15, 6, 13, 16);
				GLCD_Bitmap(dos_puntos, 28, 6, 5, 16);
				GLCD_Bitmap(num5, 33, 6, 13, 16);
				GLCD_Bitmap(num4, 46, 6, 13, 16);
				switch(received_character){
				case 0x41:
					mensajes(1);
					break;
				case 0x42:
					mensajes(2);
					break;
				case 0x43:
					mensajes(3);
					break;
				case 0x44:
					mensajes(4);
					break;
				case 0x45:
					mensajes(5);
					break;
				case 0x46:
					mensajes(6);
					break;
				case 0x47:
					mensajes(7);
					break;
				case 0x48:
					mensajes(8);
					break;
				case 0x49:
					mensajes(9);
					break;
				case 0x4A:
					mensajes(10);
					break;
				case 0x4B:
					mensajes(11);
					break;
				case 0x4C:
					mensajes(12);
					break;
				case 0x4D:
					mensajes(13);
					break;
				case 0x4E:
					mensajes(14);
					break;
				case 0x4F:
					mensajes(15);
					break;
				case 0x50:
					mensajes(16);
					break;
				case 0x51:
					mensajes(17);
					break;
				case 0x52:
					mensajes(18);
					break;
				case 0x53:
					mensajes(19);
					break;
				case 0x54:
					mensajes(20);
					break;}}
		}
	}
}



