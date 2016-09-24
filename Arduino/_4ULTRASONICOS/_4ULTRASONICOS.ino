long distancia1;
long tiempo1;
int trigPin1 = 2;
int echoPin1 = 3;

long distancia2;
long tiempo2;
int trigPin2 = 4;
int echoPin2 = 5;

long distancia3;
long tiempo3;
int trigPin3 = 6;
int echoPin3 = 7;

long distancia4;
long tiempo4;
int trigPin4 = 8;
int echoPin4 = 9;

void setup(){
  //Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin1, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  
  pinMode(trigPin2, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin2, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  
  pinMode(trigPin3, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin3, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  
  pinMode(trigPin4, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin4, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  digitalWrite(14,LOW);
  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
  digitalWrite(17,LOW);
  delay(4900);
  
}

void loop(){
  digitalWrite(trigPin1,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  
  tiempo1=pulseIn(echoPin1, HIGH);
  distancia1= int(((tiempo1)/2)/29);
  //Serial.print(distancia1);
  //Serial.println("CM_1");
  //delay(10);
  
  digitalWrite(trigPin2,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  
  tiempo2=pulseIn(echoPin2, HIGH);
  distancia2= int(((tiempo2)/2)/29);
  //Serial.print(distancia2);
  //Serial.println("CM_2");
  //delay(10);
  
  digitalWrite(trigPin3,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin3,LOW);
  
  tiempo3=pulseIn(echoPin3, HIGH);
  distancia3= int(((tiempo3)/2)/29);
  //Serial.print(distancia3);
  //Serial.println("CM_3");
  //delay(10);
  
  digitalWrite(trigPin4,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin4,LOW);
  
  tiempo4=pulseIn(echoPin4, HIGH);
  distancia4= int(((tiempo4)/2)/29);
  //Serial.print(distancia4);
  //Serial.println("CM_4");
  //delay(10);
  
  if(distancia1<10){
    digitalWrite(14,HIGH);}
  if(distancia1>10){
      digitalWrite(14,LOW);}
      
  if(distancia2<10){
    digitalWrite(15,HIGH);}
  if(distancia2>10){
      digitalWrite(15,LOW);}
  
  if(distancia3<10){
    digitalWrite(16,HIGH);}
  if(distancia3>10){
      digitalWrite(16,LOW);}
  
  if(distancia4<10){
    digitalWrite(17,HIGH);}
  if(distancia4>10){
      digitalWrite(17,LOW);}    
}
