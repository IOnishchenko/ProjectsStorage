#include "configuration.h"
#include "lcd-driver.h"
#include "IUIContext.hpp"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#include "sdr_dumy_picture.h"
#define BUFFER_COUNT (VSPI_QUEUE_SIZE + 1)

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C"
{
	void sh1106_vertical_scroll(uint8_t value);
}
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
gui::IUIContext ColorScreen;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void gui_thread(void * args)
{
	printf("gui_thread started\n");

	st7789.initialize();
	sh1106.initialize();

	uint8_t scroll = 0;

	sh1106.set_region(10, 1, 0, 0);
	static const uint8_t gdata0[] =
	{
		0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
		0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa
	};
	sh1106.write_gdata(&gdata0[0], sizeof(gdata0));

	// draw picture
	uint16_t * gdata[BUFFER_COUNT];
	for(int i = 0; i < BUFFER_COUNT; i++)
	{
		gdata[i] = (uint16_t *)malloc(VSPI_MAX_BUFFER_SIZE);
	}

	uint32_t full_size = LCD_VERTICAL_SIZE * LCD_HORIZONTAL_SIZE; // in pixel;
	uint16_t buff_index = 0;
	const uint8_t * l8_data = ((const PictureGData*)sdr_320x240_V2.gdata)->data;
	const uint16_t * lut = (const uint16_t*)((const PictureGData*)sdr_320x240_V2.gdata)->lut;

	int16_t scount = 0;
	uint8_t lut_index = 0;
	st7789.set_region(0, 0, LCD_HORIZONTAL_SIZE, LCD_VERTICAL_SIZE);
	st7789.start_writing_gdata();
	while(full_size)
	{
		uint16_t * buffer = gdata[buff_index];
		uint16_t size;
		for(size = 0; (size < (VSPI_MAX_BUFFER_SIZE/2)) && full_size; size++)
		{
			if(!scount)
			{
				scount = *l8_data;
				l8_data++;
				lut_index = *l8_data;
				l8_data++;
			}
			else
				scount--;
			
			*buffer++ = lut[lut_index];
			full_size--;
		}
		st7789.write_gdata((uint8_t*)gdata[buff_index], size*2);

		buff_index++;
		if(buff_index == BUFFER_COUNT)
			buff_index = 0;
	}

	st7789.wait_and_delay(0);
	for(int i = 0; i < BUFFER_COUNT; i++)
	{
		free(gdata[i]);
	}


	while(1)
	{
		vTaskDelay(3);
		scroll += 1;
		scroll &= 0b00111111;
		sh1106_vertical_scroll(scroll);
	}
}