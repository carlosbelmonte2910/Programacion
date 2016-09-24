/*******************************************************
Project : LED LAB 1 ATE
Version : 1.0
Date : 2/20/2013
Author : Brian Zufelt / Craig Kief
Company : COSMIAC/UNM
Comments:
This Code is intended to show how to connect, compile,
a write your first project on the Tiva Launchpad Board
 ******************************************************
Chip type : ARM TM4C123GH6PM
Program type : Firmware
Core Clock frequency: 80.000000 MHz
 *******************************************************/
// definitions & Included Files
#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#define LED_RED 0x02
#define LED_BLUE 0x04
#define LED_GREEN 0x08
void main(void) {
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF; // enable PORT F GPIO
	GPIO_PORTF_DIR_R = LED_RED|LED_BLUE|LED_GREEN; // set PORT F as output
	GPIO_PORTF_DEN_R = LED_RED|LED_BLUE|LED_GREEN; // enable digital PORT F
	GPIO_PORTF_DATA_R = 0; // clear all PORT F
	GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | LED_BLUE | LED_GREEN | LED_RED; // set LED PORT F pins high
	// loop forever
	while(1){
	}
}
