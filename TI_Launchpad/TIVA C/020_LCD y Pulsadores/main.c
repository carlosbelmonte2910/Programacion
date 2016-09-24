#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "Lcd.h"

int i=0;
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);//El sistema corre a 50Mhz
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//Pin para botones
	Lcd_init();

	/*Se debe desbloquear el puertoF cuando se desea usar los 2 switch, ya que el PF0 sirve tambien como entrada para NMI,
	 *esto se logra con las 3 lineas siguientes, mas info en el capitulo 3 del WORKSHOP*/
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
	GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_0, GPIO_DIR_MODE_IN);//Configura PF0 PF1 PF2 y PF4 como entrada
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);//Configura sus resistencia de PULL-UP


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
	SysCtlDelay(4000000);
	Lcd_desactivar();

	while(1)
	{
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==0x00)
		{
			Lcd_Goto(1,1);
			Lcd_mensajes("Lampara 1: Apagada  ");
		}
		else{
			Lcd_Goto(1,1);
			Lcd_mensajes("Lampara 1: Encendida");
		}
//------------------------------------------------------------//
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_1)==0x00)
		{
			Lcd_Goto(2,1);
			Lcd_mensajes("Lampara 2: Apagada  ");
		}
		else{
			Lcd_Goto(2,1);
			Lcd_mensajes("Lampara 2: Encendida");
		}
//------------------------------------------------------------//
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_2)==0x00)
		{
			Lcd_Goto(3,1);
			Lcd_mensajes("Lampara 3: Apagada  ");
		}
		else{
			Lcd_Goto(3,1);
			Lcd_mensajes("Lampara 3: Encendida");
		}
//------------------------------------------------------------//
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)==0x00)
		{
			Lcd_Goto(4,1);
			Lcd_mensajes("Lampara 4: Apagada  ");
		}
		else{
			Lcd_Goto(4,1);
			Lcd_mensajes("Lampara 4: Encendida");
		}
		SysCtlDelay(100000);
	}
}
