#include "Base8BitsDataIterator.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsDataIterator<TLut>::Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
		const PictureObject * object, void *)
	{
		_skipedLines = slines1;
		const PictureGData * pic = (PictureGData *)object->gdata;
		_lut = (TLut *)pic->lut;
		_gdata = pic->data;
		_gdata += slines0 + srow * object->height;
	}

	// IDataIterator methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsDataIterator<TLut>::JumpToNextPixel()
	{
		_gdata++;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	void Base8BitsDataIterator<TLut>::JumpToNextRow()
	{
		_gdata += _skipedLines;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TLut>
	inline TLut Base8BitsDataIterator<TLut>::ReadDataFromLut()
	{
		return _lut[*_gdata];
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class Base8BitsDataIterator<uint8_t>;
	template class Base8BitsDataIterator<uint16_t>;
	template class Base8BitsDataIterator<uint32_t>;
}