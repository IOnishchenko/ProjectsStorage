#include "RadioButton.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	RadioButton::RadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const std::forward_list<IUIControl *> & items, IGElement * gelement)
		:Group(x, y, w, h, context, items, gelement)
	{
		context.TouchScreenObserver->Subscribe(this);
	}

	RadioButton::RadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const std::initializer_list<IUIControl *> & items, IGElement * gelement)
		:Group(x, y, w, h, context, items, gelement)
	{
		context.TouchScreenObserver->Subscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	RadioButton::~RadioButton()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnPress(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		// RadioButtonItem * cntr = static_cast<RadioButtonItem *>(GetEnabledControlByCoordinate(penInfo.x, penInfo.y));
		// if(cntr && (cntr != _activeControl))
		// {
		// 	cntr->_state = RadioButtonItem::State::Pressed;
		// 	cntr->Draw();
		// }
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		// auto pressedControl = FindItemWithState(RadioButtonItem::State::Pressed);
		
		// if(!pressedControl)
		// 	return;
		
		// if(_activeControl)
		// {
		// 	auto activeControl = static_cast<RadioButtonItem*>(_activeControl);
		// 	activeControl->_state = RadioButtonItem::State::Normal;
		// 	activeControl->Draw();
		// }
		// _activeControl = pressedControl;
		// pressedControl->_state = RadioButtonItem::State::Selected;
		// pressedControl->Draw();
		// (*pressedControl->OnItemSelected)(pressedControl);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		auto cntr = FindItemWithState(RadioButtonItem::State::Pressed);
		if(cntr)
		{
			cntr->_state = RadioButtonItem::State::Normal;
			cntr->Draw();
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnPenMove(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		// auto cntr = FindItemWithState(RadioButtonItem::State::Pressed);
		// if(cntr && !cntr->IsPositionInsideControl(penInfo.x, penInfo.y))
		// {
		// 	cntr->_state = RadioButtonItem::State::Normal;
		// 	cntr->Draw();
		// }
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool RadioButton::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnFocused(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnFocusLost(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnKeyPress(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::SetSelected(RadioButtonItem * selected)
	{
		// for(auto item : _content)
		// {
		// 	auto rbutton = static_cast<RadioButtonItem *>(item);
		// 	rbutton->_state = rbutton == selected
		// 		? RadioButtonItem::State::Selected
		// 		: RadioButtonItem::State::Normal;
		// }
		// _activeControl = selected;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void RadioButton::ClearSelection()
	{
		// if(_activeControl)
		// {
		// 	auto itm = static_cast<RadioButtonItem *>(_activeControl);
		// 	itm->_state = RadioButtonItem::State::Normal;
		// 	itm->Draw();
		// 	_activeControl = nullptr;
		// }
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	RadioButtonItem * RadioButton::FindItemWithState(RadioButtonItem::State state) const
	{
		for(auto cntr : _content)
		{
			auto item = static_cast<RadioButtonItem *>(cntr);
			if(item->_state == state)
				return item;
		}
		return nullptr;
	}
}