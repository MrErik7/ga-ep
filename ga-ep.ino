#include "Motor.h"
#include <Servo.h>

// -- Pancake cooking configuration variables --
bool firstTimeSetup = true;
int valveTime = 500; // (miliseconds) on how the long the valve should be open 
int cookTime = 2000; // (miliseconds) on how long both the plates should cook the pancake

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
int servo_pos = 0;

// Initialize the servo
Servo servo;


void setup() {
    // --STEP MOTOR SETUP--
    motorY.setDirection(HIGH);

    // --SERVO SETUP--
    servo.attach(servo_pin);

    // -- DEBUG --
    Serial.begin(9600);
    Serial.println("initialized");

   // Move up the top plate
 // motorY.setDirection(HIGH);
//  motorY.moveTo(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Open the valve 
   // cookPancake();


  motorX.setDirection(LOW);
  motorX.moveTo(200);

  delay(1000);

  motorX.setDirection(HIGH);
  motorX.moveTo(0);
  delay(1000);


  /*
  for (x = servo_pos; x <= 45; x += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(servo_pos);              // tell servo to go to position in variable 'pos'
    servo_pos+=1;
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  // Wait for a moment before closing the valve
  delay(valveTime);

  // Close the valve
  for (x = servo_pos; x >= 0; x -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(servo_pos);              // tell servo to go to position in variable 'pos'
    servo_pos-=1;
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  */


  /*
  motorY.setDirection(HIGH);
  motorY.moveTo(200);
  delay(1000);

  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000); */


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
  for (int x = servo_pos; x <= 45; x += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(servo_pos);              // tell servo to go to position in variable 'pos'
    servo_pos+=1;
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  // Wait for a moment before closing the valve
  delay(valveTime);

  // Close the valve
  for (int x = servo_pos; x >= 0; x -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(servo_pos);              // tell servo to go to position in variable 'pos'
    servo_pos-=1;
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  // Move down the top plate
  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000); 

  // Then wait
  Serial.println("---PANCAKE IS BEING COOKED FROM BOTH SIDES---");
  Serial.println("---PLEASE WAIT---");
  delay(cookTime);

  // Move up the top plate
  motorY.setDirection(HIGH);
  motorY.moveTo(1000);

  // And then rotate the lower plate
  motorX.setDirection(HIGH);
  motorX.moveTo(100);

  // Wait for a second
  delay(1000);

  // Then rotate it back
  motorX.setDirection(LOW);
  motorX.moveTo(0);

  // THen finished
  Serial.println("---PANCAKE IS FINISHED---");











}
