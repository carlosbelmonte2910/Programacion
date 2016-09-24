#define SOUND_SPD 320
volatile long t_start;
volatile double lastDist;

void setup() {
  //Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  pinMode(13,OUTPUT);
  attachInterrupt(0,onChange,CHANGE);
  
  digitalWrite(4,LOW);
}


void onChange() {
  if(t_start==0) {
    t_start = micros();
  } else {
    lastDist = (((micros()-t_start)/1000000.0)*SOUND_SPD)/2;
    //Serial.write("Distance: ");
    //Serial.print(lastDist);
    //Serial.write("m\r\n");
    if(lastDist < 0.50){
      digitalWrite(13,HIGH);
    }
    else{
      digitalWrite(13,LOW);
    }
  }
}

void startMeasure() {
  t_start = 0;
  //Serial.write("Starting measure...\r\n");
  digitalWrite(4,HIGH);
  delayMicroseconds(10);
  digitalWrite(4,LOW);
}

void loop() {
  startMeasure();
  delay(10);
}
