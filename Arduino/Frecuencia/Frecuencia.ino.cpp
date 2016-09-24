#include <Arduino.h>
int pin = 7;
unsigned long TH;
unsigned long TL;
unsigned long TT;
unsigned long FT;



void setup()
   {  
   	pinMode(pin, INPUT);
   	Serial.begin(9600);
   }

void loop()
   {
	TH = pulseIn(pin, HIGH);
	TL = pulseIn(pin, LOW);
	TT = TH + TL;
	FT = 1/TT;
	Serial.println(FT);
	delay(1000);

   }