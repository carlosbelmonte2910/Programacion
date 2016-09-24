/*
 * KeyPad.h
 *
 *  Created on: 31/03/2015
 *      Author: Carlos  Belmonte
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define FilasKey	SYSCTL_PERIPH_GPIOE
#define ColKey		SYSCTL_PERIPH_GPIOC

#define FILAS		GPIO_PORTE_BASE
#define COLS		GPIO_PORTC_BASE
#define ENA_COL		INT_GPIOC

void setup(void);

#endif /* KEYPAD_H_ */
