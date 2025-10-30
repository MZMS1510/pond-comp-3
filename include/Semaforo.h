#include "Led.h"
#pragma once

class Semaforo {
public:
  Semaforo(Led* redLed, Led* yellowLed, Led* greenLed);
  void run();

private:
  Led redLed_m;
  Led yellowLed_m;
  Led greenLed_m;
};