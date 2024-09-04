#include "configuration.h"
#include "GUIThread.hpp"
#include "ScreenBase.hpp"
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
	IWindowManager(_renderer, this, this, nullptr, this, _commandDispatcher),
	// LogDataAsync(this, &gui::GUIThread::LogData, _asyncCommandDispatcher),
	_queue(), _asyncCommandDispatcher(_queue), _decoder(), _renderer(_decoder, lcdDriver),
	_commandQueue(), _commandDispatcher(_commandQueue)
	
{
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::Run()
{
	while(true)
	{
		_commandDispatcher.HandleAsyncCall();
		_asyncCommandDispatcher.HandleAsyncCall();
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::Initialize()
{
	st7789.initialize();
	CreateAndShowWindow<ScreenBase>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
// void gui::GUIThread::LogData(uint32_t data)
// {
// 	// char txt[64];
// 	// char * ptr = txt;
// 	// for(int i = 0; i < 32; i++)
// 	// {
// 	// 	sprintf(ptr, "%d", (data & 0x8000'0000) ? 1 : 0);
// 	// 	ptr++;
// 	// 	if((i & 1))
// 	// 	{
// 	// 		sprintf(ptr, "%s", "'");
// 	// 		ptr++;
// 	// 	}
// 	// 	data <<= 1;
		
// 	// }
// 	// printf("value to log: 0b%s\n", txt);
// 	printf("dt = %ld\n", data);
// }