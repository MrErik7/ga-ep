#include "Motor.h"

Motor::Motor(int stepPin, int dirPin, int delayTime) {
  this->stepPin = stepPin;
  this->dirPin = dirPin;
  this->delayTime = delayTime;

  this->currentPosition = 0;
  this->currentDirection = HIGH; // set direction, HIGH for clockwise, LOW for anticlockwise

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(dirPin, currentDirection);
}

void Motor::setDirection(int direction) {
    currentDirection = direction;
    digitalWrite(dirPin, currentDirection);
    Serial.println("direction changed");
}


void Motor::moveTo(int targetPosition) {
  // Firstly check so that the motor is not already in the correct position
  if (currentPosition == targetPosition) {
    return;
  }

  // Then check the current position in correlation to the target position
  if (currentPosition < targetPosition) {
    for (int x = currentPosition; x < targetPosition; x++) {
      digitalWrite(stepPin,HIGH);
      delay(delayTime);
      digitalWrite(stepPin,LOW); 
      delay(delayTime);

      currentPosition+=1;

      String pos = String(currentPosition);
      Serial.println("Pos: " + pos);
    }    
  } else {
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


}

int Motor::getPosition() {
  return currentPosition;
}
