#ifndef MENU_HPP_
	#define MENU_HPP_

#include "Game.hpp"
#include "IMenuScene.hpp"
#include "MainMenu.hpp"
#include "GameConfigScene.hpp"

class Manager : public Scene {
	public:
		Manager(IDisplay *window);
		~Manager();

		void		initManager();
		void		startManager();

	protected:
	private:
		void		initScenes();
		bool		isRunning();
		void		quit();
		void		setCurrentScene(_MENU_SCENE);
		void		startGame();
		IDisplay				*_window;
		MENU_SCENES				_Scenes;
		IMenuScene				*_currentScene;
		bool					_running;
		Game					*_game;
		MenuConfig				*_menuConfig;

};

#endif /* !MENU_HPP_ */
