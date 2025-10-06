#include "stm32f411xe.h"
#include "SaveClock.h"

	void PLLIni(void); 
	
	void ClockIni ()
	{
		RCC->CR = 0;
		RCC->CR |= RCC_CR_HSEON + RCC_CR_PLLON;
		HSE_CheckSave();
		
	
		RCC->CFGR |= RCC_CFGR_SWS_PLL;
		RCC->CFGR |= RCC_CFGR_HPRE_0;
		
		
		
		return;
	}
	
	void PLLIni ()
	{
	 
	 RCC->PLLCFGR = 0;
	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	 RCC->PLLCFGR |= 0x8 << RCC_PLLCFGR_PLLM_Pos;
	 RCC->PLLCFGR |= 0x160 << RCC_PLLCFGR_PLLN_Pos;
	 RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
	 return;
	}