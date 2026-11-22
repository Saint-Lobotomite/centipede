#include <esat/input.h>

#include "update.hh"
#include "../loader.hh"

#include "../game.hh"

#include "../structs/centipede.hh"

void UpdateStep() {
  g_tick++;
  g_game.tick++;

  u1 i; // Iteradores

  if (esat::IsKeyDown(' ')) g_current_palette = (g_current_palette+1) % 14;

  // Centipedes
  if (g_game.tick % 2 == 0) {
    Centipede_t *centi_ptr;
    for (i = 0; i < kCentipede_registry_capacity; i++) {
      centi_ptr = &kCentipede_registry[i];

      if (centi_ptr->active && !centi_ptr->tailing) Tick(centi_ptr);
    }
  }
  
}