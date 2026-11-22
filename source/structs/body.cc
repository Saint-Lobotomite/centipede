#include "body.hh"


void Tick(Body_t *self) {
  Tick(&self->track);
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