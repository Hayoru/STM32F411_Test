#include "stm32f411xe.h"

void HSE_CheckSave()
{
	 while ( !(RCC->CR & RCC_CR_HSERDY) && !(RCC->CR & RCC_CR_PLLRDY))
	 {
	 
	 }
	 
	 return;
}