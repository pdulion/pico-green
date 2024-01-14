#pragma once
#include <memory>

class Wifi {
  struct Impl;
  std::unique_ptr<Impl> impl;
public:
  Wifi();
  ~Wifi() = default;
  void start();
  void run();
};
