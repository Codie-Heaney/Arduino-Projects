#include <IRremote.h>
#include <IRremoteInt.h>
IRsend irsend;

void setup()
{
  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i < 3; i++) {
    irsend.sendRC6(0xc24, 36);
    delay(50);
  }
}
