
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, A6, A5, A2);

void setup(){
  Serial.begin(9600);
  if(!driver.init()){
    Serial.println("init failed");
  }else{
    Serial.println("Ready");
  }
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(8,INPUT);
  digitalWrite(8,HIGH);
}

void loop(){
    int x=analogRead(A7);
    int y=analogRead(A0);
    int button=digitalRead(8);
    String full=String(x)+"m"+String(y)+"m"+String(button);
    char sendFull[full.length()+1];
    full.toCharArray(sendFull,full.length()+1);
    Serial.println(sendFull);
    driver.send((uint8_t *)sendFull, strlen(sendFull));
    driver.waitPacketSent();
    delay(100);
}
