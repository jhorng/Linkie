#ifndef __RCC_H__
#define __RCC_H__

#include <stdint.h>
#include "GPIO.h"

typedef struct Rcc_t Rcc;
struct Rcc_t{
	volatile uint32_t RCC_CR;			// RCC clock control register (0x00)
	volatile uint32_t RCC_PLLCFGR;		// RCC PLL configuration register (0x04)
	volatile uint32_t RCC_CFGR;			// RCC clock configuration register (0x08)
	volatile uint32_t RCC_CIR;			// RCC clock interrupt register	(0x0C)
	volatile uint32_t RCC_AHB1RSTR;		// RCC AHB1 peripheral reset register (0x10)
	volatile uint32_t RCC_AHB2RSTR;		// RCC AHB2 peripheral reset register
	volatile uint32_t RCC_AHB3RSTR;		// RCC AHB3 peripheral reset register
	volatile uint32_t reserved_0;
	volatile uint32_t RCC_APB1RSTR;		// RCC APB1 peripheral reset register
	volatile uint32_t RCC_APB2RSTR;		// RCC APB2 peripheral reset register
	volatile uint32_t reserved_1;
	volatile uint32_t reserved_2;
	volatile uint32_t RCC_AHB1ENR;		// RCC AHB1 peripheral clock enable register
	volatile uint32_t RCC_AHB2ENR;		// RCC AHB2 peripheral clock enable register
	volatile uint32_t RCC_AHB3ENR;		// RCC AHB3 peripheral clock enable register
	volatile uint32_t reserved_3;
	volatile uint32_t RCC_APB1ENR;		// RCC APB1 peripheral clock enable register
	volatile uint32_t RCC_APB2ENR;		// RCC APB2 peripheral clock enable register
	volatile uint32_t reserved_4;
	volatile uint32_t reserved_5;
	volatile uint32_t RCC_AHB1LPENR;	// RCC AHB1 peripheral clock enable in low power mode register
	volatile uint32_t RCC_AHB2LPENR;	// RCC AHB2 peripheral clock enable in low power mode register
	volatile uint32_t RCC_AHB3LPENR;	// RCC AHB3 peripheral clock enable in low power mode register
	volatile uint32_t reserved_6;
	volatile uint32_t RCC_APB1LPENR;	// RCC APB1 peripheral clock enable in low power mode register
	volatile uint32_t RCC_APB2LPENR;	// RCC APB2 peripheral clock enable in low power mode register
	volatile uint32_t reserved_7;
	volatile uint32_t reserved_8;
	volatile uint32_t RCC_BDCR;			// RCC Backup domain control register
	volatile uint32_t RCC_CSR;			// RCC clock control & status register
	volatile uint32_t reserved_9;
	volatile uint32_t reserved_A;
	volatile uint32_t RCC_SSCGR;		// RCC spread spectrum clock generation register
	volatile uint32_t RCC_PLLI2SCFGR;	// RCC PLLI2S configuration register
};

#define GPIOA_bit	0
#define	GPIOB_bit	1
#define GPIOC_bit	2
#define GPIOD_bit	3
#define GPIOE_bit	4
#define GPIOF_bit	5
#define GPIOG_bit	6
#define GPIOH_bit	7
#define GPIOI_bit	8
#define GPIOJ_bit	9
#define GPIOK_bit	10

#define Rcc_reg	((Rcc*)0x40023800)

void gpioUnresetEnableClock(GPIO *port);

#endif // __RCC_H__
