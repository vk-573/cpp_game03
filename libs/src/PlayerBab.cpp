#include "../../include/IPlayer.hpp"

class PlayerBab : public IPlayer {
        public:
		PlayerBab();
		~PlayerBab();

		void			setSprite(sf::Sprite sprite);
                void                    initTextures();
		sf::Sprite		&getSprite();
		sf::Sprite		getSpritePlain();
		void			setPosition(const int &x, const int &y);
		const sf::Vector2f	&getPosition();
		void			move(const _P_MOVE &dir);
		void			setWeapon(IWeapon *weapon);
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

PlayerBab::PlayerBab() {
	_name = "Bab";
	_hp = 120;
	_speed = 3.3;
	initTextures();
}

PlayerBab::~PlayerBab(){
	
}

void		PlayerBab::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    PlayerBab::initTextures() {
	std::string	path = "./libs/players/ressources/playerBab.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&PlayerBab::getSprite() {
	return (_sprite);
}

sf::Sprite		PlayerBab::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			PlayerBab::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

const sf::Vector2f	&PlayerBab::getPosition() {
        return _sprite.getPosition();
}


void			PlayerBab::move(const _P_MOVE &dir) {
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

void			PlayerBab::setWeapon(IWeapon *weapon) {
	_weapon = weapon;
}

IWeapon			*PlayerBab::getWeapon() const {
	return _weapon;
}

bullet			PlayerBab::fire() {
	return _weapon->fire();
}

void			PlayerBab::gotHit(const int &damage) {
	_hp -= damage;
	if (_hp <= 0) {
		_hp = 0;
		_diying = true;
	}
}

bool			PlayerBab::isDead() {
	return _diying;
}

const int		&PlayerBab::getHP() const {
	return _hp;
}

const std::string	&PlayerBab::getName() const {
	return _name;
}

const float		&PlayerBab::getSpeed() const {
	return _speed;
}

extern "C"
PlayerBab            *getInstance()
{
	PlayerBab *tmp = new PlayerBab();
        return tmp;
}
