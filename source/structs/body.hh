#ifndef BODY_HH
#define BODY_HH

#include "../cirno.hh"
#include "track.hh"

struct Body_t {
  Vector2_t position = {0, 0};

  Track_t track = {};
};

void Tick(Body_t *self);

void MoveTo(Body_t *self, Vector2_t pos);
void Move(Body_t *self, Vector2_t delta);

#endif // BODY_HH