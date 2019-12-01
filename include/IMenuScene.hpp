#ifndef IMENUSCENE_HPP_
	#define IMENUSCENE_HPP_

#include <map>
#include "MenuConfig.hpp"

enum	_MENU_SCENE
{
	_MAIN_MENU,
	_OPTION_MENU,
	_GAME_CONFIG,
	_PLAY_GAME,
	_EXIT_SCENE
};

class IMenuScene {
	public:
		virtual void		initScene() = 0;
		virtual _MENU_SCENE	startScene() = 0;
		virtual _MENU_SCENE	getSceneID() = 0;
};

typedef std::map<_MENU_SCENE, IMenuScene*>	MENU_SCENES;

#endif /* !IMENUSCENE_HPP_ */
