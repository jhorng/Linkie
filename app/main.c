#include "stm32f4xx.h"
#include "GPIO.h"
#include "RCC.h"

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
	configurePin(GPIO_MODE_INPUT, PIN_0, PORTA);
	pullUpDown(PIN_0, PORTA, GPIO_PULL_DOWN);

	while(1){
		if((PORTA->IDR & 1) == 1){
			writeOne(PIN_13, PORTG);
			writeOne(PIN_14, PORTG);
			writeOne(PIN_13, PORTB);
			writeOne(PIN_5, PORTC);
			delay(500000);
			writeZero(PIN_13, PORTG);
			writeZero(PIN_14, PORTG);
			writeZero(PIN_13, PORTB);
			writeZero(PIN_5, PORTC);
			delay(500000);
		}
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
