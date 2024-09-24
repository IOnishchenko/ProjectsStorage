
#ifndef GUI_DSP_MODULATION_VIEW_HPP
#define GUI_DSP_MODULATION_VIEW_HPP

#include "OGTabControl5T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class DSPModulationView : public OGTabControl5T
	{
	public:
		// constructor
		DSPModulationView(const IUIContext & context);

		// destructor
		~DSPModulationView() override = default;

	private:
		// commands
		Command<DSPModulationView, IRadioButton *> _onAMClikedCmd;
		Command<DSPModulationView, IRadioButton *> _onSSBClikedCmd;
		Command<DSPModulationView, IRadioButton *> _onFMClikedCmd;
		Command<DSPModulationView, IRadioButton *> _onCWClikedCmd;
		Command<DSPModulationView, IRadioButton *> _onTODOClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnAMClicked(IRadioButton *);
		void OnSSBClicked(IRadioButton *);
		void OnFMClicked(IRadioButton *);
		void OnCWClicked(IRadioButton *);
		void OnTODOClicked(IRadioButton *);
	};
}

#endif // GUI_DSP_MODULATION_VIEW_HPP