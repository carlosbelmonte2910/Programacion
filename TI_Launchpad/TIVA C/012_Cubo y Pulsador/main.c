#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

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

void onButtonDown(void);
//void onButtonUp(void);

void apagar(){
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_ALL, FIL_ALL);}

void segundo_efecto(){
	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_3, COL_3);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_6, COL_6);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(12000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_2, COL_2);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_5, COL_5);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_8, COL_8);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(12000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_1, COL_1);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_4, COL_4);
	GPIOPinWrite(GPIO_PORTB_BASE, COL_7, COL_7);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(12000000);}

void tercer_efecto(){
	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, COL_ALL);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_1, 0);
	SysCtlDelay(12000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, COL_ALL);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_2, 0);
	SysCtlDelay(12000000);

	apagar();
	GPIOPinWrite(GPIO_PORTB_BASE, COL_ALL, COL_ALL);
	GPIOPinWrite(GPIO_PORTC_BASE, COL_9, COL_9);
	GPIOPinWrite(GPIO_PORTC_BASE, FIL_3, 0);
	SysCtlDelay(12000000);}

void onButtonDown(void) {
	if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
		// PF4 was interrupt cause
		apagar();
		tercer_efecto();
		//GPIOIntRegister(GPIO_PORTF_BASE, onButtonUp);//Register our handler function for port F
		GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_LOW_LEVEL);//Configure PF4 for rising edge trigger
		GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);//Clear interrupt flag
	}
}

/*void onButtonUp(void) {
	if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
		// PF4 was interrupt cause
		apagar();
		segundo_efecto();
		GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown); //Register our handler function for port F
		GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE);//Configure PF4 for falling edge trigger
		GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);//Clear interrupt flag
	}
}*/

int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_2_5| SYSCTL_USE_PLL | SYSCTL_OSC_INT | SYSCTL_XTAL_16MHZ);

	// Pin F4 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//Enable port F
	SysCtlDelay(10);
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);//Init PF4 as input
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);//Enable weak pullup resistor for PF4

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, COL_ALL);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, COL_9);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, FIL_ALL);
	SysCtlDelay(10);
	apagar();


	// Interrupt setuü
	GPIOIntDisable(GPIO_PORTF_BASE, GPIO_PIN_4);//Disable interrupt for PF4 (in case it was enabled)
	GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);//Clear pending interrupts for PF4
	GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown);//Register our handler function for port F
	GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_LOW_LEVEL);//Configure PF4 for falling edge trigger
	GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4);//Enable interrupt for PF4

	while(1){
		segundo_efecto();
		apagar();
		//SysCtlDelay(7000000);
	}
}
