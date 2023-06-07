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

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;

void setup() {
//   Serial.begin(9600);
//   while(!Serial.available()){
    
//   }
  pinMode(dirPinStepper, OUTPUT);
  pinMode(enablePinStepper, OUTPUT);
  pinMode(stepPinStepper, OUTPUT);

  

  engine.init();
  stepper = engine.stepperConnectToPin(stepPinStepper);
  if (stepper) {
    stepper->setDirectionPin(dirPinStepper);
    stepper->setEnablePin(enablePinStepper);
    stepper->setAutoEnable(true);

    // If auto enable/disable need delays, just add (one or both):
    // stepper->setDelayToEnable(50);
    // stepper->setDelayToDisable(500);

    // while(!Serial.available()){

    // }
    // int a = Serial.read();
    // Serial.println(123);

  //   digitalWrite(stepPinStepper, 1);
  // delay(500);
  // digitalWrite(stepPinStepper, 0);
  // delay(500);
  // digitalWrite(stepPinStepper, 1);
  // delay(500);

    stepper->setSpeedInHz(1000);  // the parameter is us/step !!! highest~~15000 
    //full steps per meter = 530 /1666=0.3182725090036
    stepper->setAcceleration(100); //10000~15000
    stepper->runForward();
   } else {
    Serial.begin(9600);
    Serial.println("epic fail");
   }
}

void loop() {}