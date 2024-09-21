#ifndef GUI_GELEMENT_DECODER_RGB565_HPP
#define GUI_GELEMENT_DECODER_RGB565_HPP

#include "stdint.h"
#include "IGElementDecoder.hpp"
#include "GERectangle.hpp"
#include "GEPicture.hpp"
#include "GEPictureMixedWithColor.hpp"
#include "GEPictureMixedWithPicture.hpp"

#include "A4CompressedDataIterator.hpp"
#include "A4DataIterator.hpp"
#include "A8CompressedDataIterator.hpp"
#include "A8DataIterator.hpp"
#include "AL44DataIterator.hpp"
#include "BitDataIterator.hpp"
#include "L4CompressedDataIterator.hpp"
#include "L4DataIterator.hpp"
#include "L8CompressedDataIterator.hpp"
#include "L8DataIterator.hpp"

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

		// fields
		A4CompressedDataIterator<uint8_t> _a4CompressedIterator;
		A4DataIterator<uint8_t> _a4Iterator;
		A8CompressedDataIterator<uint8_t> _a8CompressedIterator;
		A8DataIterator<uint8_t> _a8Iterator;
		AL44DataIterator<uint16_t> _al4Iterator;
		BitDataIterator _bitIterator;
		L4CompressedDataIterator<uint16_t> _l4CompressedIterator;
		L4DataIterator<uint16_t> _l4Iterator;
		L8CompressedDataIterator<uint16_t> _l8CompressedIterator;
		L8DataIterator<uint16_t> _l8Iterator;
	};
}

#endif // GUI_GELEMENT_DECODER_RGB565_HPP