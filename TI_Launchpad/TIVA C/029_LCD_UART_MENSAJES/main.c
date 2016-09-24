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
#include "USART.h"
#include "systick.h"
//unsigned char received_character;

int main(void) {
	systick_init();
	/*Configurar el reloj del sistema, en este caso 50Mhz*/
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	Lcd_init();
	UartInit();

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);


	/*En este bucle infinito,  si hay un caracter en el receptor, este se lee,
	 *y luego escrito al transmisor. Esto hace eco de lo que se escribe en la ventana de terminal.*/
	while(1) //bucle mientras que hay caracteres
		{

		}
}
