#ifndef u1
#define u1 unsigned char
#endif

#ifndef GAME_HH
#define GAME_HH 1


#include "cirno.hh"


enum GameState {
	kGameState_Menu,
	kGameState_Paused
};

const u1 kTargetFps = 60;

const int kPixelScale = 4;
const Vector2_t kWindowSize = {128, 120}; // 240x256

extern unsigned int g_tick; // Tick del programa

struct Game_t {
	GameState state;

	bool paused = false;

	unsigned int tick = 0; // Tick del juego, no avanza si esta pausado

	unsigned int round;
};

extern Game_t g_game;

#endif // GAME_HH