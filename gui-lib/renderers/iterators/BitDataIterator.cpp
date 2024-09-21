#include "BitDataIterator.hpp"

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
		const PictureObject * object, void * param)
	{
		_skipedLines = slines0 + slines1;
		_index = srow * object->height + slines0;
		_gdata = ((PictureGData *)object->gdata)->data;
		_colors = *static_cast<Colors *>(param);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	uint32_t BitDataIterator::GetColor()
	{
		uint8_t byte = _gdata[_index >> 3];
		uint8_t shift = _index & 0x0007;
		uint32_t res = (byte & (1 << shift)) ? _colors.Foreground : _colors.Background;
		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	uint8_t BitDataIterator::GetAlpha()
	{
		uint8_t byte = _gdata[_index >> 3];
		uint8_t shift = _index & 0x0007;
		uint8_t res = (byte & (1 << shift)) ? 0xffU : 0x00U;
		return res;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void BitDataIterator::JumpToNextPixel()
	{
		_index++;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void BitDataIterator::JumpToNextRow()
	{
		_index += _skipedLines;
	}
}