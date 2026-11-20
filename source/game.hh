#ifndef GAME_HH
#define GAME_HH 1

#define u1 unsigned int

#include "cirno.hh"


enum GameState {
	kGameState_Running,
	kGameState_Paused
};

const u1 kTargetFps = 60;

const int kPixelScale = 4;
const Vector2_t kWindowSize = {100 * kPixelScale, 100 * kPixelScale};

extern u1 g_tick; // Tick del programa

struct Game_t {
	GameState state;

	u1 last_paused;
	u1 tick; // Tick del juego, no avanza si esta pausado
};

extern Game_t g_game;

#endif // GAME_HH