#include "Rcc.h"
#include "GPIO.h"
#include "stm32f4xx_hal_gpio.h"

void gpioUnresetEnableClock(GPIO *port){
	Rcc *rcc;
	int portAddr = (int *)(port);

	switch(portAddr){
	case GPIOG_BASE_ADDRESS:
		rcc->RCC_AHB1RSTR &= ~(1 << GPIOG_bit);
		rcc->RCC_AHB1RSTR |= 1 << GPIOG_bit;
		rcc->RCC_AHB1ENR &= ~(1 << GPIOG_bit);
		rcc->RCC_AHB1ENR |= 1 << GPIOG_bit;
		break;
	case GPIOB_BASE_ADDRESS:
		rcc->RCC_AHB1RSTR &= ~(1 << GPIOB_bit);
		rcc->RCC_AHB1RSTR |= 1 << GPIOB_bit;
		rcc->RCC_AHB1ENR &= ~(1 << GPIOB_bit);
		rcc->RCC_AHB1ENR |= 1 << GPIOB_bit;
		break;
	case GPIOC_BASE_ADDRESS:
		rcc->RCC_AHB1RSTR &= ~(1 << GPIOC_bit);
		rcc->RCC_AHB1RSTR |= 1 << GPIOC_bit;
		rcc->RCC_AHB1ENR &= ~(1 << GPIOC_bit);
		rcc->RCC_AHB1ENR |= 1 << GPIOC_bit;
		break;
	default: break;
	}
}
