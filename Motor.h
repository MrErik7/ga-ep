#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor {
private:
  int stepPin;
  int dirPin;
  int delayTime;
  int currentPosition;
  int currentDirection;

public:
  Motor(int stepPin, int dirPin, int delayTime);
  void moveClockwiseTo(int targetPosition);
  void moveCounterClockwiseTo(int targetPosition);
  int getPosition();
};

#endif
