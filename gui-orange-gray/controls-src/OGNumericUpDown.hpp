#ifndef GUI_ORANGE_GRAY_NUMERIC_UP_DOWN_HPP
#define GUI_ORANGE_GRAY_NUMERIC_UP_DOWN_HPP

#include "NumericUpDown.hpp"

namespace gui
{
	class OGNumericUpDown : public NumericUpDown
	{
	public:
		// constructor
		OGNumericUpDown(uint16_t x, uint16_t y,	const IUIContext & context,
			const Action<void(const Parameters &)> & valueChanged);

		// destructor
		~OGNumericUpDown() override = default;

	private:
		// fields
		GEPicture _disabledPic;
		GEPicture _enabledPic;
		GEPicture _focusedPic;
		GEPicture _pressedPic;
		GEPicture _selectedPic;
	};
}

#endif // GUI_ORANGE_GRAY_NUMERIC_UP_DOWN_HPP