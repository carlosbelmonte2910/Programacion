#include <Servo.h>
Servo  SERVO;
int val=0;

void setup(){
  SERVO.attach(9);
  Serial.begin(9600);}
    
void loop(){
  val = Serial.read();
  if(-1 != val){
    if('A' == val || 'a' == val){
      SERVO.write(120);
      delay(500);}
    
    else if('B' == val || 'b' == val){
      SERVO.write(45);
      delay(500);}}}
