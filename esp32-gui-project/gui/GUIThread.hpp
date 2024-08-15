#ifndef GUI_GUI_THREAD_HPP
#define GUI_GUI_THREAD_HPP

#include "stdint.h"
#include "lcd-driver.h"
#include "IEncoderEventObserver.hpp"
#include "IKeyboardEventObserver.hpp"
#include "GElementDecoderRGB565.hpp"
#include "ControlRenderer.hpp"
#include "IUIContext.hpp"

#include "AsyncCommand.hpp"
#include "AsyncCallMessage.hpp"
#include "AsyncCommandDispatcher.hpp"
#include "CommandQueue.hpp"
#include "UIControlEvents.hpp"

#include "TextView.hpp"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
namespace gui
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	constexpr uint32_t GUI_THREAD_MESSAGE_NUMBER = 8;

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	enum class EncoderId
	{
		MAIN_ENCODER = 1,
		INVALID = 0
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	enum class KeyCode
	{
		ENCODER_KEY = 0x100,
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class GUIThread
	{
		// it is used for memeory size calculation when 
		// memory pool is created 
		union GUIThreadEventsContaner
		{
			AsyncCallMessage<uint32_t> OnTimerTikedMessage;
			AsyncCallMessage<KeyCode> OnKeyPressedMessage;
			AsyncCallMessage<KeyCode> OnKeyReleasedMessage;
			AsyncCallMessage<EncoderEvent> OnEncoderRotatedMessage; 
		};

	public:
		// constructor
		GUIThread(lcd_driver & lcdDriver);

		// destructor
		~GUIThread() = default;

		// methods
		void Run();
		void Initialize();

		// async commands
		AsyncCommand<GUIThread, EncoderEvent> HandleEncoderEventAsync;
		AsyncCommand<GUIThread, KeyCode> OnKeyPressedAsync;
		AsyncCommand<GUIThread, KeyCode> OnKeyReleasedAsync;
		AsyncCommand<GUIThread, uint32_t> OnTimerTikedAsync;

	private:
		// field
		IEncoderEventObserver _encoderObserver;
		IKeyboardEventObserver _keyboardObserver;
		CommandQueue<GUIThreadEventsContaner, GUI_THREAD_MESSAGE_NUMBER> _queue;
		AsyncCommandDispatcher _asyncCommandDispatcher;
		GElementDecoderRGB565 _decoder;
		ControlRenderer<uint16_t, LCD_BUFFER_SIZE_IN_BYTES/sizeof(uint16_t), LCD_BUFFER_NUMBER> _renderer;
		IUIContext _context;
		// gui
		TextView _text;

		// method
		void HandleEncoderEvent(EncoderEvent event);
		void OnKeyPressed(KeyCode key);
		void OnKeyReleased(KeyCode key);
		void OnTimerTiked(uint32_t value);
	};
}

#endif // GUI_GUI_THREAD_HPP