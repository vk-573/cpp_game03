#ifndef GAME_CONFIG_HPP_
#define GAME_CONFIG_HPP_

#include "MainMenu.hpp"

class GameConfigScene : public MainMenu {
	public:
		GameConfigScene(IDisplay *window, _MENU_SCENE scene, MenuConfig *menuConfig) : _menuConfig(menuConfig), MainMenu(window, scene) {}
		~GameConfigScene() = default;
		void		initScene() override;
		_MENU_SCENE	startScene() override;
		_MENU_SCENE	getSceneID() override;
	private:
		void		drawAll();
		void		checkEvents();
		void		action();
		void		changeState(_KEYS);
		void		moveSelector(_KEYS);
		void		changeShip1(_KEYS);
		void		changeShip2(_KEYS);
		bool		oneplayer = true;
		bool		online = false;
		MenuConfig	*_menuConfig;
		sf::Sprite	_P1;
		sf::Sprite	_P2;
		int		_maxShips = 0;
		int		_P1_pos = 0;
		int		_P2_pos = 1;

};

#endif
