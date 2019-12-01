#ifndef IDISPLAY_HPP_
	#define IDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <experimental/random>

#define _WW	(1280)
#define _WH	(720)

#include <iostream>

enum	_KEYS
{
	_NULL,
	_KEY_UP,
	_KEY_DOWN,
	_KEY_RIGHT,
	_KEY_LEFT,
	_KEY_SPACE,
	_KEY_P,
	_KEY_M,
	_KEY_L,
	_KEY_G,
	_KEY_ENTER,
	_EXIT
};

typedef std::map<_KEYS, sf::Keyboard::Key>		PLAYER_KEYS;
typedef std::map<sf::Keyboard::Key, bool>		KEY_EVENT;

class IDisplay {
	public:
					~IDisplay() = default;
		virtual void		createWindow() = 0;
		virtual void		clear() = 0;
		virtual void		refresh() = 0;
		virtual bool		isOpen() = 0;
		virtual KEY_EVENT	checkEvents() = 0;
		virtual void		createSprite(const std::string &name, const std::string &path) = 0;
		virtual void		drawExistingSprite(const std::string &name) = 0;
		virtual void		drawSprite(sf::Sprite sprite) = 0;
		virtual void		drawText(const std::string &message, const int &size, const int &x, const int &y) = 0;
		virtual sf::Sprite	getExistingSprite(const std::string &name) = 0;
		virtual void		quit() = 0;
};

#endif /* !IDISPLAY_HPP_ */
