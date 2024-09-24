#include "AudioInputLevelsView.hpp"
#include "AudioInputAGCSettingsView.hpp"
#include "AudioInputManualSettingsView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT * 2;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputLevelsView::AudioInputLevelsView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_agcEnaCheckbox
	}, &_background),
	_onAGCEnabledCmd(this, &AudioInputLevelsView::OnAGCEnabled),
	_onAGCDisabledCmd(this, &AudioInputLevelsView::OnAGCDisabled),
	_agcEnaCheckbox(COLUMN0_X, SCREEN_Y+(ROW_HEIGHT-TEXT_HEIGHT)/2, context, 
		_onAGCEnabledCmd, _onAGCDisabledCmd, "Disable AGC:", "Enable AGC:"),
	_background(0, 0, FULL_SCREEN_WIDTH, ROW_HEIGHT, BACKGROUND_DARK, nullptr),
	_subGroup{new AudioInputManualSettingsView(context)}
{
	context.FocusManager->RegisterHandler(9, &_agcEnaCheckbox);
	_agcEnaCheckbox.Uncheck();
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputLevelsView::~AudioInputLevelsView()
{
	_context.FocusManager->UnregisterHandler(&_agcEnaCheckbox);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputLevelsView::OnAGCEnabled(ICheckBox *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioInputAGCSettingsView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputLevelsView::OnAGCDisabled(ICheckBox *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioInputManualSettingsView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}