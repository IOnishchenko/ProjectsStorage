#include "lcd-driver.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configuration.h"
#include "picture_types.h"
#include "test_pic.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define BUFFER_COUNT (VSPI_QUEUE_SIZE + 1)
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void gui_thread(void * args)
{
	printf("gui_thread started!!!\n");
	st7789.initialize();
	printf("lcd_initialize done !!!\n");

	// draw picture
	uint16_t * palet_cache = (uint16_t *)malloc(test_pic.palettes->count * 2);
	uint16_t * gdata[BUFFER_COUNT];
	for(int i = 0; i < BUFFER_COUNT; i++)
	{
		gdata[i] = (uint16_t *)malloc(VSPI_MAX_BUFFER_SIZE);
	}

	// calculate palet
	for(int i = 0; i < test_pic.palettes->count; i++)
	{
		uint32_t color = test_pic.palettes->colors[i];
		uint16_t r = (color >> 8) & 0xf800;
		uint16_t g = (color >> 5) & 0x07e0;
		uint16_t b = (color >> 3) & 0x001f;
		palet_cache[i] = ~(r | g | b);
	}

	uint32_t full_size = LCD_VERTICAL_SIZE * LCD_HORIZONTAL_SIZE; // in pixel;
	uint32_t buff_index = 0;
	uint8_t * l8_data = (uint8_t*)test_pic.items[0]->data;

	st7789.set_region(0, 0, LCD_HORIZONTAL_SIZE, LCD_VERTICAL_SIZE);
	st7789.start_writing_gdata();
	while(full_size)
	{
		uint16_t * buffer = gdata[buff_index];
		uint32_t size;
		for(size = 0; (size < (VSPI_MAX_BUFFER_SIZE/2)) && full_size; size++)
		{
			*buffer++ = palet_cache[*l8_data++];
			full_size--;
		}

		st7789.write_gdata((uint8_t*)gdata[buff_index], size*2);

		buff_index++;
		if(buff_index == BUFFER_COUNT)
			buff_index = 0;
	}

	st7789.wait_and_delay(0);
	free(palet_cache);
	for(int i = 0; i < BUFFER_COUNT; i++)
	{
		free(gdata[i]);
	}

	for(;;)
	{
		vTaskDelay(500);
	}
}