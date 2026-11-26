#include "player.hh"

#include <math.h>
#include <stdio.h>

#include <esat/input.h>
#include <esat/input.h>

#include "../game.hh"

#include "../collision-handler.hh"
#include "mushroom.hh"
#include "centipede.hh"


Player_t kPlayer_registry[3] = {};

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
			// Check colisiones

			u1 op = 0; while (op < 2 && self->shot_active) {
				switch(op) {
					case 0: {
						Mushroom_t *mush = GetMushroom(self->shot.position);

						if (mush) {
							Damage(mush);
							self->shot_active = false;
							UpdateTrack(self);
						}
					}

					case 1: {
						Centipede_t *centi;
						Vector2_t pos = {0};

						for (u1 i = 0; i < kCentipede_registry_capacity; i++) {
							centi = &kCentipede_registry[i];

							if (centi->active && !centi->dying) {
								pos = AABBOverlap(&self->shot, &centi->body);

								if (pos.x > 0 && pos.y > 0) {
									Dead(centi);
									i = kCentipede_registry_capacity;
									self->shot_active = false;
								}

							}
						}


					}


				}

				op++;
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

	double magnitude;

	double delta[2];
	
  for (int i = kPlayer_speed; i > 0; i--) {
		old_pos = self->body.position;

		delta[0] = double(new_pos.x - old_pos.x);
		delta[1] = double(new_pos.y - old_pos.y);

    if (isZero(delta)) { i = 0; }
    else {

      magnitude = sqrt(
				delta.x * delta.x,
				delta.y * delta.y
			);
			delta[0] /= magnitude;
			delta[1] /= magnitude;

			self->body.position.x += (int)round(delta.x);
			if (
				GetMushroom(self->body.position.x, self->body.position.y + 2)
				|| GetMushroom(self->body.position.x + 7, self->body.position.y + 2)
				|| GetMushroom(self->body.position.x, self->body.position.y + 10)
				|| GetMushroom(self->body.position.x + 7, self->body.position.y + 10)
			) 
				self->body.position.x = old_pos.x;

			self->body.position.y += (int)round(delta.y);
			if (
				GetMushroom(self->body.position.x, self->body.position.y + 2)
				|| GetMushroom(self->body.position.x + 7, self->body.position.y + 2)
				|| GetMushroom(self->body.position.x, self->body.position.y + 10)
				|| GetMushroom(self->body.position.x + 7, self->body.position.y + 10)
			) 
				self->body.position.y = old_pos.y;

			self->body.position.x = clamp(self->body.position.x, 0, kWindowSize.x - 8);
			self->body.position.y = clamp(self->body.position.y, kPlayableBounds.x, kPlayableBounds.y);
    }
	}

	
}

void Shoot(Player_t *self) {
	
	if (!self->shot_active) {
		self->shot.position = Sum(
			self->body.position,
			{ 3, 2 }
		);
		
		self->shot_active = true;
		
		UpdateTrack(self);
	}
}