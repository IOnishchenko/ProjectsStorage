#ifndef GUI_GROUP_HPP
#define GUI_GROUP_HPP

#include "IUIControl.hpp"
#include <forward_list>

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class Group : public IUIControl
	{

	public:
		// constructor
		Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::forward_list<IUIControl *> & content, IGElement * gelement);

		Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & content, IGElement * gelement);

		// destructor
		~Group() override = default;

		// system event handlers
		void SetEnable(bool) override;
		void SetVisible(bool) override;
		
		IGElement * GetGraphicElement() override;
		void Draw() override;
		void RedrawChildren();

	protected:
		std::forward_list<IUIControl *> _content;
		IGElement * _background;
		
		IUIControl * GetEnabledControlByCoordinate(uint16_t x, uint16_t y);
	};
}

#endif // GROUP_H