#include "FastAccelStepper.h"
#include "Arduino.h"

// As in StepperDemo for Motor 1 on AVR
//#define dirPinStepper    5
//#define enablePinStepper 6
//#define stepPinStepper   9  // OC1A in case of AVR

// As in StepperDemo for Motor 1 on ESP32
#define dirPinStepper 32
#define enablePinStepper 25
#define stepPinStepper 33
#define sensorPIN 34
#define ledPIN 2
bool judge = 0;

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;

void homing() {
  int32_t pos1, pos2;
  stepper->runForward();
  while(digitalRead(sensorPIN)){
  }
  // stepper->forceStop();
  pos1 = stepper->getCurrentPosition();
  Serial.printf("pos1:%d", pos1);
  stepper->runForward();
  while(!digitalRead(sensorPIN)) {
  }
  // stepper->forceStop();
  pos2 = stepper->getCurrentPosition();
  Serial.printf("pos2:%d", pos2);
  stepper->moveTo((pos1 + pos2)/2, true);
  Serial.printf("finished move");
}

void setup() {
  digitalWrite(ledPIN, 1);
  delay(500);
  digitalWrite(ledPIN, 0);
  delay(500);
  pinMode(dirPinStepper, OUTPUT);
  pinMode(enablePinStepper, OUTPUT);
  pinMode(stepPinStepper, OUTPUT);
  pinMode(sensorPIN, INPUT);
  pinMode(ledPIN, OUTPUT);
  Serial.begin(9600);
  engine.init();
  stepper = engine.stepperConnectToPin(stepPinStepper);
  if (stepper) {
    stepper->setDirectionPin(dirPinStepper);
    stepper->setEnablePin(enablePinStepper);
    stepper->setAutoEnable(true);
    stepper->setSpeedInHz(1000);  // the parameter is us/step !!!
    stepper->setAcceleration(4000);
   }
   homing();
}

void loop() {
  judge = digitalRead(sensorPIN);
  digitalWrite(ledPIN,judge);
}
