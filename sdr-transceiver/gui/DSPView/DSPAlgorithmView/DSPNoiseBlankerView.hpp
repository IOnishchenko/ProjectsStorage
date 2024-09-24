
#ifndef GUI_DSP_NOISE_BLANKER_VIEW_HPP
#define GUI_DSP_NOISE_BLANKER_VIEW_HPP

#include "DSPAlgorithmViewBase.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"

namespace gui
{
	class DSPNoiseBlankerView : public DSPAlgorithmViewBase
	{
	public:
		// constructor
		DSPNoiseBlankerView(const IUIContext & context);

		// destructor
		~DSPNoiseBlankerView() override;
	
	private:
		// commands
		Command<DSPNoiseBlankerView, ICheckBox *> _onNoiseBlankerEnabledCmd;
		Command<DSPNoiseBlankerView, ICheckBox *> _onNoiseBlankerDisabledCmd;

		// fields
		GERectangle _settingsBackground;

		// methods
		void OnNoiseBlankerEnabled(ICheckBox *);
		void OnNoiseBlankerDisabled(ICheckBox *);
	};
}

#endif // GUI_DSP_NOISE_BLANKER_VIEW_HPP