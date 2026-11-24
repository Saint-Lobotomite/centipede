#ifndef COLLISION_HANDLER_HH
#define COLLISION_HANDLER_HH

#include "cirno.hh"
#include "structs/body.hh"

bool BoundaryCheck(Vector2_t pos, Vector2_t size = { 8, 8 });
bool BoundaryClamp(Body_t *self);

bool BoundaryClamp(Vector2_t *pos, Vector2_t size = { 8, 8 });

#endif // COLLISION_HANDLER_HH