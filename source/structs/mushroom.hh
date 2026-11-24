#ifndef MUSHROOM_HH
#define MUSHROOM_HH

#include "../cirno.hh"
#include "body.hh"
#include "../game.hh"

struct Mushroom_t {
  bool active = false;

  bool poisoned = false;
  u1 health = 4;

  Body_t body = {};
};

//const Vector2_t kMushroom_registry_size = {32, 30}; 

extern u1 g_lower_mushroom_c; // Flea
extern Mushroom_t kMushroom_registry[32][30];

bool IsValidMushroom(u1 x, u1 y);
bool IsMushroomPresent(int x, int y);

void Construct(Mushroom_t **self, u1 x, u1 y);
void Destruct(Mushroom_t *self);

void UpdateTrack(Mushroom_t *self);

void Damage(Mushroom_t *self);

void ClearMushrooms();
void SpreadMushrooms();

#endif // MUSHROOM_HH