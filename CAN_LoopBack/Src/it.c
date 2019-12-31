/*
 * it.c
 *
 *  Created on: Dec 25, 2019
 *      Author: gvnwa
 */


#include "main.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
