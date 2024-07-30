#ifndef GUI_IPICTURE_DECODER_HPP
#define GUI_IPICTURE_DECODER_HPP

#include "IGElement.hpp"

namespace gui
{
	struct IPictureDecoder
	{
		// dectructor
		virtual ~IPictureDecoder() = default;

		// methods
		virtual void Decode(const IGElement * gel) = 0;
	};
}

#endif // GUI_IPICTURE_DECODER_HPP