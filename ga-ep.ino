#include "Motor.h"
#include <Servo.h>

// -- Pancake cooking configuration variables --
bool firstTimeSetup = true;
int valveTime = 3000; // (miliseconds) on how the long the valve should be open 
int cookTime = 120; // (seconds) on how long both the plates should cook the pancake

// Define the stepper motor pins
const int stepPinX = 2;
const int dirPinX = 5;
const int delayX = 8;

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

    // -- DEBUG --
    Serial.begin(9600);
    Serial.println("initialized");

    cookPancake();
  


    

}

void loop() {
  // put your main code here, to run repeatedly:
 // cookPancake();

  



}

void cookPancake() {
  Serial.println("---PANCAKE COOK HAS STARTED---");


  // Move up the top plate
   motorY.setDirection(HIGH);
   motorY.moveTo(2000);

  delay(500);                      

  // Open the valve 
  servo.attach(servo_pin);

  servo.write(0);              // tell servo to go to position in variable 'pos'
  delay(valveTime);                       // waits 15ms for the servo to reach the position
  servo.write(180);              // tell servo to go to position in variable 'pos'

  delay(1000);                       // waits 15ms for the servo to reach the position

  // Move down the top plate
  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000); 

  // Then wait
  Serial.println("---PANCAKE IS BEING COOKED FROM BOTH SIDES---");
  Serial.println("---PLEASE WAIT---");

  for (int i = cookTime; i >= 0; i--){
    Serial.println(i);
    delay(1000);
  } 
    
  
  Serial.println("---PLEASE WAIT---");


  // Move up the top plate
  motorY.setDirection(HIGH);
  motorY.moveTo(2000);

  // And then rotate the lower plate
  motorX.setDirection(LOW);
  motorX.moveTo(50);
  delay(5000);

  motorX.setDirection(HIGH);
  motorX.moveTo(0);
  delay(1000);

  // Move down the top plate
  motorY.setDirection(LOW);
  motorY.moveTo(0);
  delay(1000); 

  // THen finished
  Serial.println("---PANCAKE IS FINISHED---");


}
