/**
  *@file  RobotSeguidorDelinea
  *@brief Robot seguidor de linea
  *@details mediante dos sensores infrarrojos el robot se guia por una linea negra
  *@author Christian Peralta
  */
#define Sensor_izq A4 //defino a la entrada analogica A4 como Sensor_izq
#define Sensor_der A5 //defino a la entrada analogica A5 como Sensor_der
#define ADELANTE HIGH //defino al estado HIGH como ADELANTE
#define ATRAS LOW     //defino al estado LOW como ATRAS
#define VELOCIDAD 100 //defino el valor 100 como VELOCIDAD que equivale aprox. a 1.95 volt
#define RANGO 300     //300 es equivalente a aprox. 1.5 volt entonces los valores de tension por arriba de
                      //este seran tomados como color blanco y los valores menores
                      //seran tomados como color negro

//pines que controlan los motores
int pwmD = 3 ;  //pin que controla la velocidad de la rueda derecha. 0-255
int pwmI = 11 ; //pin que controla la velocidad de la rueda izquierda. 0-255
int dirD = 13 ; //pines que controlan la direccion de la rueda derecha. adelante-HIGH atras-LOW
int dirI = 12 ; //pines que controlan la direccion de la rueda izquierda. adelante-HIGH  atras-LOW
 
void setup (){
  //declaro los pines 3, 11 , 12 y 13 como salida 
  pinMode(pwmD,OUTPUT); //configuro pin 3  como salida
  pinMode(pwmI,OUTPUT); //configuro pin 11 como salida
  pinMode(dirD,OUTPUT); //configuro pin 13 como salida
  pinMode(dirI,OUTPUT); //configuro pin 12 como salida 
  delay(2000);
}


void loop() {  
  //si ambos sensores estan sobre la linea negra    
  if (analogRead(Sensor_izq)<RANGO && analogRead(Sensor_der)<RANGO)             
    adelante();      //Robot se mueve hacia adelante                                         // Movimiento adelante 
  //si el sensor derecho esta sobre la linea blanca y el izquierdo sobre la linea negra
  if (analogRead(Sensor_der)>RANGO && analogRead(Sensor_izq)<RANGO)          
    izquierda();     // Giro sentido antihorario                                          // Giro diferencial a izquierda
  //si el sensor derecho esta sobre la linea negra y el izquierdo sobre la linea blanca
  if (analogRead(Sensor_izq)>RANGO && analogRead(Sensor_der)<RANGO)           
    derecha();      // Giro sentido horario
    //si ambos sensores estan sobre la superficie blanca  
  if (analogRead(Sensor_izq)>RANGO && analogRead(Sensor_der)>RANGO)                                                      
    pare();          //detengo al robot                                         // Parada                                                 
}

//Muevo el robot hacia adelante
void adelante (void) {
   analogWrite(pwmD,VELOCIDAD);
   analogWrite(pwmI,VELOCIDAD);
   digitalWrite(dirD,ADELANTE);
   digitalWrite(dirI,ADELANTE);
}
//Muevo el robot en sentido antihorario
void izquierda (void) {
  analogWrite(pwmD,VELOCIDAD);
  analogWrite(pwmI,VELOCIDAD);
  digitalWrite(dirI,ATRAS);
  digitalWrite(dirD,ADELANTE);
}
//Muevo el robot en sentido horario
void derecha (void)                                             
{
  analogWrite(pwmD,VELOCIDAD);
  analogWrite(pwmI,VELOCIDAD);
  digitalWrite(dirI,ADELANTE);
  digitalWrite(dirD,ATRAS);
}
//Detengo el robot
void pare (void)                                              
{
    analogWrite(pwmD,0);
    analogWrite(pwmI,0); 
}
