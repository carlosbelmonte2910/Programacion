#include <LiquidCrystal.h>
#include <Wire.h>
#define entrada A0
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
float valor_analog, voltios;

void setup(){
  pinMode(entrada,INPUT);
  lcd.begin(16, 2);
  lcd.print("Bienvenido!");
  delay(3000);
  lcd.clear();}
  
void loop(){
  lcd.clear();
  voltaje_positivo();
  voltaje_negativo();
  valor_analog = analogRead(entrada);
  voltios = ((5.0*float(valor_analog))/1024.0);
  }
  
void voltaje_positivo(){
  lcd.setCursor(0, 0);
  lcd.print("Vout(+):  ");
  lcd.print(voltios);
  lcd.print("V");
  }

void voltaje_negativo(){
  if(-voltios < 0){
  lcd.setCursor(0, 1);
  lcd.print("Vout(-): ");
  lcd.print(-voltios);
  lcd.print("V");}
  
  if(-voltios == 0){
  lcd.setCursor(0, 1);
  lcd.print("Vout(-):  ");
  lcd.print(-voltios);
  lcd.print("V");}
  delay(100);}
  
  
