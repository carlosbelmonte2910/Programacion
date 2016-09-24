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

//unsigned char received_character;

void UARTIntHandler(void)
{
	uint32_t ui32Status;
	unsigned char received_character;

	ui32Status = UARTIntStatus(UART2_BASE, true); //obtener el estado de la interrupción
	UARTIntClear(UART2_BASE, ui32Status); //borrar las interrupciones afirmadas

	while(UARTCharsAvail(UART2_BASE)) //bucle mientras que hay caracteres
	{
		received_character = UARTCharGetNonBlocking(UART2_BASE);
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

int main(void) {
	/*Configurar el reloj del sistema, en este caso 50Mhz*/
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	Lcd_init();

	/*Habilitar los periféricos UART2 y GPIOD (los pines UART están en el Puerto D)*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	/*Configurar los pines para el receptor y transmisor utilizando GPIOPinConfigure*/
	GPIOPinConfigure(GPIO_PD6_U2RX);
	GPIOPinConfigure(GPIO_PD7_U2TX);
	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);

	/*Inicialice los parámetros para UART: 115200, 8-1-N*/
	UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	UARTFIFOLevelSet(UART2_BASE, UART_FIFO_TX4_8, UART_FIFO_RX4_8); //set FIFO level to 8 characters
	UARTFIFOEnable(UART2_BASE); //enable FIFOs

	IntMasterEnable();
	IntEnable(INT_UART2);
	UARTIntEnable(UART2_BASE, UART_INT_TX| UART_INT_RX | UART_INT_RT);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

/*	Utilizar "UARTCharPut ()" para llamar a crear una petición
	UARTCharPut(UART0_BASE, 'E');
	UARTCharPut(UART0_BASE, 'n');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 'r');
	UARTCharPut(UART0_BASE, ' ');
	UARTCharPut(UART0_BASE, 'T');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 'x');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, ':');
	UARTCharPut(UART0_BASE, ' ');*/

	/*En este bucle infinito,  si hay un caracter en el receptor, este se lee,
	 *y luego escrito al transmisor. Esto hace eco de lo que se escribe en la ventana de terminal.*/
	while(1) //bucle mientras que hay caracteres
		{

		}
}
