#ifndef GUI_ORANGE_GRAY_DIALOG_CLOSE_BASE_240x110_HPP
#define GUI_ORANGE_GRAY_DIALOG_CLOSE_BASE_240x110_HPP

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
	constexpr uint16_t WINDOW240x110_X = 42;
	constexpr uint16_t WINDOW240x110_Y = 60;

	constexpr uint16_t WINDOW240x110_WIDTH = 240;
	constexpr uint16_t WINDOW240x110_HEIGHT = 110;
	constexpr uint16_t WINDOW240x110_HEADER_HEIGHT = 36;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class OGDialogCloseBase240x110 : public IModalWindow
	{
	public:
		// constructor
		OGDialogCloseBase240x110(const IUIContext & context,
			const std::string_view & headerText);

		// destructor
		~OGDialogCloseBase240x110() override;

	private:
		// commands
		Command<OGDialogCloseBase240x110, IButton*> _onCloseButtonClickedCmd;
		
		// field
		OGButton100x22 _closeButton;

		GEText _headerText;
		GEPicture _background;

		// methods
		void OnCloseButtonClicked(IButton *);
	};
}

#endif // GUI_ORANGE_GRAY_DIALOG_CLOSE_BASE_240x110_HPP