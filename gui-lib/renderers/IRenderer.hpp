#ifndef GUI_IRENDERER_HPP
#define GUI_IRENDERER_HPP

#include "stdint.h"

namespace gui
{
	class GEText;
	class GERectangle;
	class GEPicture;
	class GEPictureMixedWithColor;
	class GEPictureMixedWithPicture;

	struct IRenderer
	{
		// dectructor
		virtual ~IRenderer() = default;

		// methods
		virtual void Draw(const GEText * gel, uint16_t x, uint16_t y, bool enabled = true) = 0;
		virtual void Draw(const GERectangle * gel, uint16_t x, uint16_t y, bool enabled = true) = 0;
		virtual void Draw(const GEPicture * gel, uint16_t x, uint16_t y, bool enabled = true) = 0;
		virtual void Draw(const GEPictureMixedWithColor * gel, uint16_t x, uint16_t y, bool enabled = true) = 0;
		virtual void Draw(const GEPictureMixedWithPicture * gel, uint16_t x, uint16_t y, bool enabled = true) = 0;
	};
}

#endif // GUI_IRENDERER_HPP