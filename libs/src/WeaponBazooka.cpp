#include "../../include/IWeapon.hpp"

class WeaponBazooka : public IWeapon {
        public:
		WeaponBazooka();
		~WeaponBazooka();

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
		void			pullTrigger();
		std::string		_name;
		sf::Sprite		_sprite;
		sf::Texture		_texture;
                float                   _speed;
                float                   _fireSpeed;
                int                     _damage;
		sf::Vector2f		_pos;
                bullet                  _bullet;
		bool			_reloading = false;
		sf::Clock		_rateFireClock;
};

WeaponBazooka::WeaponBazooka() {
	_name = "Bazooka";
	_speed = 1;
        _fireSpeed = 0.5;
        _damage = 50;
	initTextures();
        _bullet.damage = _damage;
        _bullet.speed = _speed;
        _bullet.sprite = getSpritePlain();
	_bullet.empty = false;
}

WeaponBazooka::~WeaponBazooka(){
	
}

void		WeaponBazooka::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    WeaponBazooka::initTextures() {
	std::string	path = "./libs/weapons/ressources/WeaponBazooka.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&WeaponBazooka::getSprite() {
	return (_sprite);
}

sf::Sprite		WeaponBazooka::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			WeaponBazooka::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

void			WeaponBazooka::pullTrigger() {
	if (_rateFireClock.getElapsedTime().asSeconds() > _fireSpeed)
	{
		_reloading = true;
		_bullet.empty = false;
		_rateFireClock.restart();
	}
}

bullet			WeaponBazooka::fire() {
	pullTrigger();
	if (!_reloading) {
		_bullet.empty = true;
		return _bullet;
	}
	_reloading = false;
	return _bullet;
}


const std::string	&WeaponBazooka::getName() const {
	return _name;
}
const float		&WeaponBazooka::getSpeed() const {
	return _speed;
}
const float		&WeaponBazooka::getFireSpeed() const {
	return _fireSpeed;
}
const int	        &WeaponBazooka::getDamage() const {
        return _damage;
}

extern "C"
WeaponBazooka            *getInstance()
{
	WeaponBazooka *tmp = new WeaponBazooka();
        return tmp;
}