
const int SW_pin=2;
const int X_pin=A0;
const int Y_pin=A1;
const int right=3;
const int left=4;
const int forward=5;
const int backward=6;
const int right_2=7;
const int left_2=8;
const int forward_2=9;
const int backward_2=10;

int button,x,y;

void setup() {
  pinMode(SW_pin,INPUT);
  pinMode(right,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(forward_2,OUTPUT);
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  pinMode(backward_2,OUTPUT);
  pinMode(left,OUTPUT);
  digitalWrite(SW_pin,HIGH);
  digitalWrite(right,LOW);
  digitalWrite(right_2,LOW);
  digitalWrite(left_2,LOW);
  digitalWrite(left,LOW);
  digitalWrite(forward_2,LOW);
  digitalWrite(forward,LOW);
  digitalWrite(backward,LOW);
  digitalWrite(backward_2,LOW);
  Serial.begin(9600);
}

void loop() {
  button=digitalRead(SW_pin);
  x=analogRead(X_pin);
  y=analogRead(Y_pin);
  if(x>490 and x<500){
    digitalWrite(right,0);
    digitalWrite(right_2,0);
    digitalWrite(left,0);
    digitalWrite(left_2,0);
    Serial.println("0");
  }else if(x>500 and x<761){
    digitalWrite(right,1);
    digitalWrite(right_2,0);
    Serial.println("1");
  }else if(x<762){
    digitalWrite(right,0);
    digitalWrite(right_2,1);
    Serial.println("2");
  }else if(x<490 and x>230){
    digitalWrite(left,1);
    digitalWrite(left_2,0);
    Serial.println("3");
  }else if(x<231){
    digitalWrite(left,0);
    digitalWrite(left_2,1);
    Serial.println("4");
  }if(y>490 and y<500){
    digitalWrite(forward,0);
    digitalWrite(forward_2,0);
    digitalWrite(backward,0);
    digitalWrite(backward_2,0);
    Serial.println("5");
  }else if(y>500 and y<761){
    digitalWrite(forward,1);
    digitalWrite(forward_2,0);
    Serial.println("6");
  }else if(y<762){
    digitalWrite(forward,0);
    digitalWrite(forward_2,1);
    Serial.println("7");
  }else if(y<490 and y>230){
    digitalWrite(backward,1);
    digitalWrite(backward_2,0);
    Serial.println("8");
  }else if(y<231){
    digitalWrite(backward,0);
    digitalWrite(backward_2,1);
    Serial.println("9");
  }
}
