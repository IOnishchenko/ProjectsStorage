
#include "GElementDecoderRGB565.hpp"
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
		//std::unique_ptr<IDataIterator> iteratorSrc;

		IDataIterator * iteratorSrc;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_L4:
				iteratorSrc = &_l4Iterator;
				_l4Iterator.Initialize(Picture.skippedRows + gel->Foreground.SkippedRows,
					Picture.skippedLinesOnTop + gel->Foreground.SkippedLines,
					Picture.skippedLinesOnBottom + gel->Foreground.Bitmap->height - gel->Height,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L4A4DataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_L8:
				iteratorSrc = &_l8Iterator;
				_l8Iterator.Initialize(Picture.skippedRows + gel->Foreground.SkippedRows,
					Picture.skippedLinesOnTop + gel->Foreground.SkippedLines,
					Picture.skippedLinesOnBottom + gel->Foreground.Bitmap->height - gel->Height,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L8A8DataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESSED_L4:
				iteratorSrc = &_l4CompressedIterator;
				_l4CompressedIterator.Initialize(Picture.skippedRows + gel->Foreground.SkippedRows,
					Picture.skippedLinesOnTop + gel->Foreground.SkippedLines,
					Picture.skippedLinesOnBottom + gel->Foreground.Bitmap->height - gel->Height,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L4A4CompressedDataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESSED_L8:
				iteratorSrc = &_l8CompressedIterator;
				_l8CompressedIterator.Initialize(Picture.skippedRows + gel->Foreground.SkippedRows,
					Picture.skippedLinesOnTop + gel->Foreground.SkippedLines,
					Picture.skippedLinesOnBottom + gel->Foreground.Bitmap->height - gel->Height,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L8A8CompressedDataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
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
				*gdata = (uint16_t)iteratorSrc->GetColor();
				gdata++;
				iteratorSrc->JumpToNextPixel();
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
		IDataIterator * iteratorSrc;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_BITS:
			{
				BitDataIterator::Colors colors =
				{
					gel->Foreground.Color, gel->BackgroundColor
				};
				_bitIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, &colors);
				// std::unique_ptr<BitDataIterator> bitIterator =
				// 	std::make_unique<BitDataIterator>(Picture.skippedRows, Picture.skippedLinesOnTop,
				// 	Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				uint16_t * gdata = (uint16_t *)Frame.gdata;
				for(uint16_t x = 0; x < Picture.width; ++x)
				{
					for(uint16_t y = 0; y < Picture.height; ++y)
					{
						*gdata = _bitIterator.GetColor();
						_bitIterator.JumpToNextPixel();
						gdata++;
					}
					gdata += Frame.skippedLines;
					_bitIterator.JumpToNextRow();
				}
				return;
			}
			case PICTYPE_A4:
				iteratorSrc = &_a4Iterator;
				_a4Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				// iteratorSrc = std::make_unique<L4A4DataIterator<uint8_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESSED_A4:
				iteratorSrc = &_a4CompressedIterator;
				_a4CompressedIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				// iteratorSrc = std::make_unique<L4A4CompressedDataIterator<uint8_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_AL44:
				iteratorSrc = &_al4Iterator;
				_al4Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				break;
			case PICTYPE_A8:
				iteratorSrc = &_a8Iterator;
				_a8Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				break;
			case PICTYPE_COMPRESSED_A8:
				iteratorSrc = &_a8CompressedIterator;
				_a8CompressedIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
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
				uint8_t alpha = iteratorSrc->GetAlpha();
				uint16_t foregroundColor = iteratorSrc->GetColor();
				*gdata = CalculateColorWithAlpha(alpha, foregroundColor, gel->BackgroundColor);
				iteratorSrc->JumpToNextPixel();
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
		IDataIterator * backgroundIterator;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_L4:
				backgroundIterator = &_l4Iterator;
				_l4Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L4A4DataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_L8:
				backgroundIterator = &_l8Iterator;
				_l8Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L8A8DataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESSED_L4:
				backgroundIterator = &_l4CompressedIterator;
				_l4CompressedIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L4A4CompressedDataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESSED_L8:
				backgroundIterator = &_l8CompressedIterator;
				_l8CompressedIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, nullptr);
				// iteratorSrc = std::make_unique<L8A8CompressedDataIterator<uint16_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			default:
				return;
				// NOT IMPLEMENTED
				// TODO
		}

		IDataIterator * foregroundIterator;
		switch(gel->Foreground.Bitmap->coding)
		{
			case PICTYPE_BITS:
			{
				BitDataIterator * bitIterator = &_bitIterator;
				BitDataIterator::Colors colors =
				{
					0x00, 0x00
				};
				_bitIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, &colors);
				// std::unique_ptr<BitDataIterator> bitIterator =
				// 	std::make_unique<BitDataIterator>(Picture.skippedRows, Picture.skippedLinesOnTop,
				// 	Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				uint16_t * gdata = (uint16_t *)Frame.gdata;
				for(uint16_t x = 0; x < Picture.width; ++x)
				{
					for(uint16_t y = 0; y < Picture.height; ++y)
					{
						*gdata = bitIterator->GetAlpha() ?
							gel->Foreground.Color : backgroundIterator->GetColor();
						gdata++;
						bitIterator->JumpToNextPixel();
						backgroundIterator->JumpToNextPixel();
					}
					gdata += Frame.skippedLines;
					backgroundIterator->JumpToNextRow();
					bitIterator->JumpToNextRow();
				}
				return;
			}
			case PICTYPE_A4:
				foregroundIterator = &_a4Iterator;
				_a4Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				// iteratorSrc = std::make_unique<L4A4DataIterator<uint8_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_COMPRESSED_A4:
				foregroundIterator = &_a4CompressedIterator;
				_a4CompressedIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				// iteratorSrc = std::make_unique<L4A4CompressedDataIterator<uint8_t>>(Picture.skippedRows,
				// 	Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom, gel->Foreground.Bitmap);
				break;
			case PICTYPE_AL44:
				foregroundIterator = &_al4Iterator;
				_al4Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				break;
			case PICTYPE_A8:
				foregroundIterator = &_a8Iterator;
				_a8Iterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
				break;
			case PICTYPE_COMPRESSED_A8:
				foregroundIterator = &_a8CompressedIterator;
				_a8CompressedIterator.Initialize(Picture.skippedRows,
					Picture.skippedLinesOnTop, Picture.skippedLinesOnBottom,
					gel->Foreground.Bitmap, reinterpret_cast<void *>(gel->Foreground.Color));
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
				uint16_t background = backgroundIterator->GetColor();
				uint8_t alpha = foregroundIterator->GetAlpha();
				uint16_t foreground = foregroundIterator->GetColor();
				*gdata = CalculateColorWithAlpha(alpha, foreground, background);
				gdata++;
				backgroundIterator->JumpToNextPixel();
				foregroundIterator->JumpToNextPixel();
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
#ifdef GMT020_02_DISPLAY_IS_USED
		// GMT020-02 LCD display requires inverted bits for RGB value
		// Should be removed for other displays
		foreground = ~foreground;
		background = ~background;
#endif // GMT020_02_DISPLAY_IS_USED

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
		rgb |= (g << 3) & 0x07e0u;
		rgb |= (b >> 3);
#ifdef GMT020_02_DISPLAY_IS_USED
		// GMT020-02 LCD display requires inverted bits for RGB value
		// Should be removed for other displays
		return ~rgb;
#else
		return rgb;
#endif // GMT020_02_DISPLAY_IS_USED
	}
}