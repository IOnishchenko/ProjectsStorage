
#include "GElementDecoderRGB565.hpp"

#include "IDataIterator.hpp"
#include "BitDataIterrator.hpp"
#include "L4A4CompresedDataIterator.hpp"
#include "L4A4DataIterator.hpp"
#include "L8A8CompresedDataIterator.hpp"
#include "L8A8DataIterator.hpp"

#include "stdint.h"
#include <memory>
#include "gui_resource_types.h"

namespace gui
{
	// IGElementDecoder methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void GElementDecoderRGB565::Decode(const GERectangle * gel)
	{
		uint16_t * gdata = (uint16_t *)Frame.gdata;
		for(uint16_t x = 0; x < Picture.width; ++x)
		{
			for(uint16_t y = 0; y < Picture.height; ++y)
			{
				*gdata++ = gel->Color;
			}
			gdata += Frame.skippedLines;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void GElementDecoderRGB565::Decode(const GEPicture * gel)
	{
		std::unique_ptr<IDataIterator> iteratorSrc;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_L4:
				iteratorSrc = std::make_unique<L4A4DataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_L8:
				iteratorSrc = std::make_unique<L8A8DataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESED_L4:
				iteratorSrc = std::make_unique<L4A4CompresedDataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;;
			case PICTYPE_COMPRESED_L8:
				iteratorSrc = std::make_unique<L8A8CompresedDataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			default:
				return;
				// NOT IMPLEMENTED
				// TODO
		}

		uint16_t * gdata = (uint16_t *)Frame.gdata;
		for(uint16_t x = 0; x < Picture.width; ++x)
		{
			for(uint16_t y = 0; y < Picture.height; ++y)
			{
				*gdata = (uint16_t)iteratorSrc->GetValue();
				gdata++;
			}
			gdata += Frame.skippedLines;
			iteratorSrc->JumpToNextRow();
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void GElementDecoderRGB565::Decode(const GEPictureMixedWithColor * gel)
	{
		std::unique_ptr<IDataIterator> iteratorSrc;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_BITS:
			{
				std::unique_ptr<BitDataIterator> bitIterator =
					std::make_unique<BitDataIterator>(Picture.skippedRows, Picture.skippedLinesOnTop,
					Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				uint16_t * gdata = (uint16_t *)Frame.gdata;
				for(uint16_t x = 0; x < Picture.width; ++x)
				{
					for(uint16_t y = 0; y < Picture.height; ++y)
					{
						*gdata = bitIterator->GetValue() ? gel->Foreground.Color : gel->BackgroundColor;
						gdata++;
					}
					gdata += Frame.skippedLines;
					bitIterator->JumpToNextRow();
				}
				return;
			}
			case PICTYPE_A4:
				iteratorSrc = std::make_unique<L4A4DataIterator<uint8_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESED_A4:
				iteratorSrc = std::make_unique<L4A4CompresedDataIterator<uint8_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			default:
				return;
				// NOT IMPLEMENTED
				// TODO
		}

		uint16_t * gdata = (uint16_t *)Frame.gdata;
		for(uint16_t x = 0; x < Picture.width; ++x)
		{
			for(uint16_t y = 0; y < Picture.height; ++y)
			{
				uint8_t alpha = iteratorSrc->GetValue();
				*gdata = CalculateColorWithAlpha(alpha, gel->Foreground.Color, gel->BackgroundColor);
				gdata++;
			}
			gdata += Frame.skippedLines;
			iteratorSrc->JumpToNextRow();
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void GElementDecoderRGB565::Decode(const GEPictureMixedWithPicture * gel)
	{
		std::unique_ptr<IDataIterator> backgroundIterator;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_L4:
				backgroundIterator = std::make_unique<L4A4DataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_L8:
				backgroundIterator = std::make_unique<L8A8DataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESED_L4:
				backgroundIterator = std::make_unique<L4A4CompresedDataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;;
			case PICTYPE_COMPRESED_L8:
				backgroundIterator = std::make_unique<L8A8CompresedDataIterator<uint16_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			default:
				return;
				// NOT IMPLEMENTED
				// TODO
		}

		std::unique_ptr<IDataIterator> foregroundIterator;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_BITS:
			{
				std::unique_ptr<BitDataIterator> bitIterator =
					std::make_unique<BitDataIterator>(Picture.skippedRows, Picture.skippedLinesOnTop,
					Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				uint16_t * gdata = (uint16_t *)Frame.gdata;
				for(uint16_t x = 0; x < Picture.width; ++x)
				{
					for(uint16_t y = 0; y < Picture.height; ++y)
					{
						uint16_t background = backgroundIterator->GetValue();
						*gdata = bitIterator->GetValue() ? gel->Foreground.Color : background;
						gdata++;
					}
					gdata += Frame.skippedLines;
					backgroundIterator->JumpToNextRow();
					bitIterator->JumpToNextRow();
				}
				return;
			}
			case PICTYPE_A4:
				foregroundIterator = std::make_unique<L4A4DataIterator<uint8_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESED_A4:
				foregroundIterator = std::make_unique<L4A4CompresedDataIterator<uint8_t>>(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			default:
				return;
				// NOT IMPLEMENTED
				// TODO
		}

		uint16_t * gdata = (uint16_t *)Frame.gdata;
		for(uint16_t x = 0; x < Picture.width; ++x)
		{
			for(uint16_t y = 0; y < Picture.height; ++y)
			{
				uint16_t background = backgroundIterator->GetValue();
				uint8_t alpha = foregroundIterator->GetValue();
				*gdata = CalculateColorWithAlpha(alpha, gel->Foreground.Color, background);
				gdata++;
			}
			gdata += Frame.skippedLines;
			backgroundIterator->JumpToNextRow();
			foregroundIterator->JumpToNextRow();
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	uint16_t GElementDecoderRGB565::CalculateColorWithAlpha(uint8_t alpha, uint16_t foreground, uint16_t background)
	{
		uint16_t fr = (foreground >> 8) & 0xf8U;
		fr |= fr >> 5;
		uint16_t fg = (foreground >> 3) & 0xfcU;
		fg |= fg >> 6;
		uint16_t fb = (foreground << 3) & 0xf8U;
		fb |= fb >> 5;

		uint16_t br = (background >> 8) & 0xf8U;
		br |= br >> 5;
		uint16_t bg = (background >> 3) & 0xfcU;
		bg |= bg >> 6;
		uint16_t bb = (background << 3) & 0xf8U;
		bb |= bb >> 5;

		// mix colors
		uint16_t r = (fr * alpha + br * 255u - br * alpha)/255u;
		uint16_t g = (fg * alpha + bg * 255u - bg * alpha)/255u;
		uint16_t b = (fb * alpha + bb * 255u - bb * alpha)/255u;

		uint16_t rgb = (r << 8) & 0xf800u;
		rgb |= (g << 3) & 0x03e0u;
		rgb |= (b >> 3);

		return rgb;
	}
}