#include <DS3231_Simple.h>
DS3231_Simple Clock;
int buzzer=5;
int led1=3;
int led2=4;
int button=2;
bool endA=true;
void setup(){
  //Serial.begin(9600);
  Clock.begin();
  //disable any existing alarms
  Clock.disableAlarms();
  // Get an initialized timestamp
  DateTime MyTimestamp=Clock.read();
  // We want the alarm at this second
  MyTimestamp.Second=30;
  // And now add the alarm to happen when the second matches
  Clock.setAlarm(MyTimestamp, DS3231_Simple::ALARM_MATCH_SECOND);
  Clock.setAlarm(DS3231_Simple::ALARM_EVERY_MINUTE);
  pinMode(buzzer,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button,INPUT);
  attachInterrupt(digitalPinToInterrupt(button),stopA,CHANGE);
}

void loop(){
  endA=true;
  // To check the alarms we just ask the clock
  uint8_t AlarmsFired = Clock.checkAlarms();
  //Serial.println(digitalRead(button));
  if(AlarmsFired & 1){
    while(endA){
      Serial.println(endA);
      for(int i=0;i<10;i++){
        digitalWrite(buzzer,HIGH);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        delay(250);
        digitalWrite(buzzer,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led1,LOW);
        delay(250);
      }
      digitalWrite(buzzer,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led1,HIGH);
      delay(1000);
      digitalWrite(buzzer,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led1,LOW);
    }
  }
}void stopA(){
  endA=false;
  //Serial.println("end");
}

