#include <Servo.h>
Servo servo_;


int servo_pin=A1;

void setup(){ 
  Serial.begin(9600);
  servo_.attach(servo_pin);
} 
void ServoMove(int angle_start, int angle_limit, int angle_addition){
  for(int angle = angle_start; angle < angle_limit; angle += angle_addition){                                  
    servo_.write(angle);
    delay(15);
  }  
}  
void loop() {
  ServoMove(0,70,1);
  delay(1001);
  ServoMove(70,0,-1);
}
