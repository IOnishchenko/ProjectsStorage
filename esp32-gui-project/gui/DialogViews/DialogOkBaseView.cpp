#include "DialogOkBaseView.hpp"
#include "OGCommon.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	DialogOkBaseView::DialogOkBaseView(const IUIContext & context)
		:
		IModalWindow(38, 38, 244, 164, context, &_background),
		_headerText(20, 5, 100, 18, "MODULATION SELECTION", TEXT_COLOR, BACKGROUND_DARK,
			Font18, nullptr),
		_headedr(2, 2, 240, 164-4, BACKGROUND_DARK, &_headerText),
		_background(0, 0, 244, 164, BACKGROUND_LIGHT, &_headedr)
	{
	}
}