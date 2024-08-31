#include "OGTabControl5T.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t TAB_WIDTH = 64;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGTabControl5T::OGTabControl5T(uint16_t y, uint16_t height, const IUIContext & context,
	const std::string_view & text1, const std::string_view & text2,
	const std::string_view & text3, const std::string_view & text4,
	const std::string_view & text5,
	const Action<void(IRadioButton *)> & onTab1Selected,
	const Action<void(IRadioButton *)> & onTab2Selected,
	const Action<void(IRadioButton *)> & onTab3Selected,
	const Action<void(IRadioButton *)> & onTab4Selected,
	const Action<void(IRadioButton *)> & onTab5Selected)
	:
	Group(0, y, FULL_SCREEN_WIDTH, height, context,
	{
		&_group
	}, nullptr),
	_tab1RButton(0, y, text1, context, onTab1Selected),
	_tab2RButton(TAB_WIDTH, y, text2, context, onTab2Selected),
	_tab3RButton(TAB_WIDTH*2, y, text3, context, onTab3Selected),
	_tab4RButton(TAB_WIDTH*3, y, text4, context, onTab4Selected),
	_tab5RButton(TAB_WIDTH*4, y, text5, context, onTab5Selected),
	_group(0, y, FULL_SCREEN_WIDTH, BOTTOM_MENU_HEIGHT, context,
	{
		&_tab1RButton, &_tab2RButton, &_tab3RButton,
		&_tab4RButton, &_tab5RButton,
	}, nullptr)
{
	_tab1RButton.SetAsSelectedInitially();
	context.FocusManager->RegisterHandler(100, &_tab1RButton);
	context.FocusManager->RegisterHandler(100, &_tab2RButton);
	context.FocusManager->RegisterHandler(100, &_tab3RButton);
	context.FocusManager->RegisterHandler(100, &_tab4RButton);
	context.FocusManager->RegisterHandler(100, &_tab5RButton);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGTabControl5T::~OGTabControl5T()
{
	_context.FocusManager->UnregisterHandler(&_tab1RButton);
	_context.FocusManager->UnregisterHandler(&_tab2RButton);
	_context.FocusManager->UnregisterHandler(&_tab3RButton);
	_context.FocusManager->UnregisterHandler(&_tab4RButton);
	_context.FocusManager->UnregisterHandler(&_tab5RButton);
}

}