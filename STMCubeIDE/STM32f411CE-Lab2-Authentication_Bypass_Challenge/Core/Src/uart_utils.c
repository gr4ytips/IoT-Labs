
#include "uart_utils.h"
#include <string.h>

extern UART_HandleTypeDef huart2;

void UART_TransmitString(char *str) {
    HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}

void UART_ReceiveLine(char *buffer, uint16_t max_length) {
    uint8_t ch;
    uint16_t idx = 0;

    while (idx < (max_length - 1)) {
        if (HAL_UART_Receive(&huart2, &ch, 1, HAL_MAX_DELAY) == HAL_OK) {
            if (ch == '\r' || ch == '\n') break;
            if (ch == 0x7F || ch == 0x08) {
                if (idx > 0) {
                    idx--;
                    UART_TransmitString("\b \b");
                }
            } else if (ch >= 32 && ch <= 126) {
                buffer[idx++] = ch;
                HAL_UART_Transmit(&huart2, &ch, 1, HAL_MAX_DELAY);
            }
        }
    }
    buffer[idx] = '\0';
    UART_TransmitString("\r\n");
}
