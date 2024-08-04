#ifndef GUI_GELEMENT_DECODER_RGB565_HPP
#define GUI_GELEMENT_DECODER_RGB565_HPP

#include "stdint.h"
#include "IGElementDecoder.hpp"
#include "GERectangle.hpp"
#include "GEPicture.hpp"
#include "GEPictureMixedWithColor.hpp"
#include "GEPictureMixedWithPicture.hpp"

#include "BitDataIterrator.hpp"
#include "L4A4CompresedDataIterator.hpp"
#include "L4A4DataIterator.hpp"
#include "L8A8CompresedDataIterator.hpp"
#include "L8A8DataIterator.hpp"

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
		BitDataIterator _bitIterator;
		L4A4CompresedDataIterator<uint16_t> _l4CompresedIterator;
		L4A4CompresedDataIterator<uint8_t> _a4CompresedIterator;
		L4A4DataIterator<uint16_t> _l4Iterator;
		L4A4DataIterator<uint8_t> _a4Iterator;
		L8A8CompresedDataIterator<uint16_t> _l8CompresedIterator;
		L8A8CompresedDataIterator<uint8_t> _a8CompresedIterator;
		L8A8DataIterator<uint16_t> _l8Iterator;
		L8A8DataIterator<uint8_t> _alIterator;
	};
}

#endif // GUI_GELEMENT_DECODER_RGB565_HPP