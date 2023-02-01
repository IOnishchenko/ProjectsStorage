#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os.h"

//-----------------------------------------
// Get Tick
//-----------------------------------------
uint32_t HAL_GetTick (void)
{
	static uint32_t ticks = 0U;
	uint32_t i;
	
	if(osKernelRunning())
	{
		return ((uint32_t)osKernelSysTick());
	} 
	/* If Kernel is not running wait approximately 1 ms then increment and return auxiliary tick counter value */
	for(i = (SystemCoreClock >> 14U); i > 0U; i--) 
	{
		__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
		__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
	}
	return ++ticks;
}
