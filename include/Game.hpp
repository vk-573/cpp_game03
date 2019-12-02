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
		void		quit();
		void		dispEnd();
		void		initPlayers();
		void		drawAll();
		void		drawPlayers();
		void		drawBullets();
		void		drawMap();
		bool		gotP1Hit(const bullet &b);
		bool		gotP2Hit(const bullet &b);
		IDisplay	*_window;
		bool		_running = false;
		KEY_EVENT	_Events;
		MenuConfig	*_menuConfig;
		IPlayer		*_p1;
		IPlayer		*_p2;
		IMap		*_map;
		std::map<int, bullet>	_p1Bullets;
		std::map<int, bullet>	_p2Bullets;
		int		_b1 = 0;
		int		_b2 = 0;
		// sf::Clock	_Time;

};

#endif /* !GAME_HPP_ */
