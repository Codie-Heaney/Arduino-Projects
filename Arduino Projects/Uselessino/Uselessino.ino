#include <Servo.h>

const int SW_pin=22;
const int X_pin=1;
const int Y_pin=0;
const int LED_pin=23;
const int Servo_pin=9;
const int time_s=1000;

int pos=0;
int step_=1;
int time_=time_s;

bool start_time=false;
bool pressed=false;
bool returned=false;

Servo servo;

void setup() {
  pinMode(SW_pin,INPUT);
  pinMode(LED_pin,OUTPUT);
  digitalWrite(SW_pin,HIGH);
  Serial.begin(9600);
  servo.attach(Servo_pin);
}

void loop() {
  Serial.println(time_);
  Serial.println(returned);
  if(((analogRead(X_pin)>500||analogRead(X_pin)<490)&&(analogRead(Y_pin)>500||analogRead(Y_pin)<480))&&!pressed&&returned){
    pressed=true;
    returned=false;
    digitalWrite(LED_pin,HIGH);
    start_time=true;
    delay(50);
  }else if(((analogRead(X_pin)>500||analogRead(X_pin)<490)&&(analogRead(Y_pin)>500||analogRead(Y_pin)<480))&&pressed&&returned){
    pressed=false;
    returned=false;
    digitalWrite(LED_pin,LOW);
    delay(50);
  }else if((analogRead(X_pin)<500&&analogRead(X_pin)>490)&&(analogRead(Y_pin)<500&&analogRead(Y_pin)>480)){
    returned=true;
  }if(start_time){
    time_--;
  }if(pressed&&returned&&time_<0){
    for(pos=0;pos<=90;pos+=step_){
      servo.write(pos);
      delay(15);
    }
    digitalWrite(LED_pin,LOW);
    for(pos=90;pos>=0;pos-=step_){
      servo.write(pos);
      delay(15);
    }
    pressed=false;
    returned=true;
    time_=time_s;
    start_time=false;
    Serial.println("T");
    delay(50);
  }
}
