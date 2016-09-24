//**************************************************************
//Autor: Carlos Belmonte
//Micro: SH8
//CRISTAL:Interno
//F_BUS:8Mhz
//REVISION: 15/09/2013
//**********DENINES*********************************************
#define EnabledLCD PTCD_PTCD0
#define RS  PTCD_PTCD1
#define Clrscr 0x01 //Fijo
#define EntrymodeSet 0x06 //ID=1, el cursor se mueve 
                          //hacia la derecha. S=0, el 
                          //display no se desplaza 
                          //luego de escribir en la DDRAM
#define Displayon 0x0C  // D=1, se habilita el display
                        // C=0, no se muestra cursor en pantalla
                        // B=0, funcion parpadeo deshabilitada
#define Displayoff 0x08 // D=0, se dehabilita el display
#define Functionset 0x28  //DL=0, 4bits bus de datos
                          //N=1, 4lineas
                          //F=0, caracteres de 5x8 
#define SetDDRAMadress 0x80 //Fijo
#define Clrscrlcd  SendcmdLCD(Clrscr)
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
void SendcmdLCD(unsigned char cmd); //Envio comando LCD
void SenddataLCD(unsigned char dta);  //Envio datos
void gotoxylcd(unsigned char x, unsigned char y);
void Lcdinit(void);
void Lcdstringchars(unsigned char *cadena);
void Antirebote(void);
void Initpantalla(void);
//**************************************************************
void main(void) 
{
  ConfigMcu();     //Configuramos COP y BKGD
  ConfigOscInt();  //Oscilador interno FLL, F_Bus:8Mhz
  ConfigPorts();   //Configuro puertos
  Lcdinit();
  //***********************************************
  DisableInterrupts;    //Deshabilito interrupciones
  //EnableInterrupts; //Habilito interrupciones
  //************************************************************
  for(;;) 
  {
    //**********************************************************
  if(PTBD_PTBD0 == 1)
  {
    Antirebote();
    if(PTBD_PTBD0 == 1)
    {
     gotoxylcd(9,0);
     Lcdstringchars(" ON      ");
      
    }
  }else
  {
   gotoxylcd(9,0);
   Lcdstringchars(" OFF     "); 
  }
  
  if(PTBD_PTBD1 == 1)
  {
    Antirebote();
    if(PTBD_PTBD1 == 1)
    {
     gotoxylcd(9,1);
     Lcdstringchars(" ON      ");
      
    }
  }else
  {
   gotoxylcd(9,1);
   Lcdstringchars(" OFF     "); 
  }
  
  
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
   PTBDD = 0b00000000; //Puerto B como entrada
   PTBPE = 0xFF;       //Activo pull up
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
  _asm nop;
  _asm nop;
  _asm nop;
  return;
}

void RetardoBusy(void) 
{
  _asm nop;
  _asm nop;
  _asm nop;
  return;
}

void SendcmdLCD(unsigned char cmd)
{
  unsigned char data = 0;
  RS = 0; EnabledLCD = 0;
  data = (cmd & 0xF0);   //Parte alta
  data = data >> 4;
  PTAD = data;
  
  EnabledLCD = 1; //E=1
  RetardoEnabled(); //Retardo enabled 1,5us
  EnabledLCD = 0; 
  
  data = (cmd & 0x0F);    //Parte baja
  data = data >> 4;
  PTAD = data;
  
  EnabledLCD = 1; //E=1
  RetardoEnabled(); //Retardo enabled 1,5us
  EnabledLCD = 0;
  RetardoBusy(); //Retardo busy  1,5us
  return;
}

void SenddataLCD(unsigned char dta)
{
  unsigned char caracteres = 0;
  RS = 1; EnabledLCD = 0;
  caracteres = (dta & 0xF0);
  caracteres = caracteres >> 4;
  PTAD = caracteres;
  
  EnabledLCD = 1; //E=1
  RetardoEnabled(); //Retardo enabled 1,5us
  EnabledLCD = 0;
  
  caracteres = (dta & 0x0F);
  caracteres = caracteres >> 4;
  PTAD = caracteres;

  EnabledLCD = 1; //E=1
  RetardoEnabled(); //Retardo enabled 1,5us
  EnabledLCD = 0;
  RetardoBusy(); //Retardo busy  1,5us
  RS = 0;  
  return;
}

void gotoxylcd(unsigned char x, unsigned char y)
{        
  if(x < 40)
  {
    if(y)
    {
      x|=0b01000000;
      
    }else
    {
      x|=0b10000000;
    }
    SendcmdLCD(x);
  }
  return;
  }

void Lcdinit(void)
{
  Retardo(6000);//Espero un tiempo 16.5ms aprox.
  SendcmdLCD(EntrymodeSet);
  Retardo(2000);//Espero 5ms
  SendcmdLCD(Displayon);
  Retardo(2000);//Espero 5ms 
  SendcmdLCD(Functionset);
  Retardo(2000);//Espero 5ms 
  SendcmdLCD(SetDDRAMadress);
  Retardo(2000);//Espero 5ms
  SendcmdLCD(Clrscr);
  Retardo(2000);//Espero 5ms
  return;
}
void Lcdstringchars(unsigned char *cadena)
{
  while(*cadena)
  {
    SenddataLCD(*cadena++);
  }
  return;
}
void Antirebote(void)
{
   Retardo(1800);
   Retardo(1800);
   Retardo(1800);
   Retardo(1800);
   return;
}
void Initpantalla(void)
{
  gotoxylcd(0,0); //Primera linea
  Lcdstringchars("RELE 0:");
  gotoxylcd(0,1); //Segunda linea
  Lcdstringchars("RELE 1:");
  return;
}
//*************************************************








