#include "../../include/IPlayer.hpp"

class PlayerJojo : public IPlayer {
        public:
		PlayerJojo();
		~PlayerJojo();

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

PlayerJojo::PlayerJojo() {
	_name = "Jojo";
	_hp = 100;
	_speed = 4;
	initTextures();
}

PlayerJojo::~PlayerJojo(){
	
}

void		PlayerJojo::setSprite(sf::Sprite sprite) {
	_sprite = sprite;
}

void                    PlayerJojo::initTextures() {
	std::string	path = "./libs/players/ressources/playerJojo.png";
	if (!_texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_sprite.setTexture(_texture);
}

sf::Sprite		&PlayerJojo::getSprite() {
	return (_sprite);
}

sf::Sprite		PlayerJojo::getSpritePlain() {
	sf::Sprite tmp = _sprite;
	return tmp;
}

void			PlayerJojo::setPosition(const int &x, const int &y) {
	_pos.x = x;
	_pos.y = y;
	_sprite.setPosition(_pos);
}

const sf::Vector2f	&PlayerJojo::getPosition() {
        return _sprite.getPosition();
}

void			PlayerJojo::move(const _P_MOVE &dir) {
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

void			PlayerJojo::setWeapon(IWeapon *weapon) {
	_weapon = weapon;
}

IWeapon			*PlayerJojo::getWeapon() const {
	return _weapon;
}

bullet			PlayerJojo::fire() {
	return(_weapon->fire());
}

void			PlayerJojo::gotHit(const int &damage) {
	_hp -= damage;
	if (_hp <= 0)
		_diying = true;
}

bool			PlayerJojo::isDead() {
	return _diying;
}

const int		&PlayerJojo::getHP() const {
	return _hp;
}

const std::string	&PlayerJojo::getName() const {
	return _name;
}

const float		&PlayerJojo::getSpeed() const {
	return _speed;
}


extern "C"
PlayerJojo            *getInstance()
{
	PlayerJojo *tmp = new PlayerJojo();
        return tmp;
}
