int pin = 4;
unsigned long TL;

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
   }
    
void RxIR() 
{   
  TL = pulseIn(pin, LOW, 100000000);
  if(TL > 49500){digitalWrite(12, 1);}
  else{digitalWrite(12, 0);}     
}
     
   
