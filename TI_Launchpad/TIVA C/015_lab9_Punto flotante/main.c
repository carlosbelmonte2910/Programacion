#include <stdint.h>
#include <stdbool.h>
#include <math.h>//Contiene funciones matematicas como seno, coseno, tangente, etc...
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"//Para poder utilizar el punto flotante
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846 // se define PI con esta estructura
#endif

#define SERIES_LENGTH 100//profundidad de nuestro buffer de datos
float gSeriesData[SERIES_LENGTH];// Un array de flotantes
int32_t i32DataCount = 0;//contador para nuestro bucle de cálculo

int main(void)
{
	float fRadians;// variable para calcular el seno
	FPULazyStackingEnable();// apilamiento perezoso para guardar espacio en la pila
	FPUEnable();// Enciende Punto flotante
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);// 50MHZ
	fRadians = ((2 * M_PI) / SERIES_LENGTH);//Un ciclo de onda seno completa es 2pi radianes. Divida 2pi por la profundidad de la matriz.
	while(i32DataCount < SERIES_LENGTH)//El bucle calculará el valor del seno de cada uno de los 100 valores del ángulo y colocarlos en nuestra matriz de datos.
	{
		gSeriesData[i32DataCount] = sinf(fRadians * i32DataCount);
		i32DataCount++;
	}
	while(1)
	{
	}
}
