#include <Servo.h>
Servo myservo;
int val=0;

void setup(){
  Serial.begin(9600);
  myservo.attach(9);
  }
  
void loop(){
  val = Serial.read();
  myservo.write(0);
  if(-1 != val){
    if('A' == val || 'a' == val){
      myservo.write(45);
      delay(1000);}
    else if('B' == val || 'b' == val){
      myservo.write(125);
      delay(1000);}}}
