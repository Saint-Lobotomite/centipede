#ifndef GAME_HH
#define GAME_HH 1

#include "cirno.hh"
#include "structs/player.hh"

#include "screen-text.hh"

enum GameState {
	kGameState_Menu,
	kGameState_Paused
};

const u1 kTargetFps = 60;

const int kPixelScale = 4;

const Vector2_t kTileSize = {32, 30};
const Vector2_t kWindowSize = {
	kTileSize.x * 8, 
	kTileSize.y * 8
};
const Vector2_t kPlayableBounds = {
	(kTileSize.y - 4) *8,
	(kTileSize.y - 1) *8
};

extern unsigned int g_tick; // Tick del programa

struct Game_t {
	GameState state;

	bool paused = false;

	u1 credits = 0;

	unsigned int tick = 0; // Tick del juego, no avanza si esta pausado

	u1 current_player_n = 0;
	Player_t *current_player = nullptr;
};

extern Game_t g_game;


void DrawMenu() {

}

void ResetGame() {

}



#endif // GAME_HH