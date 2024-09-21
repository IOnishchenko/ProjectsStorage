#ifndef GUI_BIT_DATA_ITERATOR_HPP
#define GUI_BIT_DATA_ITERATOR_HPP

#include "IDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	class BitDataIterator : public IDataIterator
	{
	public:
		struct Colors
		{
			uint32_t Foreground;
			uint32_t Background;
		};

		// constructor
		// BitDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// IDataIterator methods
		void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object, void * param) override;
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
		void JumpToNextPixel() override;
		void JumpToNextRow() override;

	private:
		// fields
		uint16_t _skipedLines;
		const uint8_t * _gdata;
		uint16_t _index;
		Colors _colors;
	};
}

#endif // GUI_BIT_DATA_ITERATOR_HPP