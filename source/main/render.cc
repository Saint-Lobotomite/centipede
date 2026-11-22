#include "render.hh"

#include "../game.hh"
#include "../loader.hh"
#include "../draw.hh"

#include "../structs/body.hh"
#include "../structs/centipede.hh"

void RenderStep() {
  u1 i; // Iteradores

  // Centipedes
  Centipede_t *centi_ptr;
  for (i = 0; i < kCentipede_registry_capacity; i++) {
    centi_ptr = &kCentipede_registry[i];

    if (centi_ptr->active) Draw(&centi_ptr->body);
  }

}