#include "../../include/IWeapon.hpp"

class WeaponSpeedy : public IWeapon {
        public:
		WeaponSpeedy();
		~WeaponSpeedy();

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

WeaponSpeedy::WeaponSpeedy() {
	_name = "Speedy";
	_speed = 2.5;
        _fireSpeed = 1.3;
        _damage = 10;
	initTextures();
        _bullet.damage = _damage;
        _bullet.speed = _speed;
        _bullet.sprite = getSpritePlain();
}

WeaponSpeedy::~WeaponSpeedy(){
	
}

void		WeaponSpeedy::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    WeaponSpeedy::initTextures() {
	std::string	path = "./libs/weapons/ressources/WeaponSpeedy.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&WeaponSpeedy::getSprite() {
	return (_sprite);
}

sf::Sprite		WeaponSpeedy::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			WeaponSpeedy::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

bullet			WeaponSpeedy::fire() {
	return _bullet;
}


const std::string	&WeaponSpeedy::getName() const {
	return _name;
}
const float		&WeaponSpeedy::getSpeed() const {
	return _speed;
}
const float		&WeaponSpeedy::getFireSpeed() const {
	return _fireSpeed;
}

const int	        &WeaponSpeedy::getDamage() const {
        return _damage;
}


extern "C"
WeaponSpeedy            *getInstance()
{
	WeaponSpeedy *tmp = new WeaponSpeedy();
        return tmp;
}