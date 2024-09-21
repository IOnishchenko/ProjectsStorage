#ifndef GUI_AL44_DATA_ITERATOR_HPP
#define GUI_AL44_DATA_ITERATOR_HPP

#include "Base8BitsDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class AL44DataIterator : public Base8BitsDataIterator<TLut>
	{
		using base = Base8BitsDataIterator<TLut>;
	public:
		// constructor
		// AL44DataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~AL44DataIterator() override = default;

		// IDataIterator methods
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
	};
}

#endif // GUI_AL44_DATA_ITERATOR_HPP