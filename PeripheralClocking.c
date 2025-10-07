#include "stm32f411xe.h"

void PeripheralClocking (void)
{
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

}