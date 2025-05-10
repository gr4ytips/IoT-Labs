/*
 * Custom Module
 * Educational STM32 Challenge-Response Project
 *
 * Initial Author:gr4ytips
 * AI-Assisted Refinement: ChatGPT by OpenAI
 * License: CC BY-NC-SA 4.0
 * Disclaimer: For educational/research use only. No liability assumed.
 */



#include "uart_interface.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart2;

void UART_SendString(const char *str) {
    HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}

void UART_ReadString(char *buffer, uint16_t size) {
    uint16_t i = 0;
    char ch;
    while (i < size - 1) {
        HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
        if (ch == '\r' || ch == '\n') break;
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

void UART_ClearScreen(void) {
    char clear[] = "\033[2J\033[H";  // ANSI escape: clear screen + home cursor
    UART_SendString(clear);
}
