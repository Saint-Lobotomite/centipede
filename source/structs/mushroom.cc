#include "mushroom.hh"

#include "../loader.hh"

Mushroom_t kMushroom_registry[32][30] = {{}};


bool IsValidMushroom(u1 x, u1 y) {
  return (
    x >= 0 && y >= 0
    && x < 32
    && y < 30
  );
}



void Construct(Mushroom_t *self, u1 x, u1 y) {
  if (IsValidMushroom(x, y) && !kMushroom_registry[x][y].active) {
    self = &kMushroom_registry[x][y];
    (*self) = {};
    self->active = true;
  } else {
    self = nullptr;
  }
}

void Destruct(Mushroom_t *self) {
  self->active = false;
}


void UpdateTrack(Mushroom_t *self) {
  self->body.track = g_assets.mushroom[self->poisoned ? 1 : 0];
}


void Damage(Mushroom_t *self) {
  self->health--;

  if (self->health == 0) {
    Destruct(self);
    // TODO Dar puntos
  } else {
    self->body.track_tick = 4-self->health;
  }
}

void Poison(Mushroom_t *self) {
  self->poisoned = true;
}