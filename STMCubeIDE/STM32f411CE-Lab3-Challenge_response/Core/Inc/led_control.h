/*
 * Custom Module
 * Educational STM32 Challenge-Response Project
 *
 * Initial Author:gr4ytips
 * AI-Assisted Refinement: ChatGPT by OpenAI
 * License: CC BY-NC-SA 4.0
 * Disclaimer: For educational/research use only. No liability assumed.
 */

/*
 * uart_interface.h
 *
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "stm32f4xx_hal.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    uint8_t count;
    uint32_t interval;
    uint32_t last_toggle;
    uint8_t is_active;
} LedBlinkController;

void LED_StartBlinking(LedBlinkController *controller, GPIO_TypeDef *port, uint16_t pin, uint8_t count);
void LED_Update(LedBlinkController *controller);






#endif /* INC_LED_CONTROL_H_ */
