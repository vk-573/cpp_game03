#include "../../include/IPlayer.hpp"

class PlayerDave : public IPlayer {
        public:
		PlayerDave();
		~PlayerDave();

		void			setSprite(sf::Sprite sprite);
                void                    initTextures();
		sf::Sprite		&getSprite();
		sf::Sprite		getSpritePlain();
		void			setPosition(const int &x, const int &y);
		void			move(const int &dir);
		void			setWeapon(IWeapon *weapon);
		IWeapon			*getWeapon() const;
		void			fire();
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

PlayerDave::PlayerDave() {
	_name = "Dave";
	_hp = 80;
	_speed = 0.3;
	initTextures();
}

PlayerDave::~PlayerDave(){
	
}

void		PlayerDave::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    PlayerDave::initTextures() {
	std::string	path = "./libs/players/ressources/playerDave.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&PlayerDave::getSprite() {
	return (_sprite);
}

sf::Sprite		PlayerDave::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			PlayerDave::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

void			PlayerDave::move(const int &dir) {

}

void			PlayerDave::setWeapon(IWeapon *weapon) {
	_weapon = weapon;
}

IWeapon			*PlayerDave::getWeapon() const {
	return _weapon;
}

void			PlayerDave::fire() {
	_weapon->fire();
}

void			PlayerDave::gotHit(const int &damage) {
	_hp -= damage;
	if (_hp <= 0)
		_diying = true;
}

bool			PlayerDave::isDead() {
	return _diying;
}

const int		&PlayerDave::getHP() const {
	return _hp;
}

const std::string	&PlayerDave::getName() const {
	return _name;
}
const float		&PlayerDave::getSpeed() const {
	return _speed;
}

extern "C"
PlayerDave            *getInstance()
{
	PlayerDave *tmp = new PlayerDave();
        return tmp;
}