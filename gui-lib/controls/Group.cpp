#include "Group.hpp"
#include "IUIControlRenderer.hpp"

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
		const std::initializer_list<IUIControl *> & items, IGElement * gelement)
		: IUIControl(x, y, w, h, context), Controls{items}, _background{gelement}
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
		for(auto itm = _background; itm; itm = itm->PrepareForDrawing());
		return _background;
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::Draw()
	{
		_context.Renderer.DrawGroup(this);
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::RedrawChildren()
	{
		for(auto & itm : Controls)
		{
			itm->Draw();
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