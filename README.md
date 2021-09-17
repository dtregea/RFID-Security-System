# RFID-Security-System
The use of Arduino Uno to simulate a RFID tag based security system.
Upon the correct RFID tag being authorized, the lock will open and will wait until the user closes the door to continue reading cards.

## Component Functions
- RC522 RFID Chip | Tag reader
- LED's | Tag acceptance indicator
- Servo Motor | Locks door
- Button | Closes door
- Buzzer | Indicates RFID authorization/reject

## Components
- Arduino Uno rev3
- RC522 RFID chip
- RFID tag
- External breadboard
- 2 External LED's
- 3 Resistors
- Button
- Breadboard Power Supply Module
- 5V Power source for breadboard power supply module
- Servo Motor
- Buzzer

## Pin Layout
1. RC522
- SDA | Digital pin 10
- SCK | Digital pin 13
- MOSI | Digital pin 11
- MISO | Digital pin 12
- IRQ | unconnected
- GND | GND
- RST | Digital pin 9
- 3.3V | 3.3V (Not 5v)

2. LED's on Breadboard
- Access Denied LED | Digital pin 8
- Access Authorized LED | Digital pin 7
- Transistor between 5V and led (1 each)

3. Servo Motor on Breadboard
- PWM | Digital pin 5
- 5V |  Breadboard Power
- GND | GND

4. Button on Breadboard
- 5V | Breadboard Power
- GND | GND
- 1 Transistor between button and ground

5. Buzzer on Breadboard
- 5V | Digital pin 5
- GND | GND