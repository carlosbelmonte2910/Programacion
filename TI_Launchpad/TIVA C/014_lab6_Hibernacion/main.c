#include <stdint.h>
#include <stdbool.h>
#include "utils/ustdlib.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/hibernate.h"
#include "driverlib/gpio.h"

int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x08);
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);//habilitar el m�dulo de hibernaci�n
	HibernateEnableExpClk(SysCtlClockGet());//Define el reloj proporcionado al m�dulo de hibernaci�n.
	HibernateGPIORetentionEnable();//el estado de los pines GPIO que se mantiene durante la hibernaci�n
	SysCtlDelay(64000000);//retrasar 4 segundos para observar el LED
	HibernateRTCSet(0);
	HibernateRTCEnable();
	HibernateRTCMatchSet(0,5);
	HibernateWakeSet(HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC);//establecer la condici�n de atenci�n al pin WAKE
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x00);//apague el LED verde antes de que el dispositivo se va a dormir

/*Entrar en modo de hibernaci�n, deshabilita el regulador externo, desconecta la corriente del procesador
 *y todos los perif�ricos. El m�dulo de hibernaci�n sigue siendo alimentado por la bater�a o fuente
 *de alimentaci�n auxiliar*/
	HibernateRequest();
	while(1)
	{
	}
}
