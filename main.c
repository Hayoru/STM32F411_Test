#include "stm32f411xe.h"
#include "ClockIni.h"
#include "TinerIni.h"
#include "PeripheralClocking.h"
#include "GPIOIni.h"

void TIM2_IRQHandler (void)
{ 
	NVIC_ClearPendingIRQ(TIM2_IRQn);
	TIM2->SR =0;
	GPIOA->ODR ^= 0x1 << GPIO_ODR_OD5_Pos;

}

 int main ()
{  
	NVIC_EnableIRQ(TIM2_IRQn);
  ClockIni();
	PeripheralClocking();
  Timer2Ini();
  GPIOPortAIni();
		
		
	
	while (1)
	{__NOP();}
	
	
	return 0;
}