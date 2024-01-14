#include "wifi.h"

#include "FreeRTOS.h"
#include "task.h"

#define TASK_PRIORITY	( tskIDLE_PRIORITY + 1UL )

struct Wifi::Impl {
  TaskHandle_t handle;
};

void loop(void* param) {

}

Wifi::Wifi() : impl(new Impl()) {
  xTaskCreate(loop, "Wifi", 500, this->impl.get(), TASK_PRIORITY, &this->impl->handle);
}
