#include "BitDataIterrator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	constexpr uint16_t BIT_PER_BYTE = 8;
	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void BitDataIterator::Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
		const PictureObject * object)
	{
		_skipedLines = slines0 + slines1;
		// position for riading
		_bitIndex = srow * object->height + slines0;
		_current = ((PictureGData *)object->gdata)->data;
		_current += _bitIndex >> 3;
		_current += (_bitIndex & 0x07) ? 0x01U : 0x00U;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	uint32_t BitDataIterator::GetValue()
	{
		uint16_t shift = _bitIndex & 0x0007;
		uint32_t res = (*_current & (1 << shift)) ? 1 : 0;

		_bitIndex++;
		if(!(_bitIndex & 0x0007))
			_current++;

		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void BitDataIterator::JumpToNextRow()
	{
		uint16_t byteOffset = ((_bitIndex & 0x0007) + _skipedLines) >> 3; 
		_bitIndex += _skipedLines;
		_current += byteOffset;
		// _current += (_bitIndex & 0x0007) ? 0x01U : 0x00U;
	}
}