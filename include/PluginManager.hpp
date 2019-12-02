#ifndef PLUGINMANAGER_HPP_
	#define PLUGINMANAGER_HPP_

#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <string>
#include "IMap.hpp"
#include "IPlayer.hpp"
#include "IWeapon.hpp"

enum pluginType {
        _player_type,
        _weapon_type,
        _map_type,
};

class PluginManager {
	public:
		PluginManager() = default;
		~PluginManager();

                void            loadPLugings();
                _PLAYERS        getPlayers();
                _WEAPONS        getWeapons();
                _MAPS           getMaps();
                IPlayer         *getPlayerInstance(const std::string &name);
                IWeapon         *getWeaponInstance(const std::string &name);
                IMap            *getMapInstance(const std::string &name);

	private:
                void            loadPlayers();
                void            openPlayersLibs();
                void            closePlayersLibs();

                void            loadWeapons();
                void            openWeaponsLibs();
                void            closeWeaponsLibs();

                void            loadMaps();
                void            openMapsLibs();
                void            closeMapsLibs();

		void		getPaths(const std::string &pluginsPath, const pluginType &type);
                _PLAYERS        _Players;
                _WEAPONS        _Weapons;
                _MAPS           _Maps;

                std::string     _playersPath;
		std::vector<std::string>	_playersLibs;
                std::string     _weaponsPath;
		std::vector<std::string>	_weaponsLibs;
                std::string     _mapsPath;
		std::vector<std::string>	_mapsLibs;

		std::map<const std::string, void*>	_playersHandleLibs;
		std::map<const std::string, void*>	_weaponsHandleLibs;
		std::map<const std::string, void*>	_mapsHandleLibs;

		// void				getPaths(_STAGES stage);
		// void				openLib(const std::string &path);
		// IUnit				*getInstance(const std::string &functionName);
		// void				closeLib();
		// std::string			getStagePath(_STAGES stage);
		// ENEMIES				_Enemies;
		// STAGES_ENEMIES			_EnemiesByStage;
		// std::vector<std::string>	_libsPath;
		// void				*_handleLib;
		// std::vector<void *>		_HandleLibs;
		// std::map<_ENEMIES_TYPE, void *>	_HandlesByID;
		// int				_currentHandle = 0;
};

#endif