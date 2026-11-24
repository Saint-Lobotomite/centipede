#ifndef TRACK_HH
#define TRACK_HH

#include "mask.hh"

struct Track_t {
  u1 length = 0;

  Mask_t frame[8] = {0};
};

Mask_t* GetMask(Track_t *self);

#endif // TRACK_HH