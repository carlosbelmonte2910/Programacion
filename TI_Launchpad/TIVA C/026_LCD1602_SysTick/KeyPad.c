/*
 * KeyPad.c
 *
 *  Created on: 31/03/2015
 *      Author: Carlos  Belmonte
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "systick.h"
#include "KeyPad.h"

void setup(void){
	//Enable the driver layer
	SysCtlPeripheralEnable(FilasKey);
	SysCtlPeripheralEnable(ColKey);

	//Pinout connections:
	GPIOPinTypeGPIOInput(COLS,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
	GPIOPadConfigSet(COLS, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOIntTypeSet(COLS, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_FALLING_EDGE);

	GPIOPinTypeGPIOOutput(FILAS,GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_3|GPIO_PIN_2);

	GPIOIntEnable(COLS, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
	IntMasterEnable();
	IntEnable(ENA_COL);

	GPIOPinWrite(FILAS, GPIO_PIN_2, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_3, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_4, 0);
	GPIOPinWrite(FILAS, GPIO_PIN_5, 0);

}




