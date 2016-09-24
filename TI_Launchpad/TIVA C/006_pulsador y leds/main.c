#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

const unsigned int LED_1 = 0x01;
const unsigned int LED_2 = 0x02;
const unsigned int LED_3 = 0x04;
const unsigned int LED_4 = 0x08;
const unsigned int LED_5 = 0x10;
const unsigned int LED_6 = 0x20;
const unsigned int LED_7 = 0x40;

const unsigned int LEDS_ALL = 0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40;

int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_8|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	// Set PF4(SW_1) as input
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);

	//Set PF1(RED LED) as output
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, LEDS_ALL);
	//Turn of the LED
	GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);

	while(1)
	{
		//Check whether the button is pressed.
		if(!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4)){
			//Set PF1 as high. 2 ~ 0b00000010-->mask PF1
			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_1, LED_1);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_2, LED_2);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_3, LED_3);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_4, LED_4);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_5, LED_5);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_6, LED_6);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_7, LED_7);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);}

		else{
			GPIOPinWrite(GPIO_PORTB_BASE, LED_4, LED_4);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_3|LED_5, LED_3|LED_5);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_2|LED_6, LED_2|LED_6);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
			GPIOPinWrite(GPIO_PORTB_BASE, LED_1|LED_7, LED_1|LED_7);
			SysCtlDelay(1500000);

			GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);}
	}
}
