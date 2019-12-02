#include "GameConfigScene.hpp"

void            GameConfigScene::initScene()
{
        createSprite("background1", "./ressources/menu/bg1.png");
	createSprite("button", "./ressources/menu/button.png");
	createSprite("changeArrows", "./ressources/menu/changeArrows.png");
	createSprite("selector", "./ressources/menu/arrow.png");
	setPlayers(_menuConfig->getPlayers());
	// setWeapons(_menuConfig->getWeapons());
	// setMaps(_menuConfig->getMaps());
	_selector = getSprite("selector");
	_selector_pos = 0;
	// _maxShips = _menuConfig->getPlayers().size();
	// _P1 = _menuConfig->getPlayers().at(_FIRST)->getSpritePlain();
	// _P1.setPosition(sf::Vector2f(560, 170));
	_window->drawText("1st player :", 24, 840, 25);
	_window->drawText("1st P weapon :", 24, 840, 145);

	_window->drawText("2nd player :", 24, 840, 280);
	_window->drawText("2nd P weapon :", 24, 840, 400);

	_MenuElements.push_back(std::make_pair(_PLAYER1, getSprite("changeArrows")));
	_MenuElements[0].second.setPosition(sf::Vector2f(770, 60));
	oneplayer = false;
	// _P2 = _menuConfig->getPlayers().at(_SECOND)->getSpritePlain();
	// _P2.setPosition(sf::Vector2f(860, 350));
	_MenuElements.push_back(std::make_pair(_PLAYER1_WEAPON, getSprite("changeArrows")));
	_MenuElements[1].second.setPosition(sf::Vector2f(770, 185));
	_MenuElements.push_back(std::make_pair(_PLAYER2, getSprite("changeArrows")));
	_MenuElements[2].second.setPosition(sf::Vector2f(770, 320));
	_MenuElements.push_back(std::make_pair(_PLAYER2_WEAPON, getSprite("changeArrows")));
	_MenuElements[3].second.setPosition(sf::Vector2f(770, 440));
	_MenuElements.push_back(std::make_pair(_PLAY, getSprite("button")));
	_MenuElements.push_back(std::make_pair(_BACK, getSprite("button")));
	_MenuElements[4].second.setPosition(sf::Vector2f(825, 572));
	_MenuElements[5].second.setPosition(sf::Vector2f(825, 652));
	_elementsNB = _MenuElements.size();
	_selector.setPosition(_MenuElements[_selector_pos].second.getPosition());
	_selector.move(sf::Vector2f(-55, 5));
	setBackgroundParallax("background1", 0.5);
}

_MENU_SCENE            GameConfigScene::startScene()
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

_MENU_SCENE	GameConfigScene::getSceneID()
{
	return (_idScene);
}

// PRIVATE 

void            GameConfigScene::drawAll()
{
        moveBackgroundParallax(_window);
	for (const auto &element : _MenuElements)
	{
		_window->drawSprite(element.second);
	}
	_window->drawText("CONFIGURATION", 48, 50, 20);
	_window->drawText("1st player :", 24, 840, 25);
	_window->drawText("1st P weapon :", 24, 840, 145);

	_window->drawText("2nd player :", 24, 840, 280);
	_window->drawText("2nd P weapon :", 24, 840, 400);
        _window->drawText("P L A Y", 30, 865, 580);
	_window->drawText("B A C K", 30, 865, 660);

	//plugins
	sf::Sprite tmpP1 = _currentP1->getSpritePlain();
	tmpP1.setPosition(860, 60);
	sf::Sprite tmpP2 = _currentP2->getSpritePlain();
	_window->drawText("Name:", 20, 1090, 40);
	_window->drawText(_currentP1->getName(), 26, 1160, 36);
	_window->drawText("HP:", 20, 1090, 70);
	_window->drawText(std::to_string(_currentP1->getHP()), 26, 1160, 66);
	_window->drawText("Speed:", 20, 1090, 100);
	_window->drawText(std::to_string(_currentP1->getSpeed()), 25, 1160, 96);

	tmpP2.setPosition(860, 316);

	_window->drawSprite(tmpP1);
	_window->drawSprite(tmpP2);
	_window->drawSprite(_selector);
}

void		GameConfigScene::checkEvents()
{
	if (_Events.at(sf::Keyboard::Return))
		action();
	if (_Events.at(sf::Keyboard::Up))
		moveSelector(_KEY_UP);
	if (_Events.at(sf::Keyboard::Down))
		moveSelector(_KEY_DOWN);
	if (_Events.at(sf::Keyboard::Right))
		changeState(_KEY_RIGHT);
	if (_Events.at(sf::Keyboard::Left))
		changeState(_KEY_LEFT);
	if (_Events.at(sf::Keyboard::Escape))
		nextScene(_MAIN_MENU);
}

