#ifndef GUI_UI_CONTROL_EVENTS_HPP
#define GUI_UI_CONTROL_EVENTS_HPP

#include "stdint.h"

namespace gui
{
	/*------------------------------------------------------------//
	// Events parameters
	//------------------------------------------------------------*/
	enum class TouchScreenEventType
	{
		Unknown,
		Released,
		Pressed,
		Moved
	};

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	struct TouchScreenEven
	{
		TouchScreenEventType Type;
		uint16_t x;
		uint16_t y;
		uint16_t xOld;
		uint16_t yOld;
	};

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	enum class EncoderDirection
	{
		ENC_INCREASE,
		ENC_DECREASE
	};

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	struct EncoderEvent
	{
		EncoderDirection Direction;
	};
}
#endif // GUI_UI_CONTROL_EVENTS_HPP