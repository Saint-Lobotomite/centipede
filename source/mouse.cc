#include "mouse.hh"

#include <math.h>

#include <esat/input.h>
#include <esat/input.h>

Vector2_t g_clamped_mouse_position = kWindowSize;

constexpr double pi = 2*acos(0.0);
constexpr double half_pi = acos(0.0);
constexpr double quarter_pi = acos(0,0)/2;

int MouseGetDirection() {
  Vector2_t new = {
    (int)esat::MousePositionX(),
    (int)esat::MousePositionY()
  };

  new = Div(new, kPixelScale);

  Vector2_t delta = Sub(new, g_clamped_mouse_position);

  return round(
    atan2(
      double(delta), 
      double(delta)
    ) / quarter_pi
  );
}