#ifndef GAME_HH
#define GAME_HH 1

#define u1 unsigned int

#include "cirno.hh"


enum GameState {
	kGameState_Menu,
	kGameState_Paused
};

const u1 kTargetFps = 60;

const int kPixelScale = 4;
const Vector2_t kWindowSize = {256 * kPixelScale, 240 * kPixelScale};

extern u1 g_tick; // Tick del programa

struct Game_t {
	GameState state;

	bool paused = false;

	u1 tick = 0; // Tick del juego, no avanza si esta pausado

	unsigned int round;
};

extern Game_t g_game;

#endif // GAME_HH