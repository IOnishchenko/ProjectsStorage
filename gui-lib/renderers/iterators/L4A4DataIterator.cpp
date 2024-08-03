#include "L4A4DataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	L4A4DataIterator<TLut>::L4A4DataIterator(uint16_t srow, uint16_t slines0,
		uint16_t slines1, const PictureObject * object)
		:_skipedLines(slines0 + slines1)
	{
		_index = slines0;
		const PictureGData * pic = (PictureGData *)object->gdata;
		_lut = (TLut *)pic->lut;
		_gdata = pic->data;
		_gdata += (slines0 + srow * object->height) >> 1;
	}

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L4A4DataIterator<TLut>::GetValue()
	{
		uint8_t value = *_gdata;
		value = (_index & 0x0001) ? (value >> 4) : (value & 0x0f);
		uint32_t res = _lut[value];

		_index++;
		if(!(_index & 0x01))
			_gdata++;

		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L4A4DataIterator<TLut>::JumpToNextRow()
	{
		_index += _skipedLines;
		_gdata += _skipedLines >> 1;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L4A4DataIterator<uint8_t>;
	template class L4A4DataIterator<uint16_t>;
	template class L4A4DataIterator<uint32_t>;
}