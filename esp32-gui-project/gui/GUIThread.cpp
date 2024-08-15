#include "configuration.h"

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
static gui::Font newFont(font17_tahoma_comp);

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
	:HandleEncoderEventAsync(this, &gui::GUIThread::HandleEncoderEvent, _asyncCommandDispatcher),
	OnKeyPressedAsync(this, &gui::GUIThread::OnKeyPressed, _asyncCommandDispatcher),
	OnKeyReleasedAsync(this, &gui::GUIThread::OnKeyReleased, _asyncCommandDispatcher),
	OnTimerTikedAsync(this, &gui::GUIThread::OnTimerTiked, _asyncCommandDispatcher),
	_encoderObserver(), _keyboardObserver(), _queue(), _asyncCommandDispatcher(_queue),
	_decoder(), _renderer(_decoder, lcdDriver),
	_context{_renderer, &_encoderObserver, &_keyboardObserver, nullptr, nullptr},
	_text(10, 10, 300, 220, _context, 3, fontColor, backColor, newFont)
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
	_text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::HandleEncoderEvent(EncoderEvent event)
{
	sprintf(txt, "Encode event, code = %lu!\n", (uint32_t)event.Direction);
	_text.AddLine(txt);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::OnKeyPressed(KeyCode key)
{
	sprintf(txt, "Key pressed event, code = %lu!\n", (uint32_t)key);
	_text.AddLine(txt);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui::GUIThread::OnKeyReleased(KeyCode key)
{
	sprintf(txt, "Key released event, code = %lu!\n", (uint32_t)key);
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