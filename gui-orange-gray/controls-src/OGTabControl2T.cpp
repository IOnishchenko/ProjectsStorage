#include "OGTabControl2T.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t FULL_WIDTH = 320;
constexpr uint16_t TAB_WIDTH = 160;
constexpr uint16_t TAB_HEIGHT = 24;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGTabControl2T::OGTabControl2T(uint16_t y, uint16_t height, const IUIContext & context,
	const std::string_view & text1, const std::string_view & text2,
	const Action<void(IRadioButton *)> & onTab1Selected,
	const Action<void(IRadioButton *)> & onTab2Selected)
	:
	Group(0, y, FULL_WIDTH, height, context,
	{
		&_group
	}, nullptr),
	_tab1RButton(0, y, text1, context, onTab1Selected),
	_tab2RButton(TAB_WIDTH, y, text2, context, onTab2Selected),
	_group(0, y, FULL_SCREEN_WIDTH, TAB_HEIGHT, context,
	{
		&_tab1RButton, &_tab2RButton
	}, nullptr)
{
	_tab1RButton.SetAsSelectedInitially();
	context.FocusManager->RegisterHandler(100, &_tab2RButton);
	context.FocusManager->RegisterHandler(100, &_tab1RButton);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGTabControl2T::~OGTabControl2T()
{
	_context.FocusManager->UnregisterHandler(&_tab1RButton);
	_context.FocusManager->UnregisterHandler(&_tab2RButton);
}

}