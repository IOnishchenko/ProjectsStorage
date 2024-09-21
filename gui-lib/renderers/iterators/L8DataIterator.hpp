#ifndef GUI_L8A8_DATA_ITERATOR_HPP
#define GUI_L8A8_DATA_ITERATOR_HPP

#include "Base8BitsDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class L8DataIterator : public Base8BitsDataIterator<TLut>
	{
		using base = Base8BitsDataIterator<TLut>;
	public:
		// constructor
		// L8DataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~L8DataIterator() override = default;

		// IDataIterator methods
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
	};
}

#endif // GUI_L8A8_DATA_ITERATOR_HPP