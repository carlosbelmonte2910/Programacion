#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "systick.h"
#include "Lcd.h"

int i=0;
int j=0;
int k=0;
int main(void) {
	systick_init();
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);//50Mhz el reloj del sistema
	Lcd_init();
	delay_ms(1000);
	while (1) {
		Lcd_Goto(4,4);
		Lcd_mensajes("Carlos Mariano");
		Lcd_Goto(3,7);
		Lcd_mensajes("Belmonte");

		Lcd_Goto(1,20);
		Lcd_mensajes("U");
		SysCtlDelay(6500000);
		Lcd_Goto(1,19);
		Lcd_mensajes("UT");
		SysCtlDelay(6500000);
		Lcd_Goto(1,18);
		Lcd_mensajes("UTN");
		SysCtlDelay(6500000);
		Lcd_Goto(1,17);
		Lcd_mensajes("UTN-");
		SysCtlDelay(6500000);
		Lcd_Goto(1,16);
		Lcd_mensajes("UTN-F");
		SysCtlDelay(6500000);
		Lcd_Goto(1,15);
		Lcd_mensajes("UTN-FR");
		SysCtlDelay(6500000);

		for(i=14; i > 0; i--){
			Lcd_Goto(1,i);
			Lcd_mensajes("UTN-FRT  ");
			SysCtlDelay(7500000);}

		Lcd_Goto(1,1);
		Lcd_mensajes("TN-FRT  ");
		SysCtlDelay(6500000);
		Lcd_Goto(1,1);
		Lcd_mensajes("N-FRT   ");
		SysCtlDelay(6500000);
		Lcd_Goto(1,1);
		Lcd_mensajes("-FRT    ");
		SysCtlDelay(6500000);
		Lcd_Goto(1,1);
		Lcd_mensajes("FRT    ");
		SysCtlDelay(6500000);
		Lcd_Goto(1,1);
		Lcd_mensajes("RT    ");
		SysCtlDelay(6500000);
		Lcd_Goto(1,1);
		Lcd_mensajes("T    ");
		SysCtlDelay(6500000);
		Lcd_Goto(1,1);
		Lcd_mensajes(" ");

	}
}
