/*	Actualmente esto se desarrolla en torno a un enfoque de tipo bucle-electoral,
	y pronto será reescrito para un enfoque basado en la interrupción.
	
	Este controlador supone que sólo un botón se pulsa a la vez. Si varios botones se pulsan a la vez,
	el que más a la izquierda este (en la columna con la tecla 1) será el que se registra.
	Si todos los botones presionados están en la misma columna, el más arriba será el que se registra.

	Esta biblioteca asume que el teclado está conectado a las patas 0 a 6 en un único puerto,
	pero debería ser capaz de utilizar cualquier puerto con alfileres 0 a 6 disponible.

	Advertencia: Esta biblioteca asume sólo un teclado. Si initKeypad se ejecuta más de una vez,
	las funciones de esta biblioteca sólo reconocerán el teclado conectado al puerto más recientemente alimentado a initKeypad. */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

/*--------------------------------------------------------------------------*/
/*	Inicializa el puerto del teclado. (initKeypad)
	Establece columnas en la salida, las filas de entrada con pull-downs internos.
	Utiliza pines 0-6 y deja el pin 7 del puerto solo.
	@parametro ulPort El puerto del teclado está conectado.
	@return Sin valor de retorno.*/
void initKeypad(unsigned long ulPort);

/*--------------------------------------------------------------------------*/
/** Comprueba qué tecla (si las hubiera) en una columna dada es activo. (CheckKeypadCol)
	Conduce una columna alta, entonces comprueba cada fila para ver si han sido impulsados alta.
	@parametro checkCol La columna a comprobar.
	@return La fila que está activa en la columna dada. Devuelve -1 si no hay fila activada.*/
int checkKeypadCol(unsigned char checkCol);

/*--------------------------------------------------------------------------*/
/** Revisa cada columna/fila del teclado y devuelve la clave siendo presionados. (checkKeypad)
	Ejecuta checkKeypadCol en cada columna hasta que encuentra una tecla pulsada,
	luego busca el valor para esa combinación de columna/fila en una tabla.
	@ver checkKeypadCol()
	@return El número de la tecla pulsada. Símbolos # y * cada retorno de -1.*/
int checkKeypad(void);

/*--------------------------------------------------------------------------*/
/** Obtiene la última tecla presionada.(getLastKeyPressed)
    Llama para obtener la última tecla que se presionó.
    @return La última tecla presionada.*/
int getLastKeyPressed(void);

/*--------------------------------------------------------------------------*/
/** ISR para cuando se pulsa una tecla.
    Guarda Actualmente la tecla presionada, luego alterna entre un LED.*/
void keyPressISR(void);

#endif /* KEYPAD_H_ */
