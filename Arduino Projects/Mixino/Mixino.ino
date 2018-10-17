#define m2 A2
#define m1 A3
int motorSpeed=120;
bool bstates=false;
void setup() {
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  Serial.begin(9600);
}
void Motor(int a,int b){
  analogWrite(m1,a);
  analogWrite(m2,b);
}
void loop() {
  int buttonU=digitalRead(3);
  int buttonD=digitalRead(6);
  Serial.println(motorSpeed);
  if(buttonU and !bstates){
    motorSpeed+=5;
    bstates=true;
  }else if(buttonD and !bstates){
    motorSpeed-=5;
    bstates=true;
  }else if((!buttonU and !buttonD) and bstates){
    bstates=false;
  }else{
    Serial.println("BOREddddddd");
  }if(motorSpeed<120){
    motorSpeed=120;
  }if(motorSpeed>255){
    motorSpeed=255;
  }Motor(motorSpeed,0);
}
