#include <iostream>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

using namespace std;

int main(int, char **)
{
    stdio_init_all();

    cout << "Hello, from green-pi!" << endl;

    if (cyw43_arch_init())
    {
        while (true)
        {
            cout << "Initialization Failed!" << endl;
            sleep_ms(500);
        }
    }

    while (true)
    {
        cout << "Blink!" << endl;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }
}
