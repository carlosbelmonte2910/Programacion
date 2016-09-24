int val=0;

void setup(){
  Serial1.begin(9600);
  pinMode(13,OUTPUT);}
  
void loop(){
  val = Serial1.read();
  if(-1 != val){
    if('l' == val || 'L' == val){
      Serial1.println("Saludos desde Arduino!");}
    else if('h' == val || 'H' == val){
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);}}}
