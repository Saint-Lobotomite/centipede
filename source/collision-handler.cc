#include "collision-handler.hh"

#include "game.hh"

bool BoundaryCheck(Vector2_t pos, Vector2_t size) {
  return (
    pos.x + size.x > kWindowSize.x
  || pos.y + size.y > kWindowSize.y
  || pos.x < 0 || pos.y < 0
  );
}

bool BoundaryClamp(Body_t *self) {
  return BoundaryClamp(
    &self->position,
    self->size
  );
}

bool BoundaryClamp(Vector2_t *pos, Vector2_t size) {
  Vector2_t old = (*pos);

  pos->x = clamp(pos->x, 0, kWindowSize.x - size.x);
  pos->y = clamp(pos->y, 0, kWindowSize.y - size.y);

  return (
      old.x != pos->x 
    || old.y != pos->y
  );
}