#include "Motor.h"

const int stepPinX = 2;
const int dirPinX = 5;
const int delayX = 2;

const int stepPinY = 3;
const int dirPinY = 6;
const int delayY = 2;

const int stepPinZ = 4;
const int dirPinZ = 7;
const int delayZ = 2;

Motor motorX = Motor(stepPinX, dirPinX, delayX);
Motor motorY = Motor(stepPinY, dirPinY, delayY);
Motor motorZ = Motor(stepPinZ, dirPinZ, delayZ);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Serial.println("initialized");
}

void loop() {
  // put your main code here, to run repeatedly:


  motorY.moveClockwiseTo(200);
  delay(1000);

  motorY.moveCounterClockwiseTo(0);
  delay(1000);

  motorX.moveClockwiseTo(200);
  delay(1000);

  motorX.moveCounterClockwiseTo(0);
  delay(1000);



}
