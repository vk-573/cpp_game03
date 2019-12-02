#include "Display.hpp"

void		Display::createWindow()
{
	_open = true;
	_Window.create(sf::VideoMode(_WW, _WH), "Game");
	_Window.setFramerateLimit(42);
	createEvents();
	if (!_font.loadFromFile("./ressources/fonts/lunchds.ttf"))
	{
		std::cerr << "Couldn't load the font" << std::endl;
		exit(84);
	}
	_text.setFont(_font);
}

void		Display::clear()
{
	_Window.clear();
}

void		Display::refresh()
{
	_Window.display();
}

bool		Display::isOpen()
{
	return (_open);
}

KEY_EVENT	Display::checkEvents()
{
	resetEvents();
	while (_Window.pollEvent(_Event))
	{
 		if (_Event.type == sf::Event::Closed)
				quit();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				_Events.at(sf::Keyboard::Escape) = true;
				std::cout << "lolol" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				_Events.at(sf::Keyboard::Return) = true;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			// puts("key space pressed");
			_Events.at(sf::Keyboard::Space) = true; 

		}
	}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			// puts("key up pressed");
			_Events.at(sf::Keyboard::Up) = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			// puts("key down pressed");
			_Events.at(sf::Keyboard::Down) = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			// puts("key left pressed");
			_Events.at(sf::Keyboard::Left) = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			// puts("key right pressed");
		_Events.at(sf::Keyboard::Right) = true;
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		_Events.at(sf::Keyboard::Z) = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_Events.at(sf::Keyboard::D) = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_Events.at(sf::Keyboard::S) = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		_Events.at(sf::Keyboard::Q) = true;
	}
	return (_Events);
}

void		Display::quit()
{
	_open = false;
	_Window.close();
}

void		Display::createSprite(const std::string &name, const std::string &path)
{
	initTexture(path, name);
	setSprite(name);
}

void		Display::drawExistingSprite(const std::string &name)
{
	_Window.draw(_Sprites.at(name));
}

sf::Sprite	Display::getExistingSprite(const std::string &name)
{
	return (_Sprites.at(name));
}

void		Display::drawSprite(sf::Sprite sprite)
{
	_Window.draw(sprite);
}

void		Display::drawText(const std::string &message, const int &size, const int &x, const int &y)
{
	_text.setPosition(sf::Vector2f(x, y));
	_text.setString(message);
	_text.setCharacterSize(size);
	_Window.draw(_text);
}

//// PRIVATE

void		Display::initTexture(const std::string &path, const std::string &name)
{
	sf::Texture	texture;

	if (!texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	} else {
		_Textures.insert(std::pair<std::string, sf::Texture>(name, texture));
	}
}

void		Display::setSprite(const std::string &name)
{
	sf::Sprite			sprite;

	sprite.setTexture(_Textures.at(name));
	_Sprites.insert(std::pair<std::string, sf::Sprite>(name, sprite));
}


