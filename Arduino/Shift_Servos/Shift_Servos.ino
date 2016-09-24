#include <Servo.h>
int ENA_1 = 3;
int ENB_1 = 5;
int ENA_2 = 6;
int ENB_2 = 11;
int latchPin = 8;
int clockPin = 10;
int dataPin = 9;
Servo  SERVO1;
Servo  SERVO2;
Servo  SERVO3;
Servo  SERVO4;
Servo  SERVO5;
int cont1=0;
int cont2=0;
int cont3=0;
int cont4=0;
int cont5=0;
int val=0;

void setup() {
  Serial.begin(9600);
  SERVO1.attach(14);
  SERVO2.attach(15);
  SERVO3.attach(16);
  SERVO4.attach(17);
  SERVO5.attach(18);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(ENA_1, OUTPUT);
  pinMode(ENB_1, OUTPUT);
  pinMode(ENA_2, OUTPUT);
  pinMode(ENB_2, OUTPUT);}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 170);
  digitalWrite(latchPin, HIGH);
  analogWrite(ENA_1, 200);
  analogWrite(ENB_1, 200);
  analogWrite(ENA_2, 200);
  analogWrite(ENB_2, 200);
  
  val = Serial.read();
  if(-1 != val){
    camara_vertical();
    camara_horizontal();
    brazo_rotacional();
    brazo_vertical();
    brazo_pinza();}}
 
/*--------------------------------------*/
void camara_vertical(){
  const char UP='I';
  if(val == UP){
        if (cont1 >= 0 && cont1 < 180){
        cont1 = cont1 +10;
        //Serial.println(cont1);
        SERVO1.write(cont1);}}
  
  const char DOWN='K';
  if(val == DOWN){
        if (cont1 > 0 && cont1 <= 180){
        cont1 = cont1 -10;
        //Serial.println(cont1);
        SERVO1.write(cont1);}}}
/*--------------------------------------*/       
void camara_horizontal(){
  const char IZQ='J';
  if(val == IZQ){
        if (cont2 >= 0 && cont2 < 180){
        cont2 = cont2 +10;
        //Serial.println(cont2);
        SERVO2.write(cont2);}}
  
  const char DER='L';
  if(val == DER){
        if (cont2 > 0 && cont2 <= 180){
        cont2 = cont2 -10;
        //Serial.println(cont2);
        SERVO2.write(cont2);}}}
/*--------------------------------------*/       
void brazo_rotacional(){
  const char HS='D';
  if(val == HS){
        if (cont3 >= 0 && cont3 < 180){
        cont3 = cont3 +10;
        //Serial.println(cont3);
        SERVO3.write(cont3);}}
  
  const char AHS='A';
  if(val == AHS){
        if (cont3 > 0 && cont3 <= 180){
        cont3 = cont3 -10;
        //Serial.println(cont3);
        SERVO3.write(cont3);}}}
/*--------------------------------------*/        
void brazo_vertical(){
  const char SB='W';
  if(val == SB){
        if (cont4 >= 0 && cont4 < 180){
        cont4 = cont4 +10;
        //Serial.println(cont4);
        SERVO4.write(cont4);}}
  
  const char BB='S';
  if(val == BB){
        if (cont4 > 0 && cont4 <= 180){
        cont4 = cont4 -10;
        //Serial.println(cont4);
        SERVO4.write(cont4);}}}
/*--------------------------------------*/       
void brazo_pinza(){
  const char CL='X';
  if(val == CL){
        if (cont5 >= 0 && cont5 < 180){
        cont5 = cont5 +10;
        //Serial.println(cont5);
        SERVO5.write(cont5);}}
  
  const char OP='Z';
  if(val == OP){
        if (cont5 > 0 && cont5 <= 180){
        cont5 = cont5 -10;
        //Serial.println(cont5);
        SERVO5.write(cont5);}}}
/*--------------------------------------*/
