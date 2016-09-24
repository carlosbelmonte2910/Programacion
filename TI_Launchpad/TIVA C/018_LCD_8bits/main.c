#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

//unsigned char bus_8;
//unsigned char RS_E;
#define bus_8 GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7
#define RS_E GPIO_PIN_6 | GPIO_PIN_7

int main(void)
{
	//bus_8 = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	//RS_E = GPIO_PIN_6 | GPIO_PIN_7;

	//------------------- Stellaris Launchpad System Initilization------------------//
	SysCtlClockSet(SYSCTL_SYSDIV_16 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, RS_E);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, bus_8);

	//------------------End of Stellaris Launchpad System Initilization------------//
	//Wait 15 Miliseconds after LCD Power Up//
	SysCtlDelay(62500);

	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x00);

	//-------------------------------First LCD Command----------------------------//
	//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x38);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x80);

	//Enable Pulse Width (High Level) 230 nano second//
	SysCtlDelay(2);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x00);
	//---------------------------End of First LCD Command------------------------//

	//1 milliseconds delay//
	SysCtlDelay(4167);

	//-------------------------------Second LCD Command----------------------------//
	//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x38);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x80);

	//Enable Pulse Width (High Level) 230 nano second//
	SysCtlDelay(2);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x00);
	//---------------------------End of Second LCD Command------------------------//

	//1 milliseconds delay//
	SysCtlDelay(4167);

	//-------------------------------Third LCD Command----------------------------//
	//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x06);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x80);

	//Enable Pulse Width (High Level) 230 nanosecond//
	SysCtlDelay(2);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x00);
	//---------------------------End of Third LCD Command------------------------//

	//1 milliseconds delay//
	SysCtlDelay(4167);

	//-------------------------------Fourth LCD Command----------------------------//
	//Put on the Data Pins 0x0E Command to get Display ON, NO Cursor Blinking//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x0C);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x80);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x00);
	//---------------------------End of Fourth LCD Command------------------------//

	// 1 millisecond delay
	SysCtlDelay(4167);

	//-------------------------------Fifth LCD Command----------------------------//
	//Put on the Data Pins 0x01 command to Clear the LCD Screen//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x01);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x80);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x00);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//---------------------------End of Fifth LCD Command------------------------//

	//1 Millisecond Delay//
	SysCtlDelay(4167);

	//--------------------------- "B" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x42);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "e" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x65);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "l" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x6C);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "m" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x6D);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "o" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x6F);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "n" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x6E);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "t" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x74);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	//--------------------------- "e" LCD Data Write--------------------------//
	GPIOPinWrite(GPIO_PORTB_BASE, bus_8, 0x65);

	//Register Select(RS) = 1, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0xC0);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(2);

	//Register Select(RS) = 1, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, RS_E, 0x40);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(8333);
	//--------------------------- End of LCD Data Write-------------------------//

	while(1)
	{

	}
}
