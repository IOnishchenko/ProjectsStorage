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
		for(auto cntr : _content)
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
		for(auto cntr : _content)
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
		_context.Renderer.Draw(this);
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::RedrawChildren()
	{
		for(auto & [x, row] : _content)
		{
			for(auto & [y ,cntr] : row)
			{
				_context.Renderer.Draw(cntr);
			}
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::AddChild(IUIControl * child)
	{
		auto & item = _content[child->X];
		item[child->Y] = child;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IUIControl * Group::GetEnabledControlByCoordinate(uint16_t x, uint16_t y)
	{
		for(auto & [x, row] : _content)
		{
			for(auto & [y ,cntr] : row)
			{
				if((cntr->IsEnable()) && (cntr->IsPositionInsideControl(x, y)))
				return cntr;
			}
		}
		return nullptr;
	}
}