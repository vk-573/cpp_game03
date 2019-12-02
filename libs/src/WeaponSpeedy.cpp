#include "../../include/IWeapon.hpp"

class WeaponSpeedy : public IPlayer {
        public:
		WeaponSpeedy();
		~WeaponSpeedy();

		void			setSprite(sf::Sprite sprite);
                void                    initTextures();
		sf::Sprite		&getSprite();
		sf::Sprite		getSpritePlain();
		void			setPosition(const int &x, const int &y);
		std::vector<bullet>	fire();
		void			gotHit(const int &damage);
		bool			isDead();
		const int		&getHP() const;
		const std::string	&getName() const;
		const float		&getSpeed() const;
	private:
		std::string		_name;
		float			_speed;
		int			_hp;
		IWeapon			*_weapon;
		sf::Sprite		_sprite;
		sf::Texture		_texture;
		sf::Vector2f		_pos;
		bool			_diying = false;
};

WeaponSpeedy::WeaponSpeedy() {
	_name = "Dave";
	_hp = 80;
	_speed = 0.3;
	initTextures();
}

WeaponSpeedy::~WeaponSpeedy(){
	
}

void		WeaponSpeedy::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    WeaponSpeedy::initTextures() {
	std::string	path = "./libs/players/ressources/WeaponSpeedy.png";
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

void			WeaponSpeedy::move(const int &dir) {

}

void			WeaponSpeedy::setWeapon(IWeapon *weapon) {
	_weapon = weapon;
}

IWeapon			*WeaponSpeedy::getWeapon() const {
	return _weapon;
}

void			WeaponSpeedy::fire() {
	_weapon->fire();
}

void			WeaponSpeedy::gotHit(const int &damage) {
	_hp -= damage;
	if (_hp <= 0)
		_diying = true;
}

bool			WeaponSpeedy::isDead() {
	return _diying;
}

const int		&WeaponSpeedy::getHP() const {
	return _hp;
}

const std::string	&WeaponSpeedy::getName() const {
	return _name;
}
const float		&WeaponSpeedy::getSpeed() const {
	return _speed;
}

extern "C"
WeaponSpeedy            *getInstance()
{
	WeaponSpeedy *tmp = new WeaponSpeedy();
        return tmp;
}