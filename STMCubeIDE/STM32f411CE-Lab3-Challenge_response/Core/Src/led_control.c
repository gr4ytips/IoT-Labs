/*
 * Custom Module
 * Educational STM32 Challenge-Response Project
 *
 * Initial Author:gr4ytips
 * AI-Assisted Refinement: ChatGPT by OpenAI
 * License: CC BY-NC-SA 4.0
 * Disclaimer: For educational/research use only. No liability assumed.
 */

#include "led_control.h"

void LED_StartBlinking(LedBlinkController *controller, GPIO_TypeDef *port, uint16_t pin, uint8_t count) {
    controller->port = port;
    controller->pin = pin;
    controller->count = count * 2;  // ON and OFF cycles
    controller->interval = 200;  // 200 ms
    controller->last_toggle = HAL_GetTick();
    controller->is_active = 1;
}

void LED_Update(LedBlinkController *controller) {
    if (!controller->is_active) return;

    uint32_t now = HAL_GetTick();
    if (now - controller->last_toggle >= controller->interval) {
        HAL_GPIO_TogglePin(controller->port, controller->pin);
        controller->last_toggle = now;
        controller->count--;

        if (controller->count == 0) {
            controller->is_active = 0;
            HAL_GPIO_WritePin(controller->port, controller->pin, GPIO_PIN_RESET);
        }
    }
}
