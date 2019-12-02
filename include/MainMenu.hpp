#ifndef MAINMENU_HPP_
	#define MAINMENU_HPP_

#include "IMenuScene.hpp"
#include "Scene.hpp"

enum _BUTTON
{
	_PLAY,
	_LOCAL_MULTI,
	_NB_PLAYERS,
	_PLAYER1,
	_PLAYER2,
	_PLAYER1_WEAPON,
	_PLAYER2_WEAPON,
	_MAP,
	_OPTIONS,
	_BACK,
	_EXIT_B
};

class MainMenu : virtual public IMenuScene, public Scene {
	public:
		MainMenu(IDisplay *window, _MENU_SCENE scene);
		~MainMenu() = default;

		virtual void		initScene();
		virtual _MENU_SCENE	startScene();
		virtual _MENU_SCENE	getSceneID();

	protected:
		void		checkEvents();
		void		action();
		void		nextScene(_MENU_SCENE nextScene);
		void		moveSelector(_KEYS dir);
		void		quit();
		bool		checkTimer(float seconds);
		IDisplay			*_window;
		KEY_EVENT			_Events;
		_MENU_SCENE			_idScene;
		_MENU_SCENE			_targetScene;
		sf::Sprite			_selector;
		int				_selector_pos;
		int				_elementsNB;
		std::vector<std::pair<_BUTTON, sf::Sprite>>	_MenuElements;
		bool				_running;
		sf::Clock			_rateClock;	
	private:
		void			drawAll();
};

#endif /* !MAINMENU_HPP_ */
