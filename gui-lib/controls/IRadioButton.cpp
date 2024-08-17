#include "IRadioButton.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	IRadioButton::IRadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const std::initializer_list<IUIControl *> & items, IGElement * gelement)
		:Group(x, y, w, h, context, items, gelement)
	{
		context.TouchScreenObserver->Subscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	IRadioButton::~IRadioButton()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnPress(TouchScreenEven & event)
	{
		// IRadioButtonItem * cntr = static_cast<IRadioButtonItem *>(GetEnabledControlByCoordinate(penInfo.x, penInfo.y));
		// if(cntr && (cntr != _activeControl))
		// {
		// 	cntr->_state = IRadioButtonItem::State::Pressed;
		// 	cntr->Draw();
		// }
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnRelease(TouchScreenEven & event)
	{
		// auto pressedControl = FindItemWithState(IRadioButtonItem::State::Pressed);
		
		// if(!pressedControl)
		// 	return;
		
		// if(_activeControl)
		// {
		// 	auto activeControl = static_cast<IRadioButtonItem*>(_activeControl);
		// 	activeControl->_state = IRadioButtonItem::State::Normal;
		// 	activeControl->Draw();
		// }
		// _activeControl = pressedControl;
		// pressedControl->_state = IRadioButtonItem::State::Selected;
		// pressedControl->Draw();
		// (*pressedControl->OnItemSelected)(pressedControl);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnPenLeave(TouchScreenEven & event)
	{
		auto cntr = FindItemWithState(IRadioButtonItem::State::Pressed);
		if(cntr)
		{
			cntr->_state = IRadioButtonItem::State::Normal;
			cntr->Draw();
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnPenMove(TouchScreenEven & event)
	{
		// auto cntr = FindItemWithState(IRadioButtonItem::State::Pressed);
		// if(cntr && !cntr->IsPositionInsideControl(penInfo.x, penInfo.y))
		// {
		// 	cntr->_state = IRadioButtonItem::State::Normal;
		// 	cntr->Draw();
		// }
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool IRadioButton::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnFocused()
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnFocusLost()
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnKeyPress(KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnKeyRelease(KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::SetSelected(IRadioButtonItem * selected)
	{
		// for(auto item : _content)
		// {
		// 	auto rbutton = static_cast<IRadioButtonItem *>(item);
		// 	rbutton->_state = rbutton == selected
		// 		? IRadioButtonItem::State::Selected
		// 		: IRadioButtonItem::State::Normal;
		// }
		// _activeControl = selected;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::ClearSelection()
	{
		// if(_activeControl)
		// {
		// 	auto itm = static_cast<IRadioButtonItem *>(_activeControl);
		// 	itm->_state = IRadioButtonItem::State::Normal;
		// 	itm->Draw();
		// 	_activeControl = nullptr;
		// }
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IRadioButtonItem * IRadioButton::FindItemWithState(IRadioButtonItem::State state) const
	{
		for(auto cntr : Controls)
		{
			auto item = static_cast<IRadioButtonItem *>(cntr);
			if(item->_state == state)
				return item;
		}
		return nullptr;
	}
}