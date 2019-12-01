#ifndef MENUMANAGER_HPP_
	#define MENUMANAGER_HPP_

// #include "Player.hpp"

enum	_PLAYERS_NUM
{
	_P_N1,
	_P_N2,
};

// typedef std::vector<std::pair<_PLAYERS, IUnit*>>	CHOOSEN_PLAYERS;

class MenuConfig {
	public:
		MenuConfig();
		~MenuConfig() = default;

		// void		setPlayers(PLAYERS players);
		// PLAYERS		&getPlayers();
		// CHOOSEN_PLAYERS	getChoosenPlayers();
		// PLAYER_KEYS	getFirstPlayerKeys();
		// PLAYER_KEYS	getSecondPlayerKeys();
		// int	nb_players;
		// _PLAYERS	_P1;
		// _PLAYERS	_P2;
	private:	
		// PLAYERS		_Players;
		// PLAYER_KEYS	_P1_keys;
		// PLAYER_KEYS	_P2_keys;
};


#endif /* !MENUMANAGER_HPP_ */
