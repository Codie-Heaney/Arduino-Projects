#include <EEPROM.h>
#include <SR04.h>
#define TRIG_PIN A1
#define ECHO_PIN A2
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
long set;
int address=0;
int i=0;
int amount;
void setup() {
   Serial.begin(9600);
   delay(1000);
   set=sr04.Distance();
   for(int x;x<EEPROM.length();x++){
    amount=EEPROM.read(x);
    if(amount<255){
      address=x;
      i=amount;
      break;
    }
   }
}

void loop() {
   a=sr04.Distance();
   Serial.println(EEPROM.read(0));
   if(a<set){
    i++;
    if(i==256){
      address++;
      i=1;  
    }
    EEPROM.write(address,i);
   }
   delay(1000);
}
