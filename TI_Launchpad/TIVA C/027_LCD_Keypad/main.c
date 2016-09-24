#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "Lcd.h"
#include "systick.h"
#include "keypad.h"

#define KEYPAD_ROW_0 GPIO_PIN_0
#define KEYPAD_ROW_1 GPIO_PIN_1
#define KEYPAD_ROW_2 GPIO_PIN_2
#define KEYPAD_ROW_3 GPIO_PIN_3
#define KEYPAD_ROWS (KEYPAD_ROW_0|KEYPAD_ROW_1|KEYPAD_ROW_2|KEYPAD_ROW_3)

#define KEYPAD_COL_0 GPIO_PIN_4
#define KEYPAD_COL_1 GPIO_PIN_5
#define KEYPAD_COL_2 GPIO_PIN_6
#define KEYPAD_COL_3 GPIO_PIN_7
#define KEYPAD_COLS (KEYPAD_COL_0|KEYPAD_COL_1|KEYPAD_COL_2|KEYPAD_COL_3)

#define KEYPAD_ROW_COUNT 4
#define KEYPAD_COL_COUNT 4

#define LED_RED GPIO_PIN_1
#define LED_BLUE GPIO_PIN_2
#define LED_GREEN GPIO_PIN_3

void main(void) {
	systick_init();

  // configure system clock to run at 50 MHz
  // use external crystal (16 MHz) and PLL
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	// Enable PORT B GPIO
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	// Enable PORT F GPIO
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	// set LED pins as outputs
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_RED|LED_BLUE|LED_GREEN);

	initKeypad(GPIO_PORTD_BASE);

	GPIOPadConfigSet(GPIO_PORTD_BASE, KEYPAD_ROWS, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIOIntTypeSet(GPIO_PORTD_BASE,KEYPAD_ROWS,GPIO_RISING_EDGE); // set the interrupt type on these pins
	GPIOIntEnable(GPIO_PORTD_BASE,KEYPAD_ROWS); // enable interrupts on these pins
	GPIOIntRegister(GPIO_PORTD_BASE, keyPressISR);
	IntMasterEnable(); // enable interrupts in general

	while(1)
	{

	}
}
