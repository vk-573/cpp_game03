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
		void		processEvents();
		void		processPlayer1();
		void		processPlayer2();
		// void		initPlayers();
		void		quit();
		void		dispEnd();
		void		initPlayers();
		void		drawAll();
		void		drawPlayers();
		void		drawBullets();
		void		drawMap();
		IDisplay	*_window;
		bool		_running = false;
		KEY_EVENT	_Events;
		MenuConfig	*_menuConfig;
		IPlayer		*_p1;
		IPlayer		*_p2;
		IMap		*_map;
		// sf::Clock	_Time;

};

#endif /* !GAME_HPP_ */
