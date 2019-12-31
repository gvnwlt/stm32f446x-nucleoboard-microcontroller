/*
 * msp.c
 *
 *  Created on: Dec 16, 2019
 *      Author: gvnwa
 */
#include "main.h"



void HAL_MspInit(void)
{
	//Here we will do low level processor specific inits
	//1. set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; //usg fault, memory fault and bus fault system exceptions

	//3. configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer)
{
	//1. enable the clock for the timer 6 peripheral
	__HAL_RCC_TIM6_CLK_ENABLE();

	//2. enable the IRQ of TIM6
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//3. set the priority for TIM6_DAC_IRQn
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn,15,0);
}

