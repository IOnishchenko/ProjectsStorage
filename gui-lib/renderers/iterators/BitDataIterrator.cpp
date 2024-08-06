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
		_index = srow * object->height + slines0;
		_gdata = ((PictureGData *)object->gdata)->data;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	uint32_t BitDataIterator::GetValue()
	{
		uint8_t byte = _gdata[_index >> 3];
		uint8_t shift = _index & 0x0007;
		uint32_t res = (byte & (1 << shift)) ? 1 : 0;
		_index++;
		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void BitDataIterator::JumpToNextRow()
	{
		_index += _skipedLines;
	}
}