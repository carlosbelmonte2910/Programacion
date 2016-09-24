#include <Arduino.h>
//float voltios_por_analog = 0.0048923679060665; 
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int entrada=0;
float valor_analog, voltios;



void setup(){
  pinMode(entrada,INPUT);
  lcd.begin(16, 2);
  lcd.print("Bienvenido!");
  Serial.begin(9600);
}

void loop(){
  valor_analog = analogRead(entrada);
  voltios = ((5*float(valor_analog))/1024);
  Serial.print("El voltaje es de: ");
  Serial.println(float(voltios));
  Serial.flush();
  lcd.setCursor(0, 1);
  lcd.print(float(voltios));}
