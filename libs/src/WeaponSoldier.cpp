#include "../../include/IWeapon.hpp"

class WeaponSoldier : public IWeapon {
        public:
		WeaponSoldier();
		~WeaponSoldier();

		void			setSprite(sf::Sprite sprite);
                void                    initTextures();
		sf::Sprite		&getSprite();
		sf::Sprite		getSpritePlain();
		void			setPosition(const int &x, const int &y);
		bullet                  fire();
		const std::string	&getName() const;
		const float		&getSpeed() const;
		const float		&getFireSpeed() const;
		const int	        &getDamage() const;

	private:
		std::string		_name;
		sf::Sprite		_sprite;
		sf::Texture		_texture;
                float                   _speed;
                float                   _fireSpeed;
                int                     _damage;
		sf::Vector2f		_pos;
                bullet                  _bullet;
};

WeaponSoldier::WeaponSoldier() {
	_name = "Soldier";
	_speed = 1.6;
        _fireSpeed = 1;
        _damage = 20;
	initTextures();
        _bullet.damage = _damage;
        _bullet.speed = _speed;
        _bullet.sprite = getSpritePlain();
}

WeaponSoldier::~WeaponSoldier(){
	
}

void		WeaponSoldier::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    WeaponSoldier::initTextures() {
	std::string	path = "./libs/weapons/ressources/WeaponSoldier.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&WeaponSoldier::getSprite() {
	return (_sprite);
}

sf::Sprite		WeaponSoldier::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			WeaponSoldier::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

bullet			WeaponSoldier::fire() {
	return _bullet;
}


const std::string	&WeaponSoldier::getName() const {
	return _name;
}
const float		&WeaponSoldier::getSpeed() const {
	return _speed;
}
const float		&WeaponSoldier::getFireSpeed() const {
	return _fireSpeed;
}

const int	        &WeaponSoldier::getDamage() const {
        return _damage;
}

extern "C"
WeaponSoldier            *getInstance()
{
	WeaponSoldier *tmp = new WeaponSoldier();
        return tmp;
}