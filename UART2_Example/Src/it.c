/*
 * it.c
 *
 *  Created on: Dec 16, 2019
 *      Author: gvnwa
 */


void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
