#include "stm32f411xe.h"
#include "ClockIni.h"
#include "TinerIni.h"
#include "PeripheralClocking.h"

int main ()
{
  ClockIni();
	PeripheralClocking();
  Timer2Ini();

	
	while (1)
	{
	
	}
		return 0;
}