#include "L4DataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L4DataIterator<TLut>::GetColor()
	{
		return base::ReadDataFromLUT();
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t L4DataIterator<TLut>::GetAlpha()
	{
		return 0xff;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L4DataIterator<uint8_t>;
	template class L4DataIterator<uint16_t>;
	template class L4DataIterator<uint32_t>;
}