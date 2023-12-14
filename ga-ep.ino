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
const int delayY = 5;

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
    // --SERVO SETUP--
    servo.attach(servo_pin);
    servo.write(180);              // tell servo to go to position in variable 'pos'

    // -- DEBUG --
    Serial.begin(9600);
    Serial.println("initialized");

    // Move up the top plate
    motorY.setDirection(HIGH);
    motorY.moveTo(2000);
  

 //

  
 /* motorY.setDirection(HIGH);
  motorY.moveTo(2000);
  delay(1000);
  */


  /*

  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000); 
  */


    

}

void loop() {
  // put your main code here, to run repeatedly:
  // Open the valve 
  cookPancake();

}

void cookPancake() {
  Serial.println("---PANCAKE COOK HAS STARTED---");

  // Open the valve 
  servo.write(0);              // tell servo to go to position in variable 'pos'
  delay(1000);                       // waits 15ms for the servo to reach the position
  servo.write(180);              // tell servo to go to position in variable 'pos'
  delay(1000);                       // waits 15ms for the servo to reach the position

  // Move down the top plate
  motorY.setDirection(LOW);
  motorY.moveTo(300);
  delay(1000); 

  // Then wait
  Serial.println("---PANCAKE IS BEING COOKED FROM BOTH SIDES---");
  Serial.println("---PLEASE WAIT---");
  delay(30000);

  // Move up the top plate
  motorY.setDirection(HIGH);
  motorY.moveTo(2000);

  // And then rotate the lower plate
  motorX.setDirection(LOW);
  motorX.moveTo(50);
  delay(3000);

  motorX.setDirection(HIGH);
  motorX.moveTo(0);
  delay(1000);

  // THen finished
  Serial.println("---PANCAKE IS FINISHED---");


}
