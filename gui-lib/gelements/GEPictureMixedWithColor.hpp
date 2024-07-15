#ifndef GUI_GEPICTURE_MIXED_WITH_COLOR_HPP
#define GUI_GEPICTURE_MIXED_WITH_COLOR_HPP

#include "GEPicture.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	// Abstract class
	//----------------------------------------------------------------*/
	class GEMixedPictureWithColor : public GEPicture
	{
	public:
		
		// fields
		uint32_t BackgroundColor;

		// constructor 
		GEMixedPictureWithColor(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t skippedLines, uint16_t skippedRows, const PictureDataItem &bitmap,
			uint32_t backgroundColor, IGElement * nextElemen);

		GEMixedPictureWithColor(const PictureDataItem &bitmap, uint32_t backgroundColor,
			IGElement * nextElemen);

		// destructor
		~GEMixedPictureWithColor() override = default;

		// methods
		void DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer) override;
		void SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows,
			uint16_t width,uint16_t height) override;
	};
} // namespace gui


#endif // GUI_GEPICTURE_MIXED_WITH_COLOR_HPP