/* PWM PARA SERVOMOTOR */
#include <Servo.h>
Servo  SERVO_1;

void setup()
{
  SERVO_1.attach(9);
}

void loop()
{  
  SERVO_1.write(0);
  delay(1000);
  SERVO_1.write(45);
  delay(1000);
  SERVO_1.write(180);
  delay(1000);
  
  SERVO_1.write(180);
  delay(1000);
  
}
