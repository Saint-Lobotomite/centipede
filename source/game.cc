#include "game.hh"


const unsigned int kTargetFps = 60;

const int kPixelScale = 4;
const Vector2_t kWindowSize = {100, 100};

unsigned int g_tick = 0;

Game_t g_game = {
	kGameState_Running,
	
	0,
	0
};