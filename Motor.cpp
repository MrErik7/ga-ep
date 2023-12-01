#include "Motor.h"

Motor::Motor(int stepPin, int dirPin, int delayTime) {
  this->stepPin = stepPin;
  this->dirPin = dirPin;
  this->delayTime = delayTime;

  this->currentPosition = 0;
 // this->nextStepTime = 0;
 // this->stepStatus = LOW;
  this->currentDirection = HIGH; // set direction, HIGH for clockwise, LOW for anticlockwise

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(dirPin, currentDirection);
}

void Motor::moveClockwiseTo(int targetPosition) {

  // Firstly check so that the motor is not already in the correct position
  if (currentPosition == targetPosition) {
    return;
  }

  // Then check if the direction has changed
  if (currentDirection != HIGH) {
    currentDirection = HIGH;
    digitalWrite(dirPin, currentDirection);
     Serial.println("clockwise direction changed");
  }

  // Otherwise initiate the stepping loop 
  // * Here the decision to halt the entire script was neccesssary for my project
  // - Otherwise one would want to use a millis loop
  /*
  if (nextStepTime < millis()) {
      stepStatus = !stepStatus;
      digitalWrite(stepPin, stepStatus);

      nextStepTime = millis() + delayTime;
      currentPosition++;
 }
 */

 Serial.println("moving clockwise");

 for (int x = currentPosition; x < targetPosition; x++) {
    digitalWrite(stepPin,HIGH);
    delay(delayTime);
    digitalWrite(stepPin,LOW); 
    delay(delayTime);

    currentPosition+=1;

    String pos = String(currentPosition);
    Serial.println("Pos: " + pos);
 }
}

void Motor::moveCounterClockwiseTo(int targetPosition) {

  // Firstly check so that the motor is not already in the correct position
  if (currentPosition == targetPosition) {
    return;
  }

  // Then check if the direction has changed
  if (currentDirection != LOW) {
    currentDirection = LOW;
    digitalWrite(dirPin, currentDirection);
    Serial.println("clockwise direction changed");
  }

  /*
  // Otherwise step once
  if (nextStepTime < millis()) {
      stepStatus = !stepStatus;
      digitalWrite(stepPin, stepStatus);

      nextStepTime = millis() + delayTime;
      currentPosition--;
 }
 */
 Serial.println("moving anti clockwise");


  for (int x = currentPosition; x > targetPosition; x--) {
    digitalWrite(stepPin,HIGH);
    delay(delayTime);
    digitalWrite(stepPin,LOW); 
    delay(delayTime);

    currentPosition-=1;

    String pos = String(currentPosition);
    Serial.println("Pos: " + pos);
 }

}

int Motor::getPosition() {
  return currentPosition;
}
