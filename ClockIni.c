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
		
		
	
		RCC->CFGR |= RCC_CFGR_SWS_PLL;
		RCC->CFGR |= RCC_CFGR_HPRE_0;
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
		
		
		
		return;
	}
	
	void PLLIni (void)
	{
	 
	 RCC->PLLCFGR = 0;
	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	 
	 #ifdef _EXTERNAL_XTAL_8MHz_	 
		RCC->PLLCFGR |= 0x8 << RCC_PLLCFGR_PLLM_Pos;
		RCC->PLLCFGR |= 0xc8 << RCC_PLLCFGR_PLLN_Pos;
		RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
	 #endif
		
		#ifdef EXTERNAL_XTAL_16MHz
		RCC->PLLCFGR |= 0x16 << RCC_PLLCFGR_PLLM_Pos;
		RCC->PLLCFGR |= 0xc8 << RCC_PLLCFGR_PLLN_Pos;
		RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
		#endif
		
		
	 return;
	}