#ifndef GUI_DIALOG_DIALOG_OK_BASE_VIEW_HPP
#define GUI_DIALOG_DIALOG_OK_BASE_VIEW_HPP

#include "IModalWindow.hpp"
#include "IUIContext.hpp"
#include "GEPicture.hpp"
#include "GEText.hpp"
#include "OGRadioButtonH18.hpp"
#include "IRadioButtonGroup.hpp"
#include "Command.hpp"
#include "OGButton100x22.hpp"

namespace gui
{
	class DialogOkBaseView : public IModalWindow
	{
	public:
		// constructor
		DialogOkBaseView(const IUIContext & context);

		// destructor
		~DialogOkBaseView() override;

	private:
		// commands
		Command<DialogOkBaseView, IRadioButton*> _onAMSelectedCmd;
		Command<DialogOkBaseView, IRadioButton*> _onLSBSelectedCmd;
		Command<DialogOkBaseView, IRadioButton*> _onUSBSelectedCmd;
		Command<DialogOkBaseView, IRadioButton*> _onFMSelectedCmd;
		Command<DialogOkBaseView, IRadioButton*> _onCWSelectedCmd;
		Command<DialogOkBaseView, IButton*> _onCloseButtonClickedCmd;
		
		// field
		OGRadioButtonH18 _amRbuttom;
		OGRadioButtonH18 _lsbRbuttom;
		OGRadioButtonH18 _usbRbuttom;
		OGRadioButtonH18 _fmRbuttom;
		OGRadioButtonH18 _cwRbuttom;
		IRadioButtonGroup _radioButtonGroup;
		OGButton100x22 _closeButton;

		GEText _headerText;
		GEPicture _background;

		// methods
		void OnAMSelected(IRadioButton *);
		void OnLSBSelected(IRadioButton *);
		void OnUSBSelected(IRadioButton *);
		void OnFMSelected(IRadioButton *);
		void OnCWSelected(IRadioButton *);
		void OnCloseButtonClicked(IButton *);
	};
}

#endif // GUI_DIALOG_DIALOG_OK_BASE_VIEW_HPP