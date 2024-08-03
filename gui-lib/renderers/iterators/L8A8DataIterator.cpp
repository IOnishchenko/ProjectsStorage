#include "L8A8DataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	L8A8DataIterator<TLut>::L8A8DataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		const PictureObject * object)
		:_skipedLines(slines0 + slines1)
	{
		const PictureGData * pic = (PictureGData *)object->gdata;
		_lut = (TLut *)pic->lut;
		_gdata = pic->data;
		_gdata += slines0 + srow * object->height;
	}

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L8A8DataIterator<TLut>::GetValue()
	{
		uint32_t res = _lut[*_gdata];
		_gdata++;
		return (uint32_t)res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L8A8DataIterator<TLut>::JumpToNextRow()
	{
		_gdata += _skipedLines;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L8A8DataIterator<uint8_t>;
	template class L8A8DataIterator<uint16_t>;
	template class L8A8DataIterator<uint32_t>;
}