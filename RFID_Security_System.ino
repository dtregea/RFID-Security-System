#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

const int pinRST = 9;
const int pinSDA = 10;
// Your tag ID here. See later code to see how to find it.
const String MY_ID = "A7A5019"; 
MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino

void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
  pinMode(7, HIGH);
  pinMode(8, HIGH);
}

void loop() {
  String readID = "";
  int led;
  if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
    if(mfrc522.PICC_ReadCardSerial()) { // true, if RFID tag/card was read
      //Serial.print("RFID TAG ID:");
      for (byte i = 0; i < mfrc522.uid.size; ++i) { // read id (in parts)
        // Uncomment this to read the card number in order to set up which tags and their ID's authorize access
        //Serial.print(mfrc522.uid.uidByte[i], HEX);
        readID.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      readID.toUpperCase();
      if(readID.compareTo(MY_ID) == 0){
          Serial.print("\n" + readID + " Authorized access\n");
          digitalWrite(7, HIGH);
          led = 7;
        } else{
          Serial.print(readID + " Denied access\n");
          digitalWrite(8, HIGH);
          led = 8;
        }
       delay(1500);
       digitalWrite(led, LOW);
    }
  }
}
