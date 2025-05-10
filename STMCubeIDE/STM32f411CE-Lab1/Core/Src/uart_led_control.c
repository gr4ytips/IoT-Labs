#include "uart_led_control.h"
#include <string.h>
#include <ctype.h>

void UART_TransmitString(UART_HandleTypeDef *huart, char *str)
{
    HAL_UART_Transmit(huart, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}

void UART_ReceiveLine(UART_HandleTypeDef *huart, char *buffer, uint16_t max_length)
{
    uint8_t ch;
    uint16_t idx = 0;

    while (idx < (max_length - 1))
    {
        if (HAL_UART_Receive(huart, &ch, 1, HAL_MAX_DELAY) == HAL_OK)
        {
            if (ch == '\r')
                break;
            else if (ch == 0x7F || ch == 0x08)
            {
                if (idx > 0)
                {
                    idx--;
                    UART_TransmitString(huart, "\b \b");
                }
            }
            else if (ch >= 32 && ch <= 126)
            {
                buffer[idx++] = ch;
                HAL_UART_Transmit(huart, &ch, 1, HAL_MAX_DELAY);
            }
        }
    }

    buffer[idx] = '\0';
    UART_TransmitString(huart, "\r\n");
}

int validate_answer_n_case_sensitive(const char *input, const char *target)
{
    return strncmp(input, target, strlen(target));
}

int validate_answer_n_case_insensitive(const char *input, const char *target)
{
    while (*input && *target)
    {
        if (tolower((unsigned char)*input) != tolower((unsigned char)*target))
            return 1;
        input++;
        target++;
    }
    return (*target == '\0') ? 0 : 1;
}

void UART_ClearScreen(UART_HandleTypeDef *huart)
{
    UART_TransmitString(huart, "[2J");
}

void UART_SetCursorHome(UART_HandleTypeDef *huart)
{
    UART_TransmitString(huart, "[H");
}
