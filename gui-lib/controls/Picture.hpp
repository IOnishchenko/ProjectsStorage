#ifndef GUI_PICTURE_HPP
#define GUI_PICTURE_HPP

#include "IUIControl.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class Picture : public IUIControl
	{
	public:
		// constructor
		Picture(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
			const IUIContext & context, IGElement * gelement);

		// destructor
		~Picture() override = default;
	
		// method
		IGElement * GetGraphicElement() override;
		
	protected:
		IGElement * _gelement;
	};
}

#endif // PICTURE_H