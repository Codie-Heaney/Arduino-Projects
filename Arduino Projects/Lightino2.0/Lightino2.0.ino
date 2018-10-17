#include <Adafruit_NeoPixel.h>
#define PIN            A1
#define NUMPIXELS      35
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define PIN2            A0
#define NUMPIXELS2      35
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 0;
int brightness=1;
int r;
int b;
int g;
int rA[]={255,0,0,255};
int bA[]={0,255,0,0};
int gA[]={0,0,255,0};
int I;
bool rC=false;
bool bC=false;
bool gC=false;
void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels2.begin();

}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,0,255));
  }
  
  for(int i=0;i<NUMPIXELS2;i++){
    pixels2.setPixelColor(i, pixels2.Color(255,255,0));
  }
  pixels.show();
  pixels2.show();
  delay(delayval);
}
