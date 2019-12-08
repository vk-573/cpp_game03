#include "PluginManager.hpp"

PluginManager::~PluginManager()
{
	closePlayersLibs();
        closeWeaponsLibs();
        closeMapsLibs();
}

void            PluginManager::loadPLugings() {
        _playersPath = "./libs/players";
        _weaponsPath = "./libs/weapons";
        _mapsPath = "./libs/maps";
        loadPlayers();
        loadWeapons();
        loadMaps();
}

// PRIVATE
void            PluginManager::loadPlayers() {
        getPaths(_playersPath, _player_type);
        if (!_playersLibs.size()) {
                std::cout << "error while loading players modules" << std::endl;
                exit(84);
        }
        openPlayersLibs();
}

void            PluginManager::loadWeapons() {
        getPaths(_weaponsPath, _weapon_type);
        if (!_weaponsLibs.size()) {
                std::cout << "error while loading weapons modules" << std::endl;
                exit(84);
        }
        openWeaponsLibs();
}

void            PluginManager::loadMaps() {
        getPaths(_mapsPath, _map_type);
        if (!_mapsLibs.size()) {
                std::cout << "error while loading maps modules" << std::endl;
                exit(84);
        }
        openMapsLibs();
}

_PLAYERS        PluginManager::getPlayers() {
        return _Players;
}
_WEAPONS        PluginManager::getWeapons() {
        return _Weapons;
}
_MAPS        PluginManager::getMaps() {
        return _Maps;
}

IPlayer         *PluginManager::getPlayerInstance(const std::string &name) {
        IPlayer *tmp;
        IPlayer	*(* create)() = (IPlayer *(*)())dlsym(_playersHandleLibs.at(name), "getInstance");
        tmp = create();
        return tmp;
}

IWeapon         *PluginManager::getWeaponInstance(const std::string &name) {
        IWeapon *tmp;
        IWeapon	*(* create)() = (IWeapon *(*)())dlsym(_weaponsHandleLibs.at(name), "getInstance");
        tmp = create();
        return tmp;
}

IMap            *PluginManager::getMapInstance(const std::string &name) {
        IMap *tmp;
        IMap	*(* create)() = (IMap *(*)())dlsym(_mapsHandleLibs.at(name), "getInstance");
        tmp = create();
        return tmp;
}

// //PRIVATE
void		PluginManager::getPaths(const std::string &pluginPath, const pluginType &type)
{
	std::string	tmp;

	DIR* dirFile = opendir(pluginPath.c_str());
	if ( dirFile ) {
		struct dirent* hFile;
		errno = 0;
		while (( hFile = readdir( dirFile )) != NULL ) {
			tmp = hFile->d_name;
			if (tmp.find(".so") != std::string::npos) {
                                if (type == _player_type) {
				        _playersLibs.push_back(pluginPath + "/" + tmp);
                                }
                                else  if (type == _weapon_type) {
				        _weaponsLibs.push_back(pluginPath + "/" + tmp);
                                }
                                else if (type == _map_type) {
				        _mapsLibs.push_back(pluginPath + "/" + tmp);
                                }
                        }
		}
		closedir( dirFile );
	}
}

void		PluginManager::openPlayersLibs()
{
        for (auto path : _playersLibs) {

                // std::cout << "opeinig the path :" << path << std::endl;
                void *handleLib = dlopen(path.c_str(), RTLD_LAZY);
                if (!handleLib)
                {
                        std::cerr << "Cannot load the " << path << " :"<< dlerror() << std::endl;
                        exit (84);
                }
                IPlayer *tmp;
        	IPlayer	*(* create)() = (IPlayer *(*)())dlsym(handleLib, "getInstance");
        	tmp = create();
                // std::cout << "tmp name :" << tmp->getName() << std::endl;
                _playersHandleLibs.emplace(tmp->getName(), handleLib);
                _Players.emplace(tmp->getName(), tmp);
        }
}

void		PluginManager::openWeaponsLibs()
{
        for (auto path : _weaponsLibs) {

                //std::cout << "opeinig weaopon the path :" << path << std::endl;                
                void *handleLib = dlopen(path.c_str(), RTLD_LAZY);
                if (!handleLib)
                {
                        std::cerr << "Cannot load the " << path << " :"<< dlerror() << std::endl;
                        exit (84);
                }
                IWeapon *tmp;
        	IWeapon	*(* create)() = (IWeapon *(*)())dlsym(handleLib, "getInstance");
        	tmp = create();
                //std::cout << "tmp weapon name :" << tmp->getName() << std::endl;
                _weaponsHandleLibs.emplace(tmp->getName(), handleLib);
                _Weapons.emplace(tmp->getName(), tmp);
        }
}

void		PluginManager::openMapsLibs()
{
        for (auto path : _mapsLibs) {

                // std::cout << "opeinig map path :" << path << std::endl;
                void *handleLib = dlopen(path.c_str(), RTLD_LAZY);
                if (!handleLib)
                {
                        std::cerr << "Cannot load the " << path << " :"<< dlerror() << std::endl;
                        exit (84);
                }
                IMap    *tmp;
        	IMap    *(* create)() = (IMap *(*)())dlsym(handleLib, "getInstance");
        	tmp = create();
                // std::cout << "tmp map name :" << tmp->getName() << std::endl;
                _mapsHandleLibs.emplace(tmp->getName(), handleLib);
                _Maps.emplace(tmp->getName(), tmp);
        }
}


void		PluginManager::closePlayersLibs()
{
	for (auto &handle : _playersHandleLibs)
	{
		dlclose(handle.second);
	}
        for (auto &player : _Players)
	{
		delete(player.second);
	}
}

void		PluginManager::closeWeaponsLibs()
{
	for (auto &handle : _weaponsHandleLibs)
	{
		dlclose(handle.second);
	}
        for (auto &weapon : _Weapons)
	{
		delete(weapon.second);
	}
}

void		PluginManager::closeMapsLibs()
{
	for (auto &handle : _mapsHandleLibs)
	{
		dlclose(handle.second);
	}
        for (auto &map : _Maps)
	{
		delete(map.second);
	}
}
