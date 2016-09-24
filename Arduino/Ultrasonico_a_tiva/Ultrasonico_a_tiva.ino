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
  delay(6900);
  
}

void loop(){
  ultrasonico1();
  ultrasonico2();
  ultrasonico3();
  ultrasonico4();
}

void ultrasonico1(){
  digitalWrite(trigPin1, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(15);
  digitalWrite(trigPin1,LOW);
  
  tiempo1=pulseIn(echoPin1, HIGH);
  distancia1= int(0.017*tiempo1);
  
  if(distancia1<20){
    digitalWrite(14,HIGH);
    digitalWrite(15,LOW);
    digitalWrite(16,LOW); 
    digitalWrite(17,LOW);}
  if(distancia1>20){
    digitalWrite(14,LOW);}
}

void ultrasonico2(){
   digitalWrite(trigPin2, HIGH); /* envío del pulso ultrasónico*/
   delayMicroseconds(15);
   digitalWrite(trigPin2,LOW);
   
   tiempo2=pulseIn(echoPin2, HIGH);
   distancia2= int(0.017*tiempo2);
    
   if(distancia2<20){
     digitalWrite(15,HIGH);
     digitalWrite(14,LOW);
     digitalWrite(16,LOW); 
     digitalWrite(17,LOW);}
   if(distancia2>20){
     digitalWrite(15,LOW);}
}

void ultrasonico3(){
   digitalWrite(trigPin3, HIGH); /* envío del pulso ultrasónico*/
   delayMicroseconds(15);
   digitalWrite(trigPin3,LOW);
   
   tiempo3=pulseIn(echoPin3, HIGH);
   distancia3= int(0.017*tiempo3);
    
   if(distancia3<20){
     digitalWrite(16,HIGH);
     digitalWrite(14,LOW);
     digitalWrite(15,LOW); 
     digitalWrite(17,LOW);}
   if(distancia3>20){
     digitalWrite(16,LOW);}
}

void ultrasonico4(){
   digitalWrite(trigPin4, HIGH); /* envío del pulso ultrasónico*/
   delayMicroseconds(15);
   digitalWrite(trigPin4,LOW);
   
   tiempo4=pulseIn(echoPin4, HIGH);
   distancia4= int(0.017*tiempo4);
    
   if(distancia4<20){
     digitalWrite(17,HIGH);
     digitalWrite(14,LOW);
     digitalWrite(15,LOW); 
     digitalWrite(16,LOW);}
   if(distancia4>20){
     digitalWrite(17,LOW);}
}
