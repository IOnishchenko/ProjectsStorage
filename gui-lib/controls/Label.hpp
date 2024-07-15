#ifndef GUI_LABEL_HPP
#define GUI_LABEL_HPP

#include "IUIControl.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include <string>

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class Label : public IUIControl
	{
	public:
		// constructor
		Label(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint32_t foregroundRGB, uint32_t backgroundRGB, const Font & font, uint16_t textOffset = 0);
		
		// destructor
		~Label() override = default;

		// methods
		void SetFloatValueToLabelWithSuffix(float value, const std::string & unit, int precision, bool alwaysDotVisible);
		virtual void SetFloatValueToLabe(float value, int precision, bool alwaysDotVisible);
		virtual void SetIntValueToLabel(int value);
		IGElement * GetGraphicElement() override;

		// operators
		Label& operator=(const char * txt);
		Label& operator=(const std::string & txt);
		Label& operator=(const std::string_view & txt);
		
	protected:
		GERectangle _background;
		GEText _textGelement;
		std::string _text;
		void PrepareStringData(float value, int precision, bool alwaysDotVisible);
	};
}

#endif // LABEL_H