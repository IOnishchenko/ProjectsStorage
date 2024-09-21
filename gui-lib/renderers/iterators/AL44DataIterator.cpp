#include "AL44DataIterator.hpp"
#include "attributes.h"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
const uint8_t alpha_lut[] GUI_RESOURCE_ATTRIBUTES =
{
	0x00u,0x0Cu,0x19u,0x26u,0x33u,0x40u,0x4Eu,0x5Cu,
	0x6Bu,0x7Au,0x8Bu,0x9Cu,0xAEu,0xC3u,0xDAu,0xFFu
};

namespace gui
{
	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t AL44DataIterator<TLut>::GetColor()
	{
		return base::_lut[*base::_gdata & 0x0f];
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t AL44DataIterator<TLut>::GetAlpha()
	{
		return alpha_lut[*base::_gdata >> 4];
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class AL44DataIterator<uint8_t>;
	template class AL44DataIterator<uint16_t>;
	template class AL44DataIterator<uint32_t>;
}