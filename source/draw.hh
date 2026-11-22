#ifndef DRAW_HH
#define DRAW_HH 1

#include <esat/draw.h>

#include "cirno.hh"
#include "structs/body.hh"

void Draw(Body_t* self);

void DrawRectangle(
    Vector2_t position, 
    Vector2_t size, 
    unsigned char RGBA[4]
);

#endif // DRAW_HH