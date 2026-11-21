#ifndef TRACK_HH
#define TRACK_HH

#include "mask.hh"
#include "../game.hh"

struct Track_t {
  u1 length = 0;
  u1 time = 0;
  Mask_t frame[8] = {0};
};


#endif // TRACK_HH