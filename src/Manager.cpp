#include "Manager.hpp"

Manager::Manager(IDisplay *window)
{
	_window = window;
}

Manager::~Manager() {
	delete _menuConfig;
	delete _game;
	for (auto scene : _Scenes) {
		delete scene.second;
	}
}

void            Manager::initManager()
{
	_menuConfig = new MenuConfig();
	initScenes();
	_menuConfig->getPluginManager()->getPlayerInstance("Jojo");
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
	_game->startGame();
	delete _game;
}