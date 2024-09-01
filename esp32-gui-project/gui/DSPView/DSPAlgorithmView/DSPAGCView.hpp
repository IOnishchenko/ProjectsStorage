
#ifndef GUI_DSP_AGC_VIEW_HPP
#define GUI_DSP_AGC_VIEW_HPP

#include "DSPAlgorithmViewBase.hpp"
#include "SliderWithHeader.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"

namespace gui
{
	class DSPAGCView : public DSPAlgorithmViewBase
	{
	public:
		// constructor
		DSPAGCView(const IUIContext & context);

		// destructor
		~DSPAGCView() override;
	
	private:
		// commands
		Command<DSPAGCView, ICheckBox *> _onAGCEnabledCmd;
		Command<DSPAGCView, ICheckBox *> _onAGCDisabledCmd;
		Command<DSPAGCView, int> _onAGCMaxGainChangedCmd;
		Command<DSPAGCView, int> _onNoiseLevelChangedCmd;

		// fields
		custom::SliderWithHeader _maxAGCGainSlider;
		custom::SliderWithHeader _maxNoiseLevelSlider;
		GERectangle _settingsBackground;
		Group _settingsGroup;

		// methods
		void OnAGCEnabled(ICheckBox *);
		void OnAGCDisabled(ICheckBox *);
		void OnAGCMaxGainChanged(int value);
		void OnNoiseLevelChanged(int value);
	};
}

#endif // GUI_DSP_AGC_VIEW_HPP