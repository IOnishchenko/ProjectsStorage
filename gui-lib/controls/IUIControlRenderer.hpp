#ifndef GUI_IUICONTROL_RENDERER_HPP
#define GUI_IUICONTROL_RENDERER_HPP

#include "IUIControl.hpp"
#include "Group.hpp"

namespace gui
{
	struct IUIControlRenderer
	{
		// destructor
		virtual ~IUIControlRenderer() = default;

		// methods
		virtual void DrawUIControl(IUIControl * control) = 0;
		virtual void DrawGroup(Group * group) = 0;
	};
}

#endif // GUI_IUICONTROL_RENDERER_HPP