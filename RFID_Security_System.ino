#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <Servo.h>

// Your tag ID here. See Serial output to see your tag ID to replace.
const String MY_ID = "A7A5019"; 
const int pinRST = 9;
const int pinSDA = 10;
const int LOCKED_POSITION = 180;
const int UNLOCKED_POSITION = 0;
const int BUTTON_PIN = 2;
const int AUTH_LED = 7;
const int DENY_LED = 8;
int lockState = HIGH;
int buttonState = LOW;


MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino
Servo lockServo;

void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
  pinMode(7, HIGH);
  pinMode(8, HIGH);
  pinMode(BUTTON_PIN, INPUT);
  lockServo.attach(5);
  lockServo.write(LOCKED_POSITION);
  
}

void loop() {
  String readID = "";
  if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
    if(mfrc522.PICC_ReadCardSerial()) { // true, if RFID tag/card was read
      Serial.print("RFID Tag: ");
      for (byte i = 0; i < mfrc522.uid.size; ++i) { // read id (in parts)
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        readID.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      readID.toUpperCase();
      if(readID.compareTo(MY_ID) == 0){// Authorized, Unlock
          Serial.print(" Authorized access\n");
          lockState = LOW;
          digitalWrite(AUTH_LED, HIGH);
          lockServo.write(UNLOCKED_POSITION);  
      } else{ // Denied, Stay locked 
          Serial.print(" Denied access\n");
          digitalWrite(DENY_LED, HIGH);
      }
      delay(1500);
      digitalWrite(DENY_LED, LOW);
    }
  }
  // While unlocked, cannot read cards until door is shut (button is pressed)
  while(lockState == LOW){
    buttonState = digitalRead(BUTTON_PIN);
    if(buttonState == HIGH){
      lockServo.write(LOCKED_POSITION);
      digitalWrite(AUTH_LED, LOW);
      lockState = HIGH;
    }
  }
}
