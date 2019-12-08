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
		if (!_running) {
			displayWinScreen();
		}
    		_window->refresh();
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
		if (tmp.empty) {
			return;
		}
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
		if (tmp.empty) {
			return;
		}
		sf::Vector2f pos = _p2->getPosition();
		tmp.sprite.scale(-1, 1);
		tmp.sprite.setPosition(pos.x - _p2->getSprite().getTextureRect().width , pos.y + 30);
		tmp.id = _b2;
		_p2Bullets.emplace(_b2++, tmp);
	}
}

void		Game::drawAll() {
	drawMap();
	drawPlayers();
	drawBullets();
	drawGUI();
}

void		Game::drawGUI() {
	_window->drawText("Player 1 hp:", 24, 30, 680);
	_window->drawText(std::to_string(_p1->getHP()), 24, 200, 680);

	_window->drawText("Player 2 hp:", 24, 1030, 680);
	_window->drawText(std::to_string(_p2->getHP()), 24, 1200, 680);
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
			// _p1Bullets.erase(b.second.id);
			b.second.empty = true;
			// break;
		}
		else if (gotP2Hit(b.second)) {
			// _p1Bullets.erase(b.second.id);
			b.second.empty = true;

			// break;
		}
		else if (bulletsCollide(b.second)) {
			// _p1Bullets.erase(b.second.id);
			b.second.empty = true;

			// break;
		}
	}
	for (auto &b : _p2Bullets) {
		b.second.sprite.move(-b.second.speed, 0);
		_window->drawSprite(b.second.sprite);
		if (b.second.sprite.getPosition().x < -200) {
			// _p2Bullets.erase(b.second.id);
			b.second.empty = true;

			// break;
		}
		else if (gotP1Hit(b.second)) {
			// _p2Bullets.erase(b.second.id);
			b.second.empty = true;

			// break;
		}
	}
	for (auto &b : _p1Bullets) {
		if (b.second.empty) {
			_p1Bullets.erase(b.second.id);
		}
	}
	for (auto &b : _p2Bullets) {
		if (b.second.empty) {
			_p2Bullets.erase(b.second.id);
		}
	}
}

bool		Game::bulletsCollide(const bullet &b) {
	sf::Rect <int>shape = b.sprite.getTextureRect();
	for (auto &b2 : _p2Bullets) {
		sf::Rect <int>shape2 = b2.second.sprite.getTextureRect();
		if (b.sprite.getPosition().x + shape.width > b2.second.sprite.getPosition().x - shape2.width &&
			b.sprite.getPosition().x < b2.second.sprite.getPosition().x && 
			b.sprite.getPosition().y + shape.height > b2.second.sprite.getPosition().y &&
			b.sprite.getPosition().y < b2.second.sprite.getPosition().y + shape2.height) {
			// _p2Bullets.erase(b2.second.id);
			b2.second.empty = true;
			return true;
		}
	}
	return false;
}

bool		Game::gotP2Hit(const bullet &b) {
	sf::Rect <int>shape = b.sprite.getTextureRect();
	sf::Rect <int>p2shape = _p2->getSprite().getTextureRect();
	if (b.sprite.getPosition().x + shape.width > _p2->getPosition().x - p2shape.width &&
		b.sprite.getPosition().x < _p2->getPosition().x && 
		b.sprite.getPosition().y + shape.height > _p2->getPosition().y &&
		b.sprite.getPosition().y < _p2->getPosition().y + p2shape.height) {
		_p2->gotHit(b.damage);
		if (_p2->isDead()) {
			quit();
		}
		return true;
	}
	return false;
}

bool		Game::gotP1Hit(const bullet &b) {
	sf::Rect <int>shape = b.sprite.getTextureRect();
	sf::Rect <int>p1shape = _p1->getSprite().getTextureRect();
	if (b.sprite.getPosition().x - shape.width < _p1->getPosition().x + p1shape.width &&
		b.sprite.getPosition().x > _p1->getPosition().x && 
		b.sprite.getPosition().y + shape.height > _p1->getPosition().y &&
		b.sprite.getPosition().y < _p1->getPosition().y + p1shape.height) {
		_p1->gotHit(b.damage);
		if (_p1->isDead()) {
			quit();
		}
		return true;
	}
	return false;
}

void		Game::drawMap() {
	_map->update();
}

bool		Game::isRunning() const 
{
	return (_running);
}

void		Game::quit()
{
	_running = false;
}

void		Game::displayWinScreen()
{
	int	select = 0;
	sf::sleep(sf::seconds(0.1));
	while (3)
	{
		_window->clear();
		if (_p1->getHP()) {
			_window->drawText("PLAYER 1 HAVE WON THE GAME", 62, 200, 250);
		}
		else {
			_window->drawText("PLAYER 2 HAVE WON THE GAME", 62, 200, 250);
		}
		_window->drawText("press SPACE to quit", 32, 450, 450);
		_window->refresh();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			break;
	}
}

