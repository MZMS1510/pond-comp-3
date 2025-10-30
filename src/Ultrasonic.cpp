#include <Arduino.h>
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
  triggerPin_m = triggerPin;
  echoPin_m = echoPin;
  pinMode(triggerPin_m, OUTPUT);
  pinMode(echoPin_m, INPUT);
}

long Ultrasonic::readDistanceCM() {
  digitalWrite(triggerPin_m, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin_m, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin_m, LOW);

  float duration = pulseIn(echoPin_m, HIGH);
  return (duration * 0.0343) / 2;
}
