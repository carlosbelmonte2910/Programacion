#include <Servo.h>
int ENB_1 = 2;
int ENA_1 = 3;

int ENA_2 = 4;
int ENB_2 = 5;

int IN1_1 = 47;
int IN2_1 = 45;
int IN3_1 = 51;
int IN4_1 = 53;

int IN1_2 = 39;
int IN2_2 = 41;
int IN3_2 = 35;
int IN4_2 = 33;

int LUZ = 25;
Servo  camara1;
Servo  camara2;
Servo  brazo1;
Servo  brazo2;
Servo  pinza;
int cont1=40;
int cont2=90;
int cont3=0;
int cont4=25;
int cont5=50;
int val=0;

void setup(){
  Serial.begin(9600);
  pinMode(ENA_1, OUTPUT);
  pinMode(ENB_1, OUTPUT);
  pinMode(ENA_2, OUTPUT);
  pinMode(ENB_2, OUTPUT);
  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN3_1, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  pinMode(LUZ, OUTPUT);  
  camara1.attach(12);
  camara2.attach(11);
  brazo1.attach(10);
  brazo2.attach(9);
  pinza.attach(8);
  camara1.write(cont1);
  camara2.write(cont2);
  brazo1.write(cont3);
  brazo2.write(cont4);
  pinza.write(cont5);
  digitalWrite(LUZ, 0);
} 
 
void loop(){
  val = Serial.read();
  if(-1 != val){
    estado_luz();
    adelante();
    atras();
    izquierda();
    derecha();
    camara_vertical();
    camara_horizontal();
    brazo_rotacional();
    brazo_vertical();
    brazo_pinza();}}
/*--------------------------------------*/
void estado_luz(){
  const char ON='G';
  const char OFF='B';
  if(val == ON){
    digitalWrite(LUZ, 1);}
  if(val == OFF){
    digitalWrite(LUZ, 0);}
  
  }
/*--------------------------------------*/
void adelante(){
  const char AD='8';
  if(val == AD){
    analogWriteResolution(12);
    analogWrite(ENA_1, 4095);
    analogWrite(ENB_1, 4095);
    analogWrite(ENA_2, 4095);
    analogWrite(ENB_2, 4095);
    digitalWrite(IN1_1, 1);
    digitalWrite(IN2_1, 0);
    digitalWrite(IN3_1, 1);
    digitalWrite(IN4_1, 0);
  
    digitalWrite(IN1_2, 0);
    digitalWrite(IN2_2, 1);
    digitalWrite(IN3_2, 0);
    digitalWrite(IN4_2, 1);
    delay(50);
    analogWrite(ENA_1, 0);
    analogWrite(ENB_1, 0);
    analogWrite(ENA_2, 0);
    analogWrite(ENB_2, 0);}}
/*--------------------------------------*/
void atras(){
  const char AT='5';
  if(val == AT){
    analogWriteResolution(12);
    analogWrite(ENA_1, 4095);
    analogWrite(ENB_1, 4095);
    analogWrite(ENA_2, 4095);
    analogWrite(ENB_2, 4095);
    digitalWrite(IN1_1, 0);
    digitalWrite(IN2_1, 1);
    digitalWrite(IN3_1, 0);
    digitalWrite(IN4_1, 1);
  
    digitalWrite(IN1_2, 1);
    digitalWrite(IN2_2, 0);
    digitalWrite(IN3_2, 1);
    digitalWrite(IN4_2, 0);
    delay(50);
    analogWrite(ENA_1, 0);
    analogWrite(ENB_1, 0);
    analogWrite(ENA_2, 0);
    analogWrite(ENB_2, 0);}}
