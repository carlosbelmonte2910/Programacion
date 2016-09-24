//----PUENTES Hs
int latchPin = 2;
int clockPin = 3;
int dataPin = 4;
int EN = 5;
//----ULTRASONIDO 1
long distancia1;
long tiempo1;
int trigPin1 = 6;
int echoPin1 = 7;
//----ULTRASONIDO 2
long distancia2;
long tiempo2;
int trigPin2 = 9;
int echoPin2 = 8;
//----ULTRASONIDO 3
long distancia3;
long tiempo3;
int trigPin3 = 10;
int echoPin3 = 12;
//----ULTRASONIDO 4
long distancia4;
long tiempo4;
int trigPin4 = 11;
int echoPin4 = 14;
//----PINES IRs
int IR1 = 15;
int IR2 = 16;
int IR3 = 17;
int IR4 = 18;
//----CONSTANTES DE DISTANCIA
int cte_1=100;
int cte_2=100;
int cte_3=100;
int cte_4=100;
//----CONSTANTE DE IR
int senIR1=0;
int senIR2=0;
int senIR3=0;
int senIR4=0;


void setup(){
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin1, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(trigPin2, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin2, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(trigPin3, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin3, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(trigPin4, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin4, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  delay(50);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 255);
  digitalWrite(latchPin, HIGH);
  analogWrite(EN, 0);
  delay(4950);
}
  
void loop(){
  ultrasonico1();
  ultrasonico2();
  ultrasonico3();
  ultrasonico4();
  adelante();
  delay(500);
  atras();
  delay(500);
  izquierda();
  delay(500);
  derecha();
  delay(500);
}
  
void adelante(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 170);
  digitalWrite(latchPin, HIGH);
  analogWrite(EN, 255);}

void atras(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 85);
  digitalWrite(latchPin, HIGH);
  analogWrite(EN, 255);
}

void izquierda(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 165);
  digitalWrite(latchPin, HIGH);
  analogWrite(EN, 255); 
}

void derecha(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 90);
  digitalWrite(latchPin, HIGH);
  analogWrite(EN, 255);
}

void ultrasonico1(){
  digitalWrite(trigPin1,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  
  tiempo1=pulseIn(echoPin1, HIGH); 
  distancia1= int((tiempo1/2)/29);
  Serial.print(distancia1);
  Serial.println(" c1m");
  delay(50);
}

void ultrasonico2(){
  digitalWrite(trigPin2,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  
  tiempo2=pulseIn(echoPin2, HIGH); 
  distancia2= int((tiempo2/2)/29);
  Serial.print(distancia2);
  Serial.println(" c2m");
  delay(50);
}

void ultrasonico3(){
  digitalWrite(trigPin3,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin3,LOW);
  
  tiempo3=pulseIn(echoPin3, HIGH); 
  distancia3= int((tiempo3/2)/29);
  Serial.print(distancia3);
  Serial.println(" c3m");
  delay(50);
}

void ultrasonico4(){
  digitalWrite(trigPin4,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin4,LOW);
  
  tiempo4=pulseIn(echoPin4, HIGH); 
  distancia4= int((tiempo4/2)/29);
  Serial.print(distancia4);
  Serial.println(" c4m");
  delay(50);
}
