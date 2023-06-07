//hall sensor
//gpio26
#include "Arduino.h"
#define sensorPIN 34
#define ledPIN 2
int judge = 0;

void setup() {
    pinMode(sensorPIN, INPUT);
    pinMode(ledPIN, OUTPUT);
}

void loop() {
  judge = digitalRead(sensorPIN);
  digitalWrite(ledPIN,judge);
}
