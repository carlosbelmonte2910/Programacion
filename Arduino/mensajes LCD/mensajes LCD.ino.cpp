#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);




void setup(){
  lcd.begin(20, 4);
  //lcd.print("Bienvenido!");
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("EN CLASES - OCUPADO");
  //lcd.setCursor(0, 1);
  //lcd.print("hola mundo");
  lcd.setCursor(0, 3);
  lcd.print("Termina 22:30hs");
  lcd.setCursor(0, 1);
  lcd.print("      NO PASAR");
}
