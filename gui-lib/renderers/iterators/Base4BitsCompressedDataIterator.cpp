#include "Base4BitsCompressedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base4BitsCompressedDataIterator<TLut>::Initialize(uint16_t srow,
		uint16_t slines0, uint16_t slines1, const PictureObject * object, void *)
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
	void Base4BitsCompressedDataIterator<TLut>::JumpToNextPixel()
	{
		_count--;
		if(!_count)
		{
			_gdata++;
			_count = (*_gdata >> 4) + 1;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base4BitsCompressedDataIterator<TLut>::JumpToNextRow()
	{
		CalculatePositionToRead(_skipedLines);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base4BitsCompressedDataIterator<TLut>::CalculatePositionToRead(uint32_t skippedLine)
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
	template<typename TLut>
	TLut Base4BitsCompressedDataIterator<TLut>::ReadDataFromLUT()
	{
		uint8_t value = *_gdata & 0x0f;
		return _lut[value];
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class Base4BitsCompressedDataIterator<uint8_t>;
	template class Base4BitsCompressedDataIterator<uint16_t>;
	template class Base4BitsCompressedDataIterator<uint32_t>;
}