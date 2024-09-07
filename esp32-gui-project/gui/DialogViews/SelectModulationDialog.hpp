#ifndef GUI_DIALOG_SELECT_MODULATION_DIALOG_HPP
#define GUI_DIALOG_SELECT_MODULATION_DIALOG_HPP

#include "OGDialogCloseBase.hpp"
#include "OGRadioButtonH18.hpp"
#include "IRadioButtonGroup.hpp"

namespace gui
{
	class SelectModulationDialog : public OGDialogCloseBase
	{
	public:
		// constructor
		SelectModulationDialog(const IUIContext & context);

		// destructor
		~SelectModulationDialog() override;

	private:
		// commands
		Command<SelectModulationDialog, IRadioButton*> _onAMSelectedCmd;
		Command<SelectModulationDialog, IRadioButton*> _onLSBSelectedCmd;
		Command<SelectModulationDialog, IRadioButton*> _onUSBSelectedCmd;
		Command<SelectModulationDialog, IRadioButton*> _onFMSelectedCmd;
		Command<SelectModulationDialog, IRadioButton*> _onCWSelectedCmd;
		
		// field
		OGRadioButtonH18 _amRbuttom;
		OGRadioButtonH18 _lsbRbuttom;
		OGRadioButtonH18 _usbRbuttom;
		OGRadioButtonH18 _fmRbuttom;
		OGRadioButtonH18 _cwRbuttom;
		IRadioButtonGroup _radioButtonGroup;

		// methods
		void OnAMSelected(IRadioButton *);
		void OnLSBSelected(IRadioButton *);
		void OnUSBSelected(IRadioButton *);
		void OnFMSelected(IRadioButton *);
		void OnCWSelected(IRadioButton *);
	};
}

#endif // GUI_DIALOG_SELECT_MODULATION_DIALOG_HPP