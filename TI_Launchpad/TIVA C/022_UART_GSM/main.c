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
#include "driverlib/systick.h"

//SysCtlDelay(7440475);//500ms
	//SysCtlDelay(15000000);//1000ms
	//SysCtlDelay(22000000);//1500ms
	//SysCtlDelay(30000000);//2000ms
	//SysCtlDelay(150000000);//10000ms
	//SysCtlDelay(300000000);//20000ms


void mensaje(){
	SysCtlDelay(30000000);//2000ms
	UARTCharPut(UART3_BASE, 'A');
	UARTCharPut(UART3_BASE, 'T');
	UARTCharPut(UART3_BASE, '+');
	UARTCharPut(UART3_BASE, 'C');
	UARTCharPut(UART3_BASE, 'M');
	UARTCharPut(UART3_BASE, 'G');
	UARTCharPut(UART3_BASE, 'F');
	UARTCharPut(UART3_BASE, '=');
	UARTCharPut(UART3_BASE, '1');
	UARTCharPut(UART3_BASE, 0x0D);//retorno de carro (CR)
	UARTCharPut(UART3_BASE, 0x0A);//salto de linea (LF)
	SysCtlDelay(22000000);//1500ms
	UARTCharPut(UART3_BASE, 'A');
	UARTCharPut(UART3_BASE, 'T');
	UARTCharPut(UART3_BASE, '+');
	UARTCharPut(UART3_BASE, 'C');
	UARTCharPut(UART3_BASE, 'M');
	UARTCharPut(UART3_BASE, 'G');
	UARTCharPut(UART3_BASE, 'S');
	UARTCharPut(UART3_BASE, '=');
	UARTCharPut(UART3_BASE, 0x22);
	UARTCharPut(UART3_BASE, '3');
	UARTCharPut(UART3_BASE, '8');
	UARTCharPut(UART3_BASE, '1');
	UARTCharPut(UART3_BASE, '5');
	UARTCharPut(UART3_BASE, '2');
	UARTCharPut(UART3_BASE, '1');
	UARTCharPut(UART3_BASE, '6');
	UARTCharPut(UART3_BASE, '8');
	UARTCharPut(UART3_BASE, '6');
	UARTCharPut(UART3_BASE, '8');
	UARTCharPut(UART3_BASE, 0x22);
	UARTCharPut(UART3_BASE, 0x0D);//retorno de carro (CR)
	UARTCharPut(UART3_BASE, 0x0A);//salto de linea (LF)
	SysCtlDelay(22000000);//1500ms
	UARTCharPut(UART3_BASE, 'M');
	UARTCharPut(UART3_BASE, 'I');
	UARTCharPut(UART3_BASE, 'K');
	UARTCharPut(UART3_BASE, 'A');
	UARTCharPut(UART3_BASE, '!');
	SysCtlDelay(22000000);//1500ms
	UARTCharPut(UART3_BASE, 0x1A);//final del mensaje (Ctrl+Z)
	SysCtlDelay(150000000);//10000ms

}

int main(void) {
	/*Configurar el reloj del sistema, en este caso 50Mhz*/
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

	/*Habilitar los periféricos UART2 y GPIOD (los pines UART están en el Puerto D)*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

	/*Configurar los pines para el receptor y transmisor utilizando GPIOPinConfigure*/
	GPIOPinConfigure(GPIO_PC6_U3RX);
	GPIOPinConfigure(GPIO_PC7_U3TX);
	GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);

	/*Inicialice los parámetros para UART: 115200, 8-1-N*/
	UARTConfigSetExpClk(UART3_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	//UARTFIFOLevelSet(UART3_BASE, UART_FIFO_TX4_8, UART_FIFO_RX4_8); //set FIFO level to 8 characters
	UARTFIFOEnable(UART3_BASE); //enable FIFOs

	//SysTickPeriodSet(SysCtlClockGet());
	//SysTickEnable();

	//IntMasterEnable();
	//IntEnable(INT_UART3);
	//UARTIntEnable(UART3_BASE, UART_INT_TX| UART_INT_RX | UART_INT_RT);

	//SysCtlDelay(7440475);//500ms
	//SysCtlDelay(15000000);//1000ms
	//SysCtlDelay(22000000);//1500ms
	//SysCtlDelay(30000000);//2000ms
	//SysCtlDelay(150000000);//10000ms
	//SysCtlDelay(300000000);//20000ms




	while (1)
	{
		mensaje();

	}
}

