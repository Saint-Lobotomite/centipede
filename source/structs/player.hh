#ifndef PLAYER_HH
#define PLAYER_HH

#include "../loader.hh"

#include "../cirno.hh"
#include "body.hh"

struct Player_t {
  bool active = false;
  bool dying = false;

  u1 lives = 0;
  
  u1 score = 0;
  u1 rounds = 0;
  
  bool shot_active = false;
  
  Body_t shot = {
    {0}, 2,
    g_assets.player
  };
  Body_t body = {
    {0}, 0,
    g_assets.player
  };

  u1 field[30][30] = {0};
};

const u1 kPlayer_speed = 4;
extern Player_t kPlayer_registry[3];

void UpdateTrack(Player_t *self);

void Tick(Player_t *self);

void Shoot(Player_t *self);

void Dead(Player_t *self);

#endif // PLAYER_HH