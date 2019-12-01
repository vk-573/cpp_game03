#ifndef SCENES_HPP_
	#define SCENES_HPP_

#include "IDisplay.hpp"

class Scene {
	public:
		Scene() = default;
		~Scene() = default;
	protected:
		sf::Sprite			getSprite(const std::string &name);
		sf::Sprite			&getSpriteRef(const std::string &name);
		void				createSprite(const std::string &name, const std::string &path);
		void				initTexture(const std::string &path, const std::string &name);
		void				pushSprite(const std::string &name);
		void				setBackgroundParallax(const std::string &spriteName, const float &speed);
		void				moveBackgroundParallax(IDisplay *window);
		// void				drawGUI(const PLAYERS &players, IDisplay *window);
		void				drawTime(IDisplay *window, const float &seconds);
		void				spriteSetPosition(const std::string &name, const float &x, const float &y);
		std::map<std::string, sf::Texture>				_Textures;
		std::map<std::string, sf::Sprite>				_Sprites;
		std::map<std::string, std::pair<sf::Sprite, sf::Sprite>>	_Parallax;
		std::map<std::string, float>					_ParallaxSpeed;
	private:
};

#endif /* !SCENES_HPP_ */
