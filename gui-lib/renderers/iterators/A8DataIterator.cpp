#include "A8DataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void A8DataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
		const PictureObject * object, void * param)
	{
		base::Initialize(srow, slines0, slines1, object, nullptr);
		_foregroundColor = reinterpret_cast<uint32_t>(param);
	}

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t A8DataIterator<TLut>::GetColor()
	{
		return _foregroundColor;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint8_t A8DataIterator<TLut>::GetAlpha()
	{
		return *base::_gdata;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class A8DataIterator<uint8_t>;
	template class A8DataIterator<uint16_t>;
	template class A8DataIterator<uint32_t>;
}