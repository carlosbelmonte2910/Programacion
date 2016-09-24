#include <Servo.h>
int ENA_1 = 3;
int ENB_1 = 5;
int ENA_2 = 6;
int ENB_2 = 11;
int latchPin = 8;
int clockPin = 10;
int dataPin = 9;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(ENA_1, OUTPUT);
  pinMode(ENB_1, OUTPUT);
  pinMode(ENA_2, OUTPUT);
  pinMode(ENB_2, OUTPUT);}
  
void loop(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 170);
  digitalWrite(latchPin, HIGH);
  analogWrite(ENA_1, 255);
  analogWrite(ENB_1, 255);
  analogWrite(ENA_2, 255);
  analogWrite(ENB_2, 255);}
