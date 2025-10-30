#ifndef SEMAFORO_H
#define SEMAFORO_H
#include "Led.h"
#include "Ultrasonic.h"
class Semaforo {
public:
  Semaforo(Led *redLed, Led *yellowLed, Led *greenLed, Ultrasonic *ultrasonic);
  void run();

private:
  Led redLed_m;
  Led yellowLed_m;
  Led greenLed_m;
  Ultrasonic ultrasonic_m;
  enum State
  {
    RED,
    YELLOW,
    GREEN
  } state_m;
};
#endif // SEMAFORO_H