void		Display::createEvents()
{
	// _Events.emplace(_KEY_UP, false);
	// _Events.emplace(_KEY_RIGHT, false);
	// _Events.emplace(_KEY_DOWN, false);
	// _Events.emplace(_KEY_LEFT, false);
	// _Events.emplace(_KEY_SPACE, false);
	// _Events.emplace(_KEY_ENTER, false);
	// _Events.emplace(_EXIT, false);
	_Events.emplace(sf::Keyboard::Up, false);
	_Events.emplace(sf::Keyboard::Right, false);
	_Events.emplace(sf::Keyboard::Down, false);
	_Events.emplace(sf::Keyboard::Left, false);
	_Events.emplace(sf::Keyboard::Space, false);
	_Events.emplace(sf::Keyboard::Escape, false);
	_Events.emplace(sf::Keyboard::Return, false);
	_Events.emplace(sf::Keyboard::LControl, false);
	_Events.emplace(sf::Keyboard::LShift, false);
	_Events.emplace(sf::Keyboard::LAlt, false);
	_Events.emplace(sf::Keyboard::LSystem, false);
	_Events.emplace(sf::Keyboard::RControl, false);
	_Events.emplace(sf::Keyboard::RShift, false);
	_Events.emplace(sf::Keyboard::RAlt, false);
	_Events.emplace(sf::Keyboard::RSystem, false);
	_Events.emplace(sf::Keyboard::Tab, false);
	_Events.emplace(sf::Keyboard::A, false);
	_Events.emplace(sf::Keyboard::B, false);
	_Events.emplace(sf::Keyboard::C, false);
	_Events.emplace(sf::Keyboard::D, false);
	_Events.emplace(sf::Keyboard::E, false);
	_Events.emplace(sf::Keyboard::F, false);
	_Events.emplace(sf::Keyboard::G, false);
	_Events.emplace(sf::Keyboard::I, false);
	_Events.emplace(sf::Keyboard::J, false);
	_Events.emplace(sf::Keyboard::K, false);
	_Events.emplace(sf::Keyboard::L, false);
	_Events.emplace(sf::Keyboard::M, false);
	_Events.emplace(sf::Keyboard::N, false);
	_Events.emplace(sf::Keyboard::O, false);
	_Events.emplace(sf::Keyboard::P, false);
	_Events.emplace(sf::Keyboard::Q, false);
	_Events.emplace(sf::Keyboard::P, false);
	_Events.emplace(sf::Keyboard::Q, false);
	_Events.emplace(sf::Keyboard::R, false);
	_Events.emplace(sf::Keyboard::S, false);
	_Events.emplace(sf::Keyboard::T, false);
	_Events.emplace(sf::Keyboard::U, false);
	_Events.emplace(sf::Keyboard::V, false);
	_Events.emplace(sf::Keyboard::W, false);
	_Events.emplace(sf::Keyboard::X, false);
	_Events.emplace(sf::Keyboard::Y, false);
	_Events.emplace(sf::Keyboard::Z, false);
}

