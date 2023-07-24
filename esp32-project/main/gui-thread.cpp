#include "lcd-driver.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void gui_thread(void * args)
{
	printf("gui_thread started!!!\n");
	lcd_initialize();
	printf("lcd_initialize done !!!\n");

	for(;;)
	{
		vTaskDelay(500);
	}
}