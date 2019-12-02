#ifndef GAME_HPP_
	#define GAME_HPP_

#include "Scene.hpp"
#include "MenuConfig.hpp"

class Game : public Scene {
	public:
		Game(IDisplay *window);
		~Game();

		void		initGame(MenuConfig *menuConifg);
		void		startGame();
		bool		isRunning() const;

	protected:
	private:
		void		quit();
		void		dispEnd();
		void		initPlayers();
		IDisplay	*_window;
		
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
