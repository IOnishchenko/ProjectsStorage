#include "L8CompressedDataIterator.hpp"

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
	uint32_t L8CompressedDataIterator<TLut>::GetColor()
	{
		return base::ReadDataFromLut();
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t L8CompressedDataIterator<TLut>::GetAlpha()
	{
		return 0xffU;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L8CompressedDataIterator<uint8_t>;
	template class L8CompressedDataIterator<uint16_t>;
	template class L8CompressedDataIterator<uint32_t>;
}