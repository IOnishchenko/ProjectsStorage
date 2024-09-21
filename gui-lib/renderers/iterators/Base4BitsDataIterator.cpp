#include "Base4BitsDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base4BitsDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0,
		uint16_t slines1, const PictureObject * object, void *)
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
	void Base4BitsDataIterator<TLut>::JumpToNextPixel()
	{
		_index++;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base4BitsDataIterator<TLut>::JumpToNextRow()
	{
		_index += _skipedLines;
	}

	// Base4BitsDataIterator
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	inline TLut Base4BitsDataIterator<TLut>::ReadDataFromLUT()
	{
		uint8_t value = _gdata[_index >> 1];
		value = (_index & 0x01) ? (value >> 4) : (value & 0x0f);
		return _lut[value];
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class Base4BitsDataIterator<uint8_t>;
	template class Base4BitsDataIterator<uint16_t>;
	template class Base4BitsDataIterator<uint32_t>;
}