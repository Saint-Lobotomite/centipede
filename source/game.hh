#include "cirno.hh"


enum GameState {
	kGameState_Running,
	kGameState_Paused
};

extern const unsigned int kTargetFps;

extern const Vector2_t kWindowSize;
extern const int kPixelScale;

extern unsigned int g_tick; // Tick del programa

struct Game_t {
	GameState state;

	unsigned int last_paused;
	unsigned int tick; // Tick del juego, no avanza si esta pausado
};

extern Game_t g_game;