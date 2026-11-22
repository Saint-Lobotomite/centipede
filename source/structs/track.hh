#ifndef TRACK_HH
#define TRACK_HH

#include "mask.hh"
#include "../game.hh"

struct Track_t {
  u1 length = 0;
  u1 tick = 0;
  Mask_t frame[8] = {0};
};

// Avanza la animacion por 1 tick
void Tick(Track_t *self);

Mask_t* GetMask(Track_t *self);

#endif // TRACK_HH