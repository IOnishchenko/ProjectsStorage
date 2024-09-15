#ifndef GUI_IMODAL_WINDOW_MANAGER_HPP
#define GUI_IMODAL_WINDOW_MANAGER_HPP

#include "Group.hpp"
#include "IUIContext.hpp"
#include "CommandDispatcher.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class IWindowManager
	{
	public:
		// constructor
		IWindowManager(IUIControlRenderer & renderer, IEncoderEventManager * encoderEventManager,
			IKeyboardEventManager * keyboardEventManager,
			ITouchScreenEventObserver * touchScreenObserver,
			IFocusManager * focusManager,
			IAnimatedControlManager * animationManager,
			CommandDispatcher & commandDispatcher)
			:
			_createWindowCmd(this, &IWindowManager::CreateWindow),
			_context
			{
				renderer,
				encoderEventManager,
				keyboardEventManager, 
				touchScreenObserver,
				focusManager,
				*this,
				animationManager
			},
			_commandDispatcher{commandDispatcher}
		{
		}

		// destructor
		virtual ~IWindowManager() = default;

		// methods
		/*-----------------------------------------------------------------//
		//
		//-----------------------------------------------------------------*/
		template<typename TWindow>
		void CreateAndShowWindow()
		{
			_commandDispatcher.PushToQueue(_createWindowCmd,
				&IWindowManager::CreateWindowObject<TWindow>);
			_createWindow = &IWindowManager::CreateWindowObject<TWindow>;
		}

		/*-----------------------------------------------------------------//
		//
		//-----------------------------------------------------------------*/
		template<typename TDialog>
		void OpenDialogWindow()
		{
			_commandDispatcher.PushToQueue(_createWindowCmd,
				&IWindowManager::CreateWindowObject<TDialog>);
		}

		/*-----------------------------------------------------------------//
		//
		//-----------------------------------------------------------------*/
		void CloseDialogWindow()
		{
			_commandDispatcher.PushToQueue(_createWindowCmd,
				_createWindow);
		}

		/*-----------------------------------------------------------------//
		//
		//-----------------------------------------------------------------*/
		const IUIContext & GetContext()
		{
			return _context;
		}

	private:
		// commands
		Command<IWindowManager, void(IWindowManager::*)()> _createWindowCmd;

		// fields
		void (IWindowManager::*_createWindow)() = nullptr;
		std::unique_ptr<Group> _window = nullptr;
		const IUIContext _context;
		CommandDispatcher & _commandDispatcher;

		// methods
		/*-----------------------------------------------------------------//
		//
		//-----------------------------------------------------------------*/
		void CreateWindow(void(IWindowManager::*createWindow)())
		{
			(this->*createWindow)();
		}

		/*-----------------------------------------------------------------//
		//
		//-----------------------------------------------------------------*/
		template<typename TWindow>
		void CreateWindowObject()
		{
			_window.reset();
			_window = std::make_unique<TWindow>(_context);
			_window->Draw();
		}

	};
}

#endif // GUI_IMODAL_WINDOW_MANAGER_HPP