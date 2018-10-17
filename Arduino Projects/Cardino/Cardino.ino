#include <MFRC522.h>
#include <SPI.h> // Used for communication via SPI with the Module
#define SDAPIN 53 // RFID Module SDA Pin is connected to the UNO 10 Pin
# define RESETPIN 5 // RFID Module RST Pin is connected to the UNO 8 Pin
byte FoundTag; // Variable used to check if Tag was found
byte ReadTag; // Variable used to store anti-collision value to read Tag information
byte TagData[MAX_LEN]; // Variable used to store Full Tag Data
byte TagSerialNumber[5]; // Variable used to store only Tag Serial Number

MFRC522 nfc(SDAPIN, RESETPIN); // Init of the library using the UNO pins declared above

void setup() {
  SPI.begin();
  Serial.begin(9600);

  // Start to find an RFID Module
  Serial.println("Looking for RFID Reader");
  nfc.begin();
  byte version = nfc.getFirmwareVersion(); // Variable to store Firmware version of the Module

  // If can't find an RFID Module 
  if (!version) {
    Serial.print("Didn't find RC522 board.");
    while (1); //Wait until a RFID Module is found
  }

  // If found, print the information about the RFID Module
  Serial.print("Found chip RC522 ");
  Serial.print("Firmware version: 0x");
  Serial.println(version, HEX);
  Serial.println();
}

void loop() {

  // Check to see if a Tag was detected
  // If yes, then the variable FoundTag will contain "MI_OK"
  FoundTag = nfc.requestTag(MF1_REQIDL, TagData);

  if (FoundTag == MI_OK) {
    delay(200);

    // Get anti-collision value to properly read information from the Tag
    ReadTag = nfc.antiCollision(TagData);
    memcpy(TagSerialNumber, TagData, 4); // Write the Tag information in the TagSerialNumber variable

    Serial.println("Tag detected.");
    Serial.print("Serial Number: ");
    for (int i = 0; i < 4; i++) { // Loop to print serial number to serial monitor
      Serial.print(TagSerialNumber[i]);
      Serial.print(", ");
    }
    Serial.println("");
    Serial.println();

  }
}
