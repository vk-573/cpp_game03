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
		void		setPlayers(_PLAYERS players);
		void		setWeapons(_WEAPONS weapons);
		void		setMaps(_MAPS maps);
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
		IPlayer		*_currentP1;
		IWeapon		*_currentP1W;
		IPlayer		*_currentP2;
		IWeapon		*_currentP2W;
		IMap		*_currentMap;
		int		_maxShips = 0;
		int		_P1_pos = 0;
		int		_P2_pos = 1;
		_PLAYERS	_Players;
		_WEAPONS	_Weapons;
		_MAPS		_Maps;

};

#endif
