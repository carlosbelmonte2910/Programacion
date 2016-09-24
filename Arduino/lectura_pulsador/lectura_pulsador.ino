#include <TimerOne.h>

volatile unsigned int ticks, AnchoPulso;

int button3Pin = 12;

void setup(void)
{
  pinMode(button3Pin, INPUT);
  Timer1.initialize(100);                  // inicializado a 100 useg
  Timer1.attachInterrupt(cuentoPulsos); // cuentoPulsos es la rutina que hace el trabajo
  Serial.begin(9600);
  AnchoPulso = 0;
  ticks = 0;
}


void cuentoPulsos(void)
{
    //ticks = 0;
    if(digitalRead(button3Pin) == 0){ticks++;}
    else{AnchoPulso = ticks;}
}

void loop(void)
{
  /*unsigned int AnchoCopy;  // Almacena el valor del Ancho del Pulso 
  noInterrupts();
  AnchoCopy = AnchoPulso;
  interrupts();*/

  Serial.print("Ancho = ");
  Serial.println((float) AnchoPulso/10);    // expresado en mseg con 1 decimal
  ticks = 0;
  AnchoPulso = 0;
  delay(100);                          // no me gusta el delay pero prueba que no afecta el funcionamiento de la rutina timer1.
}
