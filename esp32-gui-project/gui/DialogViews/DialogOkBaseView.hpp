#ifndef GUI_DIALOG_DIALOG_OK_BASE_VIEW_HPP
#define GUI_DIALOG_DIALOG_OK_BASE_VIEW_HPP

#include "IModalWindow.hpp"
#include "IUIContext.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"

namespace gui
{
	class DialogOkBaseView : public IModalWindow
	{
	public:
		// constructor
		DialogOkBaseView(const IUIContext & context);

		// destructor
		~DialogOkBaseView() override = default;

	private:
		GEText _headerText;
		GERectangle _headedr;
		GERectangle _background;
	};
}

#endif // GUI_DIALOG_DIALOG_OK_BASE_VIEW_HPP