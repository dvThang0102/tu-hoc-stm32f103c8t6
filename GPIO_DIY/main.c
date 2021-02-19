#include "stm32f10x.h"                  // Device header
#include"GPIO_DIY.h"

void Delay_ms(uint32_t ms);
void config_GPIOc(void);
int main()
{
	config_GPIOc();
	while(1)
	{
		//GPIOC->BSRR = (1<<13);
		GPIOC->ODR |=(1<<13);
		Delay_ms(1000);
		//GPIOC->BSRR = (1<<29);
		GPIOC->ODR &= ~(1<<13);
		Delay_ms(1000);
		
	}
}
//void config_GPIOc(void)
//{
//	RCC->APB2ENR |=(1<<4);
//	GPIOC->CRH |= ((1<<20)|(1<<21));
//	GPIOC->CRH &= ~((1<<22)|(1<<23));
//}
void Delay_ms(uint32_t ms)
{
	uint32_t i,j;
	for(uint32_t i = 0;i < ms;i++)
	 for(volatile uint32_t j = 0; j < 525; j++);
}