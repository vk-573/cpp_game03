#include "../../include/IMap.hpp"

class MapCave : public IMap {
        public:
		MapCave();
		~MapCave();

                void	                init(IDisplay *window);
                void                    update();
                // std::vector<sf::Sprite> getSprites();
                const std::string       &getName() const;
	private:
                sf::Sprite              getSprite(const std::string &name);
		sf::Sprite		&getSpriteRef(const std::string &name);
		void			createSprite(const std::string &name, const std::string &path);
		void			initTexture(const std::string &path, const std::string &name);
		void			pushSprite(const std::string &name);
		void			setBackgroundParallax(const std::string &spriteName, const float &speed);
		void			moveBackgroundParallax();
		void			spriteSetPosition(const std::string &name, const float &x, const float &y);
                IDisplay                *_window;
		std::string		_name;
		sf::Sprite		_sprite;
                std::map<std::string, sf::Texture>				_Textures;
		std::map<std::string, sf::Sprite>				_Sprites;
		std::map<std::string, std::pair<sf::Sprite, sf::Sprite>>	_Parallax;
		std::map<std::string, float>					_ParallaxSpeed;
                // std::vector<sf::Sprite> _SpritesReturn;
};

MapCave::MapCave() {
	_name = "Cave";
}

MapCave::~MapCave(){
	
}

void                            MapCave::init(IDisplay *window) {
        _window = window;
	std::string	path = "./libs/players/ressources/playerDave.png";

        createSprite("background1", "./libs/maps/ressources/cave1.png");
	createSprite("background2", "./libs/maps/ressources/cave2.png");
	createSprite("background3", "./libs/maps/ressources/cave3.png");
	setBackgroundParallax("background1", 1.0);
	setBackgroundParallax("background2", 1.3);
	setBackgroundParallax("background3", 1.5);
}

void                            MapCave::update() {
        moveBackgroundParallax();
}


sf::Sprite	MapCave::getSprite(const std::string &name)
{
	return (_Sprites.at(name));
}
sf::Sprite	&MapCave::getSpriteRef(const std::string &name)
{
	return (_Sprites.at(name));
}

const std::string               &MapCave::getName() const {
        return _name;
}

void		MapCave::createSprite(const std::string &name, const std::string &path)
{
	initTexture(path, name);
	pushSprite(name);
}

void		MapCave::initTexture(const std::string &path, const std::string &name)
{
	sf::Texture	texture;

	if (!texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	} else {
		_Textures.insert(std::pair<std::string, sf::Texture>(name, texture));
	}
}

void		MapCave::pushSprite(const std::string &name)
{
	sf::Sprite			sprite;

	sprite.setTexture(_Textures.at(name));
	_Sprites.insert(std::pair<std::string, sf::Sprite>(name, sprite));
}

void		MapCave::setBackgroundParallax(const std::string &spriteName, const float &speed)
{
	sf::Sprite sprite1 = getSprite(spriteName);
	sf::Sprite sprite2 = getSprite(spriteName);
	sf::Rect	<float>square = sprite1.getGlobalBounds();
	sprite2.setPosition(sf::Vector2f(square.width, 0));
	_Parallax.emplace(spriteName, std::pair<sf::Sprite, sf::Sprite>(sprite1, sprite2));
	_ParallaxSpeed.emplace(spriteName, speed * -1);
}

void		MapCave::moveBackgroundParallax()
{
	for (auto &bg : _Parallax)
	{
		bg.second.first.move(sf::Vector2f(_ParallaxSpeed.at(bg.first),0));
		sf::Rect	<float>square = bg.second.first.getGlobalBounds();
		if (bg.second.first.getPosition().x <= (square.width * -1))
			bg.second.first.setPosition(sf::Vector2f(square.width, 0));
		_window->drawSprite(bg.second.first);
		bg.second.second.move(sf::Vector2f(_ParallaxSpeed.at(bg.first),0));
		square = bg.second.second.getGlobalBounds();
		if (bg.second.second.getPosition().x <= (square.width * -1))
			bg.second.second.setPosition(sf::Vector2f(square.width, 0));
		_window->drawSprite(bg.second.second);
	}
}

void		MapCave::spriteSetPosition(const std::string &name, const float &x, const float &y)
{
	_Sprites.at(name).setPosition(sf::Vector2f(x, y));
}

extern "C"
MapCave            *getInstance()
{
	MapCave *tmp = new MapCave();
        return tmp;
}