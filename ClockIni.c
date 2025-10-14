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
	 
	
	 
	 #ifdef _EXTERNAL_XTAL_8MHz_	 
		
		RCC->PLLCFGR =0;
		RCC->PLLCFGR |= 0x8 << RCC_PLLCFGR_PLLM_Pos;
		RCC->PLLCFGR |= 0xc8 << RCC_PLLCFGR_PLLN_Pos;
		RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
		
		FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_3WS;
		
	  RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	 #endif
		
		#ifdef EXTERNAL_XTAL_16MHz
		
		RCC->PLLCFGR = 0;
		RCC->PLLCFGR |= 0x16 << RCC_PLLCFGR_PLLM_Pos;
		RCC->PLLCFGR |= 0xc8 << RCC_PLLCFGR_PLLN_Pos;
		RCC->PLLCFGR |= 0x0 << RCC_PLLCFGR_PLLP_Pos;
		
		FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_3WS;
		
	  RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
		#endif
		
		
	 return;
	}
