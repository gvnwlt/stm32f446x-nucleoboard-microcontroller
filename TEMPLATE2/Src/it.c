/*
 * it.c
 *
 *  Created on: Dec 16, 2019
 *      Author: gvnwa
 */

#include "main.h"

extern TIM_HandleTypeDef htimer2;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
