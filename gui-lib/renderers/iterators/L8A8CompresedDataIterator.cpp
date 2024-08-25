#include "L8A8CompresedDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L8A8CompresedDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0,
		uint16_t slines1, const PictureObject * object)
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

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	uint32_t L8A8CompresedDataIterator<TLut>::GetValue()
	{
		uint32_t res = _lut[*_gdata];
		_count--;
		if(!_count)
		{
			_gdata++;
			_count = *_gdata;
			_count++;
			_gdata++;
		}

		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L8A8CompresedDataIterator<TLut>::JumpToNextRow()
	{
		CalculatePositionToRead(_skipedLines);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void L8A8CompresedDataIterator<TLut>::CalculatePositionToRead(uint32_t skippedLine)
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
	template class L8A8CompresedDataIterator<uint8_t>;
	template class L8A8CompresedDataIterator<uint16_t>;
	template class L8A8CompresedDataIterator<uint32_t>;
}