/*
** EPITECH PROJECT, 2018
** VK
** File description:
** mainMenu class implementation
*/

#include "MainMenu.hpp"

MainMenu::MainMenu(IDisplay *window, _MENU_SCENE scene) :
		_window(window), _idScene(scene)
{
}

void            MainMenu::initScene()
{
	createSprite("bg1", "./ressources/menu/bg1.png");
	createSprite("button", "./ressources/menu/button.png");
	createSprite("selector", "./ressources/menu/arrow.png");
	_selector = getSprite("selector");
	_selector_pos = 0;
	_MenuElements.push_back(std::make_pair(_PLAY, getSprite("button")));
	_MenuElements.push_back(std::make_pair(_EXIT_B, getSprite("button")));
	_MenuElements[0].second.setPosition(sf::Vector2f(875, 184));
	_MenuElements[1].second.setPosition(sf::Vector2f(875, 324));
	_elementsNB = 2;
	_selector.setPosition(_MenuElements[_selector_pos].second.getPosition());
	_selector.move(sf::Vector2f(-75, 4));
	setBackgroundParallax("bg1", 0.5);
}

_MENU_SCENE            MainMenu::startScene()
{
	_running = true;
	while (_running && _window->isOpen())
	{
		_window->clear();
		_Events =  _window->checkEvents();
		checkEvents();
		drawAll();
		_window->refresh();
	}
	return (_targetScene);
}

_MENU_SCENE	MainMenu::getSceneID()
{
	return (_idScene);
}

//PRROTECTED

void		MainMenu::checkEvents()
{
	if (_Events.at(sf::Keyboard::Return))
		action();
	if (_Events.at(sf::Keyboard::Up))
		moveSelector(_KEY_UP);
	if (_Events.at(sf::Keyboard::Down))
		moveSelector(_KEY_DOWN);
	if (_Events.at(sf::Keyboard::Escape))
		nextScene(_EXIT_SCENE);
}

void		MainMenu::drawAll()
{
	moveBackgroundParallax(_window);
	for (const auto &element : _MenuElements)
	{
		_window->drawSprite(element.second);
	}
	_window->drawText("MAIN MENU", 48, 550, 20);
	_window->drawText("P L A Y", 30, 920, 190);
	_window->drawText("E X I T", 30, 920, 330);
	_window->drawSprite(_selector);
}

void		MainMenu::action()
{
	if (_MenuElements[_selector_pos].first == _PLAY)
	{
		nextScene(_GAME_CONFIG);
	}
	else if (_MenuElements[_selector_pos].first == _EXIT_B)
		nextScene(_EXIT_SCENE);
}

void		MainMenu::nextScene(_MENU_SCENE nextScene)
{
	quit();
	_targetScene = nextScene;
}

void		MainMenu::moveSelector(_KEYS dir)
{
	if (checkTimer(0.075))
	{
		if (dir == _KEY_DOWN && _selector_pos + 1 < _elementsNB)
		{
			_selector_pos += 1;
			_selector.setPosition(_MenuElements[_selector_pos].second.getPosition());
			_selector.move(sf::Vector2f(-75, 4));
		}
		else if (dir == _KEY_UP && _selector_pos -1 >= 0)
		{
			_selector_pos -= 1;
			_selector.setPosition(_MenuElements[_selector_pos].second.getPosition());
			_selector.move(sf::Vector2f(-75, 4));
		}
	}
}

void		MainMenu::quit()
{
	_running = false;
	_MenuElements.clear();
}

bool		MainMenu::checkTimer(float seconds)
{
	if (_rateClock.getElapsedTime().asSeconds() > seconds) {
		_rateClock.restart();
		return (true);
	}
	else
		return (false);
}