void            GameConfigScene::action()
{
        if (_MenuElements[_selector_pos].first == _PLAY)
	{
		// _menuConfig->_P1 = (_PLAYERS)_P1_pos;
		// _menuConfig->_P2 = (_PLAYERS)_P2_pos;

		nextScene(_PLAY_GAME);
	}
	else if (_MenuElements[_selector_pos].first == _BACK)
        {
		nextScene(_MAIN_MENU);
        }
}

void		GameConfigScene::changeState(_KEYS key)
{
	if (checkTimer(0.1))
		if (_MenuElements[_selector_pos].first == _PLAYER1)
			changePlayer1(key);
		else if (_MenuElements[_selector_pos].first == _PLAYER1_WEAPON)
			changePlayer1W(key);
		else if (_MenuElements[_selector_pos].first == _PLAYER2)
			changePlayer2(key);
		else if (_MenuElements[_selector_pos].first == _PLAYER2_WEAPON)
			changePlayer2W(key);
		else if (_MenuElements[_selector_pos].first == _MAP)
			changeMap(key);
}

void		GameConfigScene::moveSelector(_KEYS dir)
{
	if (checkTimer(0.075))
	{
		if (dir == _KEY_DOWN && _selector_pos + 1 < _elementsNB)
		{
			_selector_pos += 1;
			_selector.setPosition(_MenuElements[_selector_pos].second.getPosition());
                        if (_MenuElements[_selector_pos].first == _PLAY || _MenuElements[_selector_pos].first == _BACK)
			        _selector.move(sf::Vector2f(-75, 4));
                        else
			        _selector.move(sf::Vector2f(-55, 5));

		}
		else if (dir == _KEY_UP && _selector_pos -1 >= 0)
		{
			_selector_pos -= 1;
			_selector.setPosition(_MenuElements[_selector_pos].second.getPosition());
                        if (_MenuElements[_selector_pos].first == _PLAY || _MenuElements[_selector_pos].first == _BACK)
			        _selector.move(sf::Vector2f(-75, 4));
                        else
			        _selector.move(sf::Vector2f(-55, 5));
		}
	}
}

void		GameConfigScene::changePlayer1(_KEYS key) {
	if (key == _KEY_RIGHT) {
		if (_currentP1pos + 1 >= _Players.size()) {
			return;	
		}
		else {
			_currentP1pos += 1;
			_currentP1 = _Players[_currentP1pos];
		}
	} else {
		if (_currentP1pos - 1 < 0) {
			return;	
		}
		else {
			_currentP1pos -= 1;
			_currentP1 = _Players[_currentP1pos];
		}
	}
}

void		GameConfigScene::changePlayer1W(_KEYS key) {
	// if (key == _KEY_RIGHT) {
	// 	if (_currentP1Wpos + 1 >= _Weapons.size()) {
	// 		return;	
	// 	}
	// 	else {
	// 		_currentP1Wpos += 1;
	// 		_currentP1W = _Weapons[_currentP1Wpos];
	// 	}
	// } else {
	// 	if (_currentP1pos - 1 < 0) {
	// 		return;	
	// 	}
	// 	else {
	// 		_currentP1Wpos -= 1;
	// 		_currentP1W = _Weapons[_currentP1Wpos];
	// 	}
	// }
}

void		GameConfigScene::changePlayer2(_KEYS key) {
	if (key == _KEY_RIGHT) {
		if (_currentP2pos + 1 >= _Players.size()) {
			return;	
		}
		else {
			_currentP2pos += 1;
			_currentP2 = _Players[_currentP2pos];
		}
	} else {
		if (_currentP2pos - 1 < 0) {
			return;	
		}
		else {
			_currentP2pos -= 1;
			_currentP2 = _Players[_currentP2pos];
		}
	}
}

void		GameConfigScene::changePlayer2W(_KEYS key) {
	// if (key == _KEY_RIGHT) {
	// 	if (_currentP2Wpos + 1 >= _Weapons.size()) {
	// 		return;	
	// 	}
	// 	else {
	// 		_currentP2Wpos += 1;
	// 		_currentP2W = _Weapons[_currentP2Wpos];
	// 	}
	// } else {
	// 	if (_currentP2pos - 1 < 0) {
	// 		return;	
	// 	}
	// 	else {
	// 		_currentP2Wpos -= 1;
	// 		_currentP2W = _Weapons[_currentP2Wpos];
	// 	}
	// }
}

