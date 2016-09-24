#include <Servo.h>

int Lecturas[5];
int Val,i=0,Total=0,Promedio=0;
Servo myservo; //Crea el objeto servo
    
void setup(){
  myservo.attach(9);  //Asocia el pin 9 con el objeto servo
  for(i=0;i<5;i++)   //Inicializacion del vector
  Lecturas[i]=0;
  i=0;}
   
void loop(){
  Total=Total-Lecturas[i];     //Sustrae el total con la lectura inmediata anterior
  Lecturas[i]=analogRead(A0);  //Agrega una lectura a la posicion actual dentro del vector
  Total=Total+Lecturas[i];     //Realiza la sumatoria entre lecturas
  i=i+1;
  if(i>=5){                   //Calcula el promedio y envia el resultado al servo
  i=0;
  Promedio=Total/5;
  Val=map(Promedio,0,1023,0,179);  //Escala el valor para usarlo con el servo (valor entre 0 y 180)
  myservo.write(Val);}             //Fija la posición del servo de acuerdo al valor escalado      
  delay(5);}                      //Espera a que el servo se posicione
