/******************************************************
Chip type : ARM TM4C123GH6PM
Program type : Firmware
Core Clock frequency : 80.000000 MHz
*******************************************************/
#include "inc/tm4c123gh6pm.h"
#include <stdint.h>


// definitions
#define LED_1 0x01
#define LED_2 0x02
#define LED_3 0x04
#define LED_4 0x08
#define LED_5 0x10
#define LED_6 0x20
#define LED_7 0x40

void main(void) {
	long unsigned int i = 0; //general counter
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOB; // enable PORT F GPIO
	GPIO_PORTB_DIR_R = LED_1|LED_2|LED_3|LED_4|LED_5|LED_6|LED_7; // set PORT F as output
	GPIO_PORTB_DEN_R = LED_1|LED_2|LED_3|LED_4|LED_5|LED_6|LED_7; // enable digital PORT F

	// loop forever
	while(1){
		/********************************************************************************/
		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		//GPIO_PORTB_DATA_R = 0; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2|LED_3; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2|LED_3|LED_4; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2|LED_3|LED_4|LED_5; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2|LED_3|LED_4|LED_5|LED_6; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2|LED_3|LED_4|LED_5|LED_6|LED_7; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay
		/********************************************************************************/

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_4; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_3|LED_5; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_2|LED_6; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_7; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay
		/********************************************************************************/
		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		//GPIO_PORTB_DATA_R = 0; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_7; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_7|LED_6; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_7|LED_6|LED_5; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_7|LED_6|LED_5|LED_4; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_7|LED_6|LED_5|LED_4|LED_3; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_7|LED_6|LED_5|LED_4|LED_3|LED_2; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay

		GPIO_PORTB_DATA_R = 0; // clear all PORT F
		GPIO_PORTB_DATA_R = LED_1|LED_2|LED_3|LED_4|LED_5|LED_6|LED_7; // set LED PORT F pins high
		for(i=0;i<350000;i++){}; //delay
	}
}
