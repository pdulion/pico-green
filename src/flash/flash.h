#pragma once
#include "pico/types.h"
#include <memory>

class WifiFlash {
  struct Impl;
  std::unique_ptr<Impl> impl;               // to the forward-declared implementation class
public:
  WifiFlash();
  ~WifiFlash() = default;
  void start();
  void run();
};

class GpioFlash {
  struct Impl;
  std::unique_ptr<Impl> impl;               // to the forward-declared implementation class
public:
  GpioFlash(unsigned int pin);
  ~GpioFlash() = default;
  void start();
  void run();
};
