#include "MenuConfig.hpp"

MenuConfig::MenuConfig()
{
	_pluginManager = new PluginManager();
	_pluginManager->loadPLugings();
	setPlayers(_pluginManager->getPlayers());
	setWeapons(_pluginManager->getWeapons());
	setMaps(_pluginManager->getMaps());

	// _P1_keys.emplace(_KEY_UP, sf::Keyboard::Up);
	// _P1_keys.emplace(_KEY_DOWN, sf::Keyboard::Down);
	// _P1_keys.emplace(_KEY_RIGHT, sf::Keyboard::Right);
	// _P1_keys.emplace(_KEY_LEFT, sf::Keyboard::Left);
	// _P1_keys.emplace(_KEY_SPACE, sf::Keyboard::Space);

	// _P2_keys.emplace(_KEY_UP, sf::Keyboard::Z);
	// _P2_keys.emplace(_KEY_RIGHT, sf::Keyboard::D);
	// _P2_keys.emplace(_KEY_LEFT, sf::Keyboard::Q);
	// _P2_keys.emplace(_KEY_DOWN, sf::Keyboard::S);
	// _P2_keys.emplace(_KEY_SPACE, sf::Keyboard::LShift);
}

MenuConfig::~MenuConfig() {
	delete _pluginManager;
}

void		MenuConfig::setPlayers(_PLAYERS players) {
	_Players = players;
}
_PLAYERS	MenuConfig::getPlayers() {
	return _Players;
}
void		MenuConfig::setMaps(_MAPS maps) {
	_Maps = maps;
}
_MAPS		MenuConfig::getMaps() {
	return _Maps;
}
void		MenuConfig::setWeapons(_WEAPONS weapons) {
	_Weapons = weapons;
}

_WEAPONS	MenuConfig::getWeapons() {
	return _Weapons;
}

PluginManager	*MenuConfig::getPluginManager() {
	return _pluginManager;
}
