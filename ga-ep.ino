#include "Motor.h"

const int stepPinX = 2;
const int dirPinX = 5;
const int delayX = 2;

Motor motorX = Motor(stepPinX, dirPinX, delayX);



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Serial.println("initialized");
}

void loop() {
  // put your main code here, to run repeatedly:


  motorX.moveClockwiseTo(200);
  delay(1000);

  motorX.moveCounterClockwiseTo(0);
  delay(1000);



}
