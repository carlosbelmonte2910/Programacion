#include <Servo.h>
Servo  SERVO;
int val=0;
int cont=0;

void setup(){
  SERVO.attach(9);
  Serial.begin(9600);}
    
void loop(){
  val = Serial.read();
  if('A' == val || 'a' == val){
    if (cont >= 0 && cont < 180){
      cont = cont +10;
      Serial.println(cont);
      SERVO.write(cont);}}
    
    }
