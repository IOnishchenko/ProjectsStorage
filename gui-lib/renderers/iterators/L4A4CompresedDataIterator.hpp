#ifndef GUI_L4A4_COMPRESED_DATA_ITERATOR_HPP
#define GUI_L4A4_COMPRESED_DATA_ITERATOR_HPP

#include "IDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class L4A4CompresedDataIterator : public IDataIterator
	{
	public:
		// constructor
		// L4A4CompresedDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~L4A4CompresedDataIterator() override = default;

		// IDataIterator methods
		void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object) override;
		uint32_t GetValue() override;
		void JumpToNextRow() override;
	
	private:
		// fields
		uint32_t _skipedLines;
		uint32_t _count;
		const uint8_t * _gdata;
		const TLut * _lut;

		// methods
		void CalculatePositionToRead(uint32_t skippedLine);
	};
}

#endif // GUI_L4A4_COMPRESED_DATA_ITERATOR_HPP