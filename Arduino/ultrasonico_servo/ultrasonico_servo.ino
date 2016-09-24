#include <Servo.h> 
Servo servo;

int matlabDato=0;
int pos = 0;
int distancia;
long tiempo;
int trigPin = 9;
int echoPin = 8;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  servo.attach(14);
  servo.write(5);}

void loop(){
  ULTRASONICO();
  giro();
}

void ULTRASONICO(){
  digitalWrite(trigPin,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  tiempo=pulseIn(echoPin, HIGH); // Función para medir la longitud del pulso entrante.
  distancia= int((tiempo/2)/29); /*fórmula para calcular la distancia obteniendo un valor entero*/
  Serial.println(distancia);
  //delay(50);
}

void giro(){
  matlabDato=Serial.read();
  if(matlabDato > 25 && pos <=160){
    pos += 2;
    servo.write(pos);
    delay(10);}
  else if(matlabDato < 25 && pos >= 5){
    pos -= 2;
    servo.write(pos);
    delay(10);}}
  
