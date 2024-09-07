#ifndef GUI_ORANGE_GRAY_DIALOG_CLOSE_BASE_HPP
#define GUI_ORANGE_GRAY_DIALOG_CLOSE_BASE_HPP

#include "IModalWindow.hpp"
#include "IUIContext.hpp"
#include "GEPicture.hpp"
#include "GEText.hpp"
#include "Command.hpp"
#include "OGButton100x22.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WINDOW_X = 42;
	constexpr uint16_t WINDOW_Y = 30;

	constexpr uint16_t WINDOW_WIDTH = 240;
	constexpr uint16_t WINDOW_HEIGHT = 176;
	constexpr uint16_t WINDOW_HEADER_HEIGHT = 36;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class OGDialogCloseBase : public IModalWindow
	{
	public:
		// constructor
		OGDialogCloseBase(const IUIContext & context,
			const std::string_view & headerText);

		// destructor
		~OGDialogCloseBase() override;

	private:
		// commands
		Command<OGDialogCloseBase, IButton*> _onCloseButtonClickedCmd;
		
		// field
		OGButton100x22 _closeButton;

		GEText _headerText;
		GEPicture _background;

		// methods
		void OnCloseButtonClicked(IButton *);
	};
}

#endif // GUI_ORANGE_GRAY_DIALOG_CLOSE_BASE_HPP