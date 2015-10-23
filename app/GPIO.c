#include "GPIO.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNumber, GPIO_TypeDef *port){
	GPIO_InitTypeDef gpio;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();



	int *ptr = (int *)0x40021800;	//GPIOG
	int *ptrB = (int *)0x40020400;	//GPIOB
	int *ptrC = (int *)0x40020800;	//GPIOC
	ptr[0] = 0x14000000;		// MODE.pin14 = output
	ptr[1] = 0;					// OTYPE.pin14 = push-pull
	ptr[2] = 0x20000000;		// OSPEED.pin14 = high speed

	ptrB[0] = 0x04000000;		// MODE.pin13 = output
	ptrB[1] = 0;					// OTYPE.pin13 = push-pull
	ptrB[2] = 0x20000000;		// OSPEED.pin13 = high speed

	ptrC[0] = 0x00000400;		// MODE.pin5 = output
	ptrC[1] = 0;				// OTYPE.pin5 = push-pull
	ptrC[2] = 0x20000000;		// OSPEED.pin5 = high speed

/*
	gpio.Pin = pinNumber;
	gpio.Mode = direction;
	gpio.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(port, &gpio);
*/
}


void writeOne(int pinNumber, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNumber, GPIO_PIN_SET);
}

void writeZero(int pinNumber, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNumber, GPIO_PIN_RESET);
}
