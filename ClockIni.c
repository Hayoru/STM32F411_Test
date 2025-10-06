#include "stm32f411xe.h"
#include "SaveClock.h"

	void PLLIni(void); 
	
	void ClockIni ()
	{
		
		RCC->CR |= RCC_CR_HSEON + RCC_CR_PLLON;
		HSE_CheckSave();
		
	
		return;
	}
	
	void PLLIni ()
	{
	 
	 RCC->PLLCFGR |= RCC_PLL
	 
	 return;
	}