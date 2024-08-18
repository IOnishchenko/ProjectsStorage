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
		virtual bool OnFocused() = 0;
		virtual void OnFocusLost() = 0;

		// field
		IFocusEventHandler * Previous = this;
		IFocusEventHandler * Next = this;
	};
}

#endif // GUI_IFOCUSABLE_HPP