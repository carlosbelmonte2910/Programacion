/*******************************************************
Project : LED LAB 2,3 ATE (Launchpad)
Version : 1.0
Date : 2/20/2013
Author : Brian Zufelt / Craig Kief
Company : COSMIAC/UNM
Comments:
This Code is intended to show how to connect, compile,
a write your first project on the Tiva-C Launchpad Board
 ******************************************************
Chip type : ARM TM4C123GH6PM
Program type : Firmware
Core Clock frequency : 80.000000 MHz
 *******************************************************/
#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
// definitions
#define LED_RED 0x02
#define LED_BLUE 0x04
#define LED_GREEN 0x08
// Lab definitions for the 2 versions of the lab
//#define Lab2
#define Lab3
void main(void) {
	long unsigned int i = 0; //general counter
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF; // enable PORT F GPIO
	GPIO_PORTF_DIR_R = LED_RED|LED_BLUE|LED_GREEN; // set PORT F as output
	GPIO_PORTF_DEN_R = LED_RED|LED_BLUE|LED_GREEN; // enable digital PORT F
#ifdef Lab2
	GPIO_PORTF_DATA_R = 0; // clear all PORT F
	GPIO_PORTF_DATA_R |= LED_RED|LED_BLUE|LED_GREEN; // set LED PORT F pins high
#endif
	// loop forever
	while(1){
#ifdef Lab3
		GPIO_PORTF_DATA_R = 0; // clear all PORT F
		GPIO_PORTF_DATA_R = LED_RED | LED_BLUE; // set LED PORT F pins high

		for(i=0;i<30000;i++){}; //delay

		GPIO_PORTF_DATA_R = 0; // clear all PORT F
		GPIO_PORTF_DATA_R = LED_GREEN | LED_RED| LED_BLUE; // set LED PORT F pins high

		for(i=0;i<100;i++){}; //delay

		GPIO_PORTF_DATA_R = 0; // clear all PORT F
		GPIO_PORTF_DATA_R = LED_BLUE | LED_GREEN; // set LED PORT F pins high

		for(i=0;i<3000;i++){}; //delay
#endif
	}
}
