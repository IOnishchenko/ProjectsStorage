#include "Base8BitsCompressedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsCompressedDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0,
		uint16_t slines1, const PictureObject * object, void *)
	{
		_skipedLines = slines1;
		const PictureGData * pic = (PictureGData *)object->gdata;
		
		uint32_t skipped = srow;
		skipped *= object->height;
		skipped += slines0;

		// find data position
		_lut = (TLut *)pic->lut;
		_gdata = pic->data;
		_count = *_gdata;
		_count++;
		_gdata++;
		CalculatePositionToRead(skipped);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsCompressedDataIterator<TLut>::JumpToNextPixel()
	{
		_count--;
		if(!_count)
		{
			_gdata++;
			_count = *_gdata;
			_count++;
			_gdata++;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsCompressedDataIterator<TLut>::JumpToNextRow()
	{
		CalculatePositionToRead(_skipedLines);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsCompressedDataIterator<TLut>::CalculatePositionToRead(uint32_t skippedLine)
	{
		while(skippedLine >= _count)
		{
			skippedLine -= _count;
			_gdata++;
			_count = *_gdata;
			_count++;
			_gdata++;
		}
		_count -= skippedLine;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	TLut Base8BitsCompressedDataIterator<TLut>::ReadDataFromLut()
	{
		return _lut[*_gdata];
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class Base8BitsCompressedDataIterator<uint8_t>;
	template class Base8BitsCompressedDataIterator<uint16_t>;
	template class Base8BitsCompressedDataIterator<uint32_t>;
}