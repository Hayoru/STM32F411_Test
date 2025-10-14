#include "stm32f411xe.h"

void Timer2Ini (void)
{
 
	TIM2->CR1 |= 0x0 << TIM_CR1_DIR_Pos;
	TIM2->CR1 |= 0x0 <<TIM_CR1_CMS_Pos;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM2->PSC = 2500;
	TIM2->ARR = 40000;
	TIM2->DIER |= TIM_DIER_UIE;
}