void		GameConfigScene::changeMap(_KEYS key) {
	// if (key == _KEY_RIGHT) {
	// 	if (_currentMappos + 1 >= _Maps.size()) {
	// 		return;	
	// 	}
	// 	else {
	// 		_currentMappos += 1;
	// 		_currentMap = _Maps[_currentMappos];
	// 	}
	// } else {
	// 	if (_currentP1pos - 1 < 0) {
	// 		return;	
	// 	}
	// 	else {
	// 		_currentMappos -= 1;
	// 		_currentMap = _Maps[_currentMappos];
	// 	}
	// }
}

// void		GameConfigScene::changeShip1(_KEYS key)
// {
	// if (key == _KEY_RIGHT)
	// {
	// 	if (_P1_pos + 1 != _P2_pos || oneplayer)
	// 		_P1_pos += 1;
	// 	else
	// 		_P1_pos += 2;
	// 	if (_P1_pos >= _maxShips)
	// 	{
	// 		if (_P2_pos == 0 && !oneplayer)
	// 			_P1_pos = 1;
	// 		else
	// 			_P1_pos = 0;
	// 	}
	// 	_P1 = _menuConfig->getPlayers().at((_PLAYERS)_P1_pos)->getSpritePlain();
	// 	_P1.setPosition(sf::Vector2f(560, 170));
	// }
	// else
	// {
	// 	if (_P1_pos - 1 != _P2_pos || oneplayer)
	// 		_P1_pos -= 1;
	// 	else
	// 		_P1_pos -= 2;
	// 	if (_P1_pos <= -1)
	// 	{
	// 		_P1_pos = _maxShips - 1;
	// 		if (_P1_pos == _P2_pos && !oneplayer)
	// 			_P1_pos -= 1;
	// 	}
	// 	_P1 = _menuConfig->getPlayers().at((_PLAYERS)_P1_pos)->getSpritePlain();
	// 	_P1.setPosition(sf::Vector2f(560, 170));
	// }

// }

// void		GameConfigScene::changeShip2(_KEYS key)
// {
	// if (key == _KEY_RIGHT)
	// {
	// 	if (_P2_pos + 1 != _P1_pos)
	// 		_P2_pos += 1;
	// 	else
	// 		_P2_pos += 2;
	// 	if (_P2_pos >= _maxShips)
	// 	{
	// 		if (_P1_pos == 0)
	// 			_P2_pos = 1;
	// 		else
	// 			_P2_pos = 0;
	// 	}
	// 	_P2 = _menuConfig->getPlayers().at((_PLAYERS)_P2_pos)->getSpritePlain();
	// 	_P2.setPosition(sf::Vector2f(560, 350));
	// }
	// else
	// {
	// 	if (_P2_pos - 1 != _P1_pos)
	// 		_P2_pos -= 1;
	// 	else
	// 		_P2_pos -= 2;
	// 	if (_P2_pos <= -1)
	// 	{
	// 		_P2_pos = _maxShips - 1;
	// 		if (_P1_pos == _P2_pos)
	// 			_P2_pos -= 1;
	// 	}			
	// 	_P2 = _menuConfig->getPlayers().at((_PLAYERS)_P2_pos)->getSpritePlain();
	// 	_P2.setPosition(sf::Vector2f(560, 350));
	// }
// }

void		GameConfigScene::setPlayers(_PLAYERS players) {
	for (auto p : players) {
		_Players.push_back(p.second);
		std::cout << "p : " << p.second->getName() << std::endl;
	}
	_currentP1 = _Players[0];
	_currentP1pos = 0;
	_currentP2 = _Players[0];
	_currentP2pos = 0;
	std::cout << "P1 : " << _currentP1->getName() << std::endl;
	std::cout << "P2 : " << _currentP2->getName() << std::endl;
}
void		GameConfigScene::setWeapons(_WEAPONS weapons) {
	for (auto w : weapons) {
		_Weapons.push_back(w.second);
	}
	// _currentP1W = _Weapons[0];
	// _currentP1Wpos = 0;
	// _currentP2W = _Weapons[0];
	// _currentP2Wpos = 0;
}
void		GameConfigScene::setMaps(_MAPS maps) {
	for (auto m : maps) {
		_Maps.push_back(m.second);
	}
	// _currentMap = _Maps[0];
	// _currentMappos = 0;
}