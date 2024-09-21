#ifndef GUI_L8_COMPRESSED_DATA_ITERATOR_HPP
#define GUI_L8_COMPRESSED_DATA_ITERATOR_HPP

#include "Base8BitsCompressedDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class L8CompressedDataIterator : public Base8BitsCompressedDataIterator<TLut>
	{
		using base = Base8BitsCompressedDataIterator<TLut>;
	public:
		// constructor
		// L8CompressedDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~L8CompressedDataIterator() override = default;

		// IDataIterator methods
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
	};
}

#endif // GUI_L8_COMPRESSED_DATA_ITERATOR_HPP