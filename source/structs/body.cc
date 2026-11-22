#include "body.hh"


void Tick(Body_t *self) {
  self->track_tick++;
}

Mask_t* GetCurrentMask(Body_t *self) {
  return &self->track.frame[self->track_tick % self->track.length];
}

void MoveTo(Body_t *self, Vector2_t pos) {
  self->position = pos;
}

void Move(Body_t *self, Vector2_t delta) {
  MoveTo(self,
    Sum(
      self->position,
      delta
    )
  );
}