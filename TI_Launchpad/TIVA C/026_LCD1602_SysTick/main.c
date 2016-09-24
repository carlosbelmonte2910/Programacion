#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "lcd_1602_lm4f.h"
#include "systick.h"
#include "pll.h"
#include "KeyPad.h"

unsigned long cpu_freq;
//temporal variable where to store the key press number
static int num;

/* ISR to key-scan, i have been thinking to just raise a flag and then later on check keypad */
void scan_key(void)
{
	int i;
	int key=0;
	IntMasterDisable(); //disable interrupts
	for (i=0;i<4;i++)
	{
		GPIOPinWrite(FILAS, GPIO_PIN_2, (i==0)?0:GPIO_PIN_2);
		GPIOPinWrite(FILAS, GPIO_PIN_3, (i==1)?0:GPIO_PIN_3);
		GPIOPinWrite(FILAS, GPIO_PIN_4, (i==2)?0:GPIO_PIN_4);
		GPIOPinWrite(FILAS, GPIO_PIN_5, (i==3)?0:GPIO_PIN_5);

		if ( GPIOPinRead(COLS,GPIO_PIN_7) == 0)
		{
				switch (i)
				{
					case 0: key=0x0A;break;
					case 1: key=0x0B;break;
					case 2: key=0x0C;break;
					case 3: key=0x0D;break;
					default: key=-1;
				}
				break;
		}
		else if (GPIOPinRead(COLS,GPIO_PIN_6) == 0)
		{
				switch (i)
				{
					case 0: key=0x03;break;
					case 1: key=0x06;break;
					case 2: key=0x09;break;
					case 3: key=0x0E;break;
					default: key=-1;
				}
				break;
		}
		else if (GPIOPinRead(COLS,GPIO_PIN_5) == 0)
		{
				switch (i)
				{
					case 0: key=0x02;break;
					case 1: key=0x05;break;
					case 2: key=0x08;break;
					case 3: key=0x00;break;
					default: key=-1;
				}
				break;
		}
		else if (GPIOPinRead(COLS,GPIO_PIN_4) == 0)
		{
				switch (i)
				{
					case 0: key=0x01;break;
					case 1: key=0x04;break;
					case 2: key=0x07;break;
					case 3: key=0x0F;break;
					default: key=-1;
				}
				break;
		}
	}
	//get ready for next interruption
	GPIOPinWrite(FILAS, GPIO_PIN_2, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_3, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_4, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_5, 0);
	//store the value
	num = key;
	GPIOIntClear(COLS,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
	IntMasterEnable();
}

int main(void)
{
  pll_init();              
  systick_init();
  
  set_cpu_freq(3,1);         // 50 MHz
  cpu_freq = get_cpu_freq();
  setup();
  lcd_init();
  delay_ms(1000);
  
  while(1){
  if (num == 0x0F)
  		{
  				delay_ms(10);
  				lcd_goto(1,1);
  				lcd_puts("Lampara 1: Encendida");

  			num = 0;
  		}
  }
  
}
