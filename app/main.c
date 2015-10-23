#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "GPIO.h"

void delay(uint32_t delayCount){
	while(delayCount != 0){
		delayCount--;
	}
}

int main(void)
{
	configurePin(GPIO_MODE_OUTPUT, PIN_13, PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_14, PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_13, PORTB);
	configurePin(GPIO_MODE_OUTPUT, PIN_5, PORTC);

	while(1){
		writeOne(GPIO_PIN_13, GPIOG);
		writeOne(GPIO_PIN_14, GPIOG);
		writeOne(GPIO_PIN_13, GPIOB);
		writeOne(GPIO_PIN_5, GPIOC);
		delay(500000);
		writeZero(GPIO_PIN_13, GPIOG);
		writeZero(GPIO_PIN_14, GPIOG);
		writeZero(GPIO_PIN_13, GPIOB);
		writeZero(GPIO_PIN_5, GPIOC);
		delay(500000);
	}



/*	int a = 4;
	double d = 5.6789123;

	d = d * a + 1.987656321;

	configurePort(GPIOG, GPIO_PIN_13);

	while(1)
    {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
    }*/
}
