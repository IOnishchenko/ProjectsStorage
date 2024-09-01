#ifndef GUI_DSP_ALGORITHM_VIEW_BASE_HPP
#define GUI_DSP_ALGORITHM_VIEW_BASE_HPP

#include "Group.hpp"
#include "OGCheckBoxH18.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class DSPAlgorithmViewBase :public Group
	{
	public:
		// constructor
		DSPAlgorithmViewBase(const IUIContext & context,
			const Action<void(ICheckBox *)> & checkedCmd, const Action<void(ICheckBox *)> & uncheckedCmd,
			const std::string_view & checkedText, const std::string_view & uncheckedText);

		// destructor
		~DSPAlgorithmViewBase() override;
	
	protected:
		// fields
		OGCheckBoxH18 _enaCheckbox;
		GERectangle _background;
		
	};
}

#endif // GUI_DSP_ALGORITHM_VIEW_BASE_HPP