#ifndef GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP

namespace gui
{
	class ITouchScreenEventHandler
	{
	public:

		// destructor
		virtual ~ITouchScreenEventHandler() = default;

		// methods
		virtual void OnPress(ITouchScreenEventHandler &);
		virtual void OnRelease(ITouchScreenEventHandler &);
		virtual void OnLongPress(ITouchScreenEventHandler &);
		virtual void OnPenEnter(ITouchScreenEventHandler &);
		virtual void OnPenLeave(ITouchScreenEventHandler &);
		virtual void OnPenMove(ITouchScreenEventHandler &);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP