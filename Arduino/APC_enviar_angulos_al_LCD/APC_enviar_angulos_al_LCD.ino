#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int cont=0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("ANGULO:");
}

void loop() {
  lcd.setCursor(0, 1);
  int rx;
  if (Serial.available() > 0){
    rx = Serial.read();
    if(rx == 'h'){
      if (cont >= 0 && cont < 180){
        cont = cont +10;
        Serial.println(cont);
        lcd.print(cont);}}}}



