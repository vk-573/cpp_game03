#ifndef MENUMANAGER_HPP_
	#define MENUMANAGER_HPP_

#include "IPlayer.hpp"
#include "IMap.hpp"
#include "IWeapon.hpp"
#include "PluginManager.hpp"

enum	_PLAYERS_NUM
{
	_P_N1,
	_P_N2,
};


class MenuConfig {
	public:
		MenuConfig();
		~MenuConfig();

		void		setPlayers(_PLAYERS players);
		_PLAYERS	getPlayers();
		void		setMaps(_MAPS maps);
		_MAPS		getMaps();
		void		setWeapons(_WEAPONS weapons);
		_WEAPONS	getWeapons();
		PluginManager	*getPluginManager();
	private:	
		PluginManager	*_pluginManager;
		_PLAYERS	_Players;
		_WEAPONS	_Weapons;
		_MAPS		_Maps;
		IPlayer		*_p1;
		IWeapon		*_w1;
		IPlayer		*_p2;
		IWeapon		*_w2;
		IMap		*_choosenMap;
};


#endif /* !MENUMANAGER_HPP_ */
