#define TARGET_IS_BLIZZARD_RA1 1

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"

volatile uint32_t counter;

#define RED_GPIO GPIO_PIN_1
#define GREEN_GPIO GPIO_PIN_3
#define BLUE_GPIO GPIO_PIN_2
#define RGB_GPIOPINS (RED_GPIO | GREEN_GPIO | BLUE_GPIO)

int main(void)
{
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4| SYSCTL_USE_PLL |
                       SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);  // 80MHz CPU; speed is calculated as 200MHz/SYSDIV

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RGB_GPIOPINS);  // PF1-3 as outputs

    ROM_SysTickPeriodSet(80000);  // 1ms period
    counter = 1;
    ROM_IntMasterEnable();
    ROM_SysTickIntEnable();
    ROM_SysTickEnable();


    while(1) {
        ROM_GPIOPinWrite(GPIO_PORTF_BASE, RGB_GPIOPINS, BLUE_GPIO);
        while (counter % 250)
            ;
        counter++;
        ROM_GPIOPinWrite(GPIO_PORTF_BASE, RGB_GPIOPINS, GREEN_GPIO);
        while (counter % 250)
            ;
        counter++;
        ROM_GPIOPinWrite(GPIO_PORTF_BASE, RGB_GPIOPINS, RED_GPIO);
        while (counter % 250)
            ;
        counter++;
    }
 //   return 1;
}

void TickHandler()
{
    counter++;
}
