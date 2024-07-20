#ifndef GUI_RGB_RENDERER_HPP
#define GUI_RGB_RENDERER_HPP

#include "IRenderer.hpp"

namespace gui
{
	class RGBRenderer : public IRenderer
	{
	public:
		// constructor
		RGBRenderer();

		// dectructor
		~RGBRenderer() override = default;

		// methods
		void Draw(const GEText * gel, uint16_t x, uint16_t y, bool enabled = true) override;
		void Draw(const GERectangle * gel, uint16_t x, uint16_t y, bool enabled = true) override;
		void Draw(const GEPicture * gel, uint16_t x, uint16_t y, bool enabled = true) override;
		void Draw(const GEPictureMixedWithColor * gel, uint16_t x, uint16_t y, bool enabled = true) override;
		void Draw(const GEPictureMixedWithPicture * gel, uint16_t x, uint16_t y, bool enabled = true) override;
	};
}

#endif // GUI_RGB_RENDERER_HPP