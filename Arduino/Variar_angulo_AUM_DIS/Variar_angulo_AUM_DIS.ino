#include <LiquidCrystal.h>
#include <Servo.h>
Servo  SERVO;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int cont=0;
int val=0;

void setup() {
  Serial.begin(9600);
  SERVO.attach(9);
  lcd.begin(16, 2);
  lcd.print("ANGULO:");
}

void loop() {
  lcd.setCursor(0, 1);
  val = Serial.read();
  if(-1 != val){
    aumentar();
    disminuir();}}
 

void aumentar(){
  const char IZQ='4';
  if(val == IZQ){
        if (cont >= 0 && cont < 180){
        cont = cont +10;
        Serial.println(cont);
        lcd.print(cont);
        SERVO.write(cont);}}}
        
void disminuir(){
  const char DER='6';
  if(val == DER){
        if (cont > 0 && cont <= 180){
        cont = cont -10;
        Serial.println(cont);
        //lcd.print(cont);
        SERVO.write(cont);
        if(cont <100){
          lcd.clear();
          lcd.print("ANGULO:");
          lcd.setCursor(0, 1);
          lcd.print(cont);}
        if(cont>=100){
          lcd.print(cont);}
        }}}

