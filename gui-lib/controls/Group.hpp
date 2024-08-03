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
			IGElement * gelement);

		Group(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & controls, IGElement * gelement);

		// destructor
		~Group() override = default;

		// IUIControl methods
		void SetEnable(bool) override;
		void SetVisible(bool) override;
		IGElement * GetGraphicElement() override;
		void Draw() override;
		// Group methods
		void RedrawChildren();
		void AddChild(IUIControl * child);

		// fields
		std::forward_list<IUIControl *> Controls;

	protected:
		IGElement * _background;
		
		IUIControl * GetEnabledControlByCoordinate(uint16_t x, uint16_t y);
	};
}

#endif // GUI_GROUP_HPP