#include "DSPNoiseBlankerView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT * 2;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;
constexpr uint16_t FIRST_ROW_Y = SCREEN_Y+ROW_HEIGHT;
constexpr uint16_t SECOND_ROW_Y = SCREEN_Y+ROW_HEIGHT*2+MARGIN;
constexpr uint16_t SETTINGS_SCREEN_HEIGHT = SCREEN_HEIGHT-ROW_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPNoiseBlankerView::DSPNoiseBlankerView(const IUIContext & context)
	:
	DSPAlgorithmViewBase(context, _onNoiseBlankerEnabledCmd, _onNoiseBlankerDisabledCmd,
	"Disable Noise Blanker:", "Enable Noise Blanker:"),
	_onNoiseBlankerEnabledCmd(this, &DSPNoiseBlankerView::OnNoiseBlankerEnabled),
	_onNoiseBlankerDisabledCmd(this, &DSPNoiseBlankerView::OnNoiseBlankerDisabled),
	_settingsBackground(0, ROW_HEIGHT, FULL_SCREEN_WIDTH, SETTINGS_SCREEN_HEIGHT,
		BACKGROUND_DARK, nullptr)
{
	_background.SetChild(&_settingsBackground);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPNoiseBlankerView::~DSPNoiseBlankerView()
{
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPNoiseBlankerView::OnNoiseBlankerEnabled(ICheckBox *)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPNoiseBlankerView::OnNoiseBlankerDisabled(ICheckBox *)
{

}

}