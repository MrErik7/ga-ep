#include "Motor.h"
#include <Servo.h>

// -- Pancake cooking configuration variables --
bool firstTimeSetup = true;
int valveTime = 10000; // (miliseconds) on how the long the valve should be open 
int cookTime = 1200000; // (miliseconds) on how long both the plates should cook the pancake

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

// Initialize the stepper motor pins
Motor motorX = Motor(stepPinX, dirPinX, delayX);
Motor motorY = Motor(stepPinY, dirPinY, delayY);
//Motor motorZ = Motor(stepPinZ, dirPinZ, delayZ);

// Define the servo motor pins
const int servo_pin = 12;

// Initialize the servo
Servo servo;


void setup() {
    // --STEP MOTOR SETUP--
    motorY.setDirection(HIGH);

    // --SERVO SETUP--
    servo.attach(servo_pin);
    servo.write(180);              // tell servo to go to position in variable 'pos'

    // -- DEBUG --
    Serial.begin(9600);
    Serial.println("initialized");


  // cookPancake();

}

void loop() {
  // put your main code here, to run repeatedly:
  // Open the valve 
 // cookPancake();
//

  
  motorX.setDirection(HIGH);
  motorX.moveTo(100);
  delay(1000);

  motorX.setDirection(LOW);
  motorX.moveTo(0);
  delay(1000); 


}

void cookPancake() {
  // First revert back everything to its default positions
  if (firstTimeSetup) {
    motorY.setDirection(HIGH);
    motorY.moveTo(1000);  
    firstTimeSetup = false;
  }

  // Then begin
  Serial.println("---PANCAKE COOK HAS STARTED---");
  
  // Open the valve 
  for (int x = 180; x >= 0; x -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(x);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }


  // Wait for a moment before closing the valve
  delay(10000);

  // Close the valve
  for (int x = 0; x <= 180; x += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(x);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }


  // Move down the top plate
  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000); 

  // Then wait
  Serial.println("---PANCAKE IS BEING COOKED FROM BOTH SIDES---");
  Serial.println("---PLEASE WAIT---");
  delay(60000);

  // Move up the top plate
  motorY.setDirection(HIGH);
  motorY.moveTo(1000);

  // And then rotate the lower plate
  motorX.setDirection(LOW);
  motorX.moveTo(100);

  // Wait for a second
  delay(1000);

  // Then rotate it back
  motorX.setDirection(HIGH);
  motorX.moveTo(0);

  // THen finished
  Serial.println("---PANCAKE IS FINISHED---");











}
