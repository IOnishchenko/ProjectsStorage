#include "configuration.h"
#include "lcd-driver.h"
#include "IUIContext.hpp"
#include "GElementDecoderRGB565.hpp"
#include "ControlRenderer.hpp"

#include "GEPicture.hpp"
#include "GERectangle.hpp"
#include "Picture.hpp"
#include "Group.hpp"
#include "Label.hpp"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#include "sdr_dumy_picture.h"
#include "button64x24.h"
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
//gui::IUIContext ColorScreen;
static gui::GElementDecoderRGB565 DecoderRGB565;
//template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
//ControlRenderer(IGElementDecoder & decoder, lcd_driver & lcd)
static gui::ControlRenderer<uint16_t, LCD_BUFFER_SIZE_IN_BYTES/sizeof(uint16_t),
	LCD_BUFFER_NUMBER> Renderer(DecoderRGB565, st7789);
static gui::IUIContext ColorScreen =
{
	.Renderer = Renderer,
	.EncoderEventObserver = nullptr,
	.FocusManager = nullptr,
	.TouchScreenObserver = nullptr
};

static gui::GEPicture _gpic(&sdr_320x240_V2, nullptr);
static gui::GEPicture _gpicButton(&button64x24_focused, nullptr);

static gui::Picture _cpic(110, 110, 64, 24, ColorScreen, &_gpicButton);
static gui::GERectangle _rec(0, 0, 150, 100, 0xDEBA, nullptr);
static gui::Group _group(115, 114, 150, 100, ColorScreen, {&_cpic}, &_rec);

static gui::GERectangle _recFullScreen(0, 0, 320, 240, 0xBD55, nullptr);
static gui::Group _groupFullScreen(0, 0, 320, 240, ColorScreen, {&_group}, &_gpic);

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

	_group.Draw();

	// // draw picture
	// uint16_t * gdata[BUFFER_COUNT];
	// for(int i = 0; i < BUFFER_COUNT; i++)
	// {
	// 	gdata[i] = (uint16_t *)malloc(VSPI_MAX_BUFFER_SIZE);
	// }

	// uint32_t full_size = LCD_VERTICAL_SIZE * LCD_HORIZONTAL_SIZE; // in pixel;
	// uint16_t buff_index = 0;
	// const uint8_t * l8_data = ((const PictureGData*)sdr_320x240_V2.gdata)->data;
	// const uint16_t * lut = (const uint16_t*)((const PictureGData*)sdr_320x240_V2.gdata)->lut;

	// int16_t scount = 0;
	// uint8_t lut_index = 0;
	// st7789.set_region(0, 0, LCD_HORIZONTAL_SIZE, LCD_VERTICAL_SIZE);
	// st7789.start_writing_gdata();
	// while(full_size)
	// {
	// 	uint16_t * buffer = gdata[buff_index];
	// 	uint16_t size;
	// 	for(size = 0; (size < (VSPI_MAX_BUFFER_SIZE/2)) && full_size; size++)
	// 	{
	// 		if(!scount)
	// 		{
	// 			scount = *l8_data;
	// 			l8_data++;
	// 			lut_index = *l8_data;
	// 			l8_data++;
	// 		}
	// 		else
	// 			scount--;
			
	// 		*buffer++ = lut[lut_index];
	// 		full_size--;
	// 	}
	// 	st7789.write_gdata((uint8_t*)gdata[buff_index], size*2);

	// 	buff_index++;
	// 	if(buff_index == BUFFER_COUNT)
	// 		buff_index = 0;
	// }

	// st7789.wait_and_delay(0);
	// for(int i = 0; i < BUFFER_COUNT; i++)
	// {
	// 	free(gdata[i]);
	// }

	uint16_t steps = 0;
	bool left = 0;

	while(1)
	{
		vTaskDelay(3);
		scroll += 1;
		scroll &= 0b00111111;
		sh1106_vertical_scroll(scroll);

		if(left)
		{
			_cpic.X -= 2;
			_cpic.Y -= 2;
			steps++;
			if(steps == 40)
			{
				steps = 0;
				left = false;
			}
		}
		else
		{
			_cpic.X += 2;
			_cpic.Y += 2;
			steps++;
			if(steps == 40)
			{
				steps = 0;
				left = true;
			}
		}
		// _group.Draw();
	}
}