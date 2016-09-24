//**************************************************************
//Autor: Carlos Belmonte
//Micro: SH8
//CRISTAL:Interno
//F_BUS:8Mhz
//REVISION: 15/09/2013
//**********Includes********************************************
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
//**********Variables Globales**********************************
unsigned char VarGlob = 0;
//**********Declarar Funciones**********************************
void ConfigMcu(void);
void ConfigOscInt(void);
void ConfigPorts(void);
void Retardo(unsigned int ciclos);
void RetardoEnabled(void);
void RetardoBusy(void);
//**************************************************************
void main(void) 
{
  ConfigMcu();     //Configuramos COP y BKGD
  ConfigOscInt();  //Oscilador interno FLL, F_Bus:8Mhz
  ConfigPorts();   //Configuro puertos
//***********************************************
  DisableInterrupts;    //Deshabilito interrupciones
  //EnableInterrupts; //Habilito interrupciones
  //************************************************************
  for(;;) 
  {
    //**********************************************************
  PTAD_PTAD1 = 1;
    //**********************************************************
  } 
}
//**********Definimos funciones*********************************
void ConfigMcu(void)
{
  //IRQSC = 0b00000000; //No se usa interrupcion por IRQ
  SOPT1 = 0b00000011; //COP deshabilitado,
                      //Background Debug Mode habilitado
                      //Pin Reset como reset
  //SPMSC1 = 0b00000000;//LVD deshabilitado
  //SPMSC2 = 0b00000000;//
 return; 
}


void ConfigOscInt(void)
{
  ICSC1 = 0b00000111;
  //         \\\\\\\\__IREFSTEN referencia interna habilitada en modo stop
  //          \\\\\\\__ICSIRCLK active
  //           \\\\\\__Internal reference clock selected
  //            \\\\\__RDIV3:5
  //             \\\\__RDIV4:5
  //              \\\__RDIV5:5
  //               \\__CLKS6:7-->0\ Output of FLL is selected.
  //                \__CLKS7:7-->0/
  
  ICSC2 = 0b01000000; // BDIV = 01 divide por 2
  _asm nop;
  _asm nop;
  _asm nop;
  _asm nop;
  
  return;
}


void ConfigPorts(void)
{
   PTAD = 0x00;        //Carga el valor cero
   PTADD = 0b00001111; //PTA0-A3 COMO SALIDA
   PTAPE = 0b11110000;
   PTASE = 0b00000000; //Output slew rate control disabled
   //**********************************************************
   PTBD = 0x00;
   PTBDD = 0b00000000;
   PTBPE = 0xFF;
   PTBSE = 0b00000000;
   //**********************************************************
   PTCD = 0x00;
   PTCDD = 0b00000011; //Bit 0 - 1  a salida
   PTCPE = 0b11111100;
   PTCSE = 0b00000000;
   return;
}


void Retardo(unsigned int ciclos)
{
   unsigned int i = 0;
   for(i = ciclos; i>0; i--);
   return;
}

void RetardoEnabled(void) 
{
  
  return;
}

void RetardoBusy(void) 
{
  
  return;
}
//*************************************************








