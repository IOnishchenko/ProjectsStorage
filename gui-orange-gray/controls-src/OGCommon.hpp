#ifndef GUI_ORANGE_GRAY_COMMON_HPP
#define GUI_ORANGE_GRAY_COMMON_HPP

#include "stdint.h"
#include "Font.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	extern Font Font15;
	extern Font Font18;
	extern Font Font24;
	extern Font Font32;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint32_t TEXT_COLOR_RGB888 = 0xff9302;
	constexpr uint32_t BACKGROUND_DARK_RGB888 = 0x212b2d;
	constexpr uint32_t BACKGROUND_GRAY_RGB888 = 0x3d5a68;
	constexpr uint32_t BACKGROUND_LIGHT_RGB888 = 0x5586a6;
	constexpr uint32_t BACKGROUND_DISABLED_RGB888 = 0x3d5a68;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t TEXT_COLOR = (uint16_t)~(((TEXT_COLOR_RGB888 >> 8) & 0xf800) |
		((TEXT_COLOR_RGB888 >> 5) & 0x07e0) | ((TEXT_COLOR_RGB888 >> 3) & 0x001f));
	
	constexpr uint16_t TEXT_COLOR_LIGHT = (uint16_t)~(((BACKGROUND_LIGHT_RGB888 >> 8) & 0xf800) |
		((BACKGROUND_LIGHT_RGB888 >> 5) & 0x07e0) | ((BACKGROUND_LIGHT_RGB888 >> 3) & 0x001f));

	constexpr uint16_t TEXT_COLOR_DISABLED = (uint16_t)~(((0 >> 8) & 0xf800) |
		((0 >> 5) & 0x07e0) | ((0 >> 3) & 0x001f));

	constexpr uint16_t BACKGROUND_DARK = (uint16_t)~(((BACKGROUND_DARK_RGB888 >> 8) & 0xf800) |
		((BACKGROUND_DARK_RGB888 >> 5) & 0x07e0) | ((BACKGROUND_DARK_RGB888 >> 3) & 0x001f));

	constexpr uint16_t BACKGROUND_GRAY = (uint16_t)~(((BACKGROUND_GRAY_RGB888 >> 8) & 0xf800) |
		((BACKGROUND_GRAY_RGB888 >> 5) & 0x07e0) | ((BACKGROUND_GRAY_RGB888 >> 3) & 0x001f));

	constexpr uint16_t BACKGROUND_LIGHT = (uint16_t)~(((BACKGROUND_LIGHT_RGB888 >> 8) & 0xf800) |
		((BACKGROUND_LIGHT_RGB888 >> 5) & 0x07e0) | ((BACKGROUND_LIGHT_RGB888 >> 3) & 0x001f));

	constexpr uint16_t BACKGROUND_DISABLED = (uint16_t)~(((BACKGROUND_DISABLED_RGB888 >> 8) & 0xf800) |
		((BACKGROUND_DISABLED_RGB888 >> 5) & 0x07e0) | ((BACKGROUND_DISABLED_RGB888 >> 3) & 0x001f));

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
}

#endif // GUI_ORANGE_GRAY_COMMON_HPP