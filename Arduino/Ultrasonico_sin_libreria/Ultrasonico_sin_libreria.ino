long distancia;
long tiempo;
int trigPin = 9;
int echoPin = 8;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echoPin, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(trigPin,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  tiempo=pulseIn(echoPin, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int((tiempo/2)/29); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  //Serial.println("Distancia ");
  Serial.println(distancia);
  //Serial.println(" cm");
  delay(50);
}
