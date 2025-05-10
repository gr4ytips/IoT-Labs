
#ifndef __UART_UTILS_H
#define __UART_UTILS_H

#include "stm32f4xx_hal.h"

void UART_TransmitString(char *str);
void UART_ReceiveLine(char *buffer, uint16_t max_length);

#endif
