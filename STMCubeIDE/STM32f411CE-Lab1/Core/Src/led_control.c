#include "led_control.h"

void LED_StartBlinking(LedBlinkController *controller, GPIO_TypeDef* port, uint16_t pin, uint32_t times)
{
    controller->GPIO_Port = port;
    controller->GPIO_Pin = pin;
    controller->target_blinks = times * 2;
    controller->current_blinks = 0;
    controller->last_toggle_tick = HAL_GetTick();
    controller->is_active = 1;
}

void LED_Update(LedBlinkController *controller)
{
    if (!controller->is_active) return;

    if ((HAL_GetTick() - controller->last_toggle_tick) >= 200)
    {
        HAL_GPIO_TogglePin(controller->GPIO_Port, controller->GPIO_Pin);
        controller->last_toggle_tick = HAL_GetTick();
        controller->current_blinks++;

        if (controller->current_blinks >= controller->target_blinks)
        {
            controller->is_active = 0;
            HAL_GPIO_WritePin(controller->GPIO_Port, controller->GPIO_Pin, GPIO_PIN_RESET);
        }
    }
}