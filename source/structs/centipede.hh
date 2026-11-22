#ifndef CENTIPEDE_HH
#define CENTIPEDE_HH

#include "body.hh"

struct Centipede_t {
  bool active = false;
  u1 speed = false;

  bool dying = false;
  bool poisoned = false;

  char hdir = 1;
  char vdir = 1;
  
  unsigned int lifetime = 0;

  Centipede_t *heading; // La parte de adelante
  Centipede_t *tailing; // La parte de atras

  Body_t body = {};
};


const u1 kCentipede_registry_capacity = 12;
extern Centipede_t kCentipede_registry[kCentipede_registry_capacity];

Centipede_t *Centipede_Construct(); // preguntar a fede si podemos hacer una funcion que pase una referencia
void Destruct(Centipede_t *self);

void UpdateTrack(Centipede_t *self);

// Hace que other sea la cabeza de self, actualizando propiedades
void LinkTo(Centipede_t *self, Centipede_t *other);

void Tick(Centipede_t *self);


bool EdgeAhead(Centipede_t *self);

bool MushroomAhead(Centipede_t *self);

bool CreatureAhead(Centipede_t *self);


#endif // CENTIPEDE_HH