
const int SW_pin=2;
const int X_pin=A0;
const int Y_pin=A1;
const int xp=A2;
const int yp=A3;

int button,x,y;

void setup() {
  pinMode(SW_pin,INPUT);
  pinMode(xp,OUTPUT);
  pinMode(yp,OUTPUT);
  digitalWrite(SW_pin,HIGH);
  Serial.begin(9600);
}

void loop() {
  button=digitalRead(SW_pin);
  x=analogRead(X_pin);
  y=analogRead(Y_pin);
  analogWrite(xp,x);
  analogWrite(yp,y);
}
