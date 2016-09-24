#define SensorI A5
#define SensorD A4

int pwmD = 3;
int pwmI = 11;
int dirD = 13;
int dirI = 12;

void setup(){
  pinMode(pwmD, OUTPUT);
  pinMode(pwmI, OUTPUT);
  pinMode(dirD, OUTPUT);
  pinMode(dirI, OUTPUT);
  pinMode(SensorD, INPUT);
  pinMode(SensorI, INPUT);
  delay(1000);}
  
void loop(){
  if((analogRead(SensorI)>300)&&(analogRead(SensorD)>300)){  //DETENIDO
    digitalWrite(dirI,HIGH);
    digitalWrite(dirD,HIGH);
    analogWrite(pwmI,0);
    analogWrite(pwmD,0);}
    
  if((analogRead(SensorI)>300)&&(analogRead(SensorD)<300)){  //DERECHA
    digitalWrite(dirI,HIGH);
    digitalWrite(dirD,LOW);
    analogWrite(pwmI,250);
    analogWrite(pwmD,250);}
   
  if((analogRead(SensorI)<300)&&(analogRead(SensorD)>300)){  //IZQUIERDA
    digitalWrite(dirI,LOW);
    digitalWrite(dirD,HIGH);
    analogWrite(pwmI,250);
    analogWrite(pwmD,250);}
  
  if((analogRead(SensorI)<300)&&(analogRead(SensorD)<300)){  //AVANZA
    digitalWrite(dirI,HIGH);
    digitalWrite(dirD,HIGH);
    analogWrite(pwmI,250);
    analogWrite(pwmD,250);}
}  
    
