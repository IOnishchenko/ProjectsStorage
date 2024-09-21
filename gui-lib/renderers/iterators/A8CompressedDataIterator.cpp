#include "A8CompressedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void A8CompressedDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0,
		uint16_t slines1, const PictureObject * object, void * param)
	{
		base::Initialize(srow, slines0, slines1, object, nullptr);
		_foregroundColor = reinterpret_cast<uint32_t>(param);
	}

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t A8CompressedDataIterator<TLut>::GetColor()
	{
		return _foregroundColor;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t A8CompressedDataIterator<TLut>::GetAlpha()
	{
		return base::ReadDataFromLut();
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class A8CompressedDataIterator<uint8_t>;
	template class A8CompressedDataIterator<uint16_t>;
	template class A8CompressedDataIterator<uint32_t>;
}