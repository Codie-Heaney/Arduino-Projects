#include "SR04.h"
#define TRIG_PIN A1
#define ECHO_PIN A2
#define m1 12
#define m2 11
#define m3 10
#define m4 9
#define m5 8
#define m6 7
#define m7 6
#define m8 5
//Rest:x=523 y=514 b=1
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, A0, A1, A3);
int set=0;
String x="";
String y="";
String b="";

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

long a;

void setup() {
    Serial.begin(9600);
    if(!driver.init()){
       Serial.println("init failed");
    }else{
      Serial.println("Ready1");
    }
   delay(1000);
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
/*void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}*/
void loop(){
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  if(driver.recv(buf, &buflen)){
    String strR;
    int startAt=0;
    for(int i;i<buflen;i++){
      strR+=(char)buf[i];
    }
    int o=0;
    x="";
    y="";
    b="";
    char str[strR.length()+1];
    strR.toCharArray(str,strR.length()+1);
    while(true){
      if(str[o]=='m'){
        set++;
      }else if(set==0){
        x+=str[o];
      }else if(set==1){
        y+=str[o];
      }else if(set==2){
        b+=str[o];
        set=0;
        break;
      }
      o++;
    }
    int X=x.toInt();
    int Y=y.toInt();
    int B=b.toInt();
    if(X>530){
      MotorX(X/4,0,X/4,0);
    }else if(X<516){
      MotorX(255-(X/4),0,255-(X/4),0);
    }else{
      MotorX(0,0,0,0);
    }if(Y>521){
      MotorY(Y/4,0,Y/4,0);
    }else if(Y<507){
      MotorY(255-(Y/4),0,255-(Y/4),0);
    }else{
      MotorY(0,0,0,0);
    }
  }
}
