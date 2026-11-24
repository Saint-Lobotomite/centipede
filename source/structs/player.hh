#ifndef PLAYER_HH
#define PLAYER_HH

#include "body.hh"

struct Player_t {
  bool active = false;

  u1 lives = 0;

  u1 score = 0;
  u1 rounds = 0;
  u1 field[113] = {}; //30, 30

  bool shot_active = false;
  Body_t shot = {};

  Body_t body = {};
};

extern Player_t kPlayer_registry[2];


void Tick()

#endif // PLAYER_HH