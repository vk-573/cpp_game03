/*
** EPITECH PROJECT, 2018
** VK
** File description:
** Game class
*/

#ifndef GAME_HPP_
	#define GAME_HPP_

// #include "IDisplay.hpp"
// #include "IWeapon.hpp"
#include "Scene.hpp"
#include "MenuConfig.hpp"
// #include "DefaultWeapon.hpp"
// #include "IStage.hpp"
// #include "Player.hpp"
// #include "PluginsManager.hpp"
// #include "StageSpace.hpp"
// #include "StageCave.hpp"

class Game : public Scene {
	public:
		Game(IDisplay *window);
		~Game();

		void		initGame(MenuConfig *menuConifg);
		// void		setPlayers(PLAYERS &players);
		// PLAYERS		&getPlayers();
		void		startGame();
		bool		isRunning() const;

	protected:
	private:
		void		quit();
		// bool		nextStage();
		// void		displayLoaderStage();
		void		dispEnd();
		// void		restartPlayers();
		// void		restartPlayersStats();
		// void		initStages();
		void		initPlayers();
		//void		initWeapons();
		IDisplay	*_window;
		// PLAYERS		_Players;
		// STAGES		_Stages;
		//WEAPONS		_Weapons;
		// IStage*		_currentStage;
		// int		_current = 0;
		bool		_running = false;
		MenuConfig	*_menuConfig;
		// PluginsManager	*_plugins;
		// sf::Clock	_Time;

};

#endif /* !GAME_HPP_ */
