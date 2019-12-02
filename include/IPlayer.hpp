#ifndef IPLAYER_HPP_
	#define IPLAYER_HPP_

#include "IDisplay.hpp"
#include "IWeapon.hpp"
#include <map>

enum    _P_MOVE {
        _UP,
        _UP_RIGHT,
        _RIGHT,
        _DOWN_RIGHT,
        _DOWN,
        _DOWN_LEFT,
        _LEFT,
        _UP_LEFT,
};

class IPlayer {
	public:
		virtual void			setSprite(sf::Sprite sprite) = 0;
                virtual void                    initTextures() = 0;
		virtual sf::Sprite		&getSprite() = 0;
		virtual sf::Sprite		getSpritePlain() = 0;
		virtual void			setPosition(const int &x, const int &y) = 0;
		virtual const sf::Vector2f	&getPosition() = 0;
		virtual void			move(const _P_MOVE &dir) = 0;
		virtual void			setWeapon(IWeapon *weapon) = 0;
		virtual IWeapon			*getWeapon() const = 0;
		virtual bullet			fire() = 0;
		virtual void			gotHit(const int &damage) = 0;
		virtual bool			isDead() = 0;
		virtual const int		&getHP() const = 0;
		virtual const std::string	&getName() const = 0;
		virtual const float     	&getSpeed() const = 0;

};

typedef std::map<std::string, IPlayer*>	_PLAYERS;

#endif