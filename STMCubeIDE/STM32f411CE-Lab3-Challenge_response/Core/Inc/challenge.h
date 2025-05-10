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

#ifndef CHALLENGE_H
#define CHALLENGE_H

#include "stm32f4xx_hal.h"

uint32_t GenerateChallenge(void);
uint8_t ValidateResponse(uint32_t challenge, uint32_t response);

#endif // CHALLENGE_H


