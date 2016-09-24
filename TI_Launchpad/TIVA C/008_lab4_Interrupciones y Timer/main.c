#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"  //Define para NVIC
#include "driverlib/gpio.h"
#include "driverlib/timer.h"	  //Define para TIMER

int main(void){
	uint32_t ui32Period;
	//unsigned long ui32Period;

/*Configura el reloj del sistema a 40Mhz, la frecuencia base del PLL=400Mhz se divide en 2 esta es*/
/*fija. Luego esta frecuencia de 200Mhz se divide en 5, que se la configura con SYSCTL_SYSDIV_    */
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

/*Se configura el periferico GPIO, si son como salida o entrada*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

/*Se configura el periferico TIMER*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);

/*Se desea alternar los GPIO a 10Hz, por eso se lo divide por 10... y con un ciclo de trabajo de 50% */
/*por eso luego se divide por 2*/
	ui32Period = (SysCtlClockGet() / 10) / 2;
	TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period -1);

/*A continuaci�n, tenemos que permitir la interrupci�n no s�lo en el m�dulo de temporizaci�n, sino tambi�n en NVIC*/
	IntEnable(INT_TIMER0A);// Habilita el vector especifico asociado con TIMER A0
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);//permite un evento espec�fico dentro del temporizador para generar una interrupci�n
	IntMasterEnable();//es el maestro de habilitaci�n de interrupci�n de la API para todas las interrupciones.

/*Finalmente podemos activar el temporizador*/
	TimerEnable(TIMER0_BASE, TIMER_A);//Esto iniciar� el temporizador y las interrupciones se iniciar� el disparo en los tiempos de espera

	while(1)
	{
	}
}

/*Desde esta aplicaci�n es conducido la interrupci�n*/
void Timer0IntHandler(void)
{
	// Clear the timer interrupt
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	// Read the current state of the GPIO pin and
	// write back the opposite state
	if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2))
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
	}
	else
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);
	}
}
