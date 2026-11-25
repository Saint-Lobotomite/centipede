#include <stdio.h>

#include "centipede.hh"

#include "../loader.hh"
#include "../collision-handler.hh"
#include "mushroom.hh"

Centipede_t kCentipede_registry[kCentipede_registry_capacity] = {};


void Construct(Centipede_t **self) {
  for (u1 i = 0; i < kCentipede_registry_capacity; i++) {
    if (!kCentipede_registry[i].active) {
			(*self) = &kCentipede_registry[i];
			
			(**self) = {};

     	(*self)->active = true;
			UpdateTrack(*self);

      i = kCentipede_registry_capacity;
    }
  }
}


void Destruct(Centipede_t *self) {
  self->active = false;
}

void Dead(Centipede_t *self) {
	self->dying = true;

	if (self->heading)
		self->heading->tailing = nullptr;
	
	self->heading = nullptr;

	if (self->tailing) {
		self->tailing->heading = nullptr;
		UpdateTrack(self->tailing);
	}

	self->tailing = nullptr;

	self->body.track = g_assets.explosion;
	self->body.track_tick = 0;

	Mushroom_t *mush;
	Vector2_t pos = Sum(self->body.position, { self->hdir*5 + 4, 0 });
	Construct(&mush, pos.x /8, pos.y /8);
}

void UpdateTrack(Centipede_t *self) {
	u1 offset = self->heading == nullptr ? 0 : 8;
	u1 mod = abs(self->body.position.y) % 8;
	
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
	if (self->dying) { if (self->body.track_tick == 5) Destruct(self); }
	else {

		bool turning = self->body.position.y % 8 != 0; // Posicion negativa es siempre true porque -8 % 8 != 0

		if (!turning) {

			if (self->heading) {
				turning = abs(self->heading->body.position.y - self->body.position.y) >= 8;
			} else {
				turning = self->poisoned || IsEdgeAhead(self) || IsMushroomAhead(self); // o hay seta o hay otro centipede
			}

			if (turning) { // Elegimos la direccion vertical
				if (
					self->vdir > 0 
					&& self->body.position.y >= kPlayableBounds.y // Fondo
				) {
					self->vdir = -1;
					self->poisoned = false;
				} else if (
					self->vdir < 0
					&& self->body.position.y < kPlayableBounds.x // Maximo del jugador
				) {
					self->vdir = 1;
				}
			}
		}

		if (turning) {
			self->body.position.y += self->speed * self->vdir;
			UpdateTrack(self);
		}
			
		if(self->body.position.y > -8)
			self->body.position.x += self->speed * self->hdir;

		if (self->body.position.y % 8 == 4) {
			self->hdir = -self->hdir;
			UpdateTrack(self);
		}

	}

	Tick(&self->body);
	if (self->heading) Tick(self->heading);
}


// Ahead

bool IsEdgeAhead(Centipede_t *self) {
	return BoundaryCheck(
		Sum(
			self->body.position,
			{ self->hdir*5, 0 }
		)
	);
}

bool IsMushroomAhead(Centipede_t *self) {
	Vector2_t pos = self->body.position;
	pos.x += (self->hdir < 0) ? -5 : 12;
	
	return (
		GetMushroom(pos) 
		|| GetMushroom(self->body.position)
	);
}

bool IsCreatureAhead(Centipede_t *self) {
	return false;
}