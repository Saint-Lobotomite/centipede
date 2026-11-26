#ifndef UPDATE_HH
#define UPDATE_HH

void UpdateStep();

void UpdateInput();
void UpdateAutoPlay();

void UpdateCritters();


void Start_Menu_Routine();
void Menu_Routine();

void Start_Game_Routine(bool multiplayer = false);
void Game_Routine();

// Update de los bichos y rounds
extern unsigned int g_world_sub_tick;
void World_Subroutine();

// Lo que pasa cuando el jugador esta muerto
// Cambia el jugador
extern unsigned int g_playerdead_sub_tick;
void PlayerDead_Subroutine();

#endif // UPDATE_HH