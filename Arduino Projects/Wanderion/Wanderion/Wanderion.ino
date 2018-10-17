#include "SR04.h"
#define TRIG_PIN 3
#define ECHO_PIN 2
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long dis;
int mp1=4;
int mp2=5;
int mp3=6;
int mp4=7;
int turnTime=500;
void setup() {
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  Serial.begin(9600);
}
void SetMotor(int a,int b,int c,int d){
  digitalWrite(4,a);
  digitalWrite(5,b);
  digitalWrite(6,c);
  digitalWrite(7,d);
}
void Turn(){
  SetMotor(1,0,0,0);
  delay(turnTime);
  dis=sr04.Distance();
  if(dis>10){
    SetMotor(1,0,1,0);
    return;
  }else{
    SetMotor(0,0,1,0);
    delay(turnTime*2);
  }
}
void loop() {
  dis=sr04.Distance();

  if(dis<=10){
      
  }else{
   
  }
}
