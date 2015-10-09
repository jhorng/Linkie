#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"


void configurePort(GPIO_TypeDef *port, uint32_t pinNumber) {
	GPIO_InitTypeDef gpio;
	gpio.Pin = pinNumber;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(port, &gpio);
}

int main(void)
{
	int a = 4;
	double d = 5.678912;

	d = d * a + 1.987654321;

	configurePort(GPIOG, GPIO_PIN_13);


    while(1)
    {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
    }
}
