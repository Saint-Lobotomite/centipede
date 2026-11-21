#include <esat/window.h>
#include <esat/time.h>
#include <esat/input.h>

#include "../game.hh"


int esat::main(int argc, char **argv) {
	double last_time;
	double current_time;

	esat::WindowInit(k
		WindowSize.x * kPixelScale, 
		kWindowSize.y * kPixelScale
	);

	WindowSetMouseVisibility(true); // Quitar

	
	while(
		esat::WindowIsOpened() 
		&& !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)
	) {
		double last_time = esat::Time();
		
		// Game logic

		esat::DrawBegin();
		esat::DrawClear(0,0,0);
		esat::DrawSetStrokeColor(0,0,0,0);

		// Render

		esat::DrawEnd();
		esat::WindowFrame();

		double current_time;
    do{
        current_time = esat::Time();
    } while(current_time - last_time <= 1000.0 / kTargetFps);
	}

	esat::WindowDestroy();

	return 0;
}