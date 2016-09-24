int pwmI=11;
int pwmD=3;
int dirI=12;
int dirD=13;

void setup()
{
  pinMode(pwmI,OUTPUT);
  pinMode(pwmD,OUTPUT);
  pinMode(dirI,OUTPUT);
  pinMode(dirD,OUTPUT);
}
void loop()
{
  digitalWrite(dirI,HIGH);
  digitalWrite(dirD,HIGH);
  analogWrite(pwmI,200);
  analogWrite(pwmD,200);
  delay(2000);
  digitalWrite(dirI,LOW);
  digitalWrite(dirD,LOW);
  delay(3000);
  digitalWrite(dirI,HIGH);
  digitalWrite(dirD,HIGH);
  analogWrite(pwmI,200);
  analogWrite(pwmD,0);
  delay(1000);
  digitalWrite(dirI,HIGH);
  digitalWrite(dirD,HIGH);
  analogWrite(pwmI,200);
  analogWrite(pwmD,200);
  delay(2000);
  digitalWrite(dirI,HIGH);
  digitalWrite(dirD,HIGH);
  analogWrite(pwmI,0);
  analogWrite(pwmD,200);
  delay(1000);
}
