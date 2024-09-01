
#ifndef GUI_DSP_SQUELCH_VIEW_HPP
#define GUI_DSP_SQUELCH_VIEW_HPP

#include "DSPAlgorithmViewBase.hpp"
#include "SliderWithHeader.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"

namespace gui
{
	class DSPSquelchView : public DSPAlgorithmViewBase
	{
	public:
		// constructor
		DSPSquelchView(const IUIContext & context);

		// destructor
		~DSPSquelchView() override;

		// methods
		// void SetEnable(bool ena) override;
	
	private:
		// commands
		Command<DSPSquelchView, ICheckBox *> _onSquelchEnabledCmd;
		Command<DSPSquelchView, ICheckBox *> _onSquelchDisabledCmd;
		Command<DSPSquelchView, int> _onAGCSquelchLevelChangedCmd;

		// fields
		custom::SliderWithHeader _maxSquelchLevelSlider;
		GERectangle _settingsBackground;
		Group _settingsGroup;

		// methods
		void OnSquelchEnabled(ICheckBox *);
		void OnSquelchDisabled(ICheckBox *);
		void OnSquelchLevelChanged(int value);

	};
}

#endif // GUI_DSP_SQUELCH_VIEW_HPP