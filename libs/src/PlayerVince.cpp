#include "../../include/IPlayer.hpp"

class PlayerVince : public IPlayer {
        public:
		PlayerVince();
		~PlayerVince();

		void			setSprite(sf::Sprite sprite);
                void                    initTextures();
		sf::Sprite		&getSprite();
		sf::Sprite		getSpritePlain();
		void			setPosition(const int &x, const int &y);
		void			move(const _P_MOVE &dir);
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

PlayerVince::PlayerVince() {
	_name = "Vince";
	_hp = 50;
	_speed = 7;
	initTextures();
}

PlayerVince::~PlayerVince(){
	
}

void		PlayerVince::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    PlayerVince::initTextures() {
	std::string	path = "./libs/players/ressources/playerVince.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&PlayerVince::getSprite() {
	return (_sprite);
}

sf::Sprite		PlayerVince::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			PlayerVince::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

void			PlayerVince::move(const _P_MOVE &dir) {
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

void			PlayerVince::setWeapon(IWeapon *weapon) {
	_weapon = weapon;
}

IWeapon			*PlayerVince::getWeapon() const {
	return _weapon;
}

void			PlayerVince::fire() {
	_weapon->fire();
}

void			PlayerVince::gotHit(const int &damage) {
	_hp -= damage;
	if (_hp <= 0)
		_diying = true;
}

bool			PlayerVince::isDead() {
	return _diying;
}

const int		&PlayerVince::getHP() const {
	return _hp;
}

const std::string	&PlayerVince::getName() const {
	return _name;
}

const float		&PlayerVince::getSpeed() const {
	return _speed;
}

extern "C"
PlayerVince            *getInstance()
{
	PlayerVince *tmp = new PlayerVince();
        return tmp;
}
