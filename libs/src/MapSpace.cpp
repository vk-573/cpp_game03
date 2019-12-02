#include "../../include/IMap.hpp"

class MapSpace : public IMap {
        public:
		MapSpace();
		~MapSpace();

                void	                init(IDisplay *window);
                void                    update();
                const std::string       &getName() const;
                sf::Sprite              getIcon();
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
                sf::Sprite              _icon;
                sf::Texture             _iconTexture;
                std::map<std::string, sf::Texture>				_Textures;
		std::map<std::string, sf::Sprite>				_Sprites;
		std::map<std::string, std::pair<sf::Sprite, sf::Sprite>>	_Parallax;
		std::map<std::string, float>					_ParallaxSpeed;
                // std::vector<sf::Sprite> _SpritesReturn;
};

MapSpace::MapSpace() {
	_name = "Space";
        std::string	path = "./libs/maps/ressources/MapSpaceIcon.png";
	if (!_iconTexture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	}
	_icon.setTexture(_iconTexture);
}

MapSpace::~MapSpace(){
	
}

sf::Sprite              MapSpace::getIcon() {
        return _icon;
}

//EDIT ONLY THIS
void                            MapSpace::init(IDisplay *window) {
        _window = window;
        createSprite("background1", "./libs/maps/ressources/space.png");
	createSprite("background2", "./libs/maps/ressources/whiteStars.png");
	createSprite("background3", "./libs/maps/ressources/deathStar.png");
        setBackgroundParallax("background1", 0.8);
	setBackgroundParallax("background2", 1.8);
	setBackgroundParallax("background3", 1.4);
}

void                            MapSpace::update() {
        moveBackgroundParallax();
}


sf::Sprite	MapSpace::getSprite(const std::string &name)
{
	return (_Sprites.at(name));
}
sf::Sprite	&MapSpace::getSpriteRef(const std::string &name)
{
	return (_Sprites.at(name));
}

const std::string               &MapSpace::getName() const {
        return _name;
}

void		MapSpace::createSprite(const std::string &name, const std::string &path)
{
	initTexture(path, name);
	pushSprite(name);
}

void		MapSpace::initTexture(const std::string &path, const std::string &name)
{
	sf::Texture	texture;

	if (!texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	} else {
		_Textures.insert(std::pair<std::string, sf::Texture>(name, texture));
	}
}

void		MapSpace::pushSprite(const std::string &name)
{
	sf::Sprite			sprite;

	sprite.setTexture(_Textures.at(name));
	_Sprites.insert(std::pair<std::string, sf::Sprite>(name, sprite));
}

void		MapSpace::setBackgroundParallax(const std::string &spriteName, const float &speed)
{
	sf::Sprite sprite1 = getSprite(spriteName);
	sf::Sprite sprite2 = getSprite(spriteName);
	sf::Rect	<float>square = sprite1.getGlobalBounds();
	sprite2.setPosition(sf::Vector2f(square.width, 0));
	_Parallax.emplace(spriteName, std::pair<sf::Sprite, sf::Sprite>(sprite1, sprite2));
	_ParallaxSpeed.emplace(spriteName, speed * -1);
}

void		MapSpace::moveBackgroundParallax()
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

void		MapSpace::spriteSetPosition(const std::string &name, const float &x, const float &y)
{
	_Sprites.at(name).setPosition(sf::Vector2f(x, y));
}

extern "C"
MapSpace            *getInstance()
{
	MapSpace *tmp = new MapSpace();
        return tmp;
}