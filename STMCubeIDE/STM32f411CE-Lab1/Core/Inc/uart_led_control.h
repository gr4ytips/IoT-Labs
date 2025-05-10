#ifndef INC_UART_LED_CONTROL_H_
#define INC_UART_LED_CONTROL_H_

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart2;
extern char uart_rx_buffer[100];
extern uint32_t success_count;
extern uint32_t failure_count;

void UART_TransmitString(UART_HandleTypeDef *huart, char *str);
void UART_ReceiveLine(UART_HandleTypeDef *huart, char *buffer, uint16_t max_length);
int validate_answer_n_case_sensitive(const char *input, const char *target);
int validate_answer_n_case_insensitive(const char *input, const char *target);
void UART_ClearScreen(UART_HandleTypeDef *huart);
void UART_SetCursorHome(UART_HandleTypeDef *huart);

#endif /* INC_UART_LED_CONTROL_H_ */