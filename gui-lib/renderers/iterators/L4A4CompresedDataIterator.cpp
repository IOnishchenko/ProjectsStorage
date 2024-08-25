#include "L4A4CompresedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L4A4CompresedDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
		const PictureObject * object)
	{
		_skipedLines = slines1;
		const PictureGData * pic = (PictureGData *)object->gdata;
		
		uint32_t skipped = srow;
		skipped *= object->height;
		skipped += slines0;

		// find data position
		_lut = (TLut *)pic->lut;
		_gdata = pic->data;
		_count = (*_gdata >> 4) + 1;
		CalculatePositionToRead(skipped);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L4A4CompresedDataIterator<TLut>::GetValue()
	{
		uint8_t value = *_gdata & 0x0f;
		uint32_t res = _lut[value];

		_count--;
		if(!_count)
		{
			_gdata++;
			_count = (*_gdata >> 4) + 1;
		}

		return (uint32_t)res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L4A4CompresedDataIterator<TLut>::JumpToNextRow()
	{
		CalculatePositionToRead(_skipedLines);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L4A4CompresedDataIterator<TLut>::CalculatePositionToRead(uint32_t skippedLine)
	{
		while(skippedLine >= _count)
		{
			skippedLine -= _count;
			_gdata++;
			_count = (*_gdata >> 4) + 1;
		}
		_count -= skippedLine;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class L4A4CompresedDataIterator<uint8_t>;
	template class L4A4CompresedDataIterator<uint16_t>;
	template class L4A4CompresedDataIterator<uint32_t>;
}