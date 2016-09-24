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
	GLCD_Bitmap(UTN_1_b, 64, 0, 64, 32);
	GLCD_Bitmap(UTN_2_b, 0, 0, 64, 32);
	GLCD_Bitmap(UTN_3_b, 64, 4, 64, 32);
	GLCD_Bitmap(UTN_4_b, 0, 4, 64, 32);
	delay_ms(2000);
	GLCD_ClearScreen();

	while(1){
		/*GLCD_GoTo(74,5);
		GLCD_WriteString("Esperando");
		GLCD_GoTo(5,5);
		GLCD_WriteString("estado...");
		GLCD_Bitmap(load_0, 64, 0, 64, 32);
		GLCD_Bitmap(load_31, 0, 0, 64, 32);
		delay_ms(300);
		GLCD_Bitmap(load_1, 64, 0, 64, 32);
		delay_ms(300);
		GLCD_Bitmap(load_2, 64, 0, 64, 32);
		delay_ms(300);
		GLCD_Bitmap(load_3, 64, 0, 64, 32);
		delay_ms(300);
		GLCD_Bitmap(load_3, 64, 0, 64, 32);
		GLCD_Bitmap(load_4, 0, 0, 64, 32);
		delay_ms(300);
		GLCD_Bitmap(load_5, 0, 0, 64, 32);
		delay_ms(300);
		GLCD_Bitmap(load_6, 0, 0, 64, 32);
		delay_ms(300);*/
	}
}
