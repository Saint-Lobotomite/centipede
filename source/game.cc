#include "game.hh"


unsigned int g_tick = 0;

Game_t g_game = {
	kGameState_Menu,

	false,
	0, // tick
	0, // credits
	0, // cplayer
	&kPlayer_registry[0]
};