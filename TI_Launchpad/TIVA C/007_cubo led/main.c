#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

const unsigned int COL_1 = 0x01;
const unsigned int COL_2 = 0x02;
const unsigned int COL_3 = 0x04;
const unsigned int COL_4 = 0x08;
const unsigned int COL_5 = 0x10;
const unsigned int COL_6 = 0x20;
const unsigned int COL_7 = 0x40;
const unsigned int COL_8 = 0x80;
const unsigned int COL_9 = 0x10;//PORT C4

const unsigned int FIL_1 = 0x20;
const unsigned int FIL_2 = 0x40;
const unsigned int FIL_3 = 0x80;

const unsigned int COL_ALL = 0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80;
const unsigned int FIL_ALL = 0x20 | 0x40 | 0x80;

void apagar(){
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_ALL, FIL_ALL);}

void primer_efecto(){
	apagar();
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_8, COL_8);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_7, COL_7);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_4, COL_4);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_1, COL_1);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_2, COL_2);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_3, COL_3);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_6, COL_6);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);}

void segundo_efecto(){
	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_3, COL_3);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_6, COL_6);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_2, COL_2);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_5, COL_5);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_8, COL_8);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_1, COL_1);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_4, COL_4);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_7, COL_7);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);}

void tercer_efecto(){
	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, COL_ALL);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, COL_ALL);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	SysCtlDelay(2000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, COL_ALL);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(2000000);}


int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_8|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, COL_ALL);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, COL_9);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, FIL_ALL);

	SysCtlDelay(10);
	apagar();

	while(1)
	{
		primer_efecto();
		apagar();
		SysCtlDelay(2000000);
		segundo_efecto();
		apagar();
		SysCtlDelay(2000000);
		tercer_efecto();
	}
}
