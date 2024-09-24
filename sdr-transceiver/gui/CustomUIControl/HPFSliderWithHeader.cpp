#include "HPFSliderWithHeader.hpp"
#include "Font.hpp"
#include "OGCommon.hpp"

namespace gui
{
namespace custom
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	constexpr uint16_t TEXT_WIDTH = 60;
	constexpr uint16_t SLIDER_WIDTH = COLUMN1_WIDT-MARGIN-TEXT_WIDTH;
	constexpr uint16_t LINE_HEIGHT = 2;
	constexpr uint16_t HPFSLIDER_HEIGHT = 18;
	
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	HPFSliderWithHeader::HPFSliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
		const IUIContext & context, const Action<void(int)> & valueChanged,
		const std::string_view & header, IGElement * gelement)
		:
		HPFSlider(COLUMN1_X+TEXT_WIDTH+MARGIN, y+(ROW_HEIGHT-HPFSLIDER_HEIGHT-LINE_HEIGHT)/2,
			SLIDER_WIDTH, maxValue, value, context, valueChanged),
		
		Text(COLUMN1_X, y+(ROW_HEIGHT-HPFSLIDER_HEIGHT)/2, TEXT_WIDTH,
			Font::GetCharacterHeightInPixels(Font18), context, TEXT_COLOR_DISABLED,
			BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		Header{new GEText(COLUMN0_X, y - groupY + GEText::Center_Y(ROW_HEIGHT, Font18),
			COLUMN0_WIDT, TEXT_HEIGHT, header, TEXT_COLOR, BACKGROUND_DARK, Font18, &_lineBackground)},
		_secondLineHeader{nullptr},

		_lineBackground(COLUMN1_X+TEXT_WIDTH+MARGIN, y+(ROW_HEIGHT+HPFSLIDER_HEIGHT-LINE_HEIGHT)/2,
			SLIDER_WIDTH, LINE_HEIGHT, BACKGROUND_LIGHT, gelement)
	{
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	HPFSliderWithHeader::HPFSliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
		const IUIContext & context, const Action<void(int)> & valueChanged,
		const std::string_view & header0, const std::string_view & header1,
		IGElement * gelement)
		:
		HPFSlider(COLUMN1_X+TEXT_WIDTH+MARGIN, y+(ROW_HEIGHT-HPFSLIDER_HEIGHT-LINE_HEIGHT)/2,
			SLIDER_WIDTH, maxValue, value, context, valueChanged),

		Text(COLUMN1_X, y+(ROW_HEIGHT-HPFSLIDER_HEIGHT)/2, TEXT_WIDTH,
			Font::GetCharacterHeightInPixels(Font18), context, TEXT_COLOR_DISABLED,
			BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		Header{new GEText(COLUMN0_X, y - groupY, COLUMN0_WIDT, TEXT_HEIGHT, header0, TEXT_COLOR,
			BACKGROUND_DARK, Font18, nullptr)},
		_secondLineHeader{new GEText(COLUMN0_X, y - groupY + TEXT_HEIGHT, COLUMN0_WIDT, TEXT_HEIGHT,
			header1, TEXT_COLOR, BACKGROUND_DARK, Font18, &_lineBackground)},
		
		_lineBackground(COLUMN1_X+TEXT_WIDTH+MARGIN, y-groupY+(ROW_HEIGHT+HPFSLIDER_HEIGHT-LINE_HEIGHT)/2,
			SLIDER_WIDTH, LINE_HEIGHT, BACKGROUND_LIGHT, gelement)
	{
		Header->SetChild(_secondLineHeader);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	HPFSliderWithHeader::~HPFSliderWithHeader()
	{
		if(_secondLineHeader)
			delete _secondLineHeader;
		delete Header;
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void HPFSliderWithHeader::SetEnable(bool ena)
	{
		if(ena)
		{
			Header->Foreground.Color = TEXT_COLOR;
			if(_secondLineHeader)
				_secondLineHeader->Foreground.Color = TEXT_COLOR;
		}
		else
		{
			Header->Foreground.Color = TEXT_COLOR_DISABLED;
			if(_secondLineHeader)
				_secondLineHeader->Foreground.Color = TEXT_COLOR_DISABLED;
		}
		HPFSlider::SetEnable(ena);
	}

}
}