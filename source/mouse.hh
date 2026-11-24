#ifndef MOUSE_HH
#define MOUSE_HH

#include "cirno.hh"
#include "game.hh"

const u1 kMouseSpeed = 4;
extern Vector2_t g_clamped_mouse_position;

void MouseTick();

#endif // MOUSE_HH