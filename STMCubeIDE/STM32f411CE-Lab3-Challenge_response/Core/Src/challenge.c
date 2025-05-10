/*
 * Custom Module
 * Educational STM32 Challenge-Response Project
 *
 * Initial Author:gr4ytips
 * AI-Assisted Refinement: ChatGPT by OpenAI
 * License: CC BY-NC-SA 4.0
 * Disclaimer: For educational/research use only. No liability assumed.
 */

#include "challenge.h"
#include <stdlib.h>
#include <time.h>

#define CHALLENGE_CONSTANT 3

uint32_t GenerateChallenge(void) {
    srand(HAL_GetTick());  // Seed with current tick
    return (rand() % 100) + 1;  // Random number between 1–100
}

uint8_t ValidateResponse(uint32_t challenge, uint32_t response) {
    return (response == challenge * CHALLENGE_CONSTANT);
}
