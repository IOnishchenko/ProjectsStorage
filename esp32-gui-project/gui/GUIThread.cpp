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
#include "TextView.hpp"
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

#include "font/font17_tahoma.h"
#include "font/font17_tahoma_comp.h"
#include "font/font21_tahoma.h"
#include "font/font21_tahoma_comp.h"
#include "font/font32_tahoma.h"
#include "font/font32_tahoma_comp.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#include "GUIThread.hpp"
#include "CommandQueue.hpp"
#include "AsyncCommandDispatcher.hpp"
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
static gui::GElementDecoderRGB565 DecoderRGB565;
static gui::ControlRenderer<uint16_t, LCD_BUFFER_SIZE_IN_BYTES/sizeof(uint16_t),
	LCD_BUFFER_NUMBER> Renderer(DecoderRGB565, st7789);
static gui::IUIContext ColorScreen =
{
	.Renderer = Renderer,
	.EncoderEventObserver = nullptr,
	.FocusManager = nullptr,
	.TouchScreenObserver = nullptr
};

static gui::Font newFont(font17_tahoma_comp);

constexpr uint16_t fontColor = (uint16_t)~(((0xff9302 >> 8) & 0xf800) |
	((0xff9302 >> 5) & 0x07e0) | ((0xff9302 >> 3) & 0x001f));
constexpr uint16_t backColor = (uint16_t)~(((0x3d5a68 >> 8) & 0xf800) |
	((0x3d5a68 >> 5) & 0x07e0) | ((0x3d5a68 >> 3) & 0x001f));

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static CommandQueue<gui::GUIThreadEventsContaner, 10> Queue;
static AsyncCommandDispatcher GUIThreadCommandDispatcher(Queue);
gui::GUIThread UIThread(GUIThreadCommandDispatcher);

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
gui::GUIThread::GUIThread(AsyncCommandDispatcher & dispatcher)
	:OnEncoderRotatedAsync(this, &gui::GUIThread::OnEncoderRotated, dispatcher),
	OnKeyPressedAsync(this, &gui::GUIThread::OnKeyPressed, dispatcher),
	OnKeyReleasedAsync(this, &gui::GUIThread::OnKeyReleased, dispatcher),
	OnTimerTikedAsync(this, &gui::GUIThread::OnTimerTiked, dispatcher),
	_dispatcher{dispatcher},
	_text(10, 10, 300, 220, ColorScreen, 3, fontColor, backColor, newFont)
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
		_dispatcher.HandleAsyncCall();
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
	_text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::OnEncoderRotated(uint32_t value)
{
	sprintf(txt, "Encode event, code = %lu!\n", value);
	_text.AddLine(txt);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::OnKeyPressed(uint32_t value)
{
	sprintf(txt, "Key pressed event, code = %lu!\n", value);
	_text.AddLine(txt);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::OnKeyReleased(uint32_t value)
{
	sprintf(txt, "Key released event, code = %lu!\n", value);
	_text.AddLine(txt);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::OnTimerTiked(uint32_t value)
{
	sprintf(txt, "Timer tiked, code = %lu!\n", value);
	_text.AddLine(txt);
}