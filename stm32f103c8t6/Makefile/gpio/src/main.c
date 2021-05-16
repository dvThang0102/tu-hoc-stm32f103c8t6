
#include "hw_stm32f103c8t6.h"


void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}
/*********************************/
void enable_clk()
{
	unsigned int tempreg;
	tempreg = read_reg(GPIO_RCC_APH2ENR, ~(1u<<4));
	tempreg = tempreg|(1u<<4);
	// set mode for LED PC13
	write_reg(GPIO_RCC_APH2ENR, tempreg);
	
}
void gpio_init()
{
	unsigned int tempreg;
	tempreg = read_reg(GPIO_CONF_HIGH, ~(0x00u<<22));
	tempreg = tempreg|(0x00u<<22);
	// set mode for LED PC13
	write_reg(GPIO_CONF_HIGH, tempreg);
	
	tempreg = read_reg(GPIO_CONF_HIGH, ~(0x01u<<20));
	tempreg = tempreg|(0x01u<<20);

    write_reg(GPIO_CONF_HIGH, tempreg);	
}

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          __asm(" nop");
        }
    }
}
void led_on(unsigned char pin)
{
	write_reg(GPIO_ODR, 1u<<(pin));
}
void led_off(unsigned char pin)
{
	write_reg(GPIO_ODR, ~(1u<<pin));
}
int main(void)
{
  /* int clock */
  enable_clk();
  /* init red led */
  gpio_init();
  while(1)
  {
    led_on(13);
    delay(0xff);
    led_off(13);
    delay(0xff);
  }
	return 0;
}
void SystemInit(void)
{
}


