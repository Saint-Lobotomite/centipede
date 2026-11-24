#include "mouse.hh"

#include <math.h>

#include <esat/input.h>
#include <esat/input.h>

#include "cirno.hh"

Vector2_t g_clamped_mouse_position = kWindowSize;

const double pi = acos(0.0) * 2; // Unused?
const double half_pi = acos(0.0);
const double quarter_pi = acos(0.0) / 2;

void MouseTick() {
	Vector2_t pos = {
    (int)esat::MousePositionX(),
    (int)esat::MousePositionY()
  };

	pos = Div(pos, kPixelScale);

	double angle;

	Vector2_t delta;

	for (u1 i = kMouseSpeed; i > 0; i--) {
		delta = Sub(pos, g_clamped_mouse_position);

		angle = atan2(
      delta.x, 
      delta.y
    );
		
		delta = { // change broh
			int(cos(angle) +.75),
			int(sin(angle) +.75)
		};
	}
}