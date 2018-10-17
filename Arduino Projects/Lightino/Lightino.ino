#include <Adafruit_NeoPixel.h>
#define PIN            A1
#define NUMPIXELS      34
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
const int delayv=20;
int delayval = delayv;
int f=6;
bool Rw=true;
void setup() {
  pixels.begin();
}
void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    if(Rw){
      pixels.setPixelColor(i, pixels.Color(255,0,0));
    }else{
      pixels.setPixelColor(i, pixels.Color(0,255,0));
    }
    Rw=!Rw;
    if(i>4){
      pixels.setPixelColor(i-4, pixels.Color(0,0,0));
    }
    pixels.show();
    delay(delayval);
    
  }for(int i=NUMPIXELS;i<-1;i--){
    if(Rw){
      pixels.setPixelColor(i, pixels.Color(255,0,0));
    }else{
      pixels.setPixelColor(i, pixels.Color(0,255,0));
    }
    Rw=!Rw;
    if(i<29){
      pixels.setPixelColor(i+4, pixels.Color(0,0,0));
    }
    pixels.show();
    delay(delayval);
    
  }/*while(f>=0){
     pixels.setPixelColor(NUMPIXELS-f, pixels.Color(0,0,0));
     f--;
     pixels.show();
     delay(delayval);
  }
  f=6;
  delayval=delayv;*/
}
