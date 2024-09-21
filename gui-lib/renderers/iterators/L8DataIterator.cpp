#include "L8DataIterator.hpp"

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
	uint32_t L8DataIterator<TLut>::GetColor()
	{
		return base::ReadDataFromLut();
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t L8DataIterator<TLut>::GetAlpha()
	{
		return 0xffu;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L8DataIterator<uint8_t>;
	template class L8DataIterator<uint16_t>;
	template class L8DataIterator<uint32_t>;
}