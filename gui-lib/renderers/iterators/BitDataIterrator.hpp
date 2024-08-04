#ifndef GUI_BIT_DATA_ITERATOR_HPP
#define GUI_BIT_DATA_ITERATOR_HPP

#include "IDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	class BitDataIterator : public IDataIterator
	{
	public:
		// constructor
		// BitDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// IDataIterator methods
		void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object) override;
		uint32_t GetValue() override;
		void JumpToNextRow() override;

	private:
		// fields
		uint16_t _skipedLines;
		const uint8_t * _current;
		uint16_t _bitIndex;
	};
}

#endif // GUI_BIT_DATA_ITERATOR_HPP