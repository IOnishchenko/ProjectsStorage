#ifndef GUI_L4_COMPRESSED_DATA_ITERATOR_HPP
#define GUI_L4_COMPRESSED_DATA_ITERATOR_HPP

#include "Base4BitsCompressedDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class L4CompressedDataIterator : public Base4BitsCompressedDataIterator<TLut>
	{
		using base = Base4BitsCompressedDataIterator<TLut>;
	public:
		// constructor
		// L4CompressedDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~L4CompressedDataIterator() override = default;

		// IDataIterator methods
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
	};
}

#endif // GUI_L4_COMPRESSED_DATA_ITERATOR_HPP