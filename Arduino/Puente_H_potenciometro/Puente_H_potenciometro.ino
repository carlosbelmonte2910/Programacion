#define entrada  A0

void setup(){
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);}

void loop(){
  if(analogRead(entrada) > 512 && analogRead(entrada) <= 1023){
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);}
  
  if(analogRead(entrada) == 512){
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);}
  
  if(analogRead(entrada) >= 0 && analogRead(entrada) < 512){
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);}
}
  
