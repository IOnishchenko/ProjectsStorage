#ifndef GUI_GELEMENT_DECODER_RGB565_HPP
#define GUI_GELEMENT_DECODER_RGB565_HPP

#include "stdint.h"
#include "IGElementDecoder.hpp"
#include "GERectangle.hpp"
#include "GEPicture.hpp"
#include "GEPictureMixedWithColor.hpp"
#include "GEPictureMixedWithPicture.hpp"

namespace gui
{
	class GElementDecoderRGB565 : public IGElementDecoder
	{
	public:
		// constructor
		// GElementDecoderRGB565();

		// destructor
		virtual ~GElementDecoderRGB565() override = default;

		// IGElementDecoder methods
		void Decode(const GERectangle * gel) override;
		void Decode(const GEPicture * gel) override;
		void Decode(const GEPictureMixedWithColor * gel) override;
		void Decode(const GEPictureMixedWithPicture * gel) override;

	private:
		// methods
		uint16_t CalculateColorWithAlpha(uint8_t alpha, uint16_t foreground, uint16_t background);

	};
}

#endif // GUI_GELEMENT_DECODER_RGB565_HPP