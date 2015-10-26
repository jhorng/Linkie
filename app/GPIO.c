#include "GPIO.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int mode, int pinNum, GPIO *port){
	GPIO_InitTypeDef gpio;

	//__HAL_RCC_GPIOG_CLK_ENABLE();
	//__HAL_RCC_GPIOB_CLK_ENABLE();
	//__HAL_RCC_GPIOC_CLK_ENABLE();

	int *ptrReset = (int *)0x40023810;
	ptrReset[0] = 0xFFFFFFB9;

	int *ptrSet = (int *)0x40023830;
	ptrSet[0] = 0x00100046;

	//gpioUnresetEnableClock(PORTG);
	//gpioUnresetEnableClock(PORTB);
	//gpioUnresetEnableClock(PORTC);

	port->MODER &= ~(3 << (pinNum * 2));
	port->MODER |= mode << (pinNum * 2);
	port->OTYPER &= ~(1 << pinNum);
	port->OSPEED &= ~(3 << (pinNum * 2));
	port->OSPEED |= GPIO_HIGH_SPEED << (pinNum * 2);

	//PORTB->MODER = 0x04000000;
	//PORTB->OTYPER = 0;
	//PORTB->OSPEED = 0x20000000;

	//PORTC->MODER = 0x00000400;
	//PORTC->OTYPER = 0;
	//PORTC->OSPEED = 0x20000000;

	/*
	PORTG->MODER = 0x14000000;
	PORTG->OTYPER = 0;
	PORTG->OSPEED = 0x20000000;

	PORTB->MODER = 0x04000000;
	PORTB->OTYPER = 0;
	PORTB->OSPEED = 0x20000000;

	PORTC->MODER = 0x00000400;
	PORTC->OTYPER = 0;
	PORTC->OSPEED = 0x20000000;
	*/

	//int *ptr = (int *)0x40021800;	//GPIOG
	//ptr[0] = 0x14000000;		// MODE.pin14 = output
	//ptr[1] = 0;					// OTYPE.pin14 = push-pull
	//ptr[2] = 0x20000000;		// OSPEED.pin14 = high speed

	//int *ptrB = (int *)0x40020400;	//GPIOB
	//ptrB[0] = 0x04000000;		// MODE.pin13 = output
	//ptrB[1] = 0;				// OTYPE.pin13 = push-pull
	//ptrB[2] = 0x20000000;		// OSPEED.pin13 = high speed

	//int *ptrC = (int *)0x40020800;	//GPIOC
	//ptrC[0] = 0x00000400;		// MODE.pin5 = output
	//ptrC[1] = 0;				// OTYPE.pin5 = push-pull
	//ptrC[2] = 0x20000000;		// OSPEED.pin5 = high speed

/*
	gpio.Pin = pinNumber;
	gpio.Mode = direction;
	gpio.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(port, &gpio);
*/
}


void writeOne(int pinNum, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
}

void writeZero(int pinNum, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_RESET);
}
