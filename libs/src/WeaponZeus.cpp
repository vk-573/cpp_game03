#include "../../include/IWeapon.hpp"

class WeaponZeus : public IWeapon {
        public:
		WeaponZeus();
		~WeaponZeus();

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

WeaponZeus::WeaponZeus() {
	_name = "Zeus";
	_speed = 3.0;
        _fireSpeed = 0.35;
        _damage = 35;
	initTextures();
        _bullet.damage = _damage;
        _bullet.speed = _speed;
        _bullet.sprite = getSpritePlain();
	_bullet.empty = false;
}

WeaponZeus::~WeaponZeus(){
	
}

void		WeaponZeus::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    WeaponZeus::initTextures() {
	std::string	path = "./libs/weapons/ressources/WeaponZeus.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&WeaponZeus::getSprite() {
	return (_sprite);
}

sf::Sprite		WeaponZeus::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			WeaponZeus::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

void			WeaponZeus::pullTrigger() {
	if (_rateFireClock.getElapsedTime().asSeconds() > _fireSpeed)
	{
		_reloading = true;
		_bullet.empty = false;
		_rateFireClock.restart();
	}
}

bullet			WeaponZeus::fire() {
	pullTrigger();
	if (!_reloading) {
		_bullet.empty = true;
		return _bullet;
	}
	_reloading = false;
	return _bullet;
}


const std::string	&WeaponZeus::getName() const {
	return _name;
}
const float		&WeaponZeus::getSpeed() const {
	return _speed;
}
const float		&WeaponZeus::getFireSpeed() const {
	return _fireSpeed;
}

const int	        &WeaponZeus::getDamage() const {
        return _damage;
}

extern "C"
WeaponZeus            *getInstance()
{
	WeaponZeus *tmp = new WeaponZeus();
        return tmp;
}