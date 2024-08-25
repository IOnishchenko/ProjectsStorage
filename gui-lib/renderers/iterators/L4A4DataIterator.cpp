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
	void L4A4DataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0,
		uint16_t slines1, const PictureObject * object)
	{
		_skipedLines = slines1;
		_index = slines0 + srow * object->height;
		const PictureGData * pic = (PictureGData *)object->gdata;
		_lut = (TLut *)pic->lut;
		_gdata = pic->data;
	}

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L4A4DataIterator<TLut>::GetValue()
	{
		uint8_t value = _gdata[_index >> 1];
		value = (_index & 0x01) ? (value >> 4) : (value & 0x0f);
		uint32_t res = _lut[value];
		_index++;
		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L4A4DataIterator<TLut>::JumpToNextRow()
	{
		_index += _skipedLines;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L4A4DataIterator<uint8_t>;
	template class L4A4DataIterator<uint16_t>;
	template class L4A4DataIterator<uint32_t>;
}