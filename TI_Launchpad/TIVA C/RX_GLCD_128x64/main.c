#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "KS0108.h"
#include "a_play.h"
#include "USART.h"
#include "systick.h"

int main(void)
{
	systick_init();
	//Setup system clock
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	UartInit();
	GLCD_Initalize();
	GLCD_ClearScreen();
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_1, 0);
	delay_ms(500);
	GLCD_Bitmap(UTN_sup_izq, 64, 0, 64, 32);
	GLCD_Bitmap(UTN_sup_der, 0, 0, 64, 32);
	GLCD_Bitmap(UTN_inf_izq, 64, 4, 64, 32);
	GLCD_Bitmap(UTN_inf_der, 0, 4, 64, 32);
	delay_ms(3000);
	GLCD_ClearScreen();

	while(1){
	}
}
