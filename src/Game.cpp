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

}

void		Game::initGame(MenuConfig *menuConfig)
{
	_menuConfig = menuConfig;
	_p1 = _menuConfig->getCurrentP1();
	_p2 = _menuConfig->getCurrentP2();
	_map = _menuConfig->getCurrentMap();

	std::cout << "p1 name: " << _p1->getName() << std::endl;
	std::cout << "p1 weap: " << _p1->getWeapon()->getName() << std::endl;
	std::cout << "p2 name: " << _p2->getName() << std::endl;
	std::cout << "p2 weap: " << _p2->getWeapon()->getName() << std::endl;
	std::cout << "current Map:: " << _map->getName() << std::endl;	

	_map->init(_window);
	_p1->setPosition(100, 320);
	_p2->setPosition(900, 320);
	_p2->getSprite().scale(-1, 1);
}

void		Game::startGame()
{
	_running = true;
	// _STAGE_END_STATE endState;
	while (_window->isOpen() && isRunning())
	{

		// _seconds = _timer.getElapsedTime().asSeconds() - _pauseSecs;
		_window->clear();
		_Events = _window->checkEvents();
		processEvents();
		drawAll();
		// checkFinished();
		// if (_lost)
		// 	displayLostScreen();
		// else if (_win)
		// 	displayWinScreen();
    		_window->refresh();
		// std::cout << "playing !" << std::endl;
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

void		Game::processEvents() {
	if (_Events.at(sf::Keyboard::Escape)) {
		quit();
	}
	processPlayer1();
	processPlayer2();
}

void		Game::processPlayer1() {
	bool up = false;
	bool right = false;
	bool down = false;
	bool left = false;
	if (_Events.at(sf::Keyboard::Z)) {
		up = true;
	}
	if (_Events.at(sf::Keyboard::D)) {
		right = true;
	}
	if (_Events.at(sf::Keyboard::S)) {
		down = true;
	}
	if (_Events.at(sf::Keyboard::Q)) {
		left = true;
	}
	if (up && right) {
		_p1->move(_UP_RIGHT);
	} else if (down && right) {
		_p1->move(_DOWN_RIGHT);
	} else if (down && left) {
		_p1->move(_DOWN_LEFT);
	} else if (up && left) {
		_p1->move(_UP_LEFT);
	} else if (up && !down) {
		_p1->move(_UP);
	} else if (!up && down) {
		_p1->move(_DOWN);
	} else if (!left && right) {
		_p1->move(_RIGHT);
	} else if (left && !right) {
		_p1->move(_LEFT);
	}
	if (_Events.at(sf::Keyboard::Space)) {
		bullet tmp = _p1->fire();
		sf::Vector2f pos = _p1->getPosition();
		tmp.sprite.setPosition(pos.x + _p1->getSprite().getTextureRect().width , pos.y + 30);
		tmp.id = _b1;
		_p1Bullets.emplace(_b1++, tmp);
	}
}

void		Game::processPlayer2() {
	bool up = false;
	bool right = false;
	bool down = false;
	bool left = false;
	if (_Events.at(sf::Keyboard::Up)) {
		up = true;
	}
	if (_Events.at(sf::Keyboard::Right)) {
		right = true;
	}
	if (_Events.at(sf::Keyboard::Down)) {
		down = true;
	}
	if (_Events.at(sf::Keyboard::Left)) {
		left = true;
	}
	if (up && right) {
		_p2->move(_UP_RIGHT);
	} else if (down && right) {
		_p2->move(_DOWN_RIGHT);
	} else if (down && left) {
		_p2->move(_DOWN_LEFT);
	} else if (up && left) {
		_p2->move(_UP_LEFT);
	} else if (up && !down) {
		_p2->move(_UP);
	} else if (!up && down) {
		_p2->move(_DOWN);
	} else if (!left && right) {
		_p2->move(_RIGHT);
	} else if (left && !right) {
		_p2->move(_LEFT);
	}
	if (_Events.at(sf::Keyboard::Return)) {
		bullet tmp = _p2->fire();
		sf::Vector2f pos = _p2->getPosition();
		tmp.sprite.scale(-1, 1);
		tmp.sprite.setPosition(pos.x - _p2->getSprite().getTextureRect().width , pos.y + 30);
		tmp.id = _b2;
		_p2Bullets.emplace(_b2++, tmp);
		std::cout << "width:" << tmp.sprite.getTextureRect().width << std::endl;
		std::cout << "height:" << tmp.sprite.getTextureRect().height << std::endl;
	}
}

void		Game::drawAll() {
	drawMap();
	drawPlayers();
	drawBullets();
}

void		Game::drawPlayers() {
	_window->drawSprite(_p1->getSprite());
	_window->drawSprite(_p2->getSprite());
}

void		Game::drawBullets() {
	for (auto &b : _p1Bullets) {
		b.second.sprite.move(b.second.speed, 0);
		_window->drawSprite(b.second.sprite);
		if (b.second.sprite.getPosition().x > 1300) {
			_p1Bullets.erase(b.second.id);
		}
		if (gotP2Hit(b.second)) {
			_p1Bullets.erase(b.second.id);
		}
	}
	for (auto &b : _p2Bullets) {
		b.second.sprite.move(-b.second.speed, 0);
		_window->drawSprite(b.second.sprite);
		if (b.second.sprite.getPosition().x < -200) {
			_p2Bullets.erase(b.second.id);
		}
		if (gotP1Hit(b.second)) {
			_p2Bullets.erase(b.second.id);
		}
	}
}

bool		Game::gotP2Hit(const bullet &b) {
	return false;
}

bool		Game::gotP1Hit(const bullet &b) {
	return false;
}

void		Game::drawMap() {
	_map->update();
	// for (sf::Sprite tmp : _map->getSprites()) {
	// 	_window->drawSprite(tmp);
	// }
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
	// int	select = 0;
	// sf::sleep(sf::seconds(0.1));
	// while (3)
	// {
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
	// }
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
