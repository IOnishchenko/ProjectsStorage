#ifndef GUI_GRAPHIC_ELEMENT_BASE_H
#define GUI_GRAPHIC_ELEMENT_BASE_H

#include "stdint.h"
#include "IGElementDecoder.hpp"

namespace gui
{	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class IGElement
	{
	public:

		// fields
		// position inside IUIControl
		uint16_t X;
		uint16_t Y;
		
		// constructor
		IGElement(uint16_t x, uint16_t y, IGElement *child);

		// destructor
		virtual ~IGElement() = default;
	
		// public methods
		virtual uint16_t GetWidth() = 0;
		virtual uint16_t GetHeight() = 0;
		virtual void DecodeWithDecoder(IGElementDecoder & decoder) = 0;

		virtual IGElement * GetChild();
		virtual void SetChild(IGElement * child);
		virtual IGElement * PrepareForDrawing();
			
	protected:

		// graphic element that will be draw after this element
		IGElement * _gelement;  
	};
}

#endif // GUI_GRAPHIC_ELEMENT_BASE_H