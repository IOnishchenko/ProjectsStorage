#ifndef GUI_DOALOG_SLIDER_DIALOG_HPP
#define GUI_DOALOG_SLIDER_DIALOG_HPP

#include "OGDialogCloseBase240x110.hpp"
#include "OGHorizontalSliderLabel.hpp"

namespace gui
{
	class SliderDialog : public OGDialogCloseBase240x110
	{
	public:
		// constructor
		SliderDialog(const IUIContext & context, const std::string_view & headerText,
			int maxValue, int value, const Action<void(int)> & valueChanged);

		// destructor
		~SliderDialog() override;

	protected:
		// fields
		OGHorizontalSliderLabel _slider;
	};
}

#endif // GUI_DOALOG_SLIDER_DIALOG_HPP