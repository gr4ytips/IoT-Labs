#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "stm32f4xx_hal.h"

typedef struct {
    GPIO_TypeDef* GPIO_Port;
    uint16_t GPIO_Pin;
    uint32_t target_blinks;
    uint32_t current_blinks;
    uint32_t last_toggle_tick;
    uint8_t is_active;
} LedBlinkController;

void LED_StartBlinking(LedBlinkController *controller, GPIO_TypeDef* port, uint16_t pin, uint32_t times);
void LED_Update(LedBlinkController *controller);

#endif /* INC_LED_CONTROL_H_ */