#ifndef GUI_A8_DATA_ITERATOR_HPP
#define GUI_A8_DATA_ITERATOR_HPP

#include "Base8BitsDataIterator.hpp"
#include "gui_resource_types.h"

namespace gui
{
	template<typename TLut>
	class A8DataIterator : public Base8BitsDataIterator<TLut>
	{
		using base = Base8BitsDataIterator<TLut>;
	public:
		// constructor
		// A8DataIterator(uint16_t srow, uint16_t slines0, uint16_t slines1,
		// 	const PictureObject * object);

		// destructor
		~A8DataIterator() override = default;

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

#endif // GUI_A8_DATA_ITERATOR_HPP