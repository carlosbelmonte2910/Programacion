#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h" //Libreria para usar el ADC

int main(void)
{
/*Crea un array que se utiliza para almacenar los datos leidos de la FIFO ADC, debe ser tan grande
 *como la FIFO del secuenciador en uso. Usamos el secuenciador 1 que tiene una profundidad de FIFO
 *de 4*/
	uint32_t ui32ADC0Value[4];
	//unsigned long ui32ADC0Value[4];// Usar unsigned long es igual que usar uint32_t

/*Necesitamos algunas variables para el calculode la temperatura a partir de los datos del sensor*/
	volatile uint32_t ui32TempAvg;//variable es para almacenar el promedio de la temperatura
	volatile uint32_t ui32TempValueC;//almacena los valores de temperatura de grados Celsius
	volatile uint32_t ui32TempValueF;//almacena los valores de temperatura de grados Fahrenheit
/*Todos se declaran como "volátil" de manera que cada variable no puede ser optimizado por el
 *compilador y estará a disposición de la ventana "Local" en tiempo de ejecución*/

	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);//Habilita el ADC0 en los perifericos.
	//SysCtlADCSpeedSet(SYSCTL_ADCSPEED_250KSPS);//Configura la velocidad, no funciona para TIVA,solo para stellaris
	//ADCClockConfigSet(ADC0_BASE, ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_FULL, 1);
	ADCHardwareOversampleConfigure(ADC0_BASE, 64);// 64 mediciones en cada muestra

/*Se configura el secuenciador. Se configura la secuencia de muestra (1), disparo de la secuencia por el procesador
 *y la cantidad de capturas por muestra, 8 capturas en una muestra con (0)*/
	ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);

/*Se configuran los cuatro pasos (0-3) del secuenciador(1), TS responde al sensor de temperatura*/
	ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_TS);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_TS);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 3, ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
/*El ultimo paso requiere una interrupcion de la muestra (IE) y un indicador de ultima muestra (END)*/
	
	ADCSequenceEnable(ADC0_BASE, 1);//Se habilita el secuenciador1

	while(1){
		ADCIntClear(ADC0_BASE, 1);// Se borran las banderas de conversion completa
		ADCProcessorTrigger(ADC0_BASE, 1);//Se dispara la conversion

/*Tenemos que esperar a que la conversión se complete*/
		while(!ADCIntStatus(ADC0_BASE, 1, false)){
		}

/*Cuando la ejecución de código sale del bucle en el paso anterior, sabemos que la conversión
 * se ha completado y que podemos leer el valor ADC*/
		ADCSequenceDataGet(ADC0_BASE, 1, ui32ADC0Value);

/*Calcular el promedio de los datos del sensor de temperatura*/
/*La adición de 2 es para redondeo*/
		ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
		ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
		ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;

	}
}
