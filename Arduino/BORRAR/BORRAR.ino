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
    estado_luz();
    adelante();
    //atras();
    //izquierda();
    //derecha();
    camara_vertical();
    camara_horizontal();
    brazo_vertical();
    brazo_rotacional();
    brazo_pinza();}
/*--------------------------------------*/
void estado_luz(){
    digitalWrite(LUZ, 1);}
/*--------------------------------------*/
void adelante(){
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
    /*analogWrite(ENA_1, 0);
    analogWrite(ENB_1, 0);
    analogWrite(ENA_2, 0);
    analogWrite(ENB_2, 0);*/}
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
  for(cont1 = 30; cont1 <= 120; cont1 += 1){                                   
    camara1.write(cont1);               
    delay(15);} 
    
  for(cont1 = 120; cont1 >= 30; cont1 -= 1){                                
    camara1.write(cont1);             
    delay(15);}}
/*--------------------------------------*/ 
void camara_horizontal(){
  for(cont2 = 0; cont2 <= 180; cont2 += 1){                                   
    camara2.write(cont2);               
    delay(15);} 
    
  for(cont2 = 180; cont2 >= 0; cont2 -= 1){                                
    camara2.write(cont2);             
    delay(15);}}
/*--------------------------------------*/
void brazo_rotacional(){
  for(cont3 = 0; cont3 <= 180; cont3 += 1){                                   
    brazo1.write(cont3);               
    delay(15);} 
    
  for(cont3 = 180; cont3 >= 0; cont3 -= 1){                                
    brazo1.write(cont3);             
    delay(15);}}
/*--------------------------------------*/        
void brazo_vertical(){
  for(cont4 = 45; cont4 <= 100; cont4 += 1){                                   
    brazo2.write(cont4);               
    delay(15);} 
    
  for(cont4 = 100; cont4 >= 45; cont4 -= 1){                                
    brazo2.write(cont4);             
    delay(15);}}
/*--------------------------------------*/       
void brazo_pinza(){
  for(cont5 = 0; cont5 <= 180; cont5 += 1){                                   
    pinza.write(cont5);               
    delay(15);} 
    
  for(cont5 = 180; cont5 >= 0; cont5 -= 1){                                
    pinza.write(cont5);             
    delay(15);}}
/*--------------------------------------*/
