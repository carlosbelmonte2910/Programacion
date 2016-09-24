/* 
* systick.c
*
* M.Fatih INANC
* fatihinanc.com
* 
* 09.12.2012
*/


#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "systick.h"

unsigned long systick_count = 0;

void systick_init(void)
{
  NVIC_ST_CTRL_R = 0;                   
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  
  NVIC_ST_CURRENT_R = 0;                
  
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_CLK_SRC;
}

void systick_delay(unsigned long delay)
{
  volatile unsigned long tiempo_restante;
  unsigned long hora_inicio = NVIC_ST_CURRENT_R;
  
  do
  {
	  tiempo_restante = (hora_inicio - NVIC_ST_CURRENT_R) & 0x00FFFFFF;
  }
  while(tiempo_restante <= delay);
}

void delay_us(unsigned long delay)
{
  unsigned long i;
  
  for(i=0; i<delay; i++)
    systick_delay(50); 		//1uS
}

void delay_ms(unsigned long delay)
{
  unsigned long i;
  
  for(i=0; i<delay; i++)
    systick_delay(50000);  // 1mS
}
