/*#include "SR04.h"
//#define TRIG_PIN A1
//#define ECHO_PIN A2*/
#define m1 10
#define m2 9
#define m3 8
#define m4 7
#define m5 6
#define m6 5
#define m7 4
#define m8 3

/*SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);*/

long a;
bool Lr=false;

void setup() {
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(m5,OUTPUT);
  pinMode(m6,OUTPUT);
  pinMode(m7,OUTPUT);
  pinMode(m8,OUTPUT);
}
void MotorX(int a,int b,int c,int d){
  analogWrite(m3,a);
  analogWrite(m4,b);
  analogWrite(m7,c);
  analogWrite(m8,d);
}void MotorY(int a,int b,int c,int d){
  analogWrite(m1,a);
  analogWrite(m2,b);
  analogWrite(m5,c);
  analogWrite(m6,d);
}
void loop() {
  MotorX(1023,0,0,0);
  MotorY(1023,0,0,0);
  Serial.println("Hmm");
   /*a=sr04.Distance();
   //Serial.print(a);
   //Serial.println("cm");
   /*if(a<3){
    if(Lr){
      MotorX(0,1,0,1);
      MotorY(1,0,1,0);
    }else{
      MotorX(1,0,1,0);
      MotorY(0,1,0,1);
    }
   }else{
    
   }
   Lr=!Lr;
   //delay(10);*/
}
