#include "Scene.hpp"

//PROTECTED

sf::Sprite	Scene::getSprite(const std::string &name)
{
	return (_Sprites.at(name));
}

sf::Sprite	&Scene::getSpriteRef(const std::string &name)
{
	return (_Sprites.at(name));
}

void		Scene::createSprite(const std::string &name, const std::string &path)
{
	initTexture(path, name);
	pushSprite(name);
}

void		Scene::initTexture(const std::string &path, const std::string &name)
{
	sf::Texture	texture;

	if (!texture.loadFromFile(path)) {
		std::cout << "Error while loading texture :" << path << std::endl;
		exit(84);
	} else {
		_Textures.insert(std::pair<std::string, sf::Texture>(name, texture));
	}
}

void		Scene::pushSprite(const std::string &name)
{
	sf::Sprite			sprite;

	sprite.setTexture(_Textures.at(name));
	_Sprites.insert(std::pair<std::string, sf::Sprite>(name, sprite));
}

void		Scene::setBackgroundParallax(const std::string &spriteName, const float &speed)
{
	sf::Sprite sprite1 = getSprite(spriteName);
	sf::Sprite sprite2 = getSprite(spriteName);
	sf::Rect	<float>square = sprite1.getGlobalBounds();
	sprite2.setPosition(sf::Vector2f(square.width, 0));
	_Parallax.emplace(spriteName, std::pair<sf::Sprite, sf::Sprite>(sprite1, sprite2));
	_ParallaxSpeed.emplace(spriteName, speed * -1);
}

void		Scene::moveBackgroundParallax(IDisplay *window)
{
	for (auto &bg : _Parallax)
	{
		bg.second.first.move(sf::Vector2f(_ParallaxSpeed.at(bg.first),0));
		sf::Rect	<float>square = bg.second.first.getGlobalBounds();
		if (bg.second.first.getPosition().x <= (square.width * -1))
			bg.second.first.setPosition(sf::Vector2f(square.width, 0));
		window->drawSprite(bg.second.first);
		bg.second.second.move(sf::Vector2f(_ParallaxSpeed.at(bg.first),0));
		square = bg.second.second.getGlobalBounds();
		if (bg.second.second.getPosition().x <= (square.width * -1))
			bg.second.second.setPosition(sf::Vector2f(square.width, 0));
		window->drawSprite(bg.second.second);
	}
}

void		Scene::drawTime(IDisplay *window, const float &seconds)
{
	int sec = (int)seconds;
	window->drawText(std::to_string(sec), 32, 635, 25);
}

void		Scene::spriteSetPosition(const std::string &name, const float &x, const float &y)
{
	_Sprites.at(name).setPosition(sf::Vector2f(x, y));
}
