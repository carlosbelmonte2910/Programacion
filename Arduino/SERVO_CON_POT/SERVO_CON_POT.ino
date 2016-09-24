#include <Servo.h>
Servo myservo; //Crea el objeto servo
int potpin=0;  //Pin analogico para conectar potenciometro
int val;       //Variable para leer el valor del pin analogico

void setup(){
  myservo.attach(9);} //Asocia el pin 9 con el objeto servo
  
void loop(){
  val = analogRead(potpin);    //Lee el valor del potenciometro (entre 0 y 1023)
  val = map(val,0,1023,0,179); //Escala el valor para usarlo con el servo (valor entre 0 y 180)
  myservo.write(val);          //Fija la posición del servo de acuerdo al valor escalado
  delay(5);}                  //Espera a que el servo se posicione
