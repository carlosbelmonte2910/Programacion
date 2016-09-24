#define LINE_BLACK 1
#define LINE_WHITE 0
int pwmD=3;
int pwmI=11;
int dirD=13;
int dirI=12;
int sensor_izq=5;
int sensor_der=4;
void setup()
{
  pinMode(pwmD,OUTPUT);
  pinMode(pwmI,OUTPUT);
  pinMode(dirD,OUTPUT);
  pinMode(dirI,OUTPUT);
  pinMode(sensor_izq,INPUT);
  pinMode(sensor_der,INPUT);
}
void loop()
{
  if(analogRead(sensor_izq)>300&&analogRead(sensor_der)>300)
  {
    digitalWrite(dirD,HIGH);
    digitalWrite(dirI,HIGH);
    analogWrite(pwmD,0);
    analogWrite(pwmI,0);
  }
  if(analogRead(sensor_izq)>300&&analogRead(sensor_der)<300)
  {
    digitalWrite(dirD,LOW);
    digitalWrite(dirI,HIGH);
    analogWrite(pwmD,200);
    analogWrite(pwmI,200);
  }
  if(analogRead(sensor_izq)<300&&analogRead(sensor_der)>300)
  {
    digitalWrite(dirD,HIGH);
    digitalWrite(dirI,LOW);
    analogWrite(pwmD,200);
    analogWrite(pwmI,200);
  }
  if(analogRead(sensor_izq)<300&&analogRead(sensor_der)<300)
  {
    digitalWrite(dirD,HIGH);
    digitalWrite(dirI,HIGH);
    analogWrite(pwmD,200);
    analogWrite(pwmI,200);
  }
}
  
  
