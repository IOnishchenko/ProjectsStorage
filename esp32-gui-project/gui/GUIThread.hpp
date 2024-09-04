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
#include "CommandQueueBlocked.hpp"
#include "UIEvents.hpp"
#include "ICommandQueue.hpp"
#include "CommandDispatcher.hpp"

#include "IWindowManager.hpp"
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
namespace gui
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	constexpr uint32_t GUI_THREAD_MESSAGE_NUMBER = 16;
	constexpr uint32_t GUI_INTERNAL_MESSAGE_NUMBER = 8;

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
	class GUIThread :
		public IFocusManager,
		public IEncoderEventManager,
		public IKeyboardEventManager,
		public IWindowManager
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

		union GUIInternalMessageContaner
		{
			AsyncCallMessage<void *> OnWindowManagerMessage;
		};

	public:
		// constructor
		GUIThread(lcd_driver & lcdDriver);

		// destructor
		~GUIThread() = default;

		// methods
		void Run();
		void Initialize();

		// async method
		//AsyncCommand<GUIThread, uint32_t> LogDataAsync;

	private:
		// field
		CommandQueueBlocked<GUIThreadEventsContaner, GUI_THREAD_MESSAGE_NUMBER> _queue;
		AsyncCommandDispatcher _asyncCommandDispatcher;
		GElementDecoderRGB565 _decoder;
		ControlRenderer<uint16_t, LCD_BUFFER_SIZE_IN_BYTES/sizeof(uint16_t), LCD_BUFFER_NUMBER> _renderer;

		// gui
		CommandQueue<GUIInternalMessageContaner, GUI_INTERNAL_MESSAGE_NUMBER> _commandQueue;
		CommandDispatcher _commandDispatcher;

		// method
		//void LogData(uint32_t data);
	};
}

#endif // GUI_GUI_THREAD_HPP