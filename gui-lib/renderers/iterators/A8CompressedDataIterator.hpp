#ifndef GUI_A8_COMPRESSED_DATA_ITERATOR_HPP
#define GUI_A8_COMPRESSED_DATA_ITERATOR_HPP

#include "Base8BitsCompressedDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class A8CompressedDataIterator : public Base8BitsCompressedDataIterator<TLut>
	{
		using base = Base8BitsCompressedDataIterator<TLut>;
	public:
		// constructor
		// A8CompressedDataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~A8CompressedDataIterator() override = default;

		// IDataIterator methods
		void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object, void * param) override;
		uint32_t GetColor() override;
		uint8_t GetAlpha() override;
	
	protected:
		// fields
		uint32_t _foregroundColor;
	};
}

#endif // GUI_A8_COMPRESSED_DATA_ITERATOR_HPP