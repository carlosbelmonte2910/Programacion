// Version TIVA. Enciende de los LEDs rojo (PF1), verde (PF2) y azul (PF3) de forma consecutiva y continua,
// en intervalos de 1 segundo
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h" // Necesario para funciones API en driverlib
#include "inc/hw_memmap.h" // Etiquetas de registros del micro, perifericos, ...
#include "driverlib/sysctl.h" // Definicion de funciones y etiquetas de control del sistema (SysCtl)
#include "driverlib/gpio.h" // Definicion de funciones y etiquetas de puerto (GPIOPin...)
int main(void)
{
	int LED = 2; // En binario es 00000..010, es decir, BIT1 a 1
	// Configura reloj del sistema a 50MHz (PLL a 200MHz/4=50MHz)
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	// Habilita Puerto F (LEDs)
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);// Comentar para producir error FaultISR
	// Configura pines PF1, PF2, y PF3 como salidas (control de LEDs)
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	while(1)
	{
		// Enciende el LED indicado en la variable; 1er parametro: puerto afectado
		// 2º parametro: bits afectados (mascara); 3er parametro: valor a volcar al puerto
		// solo se modificaran los bits indicados por la mascara)
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
		// Retardo para ver encendido el LED; parametro= "loops" (3 ciclos por "loop")
		SysCtlDelay(16666666); // t=16666666*3/40MHz= 1 seg (aprox)
		// Enciende el siguiente LED (el del bit que esta a continuacion)
		if (LED == 8) {LED = 2;} else {LED = LED*2;}
	}
}
