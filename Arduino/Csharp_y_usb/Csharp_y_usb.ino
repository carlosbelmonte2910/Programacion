void setup()
{
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 
}

void loop()
{
 
 int rx;

 if (Serial.available() > 0)
 {
  Serial.println("Conectado y mandando msj desde arduino UNO R3");
  rx = Serial.read();
  if (rx == 'h') digitalWrite (13, HIGH);
  else if (rx == 'l') digitalWrite (13, LOW);
 }
}
