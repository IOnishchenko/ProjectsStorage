#ifndef GUI_IFOCUSABLE_HPP
#define GUI_IFOCUSABLE_HPP

namespace gui
{
	class IFocusEventHandler
	{
	public:
		// destructor
		virtual ~IFocusEventHandler() = default;

		// methods
		virtual void OnFocused(IFocusEventHandler *) = 0;
		virtual void OnFocusLost(IFocusEventHandler *) = 0;
	};
}

#endif // GUI_IFOCUSABLE_HPP