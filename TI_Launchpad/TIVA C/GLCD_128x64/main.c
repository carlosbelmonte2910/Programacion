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
//#include "KS0108.c"
//#include "KS0108-Stellaris.c"




//uint8_t i = 0;
//uint8_t j = 0;
int main(void)
{
	//Setup system clock
	  SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	  //unsigned char j;
	 // unsigned char i;
	  GLCD_Initalize();
	  GLCD_ClearScreen();

	  //Draw the Hackaday.com skull and wrenches

	  //GLCD_GoTo(64,0);
	  //GLCD_WriteString("0123456789");


	  //GLCD_Bitmap(letra_enie, 0, 0, 7, 8);
	  GLCD_Bitmap(UTN_sup_izq, 64, 0, 64, 32);
	  GLCD_Bitmap(UTN_sup_der, 0, 0, 64, 32);
	  GLCD_Bitmap(UTN_inf_izq, 64, 4, 64, 32);
	  GLCD_Bitmap(UTN_inf_der, 0, 4, 64, 32);
	  SysCtlDelay(9500000);
	  GLCD_ClearScreen();
	  /*GLCD_GoTo(0,0);
	  GLCD_WriteString("ca");
	  GLCD_Bitmap(letra_enie, 11, 0, 7, 8);
	  GLCD_GoTo(18,0);
	  GLCD_WriteString("a seca");*/


	  while (1) {
		  GLCD_Bitmap(A, 89, 0, 13, 16);
		  GLCD_Bitmap(T, 102, 0, 13, 16);
		  GLCD_Bitmap(E, 115, 0, 13, 16);
		  GLCD_Bitmap(N, 0, 0, 13, 16);
		  GLCD_Bitmap(C, 13, 0, 13, 16);
		  GLCD_Bitmap(I, 26, 0, 13, 16);
		  GLCD_Bitmap(O, 39, 0, 13, 16);
		  GLCD_Bitmap(N, 52, 0, 13, 16);
		  GLCD_Bitmap(alerta1, 64, 0, 24, 24);
		  SysCtlDelay(4000000);
		  GLCD_Bitmap(alerta2, 64, 0, 24, 24);
		  SysCtlDelay(4000000);
		  GLCD_GoTo(90,2);
		  GLCD_WriteString("Fallas");
		  GLCD_GoTo(4,2);
		  GLCD_WriteString("detectadas");
	  }
}
