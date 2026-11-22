#include "track.hh"

void Tick(Track_t *self) {
  self->tick = (self->tick + 1) % self->length;
}

Mask_t* GetMask(Track_t *self) {
  return &self->frame[self->tick];
}