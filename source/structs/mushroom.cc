#include "mushroom.hh"

#include <stdio.h>
#include <stdlib.h>

#include "../loader.hh"

u1 g_lower_mushroom_c = 0;
Mushroom_t kMushroom_registry[32][30] = {{}};

bool IsValidMushroom(u1 x, u1 y) {
  return (
    x >= 0 && y >= 0
    && x < kTileSize.x
    && y < kTileSize.y
  );
}

bool IsMushroomPresent(int x, int y) {
  x /= 8; y /= 8;
  return (
    IsValidMushroom(x, y)
    && kMushroom_registry[x][y].active
  );
}



void Construct(Mushroom_t **self, u1 x, u1 y) {
  if (IsValidMushroom(x, y) && !kMushroom_registry[x][y].active) {
    (*self) = &kMushroom_registry[x][y];

    (**self) = {};

    (*self)->active = true;
    (*self)->body.position = {x*8, y*8};

    UpdateTrack(*self);

    if (y >= kTileSize.y - 18)
      g_lower_mushroom_c++;
  } else {
    (*self) = nullptr;
  }
}

void Destruct(Mushroom_t *self) {
  if (self->body.position.y / 8 >= kTileSize.y - 18)
      g_lower_mushroom_c--;

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


void ClearMushrooms() {
	for (int j = 0; j < kTileSize.y; j++) {
    for (int i = 0; i < kTileSize.x; i++) {
			Destruct(&kMushroom_registry[i][j]);
    }
  } 
}

void SpreadMushrooms() {
	u1 col, row = 1;
	Mushroom_t *mush;

	for (u1 c = 0; c < 46; c++) {
		col = rand() % kTileSize.x;

		Construct(&mush, col, row);

		row++;
		if (row >= kTileSize.y -1) row = 1; // Ultima hilera es el espacio jugable del jugador
	}
}