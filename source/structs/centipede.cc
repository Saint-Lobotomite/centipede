#include <stdio.h>

#include "centipede.hh"
#include "../loader.hh"
#include "../collision-handler.hh"

Centipede_t kCentipede_registry[kCentipede_registry_capacity] = {0};


Centipede_t *Centipede_Construct() {
  Centipede_t *self = nullptr;

  for (u1 i = 0; i < kCentipede_registry_capacity; i++) {
    if (!kCentipede_registry[i].active) {
			self = &kCentipede_registry[i];
			
			(*self) = {};

      self->active = true;
			UpdateTrack(self);

      i = kCentipede_registry_capacity;
    }
  }

  return self;
}


void Destruct(Centipede_t *self) {
  self->active = false;
}


void UpdateTrack(Centipede_t *self) {
	u1 offset = self->heading == nullptr ? 0 : 8;
	u1 mod = self->body.position.y % 8;
	
	u1 track = self->hdir < 0 ? kCentipedeTrack_Left : kCentipedeTrack_Right;

	if (mod > 0) {
		if (2 < mod && mod < 6 ) { // 3 - 5
			track = self->vdir > 0 ? kCentipedeTrack_Down : kCentipedeTrack_Up;
		} else {
			track += self->vdir > 0 ? 1 : 2;
		}
	}
	
  self->body.track = g_assets.centipede[track + offset];
}

void LinkTo(Centipede_t *self, Centipede_t *other) {
  self->heading = other;
  other->tailing = self;
	
	self->speed = other->speed;

  UpdateTrack(self);
}


void Tick(Centipede_t *self) {
	bool turning = self->body.position.y % 8 != 0;

	if (!turning) {

		if (self->heading) {
			turning = abs(self->heading->body.position.y - self->body.position.y) >= 8;
		} else {
			turning = self->poisoned || EdgeAhead(self); // o hay seta o hay otro centipede
		}

		if (turning) { // Elegimos la direccion vertical
			if (
				self->vdir > 0 
				&& self->body.position.y >= 112 // Fondo
			) {
				self->vdir = -1;
				self->poisoned = false;
			} else if (
				self->vdir < 0
				&& self->body.position.y < 90 // Maximo del jugador
			) {
				self->vdir = 1;
			}
		}
	}

	if (turning) {
		self->body.position.y += self->speed * self->vdir;
		UpdateTrack(self);
	}
		

	self->body.position.x += self->speed * self->hdir;

	if (self->body.position.y % 8 == 4) {
		self->hdir = -self->hdir;
		UpdateTrack(self);
	}

	Tick(&self->body);
	if (self->heading) Tick(self->heading);
}


// Ahead

bool EdgeAhead(Centipede_t *self) {
	return BoundaryCheck(
		Sum(
			self->body.position,
			{ self->hdir*5, 0 }
		)
	);
}

bool MushroomAhead(Centipede_t *self) {
	return false;
}

bool CreatureAhead(Centipede_t *self) {
	return false;
}
