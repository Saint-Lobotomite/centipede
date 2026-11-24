#include "render.hh"

#include "../game.hh"
#include "../loader.hh"
#include "../draw.hh"

#include "../structs/body.hh"
#include "../structs/centipede.hh"
#include "../structs/mushroom.hh"

void RenderStep() {
  u1 i, j; // Centinelas

  // Mushrooms
  Mushroom_t *mush_ptr;
  for (j = 0; j < 30; j++) {
    for (i = 0; i < 32; i++) {
      mush_ptr = &kMushroom_registry[i][j];

      if (mush_ptr->active) Draw(&mush_ptr->body);
    }
  } 

  // Centipedes
  Centipede_t *centi_ptr;
  for (i = 0; i < kCentipede_registry_capacity; i++) {
    centi_ptr = &kCentipede_registry[i];

    if (centi_ptr->active) Draw(&centi_ptr->body);
  }

}