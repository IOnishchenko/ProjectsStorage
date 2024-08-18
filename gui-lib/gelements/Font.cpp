#include "Font.hpp"
#include <cstdio>

namespace gui
{
	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	Font::Font(const PictureObject * const * fontGraphicData)
		: _fontGraphicData{fontGraphicData}
	{
	}
}