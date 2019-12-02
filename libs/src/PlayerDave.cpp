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
		void			move(const _P_MOVE &dir);
		void			setWeapon(IWeapon *weapon);
		const sf::Vector2f	&getPosition();
		IWeapon			*getWeapon() const;
		bullet			fire();
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
	_speed = 5;
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

const sf::Vector2f	&PlayerDave::getPosition() {
        return _sprite.getPosition();
}

void			PlayerDave::move(const _P_MOVE &dir) {
        if (dir == _UP) {
                _pos.y = _pos.y - _speed;
	} else if (dir == _UP_RIGHT) {
                _pos.x = _pos.x + _speed * 0.7;
                _pos.y = _pos.y - _speed * 0.7;
	} else if (dir == _RIGHT) {
                _pos.x = _pos.x + _speed;
	} else if (dir == _DOWN_RIGHT) {
                _pos.x = _pos.x + _speed * 0.7;
                _pos.y = _pos.y + _speed * 0.7;
	} else if (dir == _DOWN) {
                _pos.y = _pos.y + _speed;
	} else if (dir == _DOWN_LEFT) {
		_pos.x = _pos.x - _speed * 0.7;
                _pos.y = _pos.y + _speed * 0.7;
	} else if (dir == _LEFT) {
                _pos.x = _pos.x - _speed;
	} else if (dir == _UP_LEFT) {
                _pos.x = _pos.x - _speed * 0.7;
                _pos.y = _pos.y - _speed * 0.7;
	}
        setPosition(_pos.x, _pos.y);
}

void			PlayerDave::setWeapon(IWeapon *weapon) {
	_weapon = weapon;
}

IWeapon			*PlayerDave::getWeapon() const {
	return _weapon;
}

bullet			PlayerDave::fire() {
	return _weapon->fire();
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
