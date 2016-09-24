int IN_A=12;
int IN_B=11;
int IN_C=10;
int IN_D=9;

//int IR_1=;
/*int IR_2=;
int IR_3=;
int IR_4=;*/

int ULT=2;

void setup() {
  pinMode(IN_A, OUTPUT);
  pinMode(IN_B, OUTPUT);
  pinMode(IN_C, OUTPUT);
  pinMode(IN_D, OUTPUT);
  pinMode(ULT, INPUT);
  
  digitalWrite(IN_A, 0);
  digitalWrite(IN_B, 0);
  digitalWrite(IN_C, 0);
  digitalWrite(IN_D, 0);
  delay(4900);
  /*attachInterrupt(4, IR_1, LOW);
  attachInterrupt(5, IR_2, LOW);
  attachInterrupt(6, IR_3, LOW);
  attachInterrupt(7, IR_4, LOW);*/
}

void loop() {
  if((digitalRead(ULT))==LOW){ 
    izquierda();
    delay(1000);
    frenar();
    delay(1000);
    avanzar();
    delay(1000);
    frenar();
    delay(1000);
  }
  
  if((digitalRead(ULT))==HIGH){
    avanzar();
    delay(1000);
  }    
}

void frenar(){
  digitalWrite(IN_A, 0);
  digitalWrite(IN_B, 0);
  digitalWrite(IN_C, 0);
  digitalWrite(IN_D, 0);
}

void avanzar(){
  digitalWrite(IN_A, 0);
  digitalWrite(IN_B, 1);
  digitalWrite(IN_C, 0);
  digitalWrite(IN_D, 1);
}

void retroceder(){
  digitalWrite(IN_A, 1);
  digitalWrite(IN_B, 0);
  digitalWrite(IN_C, 1);
  digitalWrite(IN_D, 0);
}

void derecha(){
  digitalWrite(IN_A, 0);
  digitalWrite(IN_B, 1);
  digitalWrite(IN_C, 1);
  digitalWrite(IN_D, 0);
}

void izquierda(){
  digitalWrite(IN_A, 1);
  digitalWrite(IN_B, 0);
  digitalWrite(IN_C, 0);
  digitalWrite(IN_D, 1);
}

/*void IR_1(){
  noInterrupts();
  avanzar();
  delayMicroseconds(3500);
  derecha();
  delayMicroseconds(3500);
  interrupts();
}

void IR_2(){
  noInterrupts();
  avanzar();
  delayMicroseconds(3500);
  izquierda();
  delayMicroseconds(3500);
  interrupts();
}

void IR_3(){
  noInterrupts();
  retroceder();
  delayMicroseconds(3500);
  izquierda();
  delayMicroseconds(3500);
  interrupts();
}

void IR_4(){
  noInterrupts();
  retroceder();
  delayMicroseconds(3500);
  derecha();
  delayMicroseconds(3500);
  interrupts();
}*/
