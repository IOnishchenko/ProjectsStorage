#include "Picture.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Picture::Picture(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const IUIContext & context, IGElement * gelement)
		:IUIControl(x, y, w, h, context), _gelement{gelement}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * Picture::GetGraphicElement()
	{
		return _gelement;
	}
	
}