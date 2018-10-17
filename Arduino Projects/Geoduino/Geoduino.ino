#include <LiquidCrystal.h>
#include <SimpleDHT.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
SimpleDHT11 dht11;

int pinTempHumid=22;
int lightpin=A0;
int button1=24;
int button2=26;
int waterSys=A1;

int lights=0;
int buttonState1=0;
int buttonState2=0;
int mode=0;
int pressed=0;
int pressed2=0;
int tt=0;
int HistoryValue=0;

float p=0;
float t=0.0;

char buf3[16];
char buf[16];
char buf2[16];
char buf4[128];

void setup() {
  lcd.begin(16, 2);
  lcd.print("Booting");
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState1=digitalRead(button1);
  buttonState2=digitalRead(button2);
  byte temp=0;
  byte humidity=0;
  byte data[40]={0};
  int waterLvl=0;
  switch(buttonState1){
   case 1:
     if(pressed==0){
        mode++;
        pressed=1;
     }
     break;
   case 0:
    pressed=0;
    break;
   default:
     break;
  }switch(buttonState2){
    case 1:
      if(pressed2==0){
          mode--;
          pressed2=1;
          
       }break;
     case 0:
      pressed2=0;
      break;
    default:
      break;
  }switch(mode){
    case 0:
      lcd.clear();
      if(dht11.read(pinTempHumid,&temp,&humidity,data)){
        lcd.setCursor(0,0);
        lcd.print("????");
        delay(1000);
      }else{
        sprintf(buf,"Temp:%dC",temp);
        lcd.setCursor(0,0);
        lcd.print(buf);
        lcd.setCursor(0,1);
        sprintf(buf2,"Humidity:%d%%",humidity);
        lcd.print(buf2);
        delay(1000);  
      }
      break;
    case 1:
      lights=analogRead(lightpin);
      lcd.clear();
      lcd.setCursor(0,0);
      p=1023-lights;
      t=p/1023;
      t=t*100;
      t=round(t);
      tt=(int)t;
      sprintf(buf3,"Lighting:%d%%",tt);
      lcd.print(buf3);
      delay(100);
      break;
    case 2:
      lcd.setCursor(0,0);
      waterLvl=analogRead(waterSys);
      lcd.clear();
      sprintf(buf4,"ADC level:%d",HistoryValue);
      lcd.print(buf4);
      if(((HistoryValue>=waterLvl) && ((HistoryValue - waterLvl) > 10)) || ((HistoryValue<waterLvl) && ((waterLvl - HistoryValue) > 10))){
        lcd.clear();
        sprintf(buf4,"ADC level:%d",waterLvl);
        lcd.print(buf4);
        HistoryValue=waterLvl;
      }
      delay(100);
      break;
    default:
      lcd.clear();
      lcd.print(mode);
      delay(100);
      break;
  }
  
  
}

