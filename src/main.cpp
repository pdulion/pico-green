#include "flash/flash.h"

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "FreeRTOS.h"
#include "task.h"

#include <iostream>
using namespace std;

#define TASK_PRIORITY	( tskIDLE_PRIORITY + 1UL )

template<typename T>
void taskRunner(void* param) {
  ((T*)param)->run();
}

int main(int, char**) {
  stdio_init_all();

  cout << "Hello, from green-pi!" << endl;

  // cyw43_flash();
  // gpio_flash(10);
  WifiFlash wifi{};
  GpioFlash gpio{ 3 };

  TaskHandle_t cyw43_handle, gpio_handle;
  xTaskCreate(taskRunner<WifiFlash>, "CYW43_Flash", 500, &wifi, TASK_PRIORITY, &cyw43_handle);
  xTaskCreate(taskRunner<GpioFlash>, "GPIO_Flash", 500, &gpio, TASK_PRIORITY, &gpio_handle);
  vTaskStartScheduler();
}
