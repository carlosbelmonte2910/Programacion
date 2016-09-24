#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"

const unsigned int LED_1 = 0x01;
const unsigned int LED_2 = 0x02;
const unsigned int LED_3 = 0x04;
const unsigned int LED_4 = 0x08;


const unsigned int LEDS_ALL = 0x01 | 0x02 | 0x04|0x08;

void PortFIntHandler(){
	IntMasterDisable(); //disable interrupts

	if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_4) ==0){
				//Set PF1 as high. 2 ~ 0b00000010-->mask PF1
				GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
				GPIOPinWrite(GPIO_PORTB_BASE, LED_1, LED_1);
				SysCtlDelay(8500000);

				GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
				GPIOPinWrite(GPIO_PORTB_BASE, LED_2, LED_2);
				SysCtlDelay(8500000);

				GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
				GPIOPinWrite(GPIO_PORTB_BASE, LED_3, LED_3);
				SysCtlDelay(8500000);

				GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
				GPIOPinWrite(GPIO_PORTB_BASE, LED_4, LED_4);
				SysCtlDelay(8500000);}

	if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_5) ==0){
					//Set PF1 as high. 2 ~ 0b00000010-->mask PF1
					GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
					GPIOPinWrite(GPIO_PORTB_BASE, LED_4, LED_4);
					SysCtlDelay(8500000);

					GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
					GPIOPinWrite(GPIO_PORTB_BASE, LED_3, LED_3);
					SysCtlDelay(8500000);

					GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
					GPIOPinWrite(GPIO_PORTB_BASE, LED_2, LED_2);
					SysCtlDelay(8500000);

					GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);
					GPIOPinWrite(GPIO_PORTB_BASE, LED_1, LED_1);
					SysCtlDelay(8500000);}

	GPIOIntClear(GPIO_PORTB_BASE,GPIO_INT_PIN_4);
	GPIOIntClear(GPIO_PORTB_BASE,GPIO_INT_PIN_5);
	IntMasterEnable();
	GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);

}


int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	// Set PF4(SW_1) as input
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_4);
	GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
	GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_4,GPIO_LOW_LEVEL);

//---------------------------------------------
		GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_5);
		GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_5, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
//-----------------------------------------------------------------


	//Set PF1(RED LED) as output
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, LEDS_ALL);
	//Turn of the LED
	GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0);

//-----------------------------------------------------------------
	GPIOIntEnable(GPIO_PORTB_BASE,GPIO_INT_PIN_5);
	IntMasterEnable();
	IntEnable(INT_GPIOB);
//-----------------------------------------------------------------

	GPIOIntEnable(GPIO_PORTB_BASE,GPIO_INT_PIN_4);
	IntMasterEnable();
	IntEnable(INT_GPIOB);

	while(1)
	{
		//GPIOPinWrite(GPIO_PORTB_BASE, LEDS_ALL, 0x0F);
	}
}
