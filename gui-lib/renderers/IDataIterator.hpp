#ifndef GUI_IDATA_ITERRATOR_HPP
#define GUI_IDATA_ITERRATOR_HPP

#include "stdint.h"

namespace gui
{
	struct IDataIterator
	{
		// destructor
		virtual ~IDataIterator() = default;

		// methods
		virtual uint32_t GetValue() = 0;
		virtual void JumpToNextRow() = 0;
	};
}

#endif // GUI_IDATA_ITERRATOR_HPP