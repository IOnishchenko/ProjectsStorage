#ifndef GUI_GUI_THREAD_HPP
#define GUI_GUI_THREAD_HPP

#include "stdint.h"
#include "AsyncCommand.hpp"
#include "AsyncCallMessage.hpp"
#include "AsyncCommandDispatcher.hpp"
#include "UIControlEvents.hpp"

#include "TextView.hpp"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
namespace gui
{
	class GUIThread
	{
	public:
		// constructor
		GUIThread(AsyncCommandDispatcher & dispatcher);

		// destructor
		~GUIThread() = default;

		// methods
		void Run();
		void Initialize();

		// async commands
		AsyncCommand<GUIThread, uint32_t> OnEncoderRotatedAsync;
		AsyncCommand<GUIThread, uint32_t> OnKeyPressedAsync;
		AsyncCommand<GUIThread, uint32_t> OnKeyReleasedAsync;
		AsyncCommand<GUIThread, uint32_t> OnTimerTikedAsync;

	private:
		// field
		AsyncCommandDispatcher & _dispatcher;

		// gui
		TextView _text;

		// method
		void OnEncoderRotated(uint32_t value);
		void OnKeyPressed(uint32_t value);
		void OnKeyReleased(uint32_t value);
		void OnTimerTiked(uint32_t value);
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	union GUIThreadEventsContaner
	{
		uint32_t value;
		AsyncCallMessage<uint32_t> OnEncoderRotatedMessage;
		AsyncCallMessage<uint32_t> OnKeyPressedMessage;
		AsyncCallMessage<uint32_t> OnKeyReleasedMessage;
	};
}

#endif // GUI_GUI_THREAD_HPP