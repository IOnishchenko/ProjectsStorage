#include "DSPAGCView.hpp"
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
DSPAGCView::DSPAGCView(const IUIContext & context)
	:
	DSPAlgorithmViewBase(context, _onAGCEnabledCmd, _onAGCDisabledCmd,
	"Disable Auto Gain Control:", "Enable Auto Gain Control:"),
	_onAGCEnabledCmd(this, &DSPAGCView::OnAGCEnabled),
	_onAGCDisabledCmd(this, &DSPAGCView::OnAGCDisabled),
	_onAGCMaxGainChangedCmd(this, &DSPAGCView::OnAGCMaxGainChanged),
	_onNoiseLevelChangedCmd(this, &DSPAGCView::OnNoiseLevelChanged),

	_maxAGCGainSlider(FIRST_ROW_Y, FIRST_ROW_Y, 64, 40, context, _onAGCMaxGainChangedCmd,
		"Maximum", "Gain (dB):", nullptr),
	_maxNoiseLevelSlider(FIRST_ROW_Y, SECOND_ROW_Y, 32, 16, context, _onNoiseLevelChangedCmd,
		"Noise", "Level (dB):", _maxAGCGainSlider.Header),
	_settingsBackground(0, 0, FULL_SCREEN_WIDTH, SETTINGS_SCREEN_HEIGHT,
		BACKGROUND_DARK, _maxNoiseLevelSlider.Header),
	_settingsGroup(0, FIRST_ROW_Y, FULL_SCREEN_WIDTH, SETTINGS_SCREEN_HEIGHT, context,
	{
		&_maxAGCGainSlider.Text, &_maxAGCGainSlider,
		&_maxNoiseLevelSlider.Text, &_maxNoiseLevelSlider,
	}, &_settingsBackground)
{
	AddChild(&_settingsGroup);
	_enaCheckbox.Check();
	_settingsGroup.SetEnable(true);

	_maxAGCGainSlider.Text.SetIntValue(40);
	_maxNoiseLevelSlider.Text.SetIntValue(16);

	context.FocusManager->RegisterHandler(100, &_maxAGCGainSlider);
	context.FocusManager->RegisterHandler(100, &_maxNoiseLevelSlider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPAGCView::~DSPAGCView()
{
	_context.FocusManager->UnregisterHandler(&_maxAGCGainSlider);
	_context.FocusManager->UnregisterHandler(&_maxNoiseLevelSlider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAGCView::OnAGCEnabled(ICheckBox *)
{
	
	_settingsGroup.SetEnable(true);
	_settingsGroup.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAGCView::OnAGCDisabled(ICheckBox *)
{
	_settingsGroup.SetEnable(false);
	_settingsGroup.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAGCView::OnAGCMaxGainChanged(int value)
{
	_maxAGCGainSlider.Text.SetIntValue(value);
	_maxAGCGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAGCView::OnNoiseLevelChanged(int value)
{
	_maxNoiseLevelSlider.Text.SetIntValue(value);
	_maxNoiseLevelSlider.Text.Draw();
}

}