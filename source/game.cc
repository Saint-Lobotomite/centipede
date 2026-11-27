#include "game.hh"

#include "screen-text.hh"
#include "score.hh"
#include "structs/player.hh"

unsigned int g_tick = 0;

Game_t g_game = {
	kGameState_SinglePlayer,

	false,
	0, // tick
	0, // credits
	0, // cplayer
	&kPlayer_registry[0]
};

void PutMenu() {
	PutScoreboard();

	PutText("1 coin 1 play", 8, 12);

	PutText("bonus every", 7, 14);
	PutNumber(g_bonus_interval, 18, 14);

	PutText("C1980 atari", 9, 29);

	PutCredits();
}

void PutCredits() {
	if (g_game.credits > 0) {
		PutText("credits", 10, 13);
    PutTinyNumber(g_game.credits, 18, 13);
	}
}

void SwitchToPlayer(u1 i) {
	// TODO save player state

	g_game.current_player_n = i;
	g_game.current_player = &kPlayer_registry[i];

	g_game.current_player->active = true;
	g_game.current_player->dying = false;

	UpdateTrack(g_game.current_player);

	g_game.current_player->body.position = {
		kWindowSize.x / 2, kPlayableBounds.y
	};
}