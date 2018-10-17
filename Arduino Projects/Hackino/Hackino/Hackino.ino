#include <Mouse.h>
#include <Keyboard.h>
#include <LiquidCrystal.h>

#define modeSize 2
#define button1 11
#define button2 12
#define button3 13
#define mouseButton 4
#define xAxis A0
#define yAxis A1

char* modes[]={"Spam","Annoy","Control"};
int buttons[]={button1,button2,button3};
int count=0;
int pressed=0;
int pressed2=0;

int range = 12;
int responseDelay = 5;
int threshold = range / 4;
int center = range / 2;

LiquidCrystal lcd(5,6,7,8,9,10);

void setup()
{
  lcd.begin(16,2);
  lcd.print(modes[count]);
  pinMode(buttons[0],INPUT);
  pinMode(buttons[1],INPUT);
  pinMode(buttons[2],INPUT);
  //pinMode(mouseButton,INPUT);
  Serial.begin(9600);
}
 
void loop(){
  Serial.println(digitalRead(mouseButton));
  if(count==2){
  ButtonPresses();
    int xReading = readAxis(xAxis);
    int yReading = readAxis(yAxis);
    Mouse.move(xReading, yReading, 0);
    if (digitalRead(mouseButton) == 1) {
      if (!Mouse.isPressed(MOUSE_LEFT)) {
        Mouse.press(MOUSE_LEFT);
    }
      }
    else {
      if (Mouse.isPressed(MOUSE_LEFT)) {
        Mouse.release(MOUSE_LEFT);
      }
    }
    delay(responseDelay);
  }
}
void ButtonPresses(){
 int buttonState1=digitalRead(button1);
 int buttonState2=digitalRead(button3);
 int current=count;
  switch(buttonState1){
   case 1:
     if(pressed==0){
        count++;
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
          count--;
          pressed2=1;
       }
       break;
     case 0:
      pressed2=0;
      break;
    default:
      break;
  }
  if(count>modeSize){
    count=0;
  }else if(count<0){
    count=modeSize;
  }if(count!=current){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(modes[count]);
  }
}
int readAxis(int thisAxis) {
  int reading = analogRead(thisAxis);
  reading = map(reading, 0, 1023, 0, range);
  int distance = reading - center;
  if (abs(distance) < threshold) {
    distance = 0;
  }
  return distance;
}

