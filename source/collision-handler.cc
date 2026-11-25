#include "collision-handler.hh"

#include "game.hh"
#include "structs/mask.hh"
#include "structs/body.hh"

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
  	GetCurrentMask(self)->size
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

Vector2_t AABBOverlap(Body_t *A, Body_t *B) {
  // min(aMax, bMax) - max(aMin, bMin)
  
  Vector2_t sA = GetCurrentMask(A)->size;
  Vector2_t sB = GetCurrentMask(B)->size;

  return {
    min(A->position.x + sA.x, B->position.x + sB.x) 
    - max(A->position.x, B->position.x),

    min(A->position.y + sA.y, B->position.y + sB.y) 
    - max(A->position.y, B->position.y)
  };
}
