#ifndef __GPIO_H__
#define __GPIO_H__

#include "stm32f4xx_hal_gpio.h"

#define GPIO_OUTPUT		GPIO_MODE_OUTPUT_PP
#define GPIO_INPUT		GPIO_MODE_INPUT_PP

void configurePin(int direction, int pinNumber, GPIO_TypeDef *port);
void writeOne(int pinNumber, GPIO_TypeDef *port);
void writeZero(int pinNumber, GPIO_TypeDef *port);

#endif // __GPIO_H__
