/*
 * main.c
 *
 *  Created on: Dec 16, 2019
 *      Author: gvnwa
 */

#include <string.h>
#include "stm32f4xx_hal.h"
#include "main.h"

#define TRUE  1
#define FALSE 0

void Error_handler(void);
void SystemClock_Config(void);

int main(void)
{
	HAL_Init(); // processor specific
	SystemClock_Config();

	while(1);

	return 0;
}

void SystemClock_Config(void)
{

}

void Error_handler(void)
{
	//block
	while(1);
}



