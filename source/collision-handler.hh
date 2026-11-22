#ifndef COLLISION_HANDLER_HH
#define COLLISION_HANDLER_HH

#include "cirno.hh"
#include "structs/body.hh"

bool BoundaryCheck(Vector2_t pos);
bool BoundaryCheck(Body_t *self);


#endif // COLLISION_HANDLER_HH