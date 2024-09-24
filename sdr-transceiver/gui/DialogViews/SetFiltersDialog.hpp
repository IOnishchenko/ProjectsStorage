#ifndef GUI_DIALOG_SET_FILTERS_DIALOG_HPP
#define GUI_DIALOG_SET_FILTERS_DIALOG_HPP

#include "OGDialogCloseBase.hpp"
#include "BandPassSliderWithLabel.hpp"

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
		custom::BandPassSliderWithLabel _slider;

		// methods
		void OnHPFFrequencyChanged(int value);
		void OnLPFFrequencyChanged(int value);
	};
}

#endif // GUI_DIALOG_SET_FILTERS_DIALOG_HPP