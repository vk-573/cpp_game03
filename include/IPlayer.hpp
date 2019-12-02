#ifndef IPLAYER_HPP_
	#define IPLAYER_HPP_

#include "IDisplay.hpp"
#include "IWeapon.hpp"
#include <map>


class IPlayer {
	public:
		virtual void			setSprite(sf::Sprite sprite) = 0;
                virtual void                    initTextures() = 0;
		virtual sf::Sprite		&getSprite() = 0;
		virtual sf::Sprite		getSpritePlain() = 0;
		virtual void			setPosition(const int &x, const int &y) = 0;
		virtual void			move(const int &dir) = 0;
		virtual void			setWeapon(IWeapon *weapon) = 0;
		virtual IWeapon			*getWeapon() const = 0;
		virtual void			fire() = 0;
		virtual void			gotHit(const int &damage) = 0;
		virtual bool			isDead() = 0;
		virtual const int		&getHP() const = 0;
		virtual const std::string	&getName() const = 0;

};

typedef std::map<std::string, IPlayer*>	_PLAYERS;

#endif