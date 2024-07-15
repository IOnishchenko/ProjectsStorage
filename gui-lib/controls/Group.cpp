#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructors
	//--------------------------------------------------------------------------*/
	Group::Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const std::forward_list<IUIControl *> & content, IGElement * gelement)
		:IUIControl(x, y, w, h, context), _content{content}, _background{gelement}
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Group::Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const std::initializer_list<IUIControl *> & content, IGElement * gelement)
		: IUIControl(x, y, w, h, context), _content{content}, _background{gelement}
	{
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
	void Group::Draw()
	{
		IUIControl::Draw();
		RedrawChildren();
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Group::RedrawChildren()
	{
		for(auto cntr : _content)
		{
			cntr->Draw();
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IUIControl * Group::GetEnabledControlByCoordinate(uint16_t x, uint16_t y)
	{
		for(auto cntr : _content)
		{
			if((cntr->IsEnable()) && (cntr->IsPositionInsideControl(x, y)))
				return cntr;
		}
		return nullptr;
	}
}