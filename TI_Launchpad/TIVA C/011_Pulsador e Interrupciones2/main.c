#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void onButtonDown(void);
void onButtonUp(void);

void onButtonDown(void) {
	if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
		// PF4 was interrupt cause
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 2);
		//SysCtlDelay(4000000);
		//GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		printf("Button Down\n");
		GPIOIntRegister(GPIO_PORTF_BASE, onButtonUp);//Register our handler function for port F
		GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_RISING_EDGE);//Configure PF4 for rising edge trigger
		GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);//Clear interrupt flag
	}
}

void onButtonUp(void) {
	if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
		// PF4 was interrupt cause
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 4);
		printf("Button Up\n");
		GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown); //Register our handler function for port F
		GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE);//Configure PF4 for falling edge trigger
		GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);//Clear interrupt flag
	}
}

int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_2_5| SYSCTL_USE_PLL | SYSCTL_OSC_INT | SYSCTL_XTAL_16MHZ);

	// Pin F4 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//Enable port F
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);//Init PF4 as input
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);//Enable weak pullup resistor for PF4
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

	// Interrupt setuü
	GPIOIntDisable(GPIO_PORTF_BASE, GPIO_PIN_4);//Disable interrupt for PF4 (in case it was enabled)
	GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);//Clear pending interrupts for PF4
	GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown);//Register our handler function for port F
	GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE);//Configure PF4 for falling edge trigger
	GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4);//Enable interrupt for PF4

	while(1);
}
