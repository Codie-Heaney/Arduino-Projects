

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(2000, A0, A1, A3);
int set=0;
String x="";
String y="";
String b="";
void setup(){
  Serial.begin(9600);
  if (!driver.init()){
     Serial.println("init failed");
  }else{
    Serial.println("Ready1");
  }
}
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
    }Serial.println(x);
      Serial.println(y);
      Serial.println(b);
  }
}

