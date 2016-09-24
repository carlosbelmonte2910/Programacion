#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
//#include "driverlib/rom.h"

#define PWM_FREQUENCY 55// Para el servo se utiliza una frecuencia de 55hz

int main(void)
{
	/*Las siguientes variables se utilizan para programar el PWM. Se definen como "volátil" para garantizar
	 *que el compilador no las eliminará, independientemente de la configuración de optimización.*/
	volatile uint32_t ui32Load;
	volatile uint32_t ui32PWMClock;
	volatile uint8_t ui8Adjust;//nos permitirá ajustar la posición del servo.
	ui8Adjust = 83;//es la posición central para crear un pulso 1,5mS de la PWM.


	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);//El sistema corre a 40Mhz
	SysCtlPWMClockSet(SYSCTL_PWMDIV_64);//El modulo PWM esta sincronizado por el reloj del sistema a traves de un
	//divisor. Al fijarlo en 64 al divisor, el reloj del PWM es 625Khz

	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);//Habilita PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//Pin de salida para PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//Pin para botones

	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);//Port D pin 0 (PD0) debe estar configurado como un pin de salida PWM para el módulo 1
	GPIOPinConfigure(GPIO_PD0_M1PWM0);//generador de PWM nº 0

	/*Se debe desbloquear el puertoF cuando se desea usar los 2 switch, ya que el PF0 sirve tambien como entrada para NMI,
	 *esto se logra con las 3 lineas siguientes, mas info en el capitulo 3 del WORKSHOP*/
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
	GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);//Configura PF0 Y PF4 como entrada
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);//Configura sus resistencia de PULL-UP

	ui32PWMClock = SysCtlClockGet() / 64;//Para obtener el reloj del PWM, se divide el reloj del sistema en 64;
	ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;//Se divide el reloj del PWM en la frecuencia para cargarlo en el registro LOAD, se resta uno porque cuenta hasta 0
	PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);//Se configura el modulo1 del PWM para que haga cuenta descendente
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);//Se carga el valor del contador


	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);//Define el ancho del pulso
	PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);//Habilita el generador 0 como salida
	PWMGenEnable(PWM1_BASE, PWM_GEN_0);//Habilita el generador 0 para funcionar

	while(1)
	{
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)==0x00)
		{
			ui8Adjust--;
			if (ui8Adjust < 56)
			{
				ui8Adjust = 56;
			}
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
		}

		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==0x00)
		{
			ui8Adjust++;
			if (ui8Adjust > 111)
			{
				ui8Adjust = 111;
			}
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
		}
		SysCtlDelay(100000);
	}
}
