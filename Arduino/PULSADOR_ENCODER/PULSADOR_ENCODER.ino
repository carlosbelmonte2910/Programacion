int pulsadorA = 7;
int pulsadorB = 6;
int A = 0;
int B = 0;
int contador = 0;

void setup(){ 
  pinMode(pulsadorA, INPUT);
  pinMode(pulsadorB, INPUT);
  DDRD = B00111111;}
 
void loop(){
comienzo:
  A = digitalRead(pulsadorA);
  B = digitalRead(pulsadorB);
  
  if (A == HIGH){
volverA:
    A = digitalRead(pulsadorA);
     if(A == LOW){  
       cuenta_ascendente();
       delay(10);
       goto comienzo;}
     delay(10);
     goto volverA;}  
     
  if (B == HIGH){
volverB:
   B = digitalRead(pulsadorB);
     if(B == LOW){  
       cuenta_descendente();
       delay(10);
       goto comienzo;}
     delay(10);
     goto volverB;}}
   
void cuenta_ascendente(){
  contador++;
  PORTD = contador;
  if (contador == 9){
   contador = 0;}}

void cuenta_descendente(){
  contador--;
  PORTD = contador;
  if (contador == 1){
   contador = 10;}}
