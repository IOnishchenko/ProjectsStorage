#ifndef GUI_IENCODER_EVENT_HANDLER_HPP
#define GUI_IENCODER_EVENT_HANDLER_HPP

#include "UIControlEvents.hpp"

namespace gui
{
	class IEncoderEventHandler
	{
	public:

		// destructor
		virtual ~IEncoderEventHandler() = default;

		// methods
		virtual void OnEncoderMoved(IEncoderEventHandler *, EncoderEvent & event) = 0;
	};
}

#endif // GUI_IENCODER_EVENT_HANDLER_HPP