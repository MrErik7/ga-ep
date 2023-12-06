#include "Motor.h"
#include <Servo.h>


// Define the stepper motor pins
const int stepPinX = 2;
const int dirPinX = 5;
const int delayX = 2;

const int stepPinY = 3;
const int dirPinY = 6;
const int delayY = 2;

const int stepPinZ = 4;
const int dirPinZ = 7;
const int delayZ = 2;

//Motor motorX = Motor(stepPinX, dirPinX, delayX);
Motor motorY = Motor(stepPinY, dirPinY, delayY);
//Motor motorZ = Motor(stepPinZ, dirPinZ, delayZ);

// Initialize the servo
Servo servo1;
const int servo1_pin = 12;
int servo1_pos = 0;

void setup() {
    // --STEP MOTOR SETUP--
    motorY.setDirection(HIGH);

    // --SERVO SETUP--
    servo1.attach(servo1_pin);
    servo1.write(90); // Set the servo to a neutral position
    servo1_pos = 90;

    // -- DEBUG --
    Serial.begin(9600);
    Serial.println("initialized");

}

void loop() {
  // put your main code here, to run repeatedly:


  motorY.setDirection(HIGH);
  motorY.moveTo(200);
  delay(1000);

  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000);


}
