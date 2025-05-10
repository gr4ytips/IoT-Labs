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

#ifndef INC_UART_INTERFACE_H_
#define INC_UART_INTERFACE_H_

#include "stm32f4xx_hal.h"

void UART_SendString(const char *str);
void UART_ReadString(char *buffer, uint16_t size);
void UART_ClearScreen(void);

#endif /* INC_UART_INTERFACE_H_ */
