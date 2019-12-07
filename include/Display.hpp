#ifndef DISPLAY_HPP_
	#define DISPLAY_HPP_

#include "IDisplay.hpp"

class Display : public IDisplay
{
	public:
					Display() = default;
					~Display() = default;

                void			createWindow();
                void			clear();
                void			refresh();
		bool			isOpen();
		KEY_EVENT		checkEvents();
                void			quit();
		void			createSprite(const std::string &name, const std::string &path);
		void			drawExistingSprite(const std::string &name);
		sf::Sprite		getExistingSprite(const std::string &name);
		void			drawSprite(sf::Sprite sprite);
		void			drawText(const std::string &message, const int &size, const int &x, const int &y);

	private:
		void				initTexture(const std::string &path, const std::string &name);
		void				setSprite(const std::string &name);
		void				createEvents();
		void				resetEvents();

                sf::RenderWindow			_Window;
		sf::Event				_Event;
		sf::Font				_font;
		sf::Text				_text;
		bool					_open = false;

		//CONTAINEERS
		std::map<std::string, sf::Texture>	_Textures;
		std::map<std::string, sf::Sprite>	_Sprites;
		KEY_EVENT				_Events;
};

#endif /* !DISPLAY_HPP_ */
