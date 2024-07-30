#ifndef GUI_GFRAME_HPP
#define GUI_GFRAME_HPP

#include "stdint.h"

namespace gui
{
	template<typename TColor>
	struct GFrame
	{
		int16_t X;
		int16_t Y;
		int16_t Width;
		int16_t Height;
		int16_t skippedRows;
		int16_t skippedLines;

		TColot * GRam;
	};
}

#endif // GUI_GFRAME_HPP