#include "configuration.h"
#include "lcd-driver.h"
#include "IUIContext.hpp"
#include "GElementDecoderRGB565.hpp"
#include "ControlRenderer.hpp"

#include "GEPicture.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include "Picture.hpp"
#include "Group.hpp"
#include "Label.hpp"

#include "Font.hpp"
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#include "sdr_dumy_picture.h"
#include "button64x24.h"
#include "font12.h"
#include "font16.h"
#include "font20.h"
#include "font24.h"
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

constexpr uint16_t fontColor = ~(((0xff9302 >> 8) & 0xf800) | ((0xff9302 >> 5) & 0x07e0) | ((0xff9302 >> 3) & 0x001f));
constexpr uint16_t backColor = ~(((0x3d5a68 >> 8) & 0xf800) | ((0x3d5a68 >> 5) & 0x07e0) | ((0x3d5a68 >> 3) & 0x001f));

static gui::GEPicture _gpic(&sdr_320x240_V2, nullptr);

static gui::Font guiFont12(font12);
static gui::Font guiFont16(font16);
static gui::Font guiFont20(font20);
static gui::Font guiFont24(font24);

static gui::GEText _txt0(10, 7, 0, 20, "Test", fontColor, backColor/*0xDEBA*/, guiFont12, nullptr);
static gui::GEPicture _gpicButton0(&button64x24_focused, &_txt0);

static gui::GEText _txt1(10, 7, 0, 12, "Test", fontColor, backColor/*0xDEBA*/, guiFont12, nullptr);
static gui::GEPicture _gpicButton1(&button64x24_focused, &_txt1);

static gui::GEText _txt2(5, 5, 0, 16, "Test", fontColor, backColor/*0xDEBA*/, guiFont16, nullptr);
static gui::GEPicture _gpicButton2(&button64x24_focused, &_txt2);

static gui::GEText _txt3(10, 2, 0, 20, "Test", fontColor, backColor/*0xDEBA*/, guiFont20, nullptr);
static gui::GEPicture _gpicButton3(&button64x24_focused, &_txt3);

static gui::Picture _cpic0(110, 55, 64, 24, ColorScreen, &_gpicButton0);
static gui::Picture _cpic1(110, 80, 64, 24, ColorScreen, &_gpicButton1);
static gui::Picture _cpic2(110, 105, 64, 24, ColorScreen, &_gpicButton2);
static gui::Picture _cpic3(110, 130, 64, 24, ColorScreen, &_gpicButton3);
static gui::Picture _cpic4(110, 155, 64, 24, ColorScreen, &_gpicButton3);
static gui::Picture _cpic5(110, 180, 64, 24, ColorScreen, &_gpicButton3);

static gui::GERectangle _rec(0, 0, 150, 110, 0xDEBA, nullptr);
static gui::Group _group0(100, 50, 150, 110, ColorScreen,
	{&_cpic0, &_cpic1, &_cpic2, &_cpic3, &_cpic4, &_cpic5}, &_rec);
//static gui::Group _group1(100, 50, 150, 110, ColorScreen, {&_group0}, &_rec);

static gui::GERectangle _recFullScreen(0, 0, 320, 240, 0xBD55, nullptr);
static gui::Group _groupInter(20, 20, 280, 200, ColorScreen, {&_group0}, &_recFullScreen);
static gui::Group _groupFullScreen(0, 0, 320, 240, ColorScreen, {&_groupInter}, &_gpic);

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

	_groupFullScreen.Draw();

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
	bool left = 1;

	while(1)
	{
		vTaskDelay(3);
		scroll += 1;
		scroll &= 0b00111111;
		sh1106_vertical_scroll(scroll);

		if(left)
		{
			//_group0.Y -= 2;
			for(auto itm : _group0.Controls)
			{
				itm->Y -= 2;
			}
			steps++;
			if(steps == 40)
			{
				steps = 0;
				left = false;
			}
		}
		else
		{
			//_group0.Y += 2;
			for(auto itm : _group0.Controls)
			{
				itm->Y += 2;
			}
			steps++;
			if(steps == 40)
			{
				steps = 0;
				left = true;
			}
		}
		_group0.Draw();
	}
}