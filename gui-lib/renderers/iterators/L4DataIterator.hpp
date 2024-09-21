#ifndef GUI_L4_DATA_ITERATOR_HPP
#define GUI_L4_DATA_ITERATOR_HPP

#include "Base4BitsDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class L4DataIterator : public Base4BitsDataIterator<TLut>
	{
		using base = Base4BitsDataIterator<TLut>;
	public:
		// constructor
		// L4DataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~L4DataIterator() override = default;

		// IDataIterator methods
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
	};
}

#endif // GUI_L4A4_DATA_ITERATOR_HPP