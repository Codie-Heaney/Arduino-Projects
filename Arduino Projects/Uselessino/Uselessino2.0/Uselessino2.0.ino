#include <SR04.h>
#include <Servo.h>

int Sensor[]={2,3};
int Motor1_pins[]={53,52};
int Motor2_pins[]={55,54};
int Switch=22;
int Servo_pin=4;
int pos=0;
int rand_modes=3;
int rand_int=0;

long a;

SR04 sr04=SR04(Sensor[0],Sensor[1]);
Servo servo;

void setup() {
  pinMode(Motor1_pins[0],OUTPUT);
  pinMode(Motor1_pins[1],OUTPUT);
  pinMode(Motor2_pins[0],OUTPUT);
  pinMode(Motor2_pins[1],OUTPUT);
  pinMode(Switch,INPUT);
  servo.attach(Servo_pin);
  Serial.begin(9600);
}
void MotorMove(int m1,int m2,int m3,int m4){
  int a[]={m1,m2,m3,m4};
  for(int i=0;i < (sizeof(a)/sizeof(int));i++){//WRONG DO IT THE LONG WAY
      digitalWrite(a[i],HIGH);
      digitalWrite(a[i+2],LOW);
      Serial.println(m1);
  }
}
void StopWheel(){
  int a[]={Motor1_pins[0],Motor1_pins[1],Motor2_pins[0],Motor2_pins[1]};
  for(int i;i==5;i++){
    digitalWrite(a[i],LOW);
  }
}
void TurnOff(){
  for (pos = 0; pos <= 180; pos += 1){
    servo.write(pos);
    delay(15);
  }for (pos = 180; pos >= 0; pos -= 1){
    servo.write(pos);
    delay(15);
  }
}
void loop() {
  int dis=sr04.Distance();
  if(digitalRead(Switch)==0){
    rand_int=random(0,2);
    switch(rand_int){
      case 0:
        TurnOff();
        break;
      case 1:
        MotorMove(Motor1_pins[0],Motor1_pins[1],Motor2_pins[0],Motor2_pins[1]);
        delay(50000);
        StopWheel();
        TurnOff();
        break;
    }
  }
}
