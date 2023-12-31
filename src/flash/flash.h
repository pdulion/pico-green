#pragma once
#include "pico/types.h"

class WifiFlash {
public:
  void run();
};

class GpioFlash {
public:
  GpioFlash(uint pin): pin(pin) {}
  void run();
private:
  uint pin;
};
