int pinReceptor = 14; //Guardamos en esta variable el pin Analógico
int sensorVal=0;
int LED_V=13;
int LED_R=12;

void setup(){
  pinMode(LED_R, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(pinReceptor, INPUT);
}

void loop(){
sensorVal = digitalRead(pinReceptor);

if(sensorVal == HIGH){
  digitalWrite(LED_R, 1);
  digitalWrite(LED_V, 0);}
if(sensorVal == LOW){
  digitalWrite(LED_R, 0);
  digitalWrite(LED_V, 1);
  }
}
