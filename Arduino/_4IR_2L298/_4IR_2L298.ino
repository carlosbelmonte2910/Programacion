//---Configuracion Pines Motor DERECHO
int IN1_D=9;
int IN2_D=8;
int IN3_D=7;
int IN4_D=6;
//---Configuracion Pines Motor IZQUIERDO
int IN1_I=2;
int IN2_I=3;
int IN3_I=4;
int IN4_I=5;
//---Configuracion Pines IR
int IR_1=16;
int IR_2=17;
int IR_3=18;
int IR_4=19;
//---Entradas del otro arduino
int ult1=10;
int ult2=11;
int ult3=12;
int ult4=14;


void setup(){
  pinMode(IN1_I, OUTPUT);
  pinMode(IN2_I, OUTPUT);
  pinMode(IN3_I, OUTPUT);
  pinMode(IN4_I, OUTPUT);
 
  pinMode(IN1_D, OUTPUT);
  pinMode(IN2_D, OUTPUT);
  pinMode(IN3_D, OUTPUT);
  pinMode(IN4_D, OUTPUT);
  
  digitalWrite(IN1_I, 0);
  digitalWrite(IN2_I, 0);
  digitalWrite(IN3_I, 0);
  digitalWrite(IN4_I, 0);
  
  digitalWrite(IN1_D, 0);
  digitalWrite(IN2_D, 0);
  digitalWrite(IN3_D, 0);
  digitalWrite(IN4_D, 0);
  
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
 
  pinMode(ult1, INPUT);
  pinMode(ult2, INPUT);
  pinMode(ult3, INPUT);
  pinMode(ult4, INPUT);
  delay(4900);}


void loop()
{  
if(((digitalRead(IR_1)) == LOW) && ((digitalRead(IR_2)) == LOW) && ((digitalRead(IR_3)) == LOW) && ((digitalRead(IR_4)) == LOW)){
    //adelante(); 
  if((digitalRead(ult1))==HIGH){
      adelante();
      delay(100);}
  if((digitalRead(ult1))==LOW){
    parar();}  
  
  if((digitalRead(ult2))==HIGH){
      atras();
      delay(100);}  
  if((digitalRead(ult2))==LOW){
    parar();} 
    
  if((digitalRead(ult3))==HIGH){
      derecha();
      delay(500);} 
  if((digitalRead(ult3))==LOW){
    parar();}   
   
  if((digitalRead(ult4))==HIGH){
      izquierda();
      delay(500);}
  if((digitalRead(ult4))==LOW){
    parar();}
  }
   
  if(((digitalRead(IR_1)) == HIGH) || ((digitalRead(IR_4)) == HIGH)){
    atras();
    delay(100);} 
    
  if(((digitalRead(IR_2)) == HIGH) || ((digitalRead(IR_3)) == HIGH)){
    adelante();  
    delay(100);}
  
  if(((digitalRead(IR_1)) == HIGH) || ((digitalRead(IR_2)) == HIGH)){
    derecha();
    delay(100);}
  
  if(((digitalRead(IR_3)) == HIGH) || ((digitalRead(IR_4)) == HIGH)){
    izquierda();  
    delay(100);}
}

void adelante(){
  digitalWrite(IN1_I, 0);
  digitalWrite(IN2_I, 1);
  digitalWrite(IN3_I, 0);
  digitalWrite(IN4_I, 1);
  
  digitalWrite(IN1_D, 1);
  digitalWrite(IN2_D, 0);
  digitalWrite(IN3_D, 1);
  digitalWrite(IN4_D, 0);
}

void atras(){
  digitalWrite(IN1_I, 1);
  digitalWrite(IN2_I, 0);
  digitalWrite(IN3_I, 1);
  digitalWrite(IN4_I, 0);
  
  digitalWrite(IN1_D, 0);
  digitalWrite(IN2_D, 1);
  digitalWrite(IN3_D, 0);
  digitalWrite(IN4_D, 1);
}

void derecha(){
  digitalWrite(IN1_I, 0);
  digitalWrite(IN2_I, 1);
  digitalWrite(IN3_I, 0);
  digitalWrite(IN4_I, 1); 
  
  digitalWrite(IN1_D, 0);
  digitalWrite(IN2_D, 1);
  digitalWrite(IN3_D, 0);
  digitalWrite(IN4_D, 1);
}

void izquierda(){
  digitalWrite(IN1_I, 1);
  digitalWrite(IN2_I, 0);
  digitalWrite(IN3_I, 1);
  digitalWrite(IN4_I, 0);
  
  digitalWrite(IN1_D, 1);
  digitalWrite(IN2_D, 0);
  digitalWrite(IN3_D, 1);
  digitalWrite(IN4_D, 0);
}

void parar(){
  digitalWrite(IN1_I, 0);
  digitalWrite(IN2_I, 0);
  digitalWrite(IN3_I, 0);
  digitalWrite(IN4_I, 0);
  
  digitalWrite(IN1_D, 0);
  digitalWrite(IN2_D, 0);
  digitalWrite(IN3_D, 0);
  digitalWrite(IN4_D, 0);  
}
    
