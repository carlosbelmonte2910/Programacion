/*
 * USART.c
 *
 *  Created on: 03/04/2015
 *      Author: Carlos  Belmonte
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "Lcd.h"
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
		switch(received_character){
		case 0x34:
			Lcd_Goto(1,1);
			mensajes(0);
			break;
		case 0x35:
			Lcd_Goto(1,1);
			mensajes(1);
			break;
		case 0x36:
			Lcd_Goto(1,1);
			mensajes(2);
			break;
		case 0x38:
			Lcd_Goto(1,1);
			mensajes(3);
			break;
		case 0x4A:
			Lcd_Goto(1,1);
			mensajes(4);
			break;
		case 0x4C:
			Lcd_Goto(1,1);
			mensajes(5);
			break;
		case 0x49:
			Lcd_Goto(1,1);
			mensajes(6);
			break;
		case 0x4B:
			Lcd_Goto(1,1);
			mensajes(7);
			break;
		case 0x41:
			Lcd_Goto(1,1);
			mensajes(8);
			break;
		case 0x44:
			Lcd_Goto(1,1);
			mensajes(9);
			break;
		}
	}
}



