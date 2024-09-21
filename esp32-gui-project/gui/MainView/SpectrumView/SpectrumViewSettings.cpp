#include "SpectrumViewSettings.hpp"

namespace gui
{
/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
constexpr uint16_t MIN_SPECTRUM_HEIGHT = 20u;
constexpr uint16_t MAX_SPECTRUM_HEIGHT = 80u;
constexpr uint16_t SPECTRUN_HEIGHT_TUNING_STEP = 1u;
constexpr uint16_t SPECTRUN_DEFAULT_HEIGHT_INDEX = 30u;

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TColor>
SpectrumViewSettings<TColor>::SpectrumViewSettings()
	:SpectrumHeight(MIN_SPECTRUM_HEIGHT, MAX_SPECTRUM_HEIGHT,
		SPECTRUN_HEIGHT_TUNING_STEP, SPECTRUN_DEFAULT_HEIGHT_INDEX)
{
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template class SpectrumViewSettings<uint8_t>;
template class SpectrumViewSettings<uint16_t>;
template class SpectrumViewSettings<uint32_t>;

}