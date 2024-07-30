#ifndef GUI_GEPICTURE_MIXED_WITH_COLOR_HPP
#define GUI_GEPICTURE_MIXED_WITH_COLOR_HPP

#include "GEPicture.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	// Abstract class
	//----------------------------------------------------------------*/
	class GEPictureMixedWithColor : public GEPicture
	{
	public:
		
		// fields
		uint32_t BackgroundColor;

		// constructor
		// L4, L8 pictures
		GEPictureMixedWithColor(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t skippedLines, uint16_t skippedRows, const PictureObject * bitmap,
			uint32_t backgroundColor, IGElement * nextElement);
		// L4, L8 pictures
		GEPictureMixedWithColor(const PictureObject * bitmap, uint32_t backgroundColor,
			IGElement * nextElemen);

		// A4, A8 pictures
		GEPictureMixedWithColor(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t skippedLines, uint16_t skippedRows, const PictureObject * bitmap,
			uint32_t foregroundColor, uint32_t backgroundColor, IGElement * nextElement);
		// A4, A8 pictures
		GEPictureMixedWithColor(const PictureObject * bitmap,
			uint32_t foregroundColor, uint32_t backgroundColor, IGElement * nextElemen);

		// destructor
		~GEPictureMixedWithColor() override = default;

		// methods
		void SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows,
			uint16_t width,uint16_t height) override;
	};
} // namespace gui


#endif // GUI_GEPICTURE_MIXED_WITH_COLOR_HPP