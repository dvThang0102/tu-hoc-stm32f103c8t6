#include "stm32f10x.h"                  // Device header
#include"GPIO_DIY.h"


void config_GPIOc(void)
{
	RCC->APB2ENR |=(1<<4);
	GPIOC->CRH |= ((1<<20)|(1<<21));
	GPIOC->CRH &= ~((1<<22)|(1<<23));
}
