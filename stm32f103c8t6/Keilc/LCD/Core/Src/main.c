/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define E_SET() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1, GPIO_PIN_SET) 
#define RS_SET() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11, GPIO_PIN_SET) 
#define RW_SET() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10, GPIO_PIN_SET) 

#define E_RESET() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1, GPIO_PIN_RESET) 
#define RS_RESET() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11, GPIO_PIN_RESET) 
#define RW_RESET() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10, GPIO_PIN_RESET) 

#define D0_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_SET) 
#define D1_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_SET) 
#define D2_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_SET) 
#define D3_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_SET) 
#define D4_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_SET) 
#define D5_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, GPIO_PIN_SET)
#define D6_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2, GPIO_PIN_SET) 
#define D7_SET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_SET) 

#define D0_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET) 
#define D1_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_RESET) 
#define D2_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_RESET) 
#define D3_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_RESET) 
#define D4_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_RESET) 
#define D5_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, GPIO_PIN_RESET)
#define D6_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2, GPIO_PIN_RESET) 
#define D7_RESET() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_RESET) 
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void LCD_Init(void);
void LCD_cmd(uint8_t cmd);
void LCD_char_CP( uint8_t Data);
void LCD_char_c(uint8_t row, uint8_t col,uint8_t c);
void LCD_char(uint8_t *str);
void LCD_char_str(uint8_t row, uint8_t col, uint8_t *str);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
  /* USER CODE END 2 */
		LCD_char_CP('t');
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pins : D0_Pin D1_Pin D2_Pin D3_Pin
                           D4_Pin D5_Pin D6_Pin PA8 */
  GPIO_InitStruct.Pin = D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void LCD_cmd(uint8_t cmd)
{
	RS_RESET();
	if (((cmd >> 0) & 0x01) == 1) { D0_SET(); } else { D0_RESET(); }
  if (((cmd >> 1) & 0x01) == 1) { D1_SET(); } else { D1_RESET(); }
  if (((cmd >> 2) & 0x01) == 1) { D2_SET(); } else { D2_RESET(); }
  if (((cmd >> 3) & 0x01) == 1) { D3_SET(); } else { D3_RESET(); }
  if (((cmd >> 4) & 0x01) == 1) { D4_SET(); } else { D4_RESET(); }
  if (((cmd >> 5) & 0x01) == 1) { D5_SET(); } else { D5_RESET(); }
  if (((cmd >> 6) & 0x01) == 1) { D6_SET(); } else { D6_RESET(); }
	if (((cmd >> 7) & 0x01) == 1) { D7_SET(); } else { D7_RESET(); }
	E_SET();
	E_RESET();
	if(cmd<=0x02)
		HAL_Delay(2);
	else
		HAL_Delay(1);

}
void LCD_Init()
{
	LCD_cmd(0x30);
	HAL_Delay(5);
	LCD_cmd(0x30);
	HAL_Delay(1);
	LCD_cmd(0x30);

	LCD_cmd(0x38);	 // chon so dong hien thi , font hien thi
	LCD_cmd(0x01);	  // xoa noi dung hien thi
	LCD_cmd(0x0C); 	  // bat hien thi va tat con tro
}
void LCD_char_CP( uint8_t Data)
{
	RS_SET();
	if (((Data >> 0) & 0x01) == 1) { D0_SET(); } else { D0_RESET(); }
  if (((Data >> 1) & 0x01) == 1) { D1_SET(); } else { D1_RESET(); }
  if (((Data >> 2) & 0x01) == 1) { D2_SET(); } else { D2_RESET(); }
  if (((Data >> 3) & 0x01) == 1) { D3_SET(); } else { D3_RESET(); }
  if (((Data >> 4) & 0x01) == 1) { D4_SET(); } else { D4_RESET(); }
  if (((Data >> 5) & 0x01) == 1) { D5_SET(); } else { D5_RESET(); }
  if (((Data >> 6) & 0x01) == 1) { D6_SET(); } else { D6_RESET(); }
	if (((Data >> 7) & 0x01) == 1) { D7_SET(); } else { D7_RESET(); }
	E_RESET();
	E_SET();
	HAL_Delay(1);
}
void LCD_char_c(uint8_t row, uint8_t col,uint8_t c)
{
	uint8_t cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	LCD_cmd(cmd);

	LCD_char_CP(c);
}

void LCD_char(uint8_t *str)
{
	uint8_t i = 0;
	while(str[i]!= 0)
	{
		LCD_char_CP(str[i]);
		i++;
	}
}
void LCD_char_str(uint8_t row, uint8_t col, uint8_t *str)
{
	uint8_t cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	LCD_cmd(cmd);

	LCD_char(str);
}



/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
