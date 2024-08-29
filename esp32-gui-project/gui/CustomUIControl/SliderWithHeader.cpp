#include "SliderWithHeader.hpp"
#include "Font.hpp"
#include "OGCommon.hpp"

namespace gui
{
namespace custom
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	SliderWithHeader::SliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
		const IUIContext & context, const Action<void(int)> & valueChanged,
		const std::string_view & header, IGElement * gelement)
		:
		OGHorizontalSliderLabel(COLUMN1_X, y+(ROW_HEIGHT - HSLIDER_HEIGHT)/2, COLUMN1_WIDT-MARGIN,
			maxValue, value, context, valueChanged),
		Header{new GEText(COLUMN0_X, y - groupY + GEText::Center_Y(ROW_HEIGHT, Font18),
			COLUMN0_WIDT, TEXT_HEIGHT, header, TEXT_COLOR, BACKGROUND_DARK, Font18, gelement)},
		_secondLineHeader{nullptr}
	{
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	SliderWithHeader::SliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
		const IUIContext & context, const Action<void(int)> & valueChanged,
		const std::string_view & header0, const std::string_view & header1,
		IGElement * gelement)
		:
		OGHorizontalSliderLabel(COLUMN1_X, y+(ROW_HEIGHT - HSLIDER_HEIGHT)/2, COLUMN1_WIDT-MARGIN,
			maxValue, value, context, valueChanged),
		Header{new GEText(COLUMN0_X, y - groupY, COLUMN0_WIDT, TEXT_HEIGHT, header0, TEXT_COLOR,
			BACKGROUND_DARK, Font18, nullptr)},
		_secondLineHeader{new GEText(COLUMN0_X, y - groupY + TEXT_HEIGHT, COLUMN0_WIDT, TEXT_HEIGHT,
			header1, TEXT_COLOR, BACKGROUND_DARK, Font18, gelement)}
	{
		Header->SetChild(_secondLineHeader);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	SliderWithHeader::~SliderWithHeader()
	{
		if(_secondLineHeader)
			delete _secondLineHeader;
		delete Header;
	}
}
}