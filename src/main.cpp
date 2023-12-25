#include <Arduino.h>
#include "FastAccelStepper.h"

#define dirPinStepper 22
#define enablePinStepper 23
#define stepPinStepper 19

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;

void setup()
{
  engine.init();
  stepper = engine.stepperConnectToPin(stepPinStepper);
  if (stepper)
  {
    stepper->setDirectionPin(dirPinStepper);
    stepper->setEnablePin(enablePinStepper);
    stepper->setAutoEnable(true);

    // If auto enable/disable need delays, just add (one or both):
    // stepper->setDelayToEnable(50);
    // stepper->setDelayToDisable(1000);

    stepper->setSpeedInUs(100); // the parameter is us/step !!!
    stepper->setAcceleration(5000);
    uint distance = 30000;
    for(int i=0; i<100; i++)
    {
    stepper->move(distance);
    while(stepper->isRunning()) delay(1);
    stepper->move(-distance);
    while(stepper->isRunning()) delay(1);
    }
  }
}

void loop()
{
}
