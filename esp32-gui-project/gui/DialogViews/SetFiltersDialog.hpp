#ifndef GUI_DIALOG_SET_FILTERS_DIALOG_HPP
#define GUI_DIALOG_SET_FILTERS_DIALOG_HPP

#include "OGDialogCloseBase.hpp"
#include "HPFSlider.hpp"
#include "LPFSlider.hpp"
#include "Label.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class SetFiltersDialog : public OGDialogCloseBase
	{
	public:
		// constructor
		SetFiltersDialog(const IUIContext & context);

		// destructor
		~SetFiltersDialog() override;

	private:
		// commands
		Command<SetFiltersDialog, int> _hpfFrequencyChangedCmd;
		Command<SetFiltersDialog, int> _lpfFrequencyChangedCmd;
		
		// field
		custom::HPFSlider _hpfSlider;
		custom::LPFSlider _lpfSlider;
		Label _hpfLabel;
		Label _lpfLabel;
		Label _bandLabel;

		// GERectangle _rightLine;
		// GERectangle _topLine;
		GERectangle _bottomLine;
		//GERectangle _legtLine;

		// methods
		void OnHPFFrequencyChanged(int value);
		void OnLPFFrequencyChanged(int value);
	};
}

#endif // GUI_DIALOG_SET_FILTERS_DIALOG_HPP