#include <Servo.h>
Servo  SERVO;
int cont=0;

void setup(){
  SERVO.attach(9);
  Serial.begin(9600);
  SERVO.write(0);}
    
void loop(){
  int rx;
  if (Serial.available() > 0){
    
    rx = Serial.read();
    if(rx == 'h'){
      
      if (cont >= 0 && cont < 180){
        cont = cont +10;
        Serial.println(cont);
        SERVO.write(cont);}}}}
