#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
/*IN_1 = 0x01;IN_2 = 0x02;IN_3 = 0x04;IN_4 = 0x08;*/
const unsigned int IN_ALL = 0x0F;

#define PWM_FREQUENCY 50//Se define la frecuencia del PWM
volatile uint32_t ui32Load;
volatile uint32_t ui32PWMClock;
volatile uint8_t ui32Adjust;//nos permitirá ajustar la posición del ancho.

void configPWM(){
	ui32Adjust = 15;
	SysCtlPWMClockSet(SYSCTL_PWMDIV_64);//El modulo PWM esta sincronizado por el reloj del sistema a traves de un divisor. Al fijarlo en 64 al divisor, el reloj del PWM es 625Khz
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);//Habilita PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//Pin de salida para PWM
	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);//Port D pin 0 (PD0) debe estar configurado como un pin de salida PWM para el módulo 1

	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);/*---------------------------------------------------*/

	GPIOPinConfigure(GPIO_PD0_M1PWM0);//generador de PWM nº 0

	GPIOPinConfigure(GPIO_PD1_M1PWM1);/*-------------------------------------------------------------*/

	ui32PWMClock = SysCtlClockGet() / 41000;//Para obtener el reloj del PWM, se divide el reloj del sistema en 64;
	ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;//Se divide el reloj del PWM en la frecuencia para cargarlo en el registro LOAD, se resta uno porque cuenta hasta 0
	PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);//Se configura el modulo1 del PWM para que haga cuenta descendente
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);//Se carga el valor del contador
	PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);//Habilita el generador 0 como salida

	PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);/*-------------------------------------------------------------*/

	PWMGenEnable(PWM1_BASE, PWM_GEN_0);//Habilita el generador 0 para funcionar
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui32Adjust * ui32Load / 255);

	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 128 * ui32Load / 255);/*-------------------------------------------------------------*/


}
//-----------------------------------------------------------------------------
void frenar(){
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 15 * ui32Load / 255);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x00);}

void avanzar(){
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 200 * ui32Load / 255);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x0A);}

void retroceder(){
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 200 * ui32Load / 255);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x05);}

void izquierda(){
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 200 * ui32Load / 255);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x09);}

void derecha(){
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 200 * ui32Load / 255);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x06);}
//-----------------------------------------------------------------------------


void PortFIntHandler3(){
	IntMasterDisable(); //disable interrupts
	int ULT1 = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_4);


	if((ULT1 == 0)){
		GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x00);
		avanzar();
		SysCtlDelay(8500000);}

	GPIOIntClear(GPIO_PORTA_BASE,GPIO_INT_PIN_4);

	IntMasterEnable();
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 15 * ui32Load / 255);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x00);
}

int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	configPWM();

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	//-----------------------------------------------------------------------------------------------------------
	GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_4);
	GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
	GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_LOW_LEVEL);

	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, IN_ALL);
	GPIOPinWrite(GPIO_PORTB_BASE, IN_ALL, 0x00);



	GPIOIntEnable(GPIO_PORTA_BASE,GPIO_INT_PIN_4);
	IntMasterEnable();
	IntEnable(INT_GPIOA);




	while(1)
	{
		izquierda();
	}
}

