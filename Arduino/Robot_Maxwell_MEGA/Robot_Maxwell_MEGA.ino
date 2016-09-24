

//---Configuracion Pines Motor Izquierdo
int ENA_I=2;
int IN1_I=3;
int IN2_I=4;
int IN3_I=5;
int IN4_I=6;
int ENB_I=7;
//---Configuracion Pines Motor Derecho
int ENA_D=8;
int IN1_D=9;
int IN2_D=10;
int IN3_D=11;
int IN4_D=12;
int ENB_D=13;


void setup()   
{
  pinMode(ENA_I, OUTPUT);
  pinMode(ENB_I, OUTPUT);
  pinMode(IN1_I, OUTPUT);
  pinMode(IN2_I, OUTPUT);
  pinMode(IN3_I, OUTPUT);
  pinMode(IN4_I, OUTPUT);
 
  pinMode(ENA_D, OUTPUT);
  pinMode(ENB_D, OUTPUT);
  pinMode(IN1_D, OUTPUT);
  pinMode(IN2_D, OUTPUT);
  pinMode(IN3_D, OUTPUT);
  pinMode(IN4_D, OUTPUT);
 
  
  analogWrite(ENA_I, 0);
  analogWrite(ENB_I, 0);
  analogWrite(ENA_D, 0);
  analogWrite(ENB_D, 0);
  
  digitalWrite(IN1_D, 1);
  digitalWrite(IN2_D, 1);
  digitalWrite(IN3_D, 1);
  digitalWrite(IN4_D, 1);
  
  digitalWrite(IN1_I, 1);
  digitalWrite(IN2_I, 1);
  digitalWrite(IN3_I, 1);
  digitalWrite(IN4_I, 1);
  delay(3000); 
}


void loop()
{
  adelante();
  delay(3000);
  atras();
  delay(3000);
  izquierda();
  delay(3000);
  derecha();
  delay(3000);
}

void adelante(){
  analogWrite(ENA_I, 150);
  analogWrite(ENB_I, 150);
  digitalWrite(IN1_I, 0);
  digitalWrite(IN2_I, 1);
  digitalWrite(IN3_I, 0);
  digitalWrite(IN4_I, 1);
  
  analogWrite(ENA_D, 150);
  analogWrite(ENB_D, 150);
  digitalWrite(IN1_D, 0);
  digitalWrite(IN2_D, 1);
  digitalWrite(IN3_D, 0);
  digitalWrite(IN4_D, 1);
}

void atras(){
  analogWrite(ENA_I, 150);
  analogWrite(ENB_I, 150);
  digitalWrite(IN1_I, 1);
  digitalWrite(IN2_I, 0);
  digitalWrite(IN3_I, 1);
  digitalWrite(IN4_I, 0);
  
  analogWrite(ENA_D, 150);
  analogWrite(ENB_D, 150);
  digitalWrite(IN1_D, 1);
  digitalWrite(IN2_D, 0);
  digitalWrite(IN3_D, 1);
  digitalWrite(IN4_D, 0);
}

void izquierda(){
  analogWrite(ENA_I, 255);
  analogWrite(ENB_I, 255);
  digitalWrite(IN1_I, 0);
  digitalWrite(IN2_I, 1);
  digitalWrite(IN3_I, 0);
  digitalWrite(IN4_I, 1); 
  
  analogWrite(ENA_D, 255);
  analogWrite(ENB_D, 255);
  digitalWrite(IN1_D, 1);
  digitalWrite(IN2_D, 0);
  digitalWrite(IN3_D, 1);
  digitalWrite(IN4_D, 0);
}

void derecha(){
  analogWrite(ENA_D, 255);
  analogWrite(ENB_D, 255);
  digitalWrite(IN1_D, 0);
  digitalWrite(IN2_D, 1);
  digitalWrite(IN3_D, 0);
  digitalWrite(IN4_D, 1);
  
  analogWrite(ENA_I, 255);
  analogWrite(ENB_I, 255);
  digitalWrite(IN1_I, 1);
  digitalWrite(IN2_I, 0);
  digitalWrite(IN3_I, 1);
  digitalWrite(IN4_I, 0);
}

