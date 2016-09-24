//*************************************************
//Autor: Carlos Belmonte
//Micro: SH8
//CRISTAL:
//F_BUS:
//REVISION: 15/09/2013
//**********Defines********************************
#define Enablelcd PTCD_PTCD0
#define RS  PTCD_PTCD1
#define Clrscr 0x01
#define EntrymodeSet 0x06
#define Displayon 0x0C
#define Displayoff 0x08
#define Functionset 0x38
#define SetDDRAMadress 0x80
//**********Includes*******************************
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
//**********Variables Globales*********************
unsigned char VarGlob = 0;
//**********Declarar Funciones*********************
void ConfigMcu(void);
void ConfigOscInt(void);
void ConfigPorts(void);
void Retardo(unsigned int ciclos);
void Sendcmdlcd(unsigned char cmd);
void Senddatalcd(unsigned char dta);
void gotoxylcd(unsigned char x, unsigned char y);
void Lcdinit(void);
//*************************************************
void main(void) 
{
  //***********************************************
  ConfigMcu();  //Configuramos COP y BKGD
  ConfigOscInt();  //Oscilador internos FLL, Fbus = 8MHz
  ConfigPorts();   //configuro puertos
  //***********************************************
  DisableInterrupts; //Deshabilito interrupciones
  //***********************************************
  for(;;) 
  {
    //*********************************************
    //*********************************************
  } 
}
//**********Definimos funciones********************
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
   PTAD = 0x00;         //Carga el valor cero
   PTADD = 0b00001111;  //PTA0-PTA3 como salida
   PTAPE = 0b11110000;  //Habilito pull up bit 4-7
   PTASE = 0b00000000;  //Output slew rate control disabled
   //*****************
   PTBD = 0x00;
   PTBDD = 0b00000000;
   PTBPE = 0xFF;
   PTBSE = 0b00000000;  //Output slew rate control disabled
   //*****************
   PTCD = 0x00;
   PTCDD = 0b00000011;  //Bit 0-1 como salida
   PTCPE = 0b11111100;  
   PTCSE = 0b00000000;  //Output slew rate control disabled
   return;
}
void Retardo(unsigned int ciclos)
{
  unsigned int i = 0;
  for(i = ciclos; i > 0; i--);
  return;
}
void Sendcmdlcd(unsigned char cmd)
{
  unsigned char data = 0;
  RS = 0; Enablelcd = 0;
  data = (cmd & 0xF0);  //Parte alta
  data = data >> 4;
  PTAD = data;
  
  Enablelcd = 1;  //E = 1
  Retardo(1000);  //calcular retardo enable
  Enablelcd = 0;
  
  data = (cmd & 0x0F);  //Parte baja
  data = data >> 4;
  PTAD = data;
  
  Enablelcd = 1;  //E = 1
  Retardo(1000);  //calcular retardo enable
  Enablelcd = 0;
  Retardo(4000);  //Calcular retardo busy
  return;
}
void Senddatalcd(unsigned char dta)
{
 unsigned char caracteres = 0;
 RS = 1; Enablelcd = 0;
 caracteres = (dta & 0xF0); //Parte alta
 caracteres = caracteres >> 4;
 PTAD = caracteres;
 
 Enablelcd = 1;
 Retardo(1000);  //calcular retardo enable
 Enablelcd = 0;
 
 caracteres = (dta & 0x0F); //Parte baja
 caracteres = caracteres >> 4;
 PTAD = caracteres;
 
 Enablelcd = 1;
 Retardo(1000);  //calcular retardo enable
 Enablelcd = 0;
 Retardo(4000);  //Calcular retardo busy 
  return;
}
void gotoxylcd(unsigned char x, unsigned char y)
{
  if(x < 40)
	{
		if(y)
		{
		  x |= 0b01000000;
		}else
		{
		  x |= 0b10000000;
		}
		Sendcmdlcd(x);
	}
  return;
}
void Lcdinit(void)
  {
    Retardo(2000); //Espero un tiempo 16.3mS aprox 
    Sendcmdlcd(EntrymodeSet);
    //Espero 5ms
    Sendcmdlcd(Displayon);
    //Espero 5ms
    Sendcmdlcd(Functionset);
    //Espero 5ms
    Sendcmdlcd(SetDDRAMadress);
    //Espero 5ms
    Sendcmdlcd(Clrscr);
    //Espero 5ms
    return;
  }
//*************************************************