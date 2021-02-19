#include "stm32f10x.h"                  // Device header



void Delay_ms(uint32_t ms);
void GPIO_conf(void);
int main(void)
{
	GPIO_conf();
	while(1)
	{
	GPIOC->BSRR =(1<<13);
	Delay_ms(1000);
	GPIOC->BSRR = (1<<13+16);
	Delay_ms(1000);
	}
}
void GPIO_conf(void)
{
	// enabling GPIOc
	RCC->APB2ENR |= (1<<4);
	//reset pin 13C
	GPIOC->CRH |= ((1<<20)|(1<<21));//output 50Mhz
	GPIOC->CRH |= ((1<<22)|(1<<23));//General pupose output
	// Output mode
	//GPIOC->CRH |=0x00300000;
	
}

void Delay_ms(uint32_t ms)
{
	for(uint32_t i = 0;i<ms; i++)
		for(volatile uint32_t j = 0; j<525; j++);
}