void		Display::resetEvents()
{
	// _Events.at(_KEY_UP) = false;
	// _Events.at(_KEY_RIGHT) = false;
	// _Events.at(_KEY_DOWN) = false;
	// _Events.at(_KEY_LEFT) = false;
	// _Events.at(_KEY_SPACE) = false;
	// _Events.at(_KEY_ENTER) = false;
	// _Events.at(_EXIT) = false;
	// _Events.emplace(sf::Keyboard:Up, false);
	// _Events.emplace(sf::Keyboard:Right, false);
	// _Events.emplace(sf::Keyboard:Down, false);
	// _Events.emplace(sf::Keyboard:Left, false);
	// _Events.emplace(sf::Keyboard:Space, false);
	// _Events.emplace(sf::Keyboard:Escape, false);
	// _Events.emplace(sf::Keyboard:Enter, false);
	// _Events.emplace(sf::Keyboard:LControl, false);
	// _Events.emplace(sf::Keyboard:LShift, false);
	// _Events.emplace(sf::Keyboard:LAlt, false);
	// _Events.emplace(sf::Keyboard:LSystem, false);
	// _Events.emplace(sf::Keyboard:RControl, false);
	// _Events.emplace(sf::Keyboard:RShift, false);
	// _Events.emplace(sf::Keyboard:RAlt, false);
	// _Events.emplace(sf::Keyboard:RSystem, false);
	// _Events.emplace(sf::Keyboard:Tab, false);
	// _Events.emplace(sf::Keyboard:A, false);
	// _Events.emplace(sf::Keyboard:B, false);
	// _Events.emplace(sf::Keyboard:C, false);
	// _Events.emplace(sf::Keyboard:D, false);
	// _Events.emplace(sf::Keyboard:E, false);
	// _Events.emplace(sf::Keyboard:F, false);
	// _Events.emplace(sf::Keyboard:G, false);
	// _Events.emplace(sf::Keyboard:I, false);
	// _Events.emplace(sf::Keyboard:J, false);
	// _Events.emplace(sf::Keyboard:K, false);
	// _Events.emplace(sf::Keyboard:L, false);
	// _Events.emplace(sf::Keyboard:M, false);
	// _Events.emplace(sf::Keyboard:N, false);
	// _Events.emplace(sf::Keyboard:O, false);
	// _Events.emplace(sf::Keyboard:P, false);
	// _Events.emplace(sf::Keyboard:Q, false);
	// _Events.emplace(sf::Keyboard:P, false);
	// _Events.emplace(sf::Keyboard:Q, false);
	// _Events.emplace(sf::Keyboard:R, false);
	// _Events.emplace(sf::Keyboard:S, false);
	// _Events.emplace(sf::Keyboard:T, false);
	// _Events.emplace(sf::Keyboard:U, false);
	// _Events.emplace(sf::Keyboard:V, false);
	// _Events.emplace(sf::Keyboard:W, false);
	// _Events.emplace(sf::Keyboard:X, false);
	// _Evenatace(sf::Keyboard:Y) = false;
	// _Evenatace(sf::Keyboard:Z) = false;
	_Events.at(sf::Keyboard::Up) = false;
	_Events.at(sf::Keyboard::Right) = false;
	_Events.at(sf::Keyboard::Down) = false;
	_Events.at(sf::Keyboard::Left) = false;
	_Events.at(sf::Keyboard::Space) = false;
	_Events.at(sf::Keyboard::Escape) = false;
	_Events.at(sf::Keyboard::Return) = false;
	// _Events.at(sf::Keyboard:Enter) = false;
	// _Events.at(sf::Keyboard:LControl) = false;
	// _Events.at(sf::Keyboard:LShift) = false;
	_Events.at(sf::Keyboard::LAlt) = false;
	// _Events.at(sf::Keyboard:LSystem) = false;
	// _Events.at(sf::Keyboard:RControl) = false;
	// _Events.at(sf::Keyboard:RShift) = false;
	// _Events.at(sf::Keyboard:RAlt) = false;
	// _Events.at(sf::Keyboard:RSystem) = false;
	// _Events.at(sf::Keyboard:Tab) = false;
	// _Events.at(sf::Keyboard:A) = false;
	// _Events.at(sf::Keyboard:B) = false;
	// _Events.at(sf::Keyboard:C) = false;
	_Events.at(sf::Keyboard::D) = false;
	// _Events.at(sf::Keyboard:E) = false;
	// _Events.at(sf::Keyboard:F) = false;
	// _Events.at(sf::Keyboard:G) = false;
	// _Events.at(sf::Keyboard:I) = false;
	// _Events.at(sf::Keyboard:J) = false;
	// _Events.at(sf::Keyboard:K) = false;
	// _Events.at(sf::Keyboard:L) = false;
	// _Events.at(sf::Keyboard:M) = false;
	// _Events.at(sf::Keyboard:N) = false;
	// _Events.at(sf::Keyboard:O) = false;
	// _Events.at(sf::Keyboard:P) = false;
	// _Events.at(sf::Keyboard:Q) = false;
	// _Events.at(sf::Keyboard:P) = false;
	_Events.at(sf::Keyboard::Q) = false;
	// _Events.at(sf::Keyboard:R) = false;
	_Events.at(sf::Keyboard::S) = false;
	// _Events.at(sf::Keyboard:T) = false;
	// _Events.at(sf::Keyboard:U) = false;
	// _Events.at(sf::Keyboard:V) = false;
	// _Events.at(sf::Keyboard:W) = false;
	// _Events.at(sf::Keyboard:X) = false;
	// _Events.at(sf::Keyboard:Y) = false;
	_Events.at(sf::Keyboard::Z) = false;
}
