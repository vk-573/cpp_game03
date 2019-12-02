#ifndef GAME_CONFIG_HPP_
#define GAME_CONFIG_HPP_

#include "MainMenu.hpp"
#include <vector>

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
		void		changePlayer1(_KEYS);
		void		changePlayer1W(_KEYS);
		void		changePlayer2(_KEYS);
		void		changePlayer2W(_KEYS);
		void		changeMap(_KEYS);

		bool		oneplayer = true;
		bool		online = false;
		MenuConfig	*_menuConfig;
		IPlayer		*_currentP1;
		int		_currentP1pos;
		IWeapon		*_currentP1W;
		int		_currentP1Wpos;
		IPlayer		*_currentP2;
		int		_currentP2pos;
		IWeapon		*_currentP2W;
		int		_currentP2Wpos;
		IMap		*_currentMap;
		int		_currentMappos;
		int		_maxShips = 0;
		int		_P1_pos = 0;
		int		_P2_pos = 1;
		std::vector<IPlayer*>	_Players;
		std::vector<IWeapon*>	_Weapons;
		std::vector<IMap*>	_Maps;

};

#endif
