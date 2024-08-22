#ifndef GUI_FOCUS_EVENT_OBSERVER_HPP
#define GUI_FOCUS_EVENT_OBSERVER_HPP

#include "stdint.h"
#include "IEncoderEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "IFocusEventHandler.hpp"

namespace gui
{
	class IFocusManager :
		public IEncoderEventHandler,
		public IKeyboardEventHandler
	{
	public:
		// constructor
		//IFocusManager();

		// destructor
		~IFocusManager() override = default;
		
		// methods
		void RegisterHandler(uint16_t focusIndex, IFocusEventHandler * subscriber);
		void UnregisterHandler(IFocusEventHandler * subscriber);
		bool HasHandlers();
		bool HasFocused();

		// IEncoderEventHandler methods
		void OnEncoderMoved(EncoderEvent & event);

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;

	private:
		// fields
		IFocusEventHandler * _focused = nullptr;
		IFocusEventHandler * _first = nullptr;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP