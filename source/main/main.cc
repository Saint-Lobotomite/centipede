#include <esat/window.h>
#include <esat/time.h>
#include <esat/draw.h>
#include <esat/input.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "../game.hh"
#include "../loader.hh"
#include "update.hh"
#include "render.hh"
#include "../score.hh"

#include "../structs/centipede.hh" // TEMP
#include "../structs/mushroom.hh"
#include "../structs/player.hh"
#include "../screen-text.hh"

int esat::main(int argc, char **argv) {
	srand(time(NULL));

	double last_time;
	double current_time;

	esat::WindowInit(
		kWindowSize.x * kPixelScale,
		kWindowSize.y * kPixelScale
	);

	WindowSetMouseVisibility(true);

	LoadAssets();

	/*
	// testinggg
	// Spawn centis
	Centipede_t *buddy = nullptr;
	Centipede_t *old = nullptr;
	for (int i = 0; i < 12; i++) {
		Construct(&buddy);
		buddy->body.position = {16, -8};
		buddy->hdir = 1;
		buddy->speed = 2;
		buddy->body.track_tick = i;
		UpdateTrack(buddy);

		if (old != nullptr) LinkTo(buddy, old);
		old = buddy;
	}*/


	PutNumber(0, 0, 0);
	PutNumber(0, 24, 0);

	Start_Menu_Routine();

	while(
		esat::WindowIsOpened() 
		&& !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)
	) {
		last_time = esat::Time();
		
		// Game logic
		UpdateStep();

		esat::DrawBegin();
		esat::DrawClear(0,0,0);
		esat::DrawSetStrokeColor(0,0,0,0);

		// Render
		RenderStep();

		esat::DrawEnd();
		esat::WindowFrame();

    do{
        current_time = esat::Time();
    } while(current_time - last_time <= 1000.0 / kTargetFps);
	}

	esat::WindowDestroy();

	ReleaseAssets();

	return 0;
}