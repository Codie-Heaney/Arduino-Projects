#include "Keyboard.h";
void setup() {
  pinMode(2 ,INPUT_PULLUP);
  pinMode(3 ,INPUT_PULLUP);
  pinMode(4 ,INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  randomSeed(analogRead(0));
  Keyboard.begin();
}
void loop() {
  if (digitalRead(2) != HIGH) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_DELETE);
    delay(100);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  } if (digitalRead(3) != HIGH) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.print("t");
    Keyboard.releaseAll();
    delay(50);
  } if (digitalRead(4) != HIGH) {
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.releaseAll();
  }if (digitalRead(5) != HIGH) {
    Keyboard.print("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible.");
    Keyboard.releaseAll();
  }if (digitalRead(6) != HIGH) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("idle");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(5000);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.print("n");
    Keyboard.releaseAll();
    delay(2000);
    Keyboard.println("import random");
    Keyboard.press(KEY_RETURN);
    delay(50);
    Keyboard.println("while True:");
    Keyboard.press(KEY_RETURN);
    delay(50);
    Keyboard.println("print(random.randint(0,103823467890)*random.randint(3,4883782)+random.randint(2,488838)/random.randint(0,103823467890)%random.randint(0,103823467890))");
    delay(50);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.print("s");
    Keyboard.releaseAll();
    Keyboard.print(random(0, 2000));
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    Keyboard.press(KEY_F5);
    Keyboard.releaseAll();
    delay(4000);
  }
}








