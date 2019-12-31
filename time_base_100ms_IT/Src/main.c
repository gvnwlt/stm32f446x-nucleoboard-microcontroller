/*
 * main.c
 *
 *  Created on: Dec 16, 2019
 *      Author: gvnwa
 */

#include "stm32f4xx_hal.h"
#include "main.h"

#define TRUE  1
#define FALSE 0

void SystemClock_Config(void);
void Error_handler(void);
void GPIO_Init(void);
void TIMER6_Init(void);

TIM_HandleTypeDef htimer6;

int main(void)
{
	HAL_Init(); // processor specific
	SystemClock_Config();
	GPIO_Init();
	TIMER6_Init();

	//lets start timer
	HAL_TIM_Base_Start_IT(&htimer6);

	while(1);

	return 0;
}

void SystemClock_Config(void)
{

}

void GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&ledgpio);
}

void TIMER6_Init(void)
{
	htimer6.Instance = TIM6;
	htimer6.Init.Prescaler = 24;
	htimer6.Init.Period = 64000-1; //calculated value between counts
	if (HAL_TIM_Base_Init(&htimer6) != HAL_OK)
	{
		Error_handler();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

void Error_handler(void)
{
	//block
	while(1);
}



