#include "player.hh"

#include <math.h>
#include <stdio.h>

#include <esat/input.h>
#include <esat/input.h>

#include "../collision-handler.hh"
#include "mushroom.hh"

Player_t kPlayer_registry[2] = {};

void UpdateTrack(Player_t *self) {
  self->body.track_tick = self->shot_active;
}


void Tick(Player_t *self) {
	// Update Shot
	if (self->shot_active) {
		Move(&self->shot, {0, -8});
	
		if (BoundaryClamp(&self->shot)) {

			self->shot_active = false;
			UpdateTrack(self);

		} else {

			Vector2_t p = Div(self->shot.position, 8);
			Mushroom_t *mush = nullptr;

			if (IsValidMushroom(p.x, p.y)) mush = &kMushroom_registry[p.x][p.y];

			if (mush && mush->active) {
				Damage(mush);
				self->shot_active = false;
				UpdateTrack(self);
			}
		}
	}

	// Update Player
	Vector2_t old_pos;

  Vector2_t new_pos = {
		(int)esat::MousePositionX(),
    (int)esat::MousePositionY()
  };
	
  new_pos = Div(new_pos, kPixelScale);
	
	new_pos.x -= 3;
	new_pos.y -= 3;

	double angle;
	
	Vector2_t delta;
	
  for (int i = kPlayer_speed; i > 0; i--) {
		old_pos = self->body.position;

		delta = Sub(new_pos, old_pos);

    if (isZero(delta)) { i = 0; }
    else {

      angle = atan2(
        delta.x,
        delta.y
      );

			self->body.position.x += (int)round(sin(angle));
			if (
				IsMushroomPresent(self->body.position.x, self->body.position.y + 2)
				|| IsMushroomPresent(self->body.position.x + 7, self->body.position.y + 2)
				|| IsMushroomPresent(self->body.position.x, self->body.position.y + 10)
				|| IsMushroomPresent(self->body.position.x + 7, self->body.position.y + 10)
			) 
				self->body.position.x = old_pos.x;

			self->body.position.y += (int)round(cos(angle));
			if (
				IsMushroomPresent(self->body.position.x, self->body.position.y + 2)
				|| IsMushroomPresent(self->body.position.x + 7, self->body.position.y + 2)
				|| IsMushroomPresent(self->body.position.x, self->body.position.y + 10)
				|| IsMushroomPresent(self->body.position.x + 7, self->body.position.y + 10)
			) 
				self->body.position.y = old_pos.y;

			BoundaryClamp(&self->body.position);
    }
	}

	
}

void Shoot(Player_t *self) {
	
	if (!self->shot_active) {
		self->shot.position = Sum(
			self->body.position,
			{ 3, -2 }
		);
		
		self->shot_active = true;
		
		UpdateTrack(self);
	}
}