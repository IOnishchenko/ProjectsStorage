#include "AudioInputLevelsScreen.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 48;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;
constexpr uint16_t MARGIN = 3;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputLevelsScreen::AudioInputLevelsScreen(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_ageEnaCheckbox
	}, &_background),
	_onAGCEnabledCmd(this, &AudioInputLevelsScreen::OnAGCEnabled),
	_onAGCDisabledCmd(this, &AudioInputLevelsScreen::OnAGCDisabled),
	_ageEnaCheckbox(MARGIN, SCREEN_Y+MARGIN, context, _onAGCEnabledCmd, _onAGCDisabledCmd,
	"Disable AGC:", "Enable AGC:"),
	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, nullptr)
{
	context.FocusManager->RegisterHandler(100, &_ageEnaCheckbox);
	_ageEnaCheckbox.Uncheck();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputLevelsScreen::~AudioInputLevelsScreen()
{
	_context.FocusManager->UnregisterHandler(&_ageEnaCheckbox);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputLevelsScreen::OnAGCEnabled(ICheckBox *)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputLevelsScreen::OnAGCDisabled(ICheckBox *)
{

}

}