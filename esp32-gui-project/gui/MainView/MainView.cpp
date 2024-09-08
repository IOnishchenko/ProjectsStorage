#include "MainView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IEncoderEventManager.hpp"
#include "IKeyboardEventManager.hpp"

#include <cstdio>
#include "dumy_picture.h"
#include "SelectModulationDialog.hpp"
#include "SetReceiverAGCDialog.hpp"
#include "SetVolumeDialog.hpp"
#include "SetFiltersDialog.hpp"
#include "IWindowManager.hpp"

#include "dumy_picture.h"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
MainView::MainView(const IUIContext & context)
	:Group(0, 0, 320, 240-24, context,
	{
		&_button0, &_button1, &_button2, &_button3,
		&_frequencyLabel
	}, &_background),

	_onButton0ClickedCmd(this, &MainView::OnButton0Clicked),
	_onButton1ClickedCmd(this, &MainView::OnButton1Clicked),
	_onButton2ClickedCmd(this, &MainView::OnButton2Clicked),
	_onButton3ClickedCmd(this, &MainView::OnButton3Clicked),

	_onFrequencyChangedCmd(this, &MainView::OnFrequencyChanged),

	_button0(6, 24, "MOD: USB", context, _onButton0ClickedCmd),
	_button1(6, 46, "AGC: 40", context, _onButton1ClickedCmd),
	_button2(6, 68, "BW: 2.75", context, _onButton2ClickedCmd),
	_button3(6, 90, "VOL: 45", context, _onButton3ClickedCmd),

	_frequencyLabel(117, 68, context, _onFrequencyChangedCmd),
	_background(0, 0, 320, 240-24, 0, 0, &gui320x240, nullptr)
{
	context.FocusManager->RegisterHandler(0, &_frequencyLabel);
	context.FocusManager->RegisterHandler(1, &_button0);
	context.FocusManager->RegisterHandler(2, &_button1);
	context.FocusManager->RegisterHandler(3, &_button2);
	context.FocusManager->RegisterHandler(4, &_button3);

	_frequencyLabel.SetIntValue(_frequency, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
MainView::~MainView()
{
	_context.FocusManager->UnregisterHandler(&_frequencyLabel);
	_context.FocusManager->UnregisterHandler(&_button0);
	_context.FocusManager->UnregisterHandler(&_button1);
	_context.FocusManager->UnregisterHandler(&_button2);
	_context.FocusManager->UnregisterHandler(&_button3);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainView::OnButton0Clicked(IButton *)
{
	_context.WindowManager.OpenDialogWindow<SelectModulationDialog>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainView::OnButton1Clicked(IButton *)
{
	_context.WindowManager.OpenDialogWindow<SetReceiverAGCDialog>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainView::OnButton2Clicked(IButton *)
{
	_context.WindowManager.OpenDialogWindow<SetFiltersDialog>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainView::OnButton3Clicked(IButton *)
{
	_context.WindowManager.OpenDialogWindow<SetVolumeDialog>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainView::OnFrequencyChanged(const NumericUpDown::Parameters & params)
{
	(params.EventType == NumericUpDown::Direction::Increase) ?
		_frequency++ : _frequency--;

	_frequencyLabel.SetIntValue(_frequency, "Hz");
	_frequencyLabel.Draw();
}

}