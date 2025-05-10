
#include "led_control.h"

void Blink_LED(uint32_t times) {
    for (uint32_t i = 0; i < times; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(200);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(200);
    }
}
