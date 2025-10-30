#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
public:
  Ultrasonic(int triggerPin, int echoPin);
  long readDistanceCM();

private:
  int triggerPin_m;
  int echoPin_m;
};

#endif // ULTRASONIC_H