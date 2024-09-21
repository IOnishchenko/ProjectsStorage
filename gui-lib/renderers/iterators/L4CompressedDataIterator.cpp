#include "L4CompressedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L4CompressedDataIterator<TLut>::GetColor()
	{
		return base::ReadDataFromLUT();
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t L4CompressedDataIterator<TLut>::GetAlpha()
	{
		return 0xffU;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L4CompressedDataIterator<uint8_t>;
	template class L4CompressedDataIterator<uint16_t>;
	template class L4CompressedDataIterator<uint32_t>;
}