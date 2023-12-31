#include "flash.h"

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "FreeRTOS.h"
#include "task.h"

#include <iostream>
using namespace std;

void WifiFlash::run() {
  if (cyw43_arch_init()) {
    for (;;) {
      cout << "Initialization Failed!" << endl;
      vTaskDelay(500);
    }
  }

  for (;;) {
    cout << "Blink!" << endl;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    vTaskDelay(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    vTaskDelay(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    vTaskDelay(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    vTaskDelay(1000);
  }
}

void GpioFlash::run() {
  gpio_init(pin);
  gpio_set_dir(pin, GPIO_OUT);
  for (;;) {
    cout << "Blink!" << endl;
    gpio_put(pin, 1);
    vTaskDelay(250);
    gpio_put(pin, 0);
    vTaskDelay(250);
    gpio_put(pin, 1);
    vTaskDelay(250);
    gpio_put(pin, 0);
    vTaskDelay(1000);
  }
}
