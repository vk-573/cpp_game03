#ifndef IMAP_HPP_
	#define IMAP_HPP_

#include "IDisplay.hpp"
#include <map>

class IMap {
	public:
		virtual void	                init(IDisplay *window) = 0;
                virtual void                    update() = 0;
                virtual const std::string       &getName() const = 0;
                virtual sf::Sprite              getIcon() = 0;
};

typedef std::map<std::string, IMap*>	_MAPS;

#endif