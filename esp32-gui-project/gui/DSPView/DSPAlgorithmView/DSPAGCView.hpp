
#ifndef GUI_DSP_AGC_VIEW_HPP
#define GUI_DSP_AGC_VIEW_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class DSPAGCView : public Group
	{
	public:
		// constructor
		DSPAGCView(const IUIContext & context);

		// destructor
		~DSPAGCView() override = default;
	
	private:
		// fields
		GERectangle _background;

	};
}

#endif // GUI_DSP_AGC_VIEW_HPP