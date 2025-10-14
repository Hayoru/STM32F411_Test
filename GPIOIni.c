#include "stm32f411xe.h"
#include "GPIOIni.h"

void GPIOPortAIni (void)
{ 
	GPIOA->MODER |= 0x1 << GPIO_MODER_MODE5_Pos;
	GPIOA->OTYPER |= 0x0 << GPIO_OTYPER_OT5_Pos;
	GPIOA->OSPEEDR |= 0x1 << GPIO_OSPEEDR_OSPEED5_Pos;
	GPIOA->ODR |= 0x1 << GPIO_ODR_OD5_Pos;
}