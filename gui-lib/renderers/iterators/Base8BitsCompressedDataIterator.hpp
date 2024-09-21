#ifndef GUI_BASE_8BITS_COMPRESSED_DATA_ITERATOR_HPP
#define GUI_BASE_8BITS_COMPRESSED_DATA_ITERATOR_HPP

#include "IDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class Base8BitsCompressedDataIterator : public IDataIterator
	{
	public:
		// constructor
		// Base8BitsCompressedDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~Base8BitsCompressedDataIterator() override = default;

		// IDataIterator methods
		void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object, void * param) override;
		void JumpToNextPixel() override;
		void JumpToNextRow() override;
	
	protected:
		// fields
		uint32_t _skipedLines;
		uint32_t _count;
		const uint8_t * _gdata;
		const TLut * _lut;

		// methods
		void CalculatePositionToRead(uint32_t skippedLine);
		TLut ReadDataFromLut();
	};
}

#endif // GUI_BASE_8BITS_COMPRESSED_DATA_ITERATOR_HPP