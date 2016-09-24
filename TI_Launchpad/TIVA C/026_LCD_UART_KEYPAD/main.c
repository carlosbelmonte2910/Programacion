#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/rom.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "Lcd.h"
#include "KeyPad.h"

//unsigned char received_character;
//temporal variable where to store the key press number
static int num;

/* ISR to key-scan, i have been thinking to just raise a flag and then later on check keypad */
void scan_key(void)
{
	int i;
	int key=0;
	IntMasterDisable(); //disable interrupts
	for (i=0;i<4;i++)
	{
		GPIOPinWrite(FILAS, GPIO_PIN_2, (i==0)?0:GPIO_PIN_2);
		GPIOPinWrite(FILAS, GPIO_PIN_3, (i==1)?0:GPIO_PIN_3);
		GPIOPinWrite(FILAS, GPIO_PIN_4, (i==2)?0:GPIO_PIN_4);
		GPIOPinWrite(FILAS, GPIO_PIN_5, (i==3)?0:GPIO_PIN_5);

		if ( GPIOPinRead(COLS,GPIO_PIN_3) == 0)
		{
			switch (i)
			{
			case 0: key=0x0A;break;
			case 1: key=0x0B;break;
			case 2: key=0x0C;break;
			case 3: key=0x0D;break;
			default: key=-1;
			}
			break;
		}
		else if (GPIOPinRead(COLS,GPIO_PIN_2) == 0)
		{
			switch (i)
			{
			case 0: key=0x03;break;
			case 1: key=0x06;break;
			case 2: key=0x09;break;
			case 3: key=0x0E;break;
			default: key=-1;
			}
			break;
		}
		else if (GPIOPinRead(COLS,GPIO_PIN_1) == 0)
		{
			switch (i)
			{
			case 0: key=0x02;break;
			case 1: key=0x05;break;
			case 2: key=0x08;break;
			case 3: key=0x00;break;
			default: key=-1;
			}
			break;
		}
		else if (GPIOPinRead(COLS,GPIO_PIN_0) == 0)
		{
			switch (i)
			{
			case 0: key=0x01;break;
			case 1: key=0x04;break;
			case 2: key=0x07;break;
			case 3: key=0x0F;break;
			default: key=-1;
			}
			break;
		}
	}
	//get ready for next interruption
	GPIOPinWrite(FILAS, GPIO_PIN_2, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_3, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_4, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_5, 0);
	//store the value
	num = key;
	GPIOIntClear(COLS,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	IntMasterEnable();
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
		//UARTCharPutNonBlocking(UART0_BASE, received_character); //echo character
		if (received_character == 0x47){
			//UARTCharPutNonBlocking(UART0_BASE, 10); //if CR received,issue LF as well
			Lcd_Goto(1,1);
			Lcd_mensajes("Lampara 1: Apagada  ");}
		if (received_character == 0x42){
			//UARTCharPutNonBlocking(UART0_BASE, 10); //if CR received,issue LF as well
			Lcd_Goto(1,1);
			Lcd_mensajes("Lampara 1: Encendida");}


	}
}

void mensaje(){
	if (num == 1)
	{
		SysCtlDelay(SysCtlClockGet()/4);
		if (num == 9)
		{
			Lcd_Goto(1,1);
			Lcd_mensajes("Lampara 1: Encendida");
		}
		num = 0;
	}
}

void main(void) {
		/*Configurar el reloj del sistema, en este caso 50Mhz*/
		SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
		setup();
		Lcd_init();

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

		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);


		/*En este bucle infinito,  si hay un caracter en el receptor, este se lee,
		 *y luego escrito al transmisor. Esto hace eco de lo que se escribe en la ventana de terminal.*/
		while(1) //bucle mientras que hay caracteres
		{
			mensaje();
		}
}
