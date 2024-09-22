#include "configuration.h"
#include "GUIThread.hpp"
#include "AnimatedTimer.hpp"

// debug init
#include "SpectrumViewSettings.hpp"
#include "OGCommon.hpp"

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


// debug init
extern gui::SpectrumViewSettings<color_t> Settings;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void gui_thread(void * args)
{
	// debug initialization
	Settings.Colors.SpectrumTopColor = 0;
	Settings.Colors.SpectrumTopAlpha = 0;
	Settings.Colors.SpectrumCurveColor = gui::TEXT_COLOR;
	Settings.Colors.SpectrumCurveAlpha = 0x0e;
	Settings.Colors.SpectrumBottomColor = gui::BACKGROUND_LIGHT;
	Settings.Colors.SpectrumBottomAlpha = 0x0e;
	Settings.WaterfallColor = gui::TEXT_COLOR;
	Settings.WaterfallDepth = 40;
	
	UIThread.Initialize();
	UIThread.Run();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
gui::GUIThread::GUIThread(lcd_driver & lcdDriver)
	:IFocusManager(), IEncoderEventManager(this), IKeyboardEventManager(this),
	IWindowManager(_renderer, this, this, nullptr, this, this, _commandDispatcher),
	IAnimatedControlManager(),
	HandleEncoderEventAsync(this, &IEncoderEventManager::HandleEncoderEvent,
		_asyncCommandDispatcher),
	HandleKeyboardEventAsync(this, &IKeyboardEventManager::HandleKeyboardEvent,
		_asyncCommandDispatcher),
	HandleAnimationTimerTickAsync(this, &IAnimatedControlManager::AnimateControls,
		_asyncCommandDispatcher),

// LogDataAsync(this, &gui::GUIThread::LogData, _asyncCommandDispatcher),

	_queue(), _asyncCommandDispatcher(_queue), _decoder(), _renderer(_decoder, lcdDriver),
	_commandQueue(), _commandDispatcher(_commandQueue),
	_baseScreen(GetContext())
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
	CreateAnimationTimer();
	_baseScreen.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
CommandDispatcher & gui::GUIThread::GetCommandDispatcher()
{
	return _commandDispatcher;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::StartAnimation()
{
	// start animation timer
	StartAnimationTimer();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::StopAnimation()
{
	// stop animation timer
	StopAnimationTimer();
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