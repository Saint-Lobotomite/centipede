#ifndef COLLISION_HANDLER_HH
#define COLLISION_HANDLER_HH

#include "cirno.hh"
#include "structs/body.hh"

bool BoundaryCheck(Vector2_t pos, Vector2_t size = { 8, 8 });
bool BoundaryClamp(Body_t *self);

bool BoundaryClamp(Vector2_t *pos, Vector2_t size = { 8, 8 });

Vector2_t AABBOverlap(Body_t *A, Body_t *B);

#endif // COLLISION_HANDLER_HH