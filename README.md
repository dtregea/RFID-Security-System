# RFID-Security-System
The use of Arduino Uno to simulate a RFID tag based security system.

## Components
- Arduino Uno rev3
- RC522 RFID chip
- RFID tag
- External breadboard
- 2 External LED's
- 2 resistors

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

2. LED on Breadboard
- Access Denied LED | Digital pin 8
- Access Authorized LED | Digital pin 7