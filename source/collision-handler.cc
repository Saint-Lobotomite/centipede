#include "collision-handler.hh"

#include "game.hh"

bool BoundaryCheck(Vector2_t pos) {
  return (
    pos.x + 8 > kWindowSize.x
  || pos.y + 8 > kWindowSize.y
  || pos.x < 0 || pos.y < 0
  );
}

bool BoundaryCheck(Body_t *self) {
  Vector2_t old = self->position;

  self->position.x = clamp(old.x, 0, kWindowSize.x - 8);
  self->position.y = clamp(old.y, 0, kWindowSize.y - 8);

  return old.x != self->position.x || old.y != self->position.y;
}