/*--------------------------------------*/    
void izquierda(){
  const char IZ='4';
  if(val == IZ){
    analogWriteResolution(12);
    analogWrite(ENA_1, 4095);
    analogWrite(ENB_1, 4095);
    analogWrite(ENA_2, 4095);
    analogWrite(ENB_2, 4095);
    digitalWrite(IN1_1, 1);
    digitalWrite(IN2_1, 0);
    digitalWrite(IN3_1, 1);
    digitalWrite(IN4_1, 0);
  
    digitalWrite(IN1_2, 1);
    digitalWrite(IN2_2, 1);
    digitalWrite(IN3_2, 1);
    digitalWrite(IN4_2, 1);
    delay(300);
    analogWrite(ENA_1, 0);
    analogWrite(ENB_1, 0);
    analogWrite(ENA_2, 0);
    analogWrite(ENB_2, 0);}}
/*--------------------------------------*/
void derecha(){
  const char DE='6';
  if(val == DE){
    analogWriteResolution(12);
    analogWrite(ENA_1, 4000);
    analogWrite(ENB_1, 4000);
    analogWrite(ENA_2, 4000);
    analogWrite(ENB_2, 4000);
    digitalWrite(IN1_1, 1);
    digitalWrite(IN2_1, 1);
    digitalWrite(IN3_1, 1);
    digitalWrite(IN4_1, 1);
  
    digitalWrite(IN1_2, 0);
    digitalWrite(IN2_2, 1);
    digitalWrite(IN3_2, 0);
    digitalWrite(IN4_2, 1);
    delay(300);
    analogWrite(ENA_1, 0);
    analogWrite(ENB_1, 0);
    analogWrite(ENA_2, 0);
    analogWrite(ENB_2, 0);}}
/*--------------------------------------*/
void camara_vertical(){
  const char UP='I';
  if(val == UP){
        if (cont1 >= 0 && cont1 < 180){
        cont1 = cont1 +5;
        //Serial.println(cont1);
        camara1.write(cont1);}}
  
  const char DOWN='K';
  if(val == DOWN){
        if (cont1 > 0 && cont1 <= 180){
        cont1 = cont1 -5;
        //Serial.println(cont1);
        camara1.write(cont1);}}}
/*--------------------------------------*/ 
void camara_horizontal(){
  const char IZQ='J';
  if(val == IZQ){
        if (cont2 >= 0 && cont2 < 180){
        cont2 = cont2 +5;
        //Serial.println(cont2);
        camara2.write(cont2);}}
  
  const char DER='L';
  if(val == DER){
        if (cont2 > 0 && cont2 <= 180){
        cont2 = cont2 -5;
        //Serial.println(cont2);
        camara2.write(cont2);}}}
/*--------------------------------------*/
void brazo_rotacional(){
  const char HS='D';
  if(val == HS){
        if (cont3 >= 0 && cont3 < 180){
        cont3 = cont3 +5;
        //Serial.println(cont3);
        brazo1.write(cont3);}}
  
  const char AHS='A';
  if(val == AHS){
        if (cont3 > 0 && cont3 <= 180){
        cont3 = cont3 -5;
        //Serial.println(cont3);
        brazo1.write(cont3);}}}
/*--------------------------------------*/        
void brazo_vertical(){
  const char SB='W';
  if(val == SB){
        if (cont4 >= 0 && cont4 < 180){
        cont4 = cont4 +5;
        //Serial.println(cont4);
        brazo2.write(cont4);}}
  
  const char BB='S';
  if(val == BB){
        if (cont4 > 0 && cont4 <= 180){
        cont4 = cont4 -5;
        //Serial.println(cont4);
        brazo2.write(cont4);}}}
/*--------------------------------------*/       
void brazo_pinza(){
  const char CL='X';
  if(val == CL){
        if (cont5 >= 0 && cont5 < 180){
        cont5 = cont5 +5;
        //Serial.println(cont5);
        pinza.write(cont5);}}
  
  const char OP='Z';
  if(val == OP){
        if (cont5 > 0 && cont5 <= 180){
        cont5 = cont5 -5;
        //Serial.println(cont5);
        pinza.write(cont5);}}}
/*--------------------------------------*/
