#ifndef GUI_IDATA_ITERRATOR_HPP
#define GUI_IDATA_ITERRATOR_HPP

#include "stdint.h"
#include "gui_resource_types.h"

namespace gui
{
	struct IDataIterator
	{
		// destructor
		virtual ~IDataIterator() = default;

		// methods
		virtual void Initialize(uint16_t srow, uint16_t slines0, uint16_t slines1,
			const PictureObject * object) = 0;
		virtual uint32_t GetValue() = 0;
		virtual void JumpToNextRow() = 0;
	};
}

#endif // GUI_IDATA_ITERRATOR_HPP