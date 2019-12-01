#ifndef MENU_HPP_
	#define MENU_HPP_

#include "Game.hpp"
#include "IMenuScene.hpp"
#include "MainMenu.hpp"
#include "GameConfigScene.hpp"

class Manager : public Scene {
	public:
		Manager(IDisplay *window);
		~Manager() =  default;

		void		initManager();
		void		startManager();

	protected:
	private:
		void		initScenes();
		void		initPlayers();
		void		initWeapons();
		void		initMaps();
		void		deletePlayer();
		// PLAYERS		&getPlayers();
		bool		isRunning();
		void		quit();
		void		setCurrentScene(_MENU_SCENE);
		void		startGame();
		IDisplay				*_window;
		// PLAYERS					_Players;
		// int					_nb_players;
		MENU_SCENES				_Scenes;
		// WEAPONS					_Weapons;
		IMenuScene				*_currentScene;
		bool					_running;
		Game					*_game;
		MenuConfig				*_menuConfig;

};

#endif /* !MENU_HPP_ */
