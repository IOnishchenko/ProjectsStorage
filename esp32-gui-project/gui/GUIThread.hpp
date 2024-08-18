#ifndef GUI_GUI_THREAD_HPP
#define GUI_GUI_THREAD_HPP

#include "stdint.h"
#include "lcd-driver.h"
#include "IEncoderEventManager.hpp"
#include "IKeyboardEventManager.hpp"
#include "IFocusManager.hpp"
#include "GElementDecoderRGB565.hpp"
#include "ControlRenderer.hpp"
#include "IUIContext.hpp"

#include "AsyncCallMessage.hpp"
#include "AsyncCommandDispatcher.hpp"
#include "CommandQueue.hpp"
#include "UIEvents.hpp"

#include "TextView.hpp"
#include "Picture.hpp"

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
	class GUIThread :
		public IFocusManager,
		public IEncoderEventManager,
		public IKeyboardEventManager
	{
		// it is used for memeory size calculation when 
		// memory pool is created 
		union GUIThreadEventsContaner
		{
			AsyncCallMessage<uint32_t> OnTimerTikedMessage;
			AsyncCallMessage<TouchScreenEven> OnTouchScreenMessage;
			AsyncCallMessage<KeyEvent> OnKeyboardMessage;
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

		// field

	private:
		// field
		CommandQueue<GUIThreadEventsContaner, GUI_THREAD_MESSAGE_NUMBER> _queue;
		AsyncCommandDispatcher _asyncCommandDispatcher;
		GElementDecoderRGB565 _decoder;
		ControlRenderer<uint16_t, LCD_BUFFER_SIZE_IN_BYTES/sizeof(uint16_t), LCD_BUFFER_NUMBER> _renderer;
		IUIContext _context;
		// gui
		TextView _text;
		GEPicture _gelPicture;
		Picture _picture;

		// method
		
	};
}

#endif // GUI_GUI_THREAD_HPP