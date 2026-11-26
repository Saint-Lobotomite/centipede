#include <esat/input.h>

#include "update.hh"
#include "../loader.hh"

#include "../game.hh"
#include "../screen-text.hh"

#include "../structs/mushroom.hh"
#include "../structs/centipede.hh"
#include "../structs/player.hh"


void UpdateStep() {
  g_tick++;
  g_game.tick++;

  // test
  if (esat::IsKeyDown('C')) g_game.credits++;
  if (esat::IsKeyDown('K')) g_current_palette = (g_current_palette+1) % 14;

  if (g_game.current_player_n == 2)
    Menu_Routine();
  else
    Game_Routine();
}


void Start_Menu_Routine() {
  ClearMushrooms();

  kPlayer_registry[2] = {};
	SwitchToPlayer(2); // 3

  SpreadMushrooms();

  PutMenu();
}

void Menu_Routine() {
  if (esat::IsKeyDown('C'))
    PutCredits();

    // enter

  if (g_game.current_player->dying)
      PlayerDead_Subroutine();
    else {
      UpdateAutoPlay();

      Tick(g_game.current_player);

      World_Subroutine();
    }
}



void Start_Game_Routine(bool multiplayer) {
  ClearMushrooms();
 
  kPlayer_registry[0] = {};
  kPlayer_registry[1] = {};
	SwitchToPlayer(0); // 1

  g_game.tick = 0;
}


void Game_Routine() {

  if (g_game.tick <= 120) { // Anuncia el jugador, 2 segundos

    if (g_game.tick == 1) {
      PutText("start player", 8, 15);
      PutNumber(g_game.current_player_n, 21, 15);
    }
    
    if (g_game.tick == 120) {
      ClearMushrooms();

      SpreadMushrooms();
    }

  } else { // El resto del comportamiento

    if (g_game.current_player->dying)
      PlayerDead_Subroutine();
    else {
      UpdateInput();

      Tick(g_game.current_player);

      World_Subroutine();
    }

  }

}



// Subrutinas

unsigned int g_world_sub_tick = 60;
void World_Subroutine() {
  // si todos los centipedes estan muertos tick--
  //    si tick = 0 round++ y spawn
  
  bool centi_dead = true;
  for (u1 i = 0; i < kCentipede_registry_capacity && centi_dead; i++) {
    if (kCentipede_registry[i].active) centi_dead = false;
  }

  if (centi_dead) {
    g_world_sub_tick--;

    if (g_world_sub_tick == 0) {
      g_world_sub_tick = 60;
      g_current_palette = (g_current_palette+1) % 14;

      // TODO
    }
  };

  UpdateCritters();
}

// Lo que pasa cuando el jugador esta muerto
// Cambia el jugador
unsigned int g_playerdead_sub_tick = 0;
void PlayerDead_Subroutine() {

}


// Updates

void UpdateCritters() {
  u1 i; // Centinelas

  // Centipedes
  if (g_game.tick % 2 == 0) {
    Centipede_t *centi_ptr;
    for (i = 0; i < kCentipede_registry_capacity; i++) {
      centi_ptr = &kCentipede_registry[i];

      if (centi_ptr->active && !centi_ptr->tailing) Tick(centi_ptr);
    }
  }
}


void UpdateInput() {
  if (esat::IsKeyDown(' ')) Shoot(g_game.current_player);
  
  // Delta del jugador
}

// Autoplay del menu
void UpdateAutoPlay() {

}