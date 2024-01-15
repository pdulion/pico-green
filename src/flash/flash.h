#pragma once
#include "pico/types.h"
#include <memory>

class WifiFlash {
public:
  WifiFlash() {};
  ~WifiFlash() = default;
  void start();
  void run();
};

class GpioFlash {
  unsigned int pin;
public:
  GpioFlash(unsigned int pin) : pin(pin) {};
  ~GpioFlash() = default;
  void start();
  void run();
};
