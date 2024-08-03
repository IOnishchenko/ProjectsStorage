#ifndef GUI_L4A4_DATA_ITERATOR_HPP
#define GUI_L4A4_DATA_ITERATOR_HPP

#include "IDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class L4A4DataIterator : public IDataIterator
	{
	public:
		// constructor
		L4A4DataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object);

		// destructor
		~L4A4DataIterator() override = default;

		// IDataIterator methods
		uint32_t GetValue() override;
		void JumpToNextRow() override;
	
	private:
		// fields
		uint16_t _skipedLines;
		uint16_t _index;
		const uint8_t * _gdata;
		const TLut * _lut;
	};
}

#endif // GUI_L4A4_DATA_ITERATOR_HPP