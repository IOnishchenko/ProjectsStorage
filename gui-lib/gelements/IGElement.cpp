#include "IGElement.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	// Base graphic element
	//----------------------------------------------------------------*/
	IGElement::IGElement(uint16_t x, uint16_t y, IGElement * nextElement)
		:X{x}, Y{y}, _gelement{nextElement}
	{
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	IGElement * IGElement::GetChild()
	{
		return _gelement;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IGElement::SetChild(IGElement * child)
	{
		_gelement = child;
	}

	/*----------------------------------------------------------------//
	// Called from UIControl
	//----------------------------------------------------------------*/
	IGElement * IGElement::PrepareForDrawing()
	{
		return _gelement;
	}
}
