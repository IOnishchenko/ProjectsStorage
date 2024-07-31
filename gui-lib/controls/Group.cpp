#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructors
	//--------------------------------------------------------------------------*/
	Group::Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement * gelement)
		:IUIControl(x, y, w, h, context), _background{gelement}
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Group::Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement * gelement)
		: IUIControl(x, y, w, h, context), _background{gelement}
	{
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Group::SetEnable(bool state)
	{
		for(auto cntr : Controls)
		{
			cntr->SetEnable(state);
		}
		_enable = state;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Group::SetVisible(bool state)
	{
		for(auto cntr : Controls)
		{
			cntr->SetVisible(state);
		}
		_visible = state;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IGElement * Group::GetGraphicElement()
	{
		return _background;
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::Draw()
	{
		//_context.Renderer.Draw(this);
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::RedrawChildren()
	{
		for(auto & itm : Controls)
		{
			// _context.Renderer.Draw(itm);
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::AddChild(IUIControl * child)
	{
		Controls.push_front(child);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IUIControl * Group::GetEnabledControlByCoordinate(uint16_t x, uint16_t y)
	{
		for(auto itm : Controls)
		{
			if((itm->IsEnable()) && (itm->IsPositionInsideControl(x, y)))
				return itm;
		}
		return nullptr;
	}
}