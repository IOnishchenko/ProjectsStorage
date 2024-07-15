#ifndef GUI_GERECTANLGE_HPP
#define GUI_GERECTANLGE_HPP

#include "IGElement.hpp"

namespace gui
{
	class GERectangle : public IGElement
	{
	public:	
		
		// fields
		uint32_t Color;

		// constructor
		GERectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color,
			IGElement * nextElement);
		
		// destructor
		~GERectangle() override = default;

		// methods
		void DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer) override;
		uint16_t GetWidth() override;
		uint16_t GetHeight() override;
		void SetWidth(uint16_t width);
		void SetHeight(uint16_t height);

	private:
		int _width;
		int _height;
	};
}

#endif // GUI_GERECTANLGE_HPP