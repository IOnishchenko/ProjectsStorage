#ifndef GUI_UI_CONTROL_EVENTS_HPP
#define GUI_UI_CONTROL_EVENTS_HPP

#include "stdint.h"

namespace gui
{
	/*------------------------------------------------------------//
	// Touch panel event types
	//------------------------------------------------------------*/
	enum class TouchScreenEventType
	{
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
	// Encoder event types
	//------------------------------------------------------------*/
	enum class EncoderDirection
	{
		ENC_INCREASE,
		ENC_DECREASE
	};

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	enum class EncoderId;

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	struct EncoderEvent
	{
		EncoderId Id;
		EncoderDirection Direction;
		uint32_t Duration;
	};

	/*------------------------------------------------------------//
	// Keyboard event types
	//------------------------------------------------------------*/
	enum class KeyCode
	{
		KEY_ARROW_UP = 0x001,
		KEY_ARROW_DOWN,
		KEY_ARROW_LEFT,
		KEY_ARROW_RIGHT,
		KEY_ENTER,
		ENCODER_KEY = 0x100,
	};

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	enum class KeyEventType
	{
		Released,
		Pressed,
		LongPressed
	};

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	struct KeyEvent
	{
		KeyCode Code;
		KeyEventType Type;
	};
}
#endif // GUI_UI_CONTROL_EVENTS_HPP