#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         5
#define SS_PIN          53
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(2, 3, 4, 8, 6, 7);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  RfidScan();
}

void dump_byte_array(byte *buffer, byte bufferSize) {
  lcd.clear();
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    lcd.print(buffer[i], HEX);
  }
}

void RfidScan()
{
  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
}
