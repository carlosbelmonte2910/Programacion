#include <Servo.h>
int EN1=2;
int EN2=3;
int IN1=22;
int IN2=24;
int IN3=26;
int IN4=28;

void setup() {
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);}
  
void loop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWriteResolution(12);
  analogWrite(EN1,100);
  analogWrite(EN2,100);
   }
