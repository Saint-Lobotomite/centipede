#include <esat/window.h>
#include <esat/time.h>
#include <esat/draw.h>
#include <esat/input.h>

#include <stdio.h>

#include "../game.hh"
#include "../loader.hh"
#include "update.hh"
#include "render.hh"

int esat::main(int argc, char **argv) {
	double last_time;
	double current_time;

	esat::WindowInit(
		kWindowSize.x * kPixelScale, 
		kWindowSize.y * kPixelScale
	);

	WindowSetMouseVisibility(true); // Quitar

	LoadAssets();

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