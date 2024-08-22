#include "configuration.h"
#include "GUIThread.hpp"

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
gui::GUIThread UIThread(st7789);

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
	_mainScreen(_context)
{
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
	_mainScreen.Draw();
}