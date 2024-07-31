#ifndef GUI_UICONTROL_HPP
#define GUI_UICONTROL_HPP

#include "IGElement.hpp"
#include "IUIContext.hpp"
#include "UIControlEvents.hpp"

namespace gui
{	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class IUIControl
	{
	public:

		// position on a screen
		uint16_t X;
		uint16_t Y;
		uint16_t Width;
		uint16_t Height;
		
		// constructor
		IUIControl(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context);

		// destructor
		virtual ~IUIControl() = default;

		// methods
		virtual IGElement * GetGraphicElement() = 0;
		virtual void Draw();
		// common methods
		bool IsEnable() const;
		virtual void SetEnable(bool);
		bool IsVisible() const;
		virtual void SetVisible(bool);
		bool IsPositionInsideControl(uint16_t x, uint16_t y) const;
		bool DoesOverlapRegion(uint16_t x, uint16_t y, uint16_t w, uint16_t h) const;
		
	protected:

		bool _enable;
		bool _visible;
		const IUIContext & _context;
	};
}

#endif // GUI_UICONTROL_HPP