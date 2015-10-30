#include "RCC.h"
#include "GPIO.h"

void gpioUnresetEnableClock(GPIO* port){
	int valShift = ((int)port - (0x40020000))/(0x400);
	Rcc_reg->RCC_AHB1RSTR &= ~(1 << (valShift));
	Rcc_reg->RCC_AHB1ENR |= (0x00100000 | ~(0 << (valShift)));
}
