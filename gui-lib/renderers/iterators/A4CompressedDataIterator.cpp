#include "A4CompressedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void A4CompressedDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
		const PictureObject * object, void * param)
	{
		base::Initialize(srow, slines0, slines1, object, nullptr);
		_foregroundColor = reinterpret_cast<uint32_t>(param);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t A4CompressedDataIterator<TLut>::GetColor()
	{
		return _foregroundColor;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t A4CompressedDataIterator<TLut>::GetAlpha()
	{
		return base::ReadDataFromLUT();
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class A4CompressedDataIterator<uint8_t>;
	template class A4CompressedDataIterator<uint16_t>;
	template class A4CompressedDataIterator<uint32_t>;
}