#include "DSPSquelchView.hpp"
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
constexpr uint16_t SETTINGS_SCREEN_HEIGHT = SCREEN_HEIGHT-ROW_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPSquelchView::DSPSquelchView(const IUIContext & context)
	:
	DSPAlgorithmViewBase(context, _onSquelchEnabledCmd, _onSquelchDisabledCmd,
	"Disable Squelch:", "Enable Squelch:"),
	_onSquelchEnabledCmd(this, &DSPSquelchView::OnSquelchEnabled),
	_onSquelchDisabledCmd(this, &DSPSquelchView::OnSquelchDisabled),
	_onAGCSquelchLevelChangedCmd(this, &DSPSquelchView::OnSquelchLevelChanged),

	_maxSquelchLevelSlider(FIRST_ROW_Y, FIRST_ROW_Y, 64, 40, context,
		_onAGCSquelchLevelChangedCmd, "Squelch", "Level (dB):", nullptr),

	_settingsBackground(0, 0, FULL_SCREEN_WIDTH, SETTINGS_SCREEN_HEIGHT,
		BACKGROUND_DARK, _maxSquelchLevelSlider.Header),
	_settingsGroup(0, FIRST_ROW_Y, FULL_SCREEN_WIDTH, SETTINGS_SCREEN_HEIGHT, context,
	{
		&_maxSquelchLevelSlider.Text, &_maxSquelchLevelSlider,
	}, &_settingsBackground)
{
	AddChild(&_settingsGroup);
	_enaCheckbox.Uncheck();
	_settingsGroup.SetEnable(false);

	_maxSquelchLevelSlider.Text.SetIntValue(40);
	context.FocusManager->RegisterHandler(100, &_maxSquelchLevelSlider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPSquelchView::~DSPSquelchView()
{
	_context.FocusManager->UnregisterHandler(&_maxSquelchLevelSlider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPSquelchView::OnSquelchEnabled(ICheckBox *)
{
	_settingsGroup.SetEnable(true);
	_settingsGroup.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPSquelchView::OnSquelchDisabled(ICheckBox *)
{
	_settingsGroup.SetEnable(false);
	_settingsGroup.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPSquelchView::OnSquelchLevelChanged(int value)
{
	_maxSquelchLevelSlider.Text.SetIntValue(value);
	_maxSquelchLevelSlider.Text.Draw();
}

}