#ifndef IWEAPON_HPP_
	#define IWEAPON_HPP_

#include "IDisplay.hpp"
#include <map>

typedef struct		my_struct_bullet
{
	float		damage;
	float		speed;
	sf::Sprite	sprite;
	int		id;
}			bullet;

class IWeapon {
	public:
		virtual void			setSprite(sf::Sprite sprite) = 0;
                virtual void                    initTextures() = 0;
		virtual sf::Sprite		&getSprite() const = 0;
		virtual sf::Sprite		getSpritePlain() = 0;
		virtual void			setPosition(const int &x, const int &y) = 0;
                virtual const std::string       &getName() const = 0;
		virtual void			move() = 0;
		virtual std::vector<bullet>	fire() = 0;
		virtual const int		&getDamage() const = 0;

};

typedef std::map<std::string, IWeapon*>	_WEAPONS;

#endif