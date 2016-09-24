// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at www.ardublog.com

#include <Ultrasonic.h>
int led=2;
int cte=15;
Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)

void setup() {
  Serial.begin(9600); 
  pinMode(led,OUTPUT);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  delay(100);
  if(ultrasonic.Ranging(CM) > cte){
    digitalWrite(led,HIGH);}
    else{
      digitalWrite(led,LOW);
    }
}
