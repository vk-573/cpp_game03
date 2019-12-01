#include "Manager.hpp"

Manager::Manager(IDisplay *window)
{
	_window = window;
}

void            Manager::initManager()
{
	_menuConfig = new MenuConfig();
	initScenes();
	
}

void		Manager::startManager()
{
	_running = true;
	_MENU_SCENE	target;
	while (isRunning() && _window->isOpen())
	{
		_currentScene->initScene();
		target = _currentScene->startScene();
		setCurrentScene(target);
	}
	_window->quit();
}

//// PRIVATE

void		Manager::initScenes()
{
	IMenuScene	*mainMenu = new MainMenu(_window, _MAIN_MENU);
	IMenuScene	*gameMenu = new GameConfigScene(_window, _GAME_CONFIG, _menuConfig);

	_Scenes.emplace(mainMenu->getSceneID(), mainMenu);
	_Scenes.emplace(gameMenu->getSceneID(), gameMenu);
	_currentScene = _Scenes.at(_MAIN_MENU);
}

void		Manager::initPlayers()
{
	// IUnit	*dave = new Player("Dave");
	// IUnit	*jojo = new Player("Jojo");
	// IUnit	*bab = new Player("Bab");
	// IUnit	*vince = new Player("Vince");

	// createSprite("player1", "./ressources/game/player.png");
	// createSprite("player2", "./ressources/game/player2.png");
	// createSprite("player3", "./ressources/game/player3.png");
	// createSprite("player4", "./ressources/game/player4.png");

	// dave->setSprite(getSprite("player1"));
	// jojo->setSprite(getSprite("player2"));
	// bab->setSprite(getSprite("player3"));
	// vince->setSprite(getSprite("player4"));

	// _Players.emplace(_FIRST, dave);
	// _Players.emplace(_SECOND, jojo);
	// _Players.emplace(_THIRD, bab);
	// _Players.emplace(_FOURTH, vince);

}

void		Manager::initWeapons()
{

}

void		Manager::deletePlayer()
{

}

void		Manager::initMaps() {

}

// PLAYERS		&Menu::getPlayers()
// {
// 	return (_Players);
// }

bool		Manager::isRunning()
{
	return (_running);
}

void		Manager::quit()
{
	_running = false;
}

void		Manager::setCurrentScene(_MENU_SCENE target)
{
	if (target == _EXIT_SCENE)
		quit();
	else if (target == _PLAY_GAME)
	{
		startGame();
		_currentScene = _Scenes.at(_MAIN_MENU);
	}
	else 
		_currentScene = _Scenes.at(target);
}

void		Manager::startGame()
{
	_game = new Game(_window);
	_game->initGame(_menuConfig);
	// _game->setPlayers(getPlayers());
	_game->startGame();
	delete _game;
}