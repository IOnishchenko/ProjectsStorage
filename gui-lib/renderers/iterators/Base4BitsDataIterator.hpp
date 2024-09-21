#ifndef GUI_BASE_4BITS_DATA_ITERATOR_HPP
#define GUI_BASE_4BITS_DATA_ITERATOR_HPP

#include "IDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class Base4BitsDataIterator : public IDataIterator
	{
	public:
		// constructor
		// Base4BitsDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~Base4BitsDataIterator() override = default;

		// IDataIterator methods
		void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object, void * param) override;
		void JumpToNextPixel() override;
		void JumpToNextRow() override;
	
	protected:
		// fields
		uint16_t _skipedLines;
		uint16_t _index;
		const uint8_t * _gdata;
		const TLut * _lut;

		// method
		TLut ReadDataFromLUT(); 
	};
}

#endif // GUI_BASE_4BITS_DATA_ITERATOR_HPP