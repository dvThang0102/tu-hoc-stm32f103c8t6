/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Anh Vo Tuan <votuananhs@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/*
 * MCU:     STM32F103C8T6
 */

#ifndef __HW_STM32F103C8T6_H__
#define __HW_STM32F103C8T6_H__

#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)


/**LED PC13**/
#define LED 13

#define BASE_ADD_GPIOC   0x40011000 
#define BASE_ADD_RCC     0x40021000
#define GPIO_CONF_LOW       (BASE_ADD_GPIOC + 0x00u)
#define GPIO_CONF_HIGH      (BASE_ADD_GPIOC + 0x04u)
#define GPIO_ODR            (BASE_ADD_GPIOC + 0x0Cu)
#define RCC_APB2ENR       (BASE_ADD_RCC + 0x18u)


/* end file */
#endif /* __HW_STM32F103C8T6__ */

