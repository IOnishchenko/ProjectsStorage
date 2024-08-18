#include "configuration.h"
#include "GUIThread.hpp"
#include <cstring>

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
#include "dumy_picture.h"
#include "font18.h"
static gui::Font newFont(font18);

constexpr uint16_t fontColor = (uint16_t)~(((0xff9302 >> 8) & 0xf800) |
	((0xff9302 >> 5) & 0x07e0) | ((0xff9302 >> 3) & 0x001f));
constexpr uint16_t backColor = (uint16_t)~(((0x3d5a68 >> 8) & 0xf800) |
	((0x3d5a68 >> 5) & 0x07e0) | ((0x3d5a68 >> 3) & 0x001f));

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
gui::GUIThread UIThread(st7789);
char txt[256] = {0};

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void gui_thread(void * args)
{
	UIThread.Initialize();
	UIThread.Run();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
gui::GUIThread::GUIThread(lcd_driver & lcdDriver)
	:IFocusManager(), IEncoderEventManager(this, _asyncCommandDispatcher),
	IKeyboardEventManager(this, _asyncCommandDispatcher),
	_queue(), _asyncCommandDispatcher(_queue), _decoder(), _renderer(_decoder, lcdDriver),
	_context{_renderer, this, this, nullptr, this},
	_text(10, 10, 300, 220, _context, 3, fontColor, backColor, newFont),
	_gelPicture(&gui320x240, nullptr),
	_picture(0, 0, 320, 240, _context, &_gelPicture)
{
	_text.RedrawEachLine = true;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::Run()
{
	while(true)
	{
		_asyncCommandDispatcher.HandleAsyncCall();
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::Initialize()
{
	st7789.initialize();
	sh1106.initialize();

	sh1106.set_region(10, 1, 0, 0);
	static const uint8_t gdata0[] =
	{
		0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
		0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa
	};
	sh1106.write_gdata(&gdata0[0], sizeof(gdata0));

	memset(txt, 0, 256);
	_picture.Draw();
}