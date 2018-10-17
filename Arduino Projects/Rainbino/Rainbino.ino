#include <Adafruit_NeoPixel.h>
#define PIN            A1
#define NUMPIXELS      40
#define PIN2            A0
#define NUMPIXELS2      40
#define PIN3            A2
#define NUMPIXELS3      40
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
int delayval = 1;
int coldelay=255/2;
int brightness=1;
int r=10;
int g=215;
int b=10;
bool flipR=true;
bool flipG=false;
bool flipB=false;
bool bst=false;
bool gst=false;
void setup() {
  //pinMode(10,INPUT);
  Serial.begin(9600);
  pixels.begin();
  pixels2.begin();
  pixels3.begin();
  pixels.show();
  pixels2.show();
  pixels3.show();
}
void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, r/brightness,g/brightness,b/brightness);
    Serial.println(r);
  }
  pixels.show();
  for(int i=0;i<NUMPIXELS2;i++){
    pixels2.setPixelColor(i,r/brightness,g/brightness,b/brightness);
    Serial.println(r);
  }
  pixels2.show();
  for(int i=0;i<NUMPIXELS3;i++){
    pixels3.setPixelColor(i, r/brightness,g/brightness,b/brightness);
    Serial.println(r);
  }
  pixels3.show();
  delay(delayval);
}
