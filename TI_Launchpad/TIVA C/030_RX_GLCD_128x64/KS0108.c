//-------------------------------------------------------------------------------------------------
// Universal KS0108 driver library
// (c) Rados³aw Kwiecieñ, radek@dxp.pl
//-------------------------------------------------------------------------------------------------
#include "KS0108.h"
#include "font5x8.h"
#include "systick.h"
#include "a_play.h"
//-------------------------------------------------------------------------------------------------
extern void GLCD_InitalizePorts(void);
//-------------------------------------------------------------------------------------------------
unsigned char screen_x = 0, screen_y = 0;
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_Initalize(void)
{
unsigned char i;
GLCD_InitalizePorts();
for(i = 0; i < 3; i++)
  GLCD_WriteCommand((DISPLAY_ON_CMD | ON), i);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_GoTo(unsigned char x, unsigned char y)
{
unsigned char i;
screen_x = x;
screen_y = y;

for(i = 0; i < KS0108_SCREEN_WIDTH/64; i++)
  {
  GLCD_WriteCommand(DISPLAY_SET_Y | 0,i);
  GLCD_WriteCommand(DISPLAY_SET_X | y,i);
  GLCD_WriteCommand(DISPLAY_START_LINE | 0,i);
  }
GLCD_WriteCommand(DISPLAY_SET_Y | (x % 64), (x / 64));
GLCD_WriteCommand(DISPLAY_SET_X | y, (x / 64));
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_ClearScreen(void)
{
unsigned char i, j;
for(j = 0; j < KS0108_SCREEN_HEIGHT/8; j++)
  {
  GLCD_GoTo(0,j);
  for(i = 0; i < KS0108_SCREEN_WIDTH; i++)
    GLCD_WriteData(0x00);
  }
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteChar(char charToWrite)
{
int i;
charToWrite -= 32; 
for(i = 0; i < 5; i++) 
  GLCD_WriteData(GLCD_ReadByteFromROMMemory((char *)((int)font5x8 + (5 * charToWrite) + i))); 
GLCD_WriteData(0x00);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteString(char * stringToWrite)
{
while(*stringToWrite)
  GLCD_WriteChar(*stringToWrite++);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char color)
{
unsigned char tmp;
GLCD_GoTo(x, (y / 8));
tmp = GLCD_ReadData();
GLCD_GoTo(x, (y / 8));
tmp = GLCD_ReadData();
GLCD_GoTo(x, (y / 8));
tmp |= (1 << (y % 8));
GLCD_WriteData(tmp);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_Bitmap(char * bmp, unsigned char x, unsigned char y, unsigned char dx, unsigned char dy)
{
unsigned char i, j;
for(j = 0; j < dy /8; j++)
  {
  GLCD_GoTo(x,y + j);
  for(i = 0; i < dx; i++) 
    GLCD_WriteData(GLCD_ReadByteFromROMMemory(bmp++));
  }
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------

void mensajes1(int u){
	if(u==0){
		GLCD_Bitmap(M17x24, 64, 1, 17, 24);
		GLCD_Bitmap(O17x24, 80, 1, 17, 24);
		GLCD_Bitmap(L17x24, 96, 1, 17, 24);
		GLCD_Bitmap(I17x24, 112, 1, 17, 24);
		GLCD_Bitmap(E17x24, 0, 1, 17, 24);
		GLCD_Bitmap(N17x24, 16, 1, 17, 24);
		GLCD_Bitmap(D17x24, 32, 1, 17, 24);
		GLCD_Bitmap(A17x24, 48, 1, 17, 24);

		GLCD_Bitmap(N17x24, 80, 4, 17, 24);
		GLCD_Bitmap(O17x24, 96, 4, 17, 24);
		GLCD_Bitmap(R17x24, 112, 4, 17, 24);
		GLCD_Bitmap(M17x24, 0, 4, 17, 24);
		GLCD_Bitmap(A17x24, 16, 4, 17, 24);
		GLCD_Bitmap(L17x24, 32, 4, 17, 24);}}

void mensajes(int w){
	if(w==1){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falta de c");
		GLCD_GoTo(0,4);
		GLCD_WriteString("a");
		GLCD_Bitmap(letra_enie, 6, 4, 7, 8);
		GLCD_WriteString("a        ");}
	if(w==2){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla Usin");
		GLCD_GoTo(0,4);
		GLCD_WriteString("a SIEMENS ");}
	if(w==3){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla Usin");
		GLCD_GoTo(0,4);
		GLCD_WriteString("a MARELLI ");}
	if(w==4){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla en C");
		GLCD_GoTo(0,4);
		GLCD_WriteString("aldera 1  ");}
	if(w==5){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla en C");
		GLCD_GoTo(0,4);
		GLCD_WriteString("aldera 2  ");}
	if(w==6){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla en C");
		GLCD_GoTo(0,4);
		GLCD_WriteString("aldera 3  ");}
	if(w==7){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla en C");
		GLCD_GoTo(0,4);
		GLCD_WriteString("aldera 4  ");}
	if(w==8){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Baja presi");
		GLCD_GoTo(0,4);
		GLCD_WriteString("on vapor  ");}
	if(w==9){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falta de g");
		GLCD_GoTo(0,4);
		GLCD_WriteString("as        ");}
	if(w==10){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Atascamien");
		GLCD_GoTo(0,4);
		GLCD_WriteString("to Molino1");}
	if(w==11){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Atascamien");
		GLCD_GoTo(0,4);
		GLCD_WriteString("to Molino2");}
	if(w==12){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Atascamien");
		GLCD_GoTo(0,4);
		GLCD_WriteString("to Molino3");}
	if(w==13){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla en E");
		GLCD_GoTo(0,4);
		GLCD_WriteString("ncaladora ");}
	if(w==14){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla Horn");
		GLCD_GoTo(0,4);
		GLCD_WriteString("o Azufre  ");}
	if(w==15){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Rotura Cin");
		GLCD_GoTo(0,4);
		GLCD_WriteString("ta Bagacer");}
	if(w==16){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Fallas en ");
		GLCD_GoTo(0,4);
		GLCD_WriteString("Centrifuga");}
	if(w==17){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Filtro Cac");
		GLCD_GoTo(0,4);
		GLCD_WriteString("haza Lleno");}
	if(w==18){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla en C");
		GLCD_GoTo(0,4);
		GLCD_WriteString("alentador ");}
	if(w==19){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla Cris");
		GLCD_GoTo(0,4);
		GLCD_WriteString("talizador ");}
	if(w==20){
		GLCD_GoTo(67,4);
		GLCD_WriteString("Falla Tolv");
		GLCD_GoTo(0,4);
		GLCD_WriteString("a Azucar  ");}
}



