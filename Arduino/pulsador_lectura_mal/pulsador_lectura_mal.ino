int Tiempo=0;
int pin = 4;

void setup()
{ 
  pinMode(pin, INPUT);
  attachInterrupt( 0, RxIR, FALLING);
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  digitalWrite(12, 0);
}

void loop()
{
  Tiempo= pulseIn(pin, HIGH);
}

void RxIR() 
{   
  digitalWrite(12, 1);
  delayMicroseconds(Tiempo);
  Tiempo = 0;  
  digitalWrite(12, 0);
}
