#include "stm32f411xe.h"

void HSE_Insurance()
{
	 while ( !(RCC->CR & RCC_CR_HSERDY) && !(RCC->CR & RCC_CR_PLLRDY))
	 {
	 
	 }
	 
	 return;
}