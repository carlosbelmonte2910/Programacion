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
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);//habilitar el módulo de hibernación
	HibernateEnableExpClk(SysCtlClockGet());//Define el reloj proporcionado al módulo de hibernación.
	HibernateGPIORetentionEnable();//el estado de los pines GPIO que se mantiene durante la hibernación
	SysCtlDelay(64000000);//retrasar 4 segundos para observar el LED
	HibernateRTCSet(0);
	HibernateRTCEnable();
	HibernateRTCMatchSet(0,5);
	HibernateWakeSet(HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC);//establecer la condición de atención al pin WAKE
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x00);//apague el LED verde antes de que el dispositivo se va a dormir

/*Entrar en modo de hibernación, deshabilita el regulador externo, desconecta la corriente del procesador
 *y todos los periféricos. El módulo de hibernación sigue siendo alimentado por la batería o fuente
 *de alimentación auxiliar*/
	HibernateRequest();
	while(1)
	{
	}
}
