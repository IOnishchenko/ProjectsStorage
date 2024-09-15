#ifndef GUI_EVENTS_IANIMATED_CONTROL_HPP
#define GUI_EVENTS_IANIMATED_CONTROL_HPP

namespace gui
{
	class IAnimatedControl
	{
	public:
		// destructor
		virtual ~IAnimatedControl() = default;

		// methods
		virtual void Animate() = 0;
	};
}

#endif // GUI_EVENTS_IANIMATED_CONTROL_HPP