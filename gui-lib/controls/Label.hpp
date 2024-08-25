#ifndef GUI_LABEL_HPP
#define GUI_LABEL_HPP

#include "IUIControl.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include <string>
#include <memory>

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class Label : public IUIControl
	{
	public:
		// constructor
		Label(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement & disabledGEl, IGElement & enabledGEl,
			uint32_t disForegroubd, uint32_t disBackground,
			uint32_t enaForeground, uint32_t enaBackground,
			const Font & font, uint16_t textOffset = 0);

		Label(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint32_t disForegroubd, uint32_t disBackground,
			uint32_t enaForeground, uint32_t enaBackground,
			const Font & font, uint16_t textOffset = 0);
		
		// destructor
		~Label() override = default;

		// methods
		virtual void SetFloatValue(float value, const std::string & unit, int precision, bool alwaysDotVisible);
		virtual void SetFloatValue(float value, int precision, bool alwaysDotVisible);
		virtual void SetIntValue(int value, const std::string & unit);
		virtual void SetIntValue(int value);

		// IUIControl methods
		IGElement * GetGraphicElement() override;
		void SetEnable(bool value) override;

		// operators
		Label& operator=(const char * txt);
		Label& operator=(const std::string & txt);
		Label& operator=(const std::string_view & txt);
		
	protected:
		// fields
		std::string _text;
		GEText _textGelement;

	private:
		std::unique_ptr<GERectangle> _defaultBackground;

		IGElement & _disabledGEl;
		IGElement & _enabledGEl;

		uint32_t _disForeground, _disBackground;
		uint32_t _enaForeground, _enaBackground;

		// methods
		void PrepareStringData(float value, int precision, bool alwaysDotVisible);
	};
}

#endif // GUI_LABEL_H