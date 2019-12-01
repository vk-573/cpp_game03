/*
** EPITECH PROJECT, 2018
** VK
** File description:
** Game class implementation
*/

#include "Game.hpp"

Game::Game(IDisplay *window) : _window(window)
{
}

Game::~Game()
{
// 	delete _plugins;
// 	for (auto &weapon : _Weapons)
// 		delete weapon.second;
// 	_Weapons.clear();
// 	for (auto &stage : _Stages)
// 		delete stage.second;
// 	_Stages.clear();
}

void		Game::initGame(MenuConfig *menuConfig)
{
	// _plugins = new PluginsManager;
	_menuConfig = menuConfig;
	// initStages();
	// initWeapons();
	// initPlayers();
}

// void		Game::setPlayers(PLAYERS &players)
// {
// 	_Players = players;
// 	// for (auto const& x : _Players)
// 	// {
// 	// 	x.second->setWeapon(_Weapons[0].second);
// 	// }
// }

// PLAYERS		&Game::getPlayers()
// {
// 	return (_Players);
// }

void		Game::startGame()
{
	_running = true;
	// _STAGE_END_STATE endState;
	while (_window->isOpen() && isRunning())
	{
		std::cout << "playing !" << std::endl;
		// displayLoaderStage();
		// _currentStage->initStage();
		// _currentStage->setPlayers(_Players);
		// _currentStage->setEnemies(_plugins->getEnemiesByStage(_currentStage->getStageID()));
		// endState = _currentStage->startStage();
		// if (endState == _ENDSTAGE_MAIN_MENU) {
		// 	restartPlayersStats();
		// 	break;
		// }
		// else if (endState == _ENDSTAGE_NEXT_STAGE) {
		// 	restartPlayers();
		// 	if (!nextStage())
		// 	{
		// 		dispEnd();
		// 		quit();
		// 	}
		// }
		// else if (endState == _ENDSTAGE_RESTART_ALL) {
		// 	restartPlayersStats();
		// 	_currentStage = _Stages.at(0).second;
		// }
	}
}

bool		Game::isRunning() const 
{
	return (_running);
}

////////PRIVATE

void		Game::quit()
{
	_running = false;
}

void		Game::dispEnd()
{
	int	select = 0;
	sf::sleep(sf::seconds(0.1));
	while (3)
	{
		// _window->clear();
		// _window->drawText("YOU HAVE WON THE GAME", 72, 200, 150);
		// _window->drawText("Scores",55, 485, 280);
		// // _window->drawText("Player 1 : " + std::to_string(_Players.at(_FIRST)->getScore()),55, 430, 400);
		// if (_Players.size() == 2)
		// 	_window->drawText("Player 2 : " + std::to_string(_Players.at(_SECOND)->getScore()),55, 430, 480);
		// _window->drawText("Press *Space* to quit...", 38, 390, 570);
		// _window->refresh();
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		// 	break;
	}
}

// void		Game::initWeapons()
// {
// 	createSprite("DefaultWeapon", "./ressources/game/defaultWeapon.png");
// 	IWeapon		*defaultWeapon = new DefaultWeapon(getSprite("DefaultWeapon"), "Zebi");
// 	_Weapons.push_back(std::make_pair(_W_DEFAULT, defaultWeapon));
// }

// void		Game::initPlayers() 
// {
// 	_Players.emplace(_FIRST, _menuConfig->getChoosenPlayers()[0].second);
// 	_Players.at(_FIRST)->setWeapon(_Weapons[0].second);
// 	_Players.at(_FIRST)->setPlayerKeys(_menuConfig->getFirstPlayerKeys());
// 	_Players.at(_FIRST)->setID(_FIRST);
// 	if (_menuConfig->nb_players == 2)
// 	{
// 		_Players.emplace(_SECOND, _menuConfig->getChoosenPlayers()[1].second);
// 		_Players.at(_SECOND)->setWeapon(_Weapons[0].second);
// 		_Players.at(_SECOND)->setPlayerKeys(_menuConfig->getSecondPlayerKeys());
// 		_Players.at(_SECOND)->setID(_SECOND);
// 	}
// }
