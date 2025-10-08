#include "stm32f411xe.h"
#include "SaveClock.h"
#define _EXTERNAL_XTAL_8MHz_ 
//#define EXTERNAL_XTAL_16MHz
	void PLLIni(void); 
	
	void ClockIni (void)
	{

		RCC->CR |= RCC_CR_HSEON;
		PLLIni();
		RCC->CR |= RCC_CR_PLLON;
		HSE_Insurance();
		
		
	
		
		RCC->CFGR |= 0x0 << RCC_CFGR_HPRE_Pos;
    RCC->CFGR |= 0x4 << RCC_CFGR_PPRE1_Pos;
		
		RCC->CFGR |= 0x2 << RCC_CFGR_SW_Pos;
		
		
		
		return;
	}
	
	void PLLIni (void)
	{
	 
	
	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	 
	 #ifdef _EXTERNAL_XTAL_8MHz_	 
		RCC->PLLCFGR |= 0x8 << RCC_PLLCFGR_PLLM_Pos;
		RCC->PLLCFGR |= 0xc8 << RCC_PLLCFGR_PLLN_Pos;
		RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
		RCC->PLLCFGR |= 0x1 << RCC_PLLCFGR_PLLSRC_Pos;
	 #endif
		
		#ifdef EXTERNAL_XTAL_16MHz
		RCC->PLLCFGR |= 0x16 << RCC_PLLCFGR_PLLM_Pos;
		RCC->PLLCFGR |= 0xc8 << RCC_PLLCFGR_PLLN_Pos;
		RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
		#endif
		
		
	 return;
	}