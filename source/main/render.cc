#include "render.hh"

#include "../game.hh"
#include "../loader.hh"
#include "../draw.hh"


#include "../structs/body.hh"

void RenderStep() {

  Body_t test = {
    {10, 10},
    g_assets.centipede[0]
  };

  
  test.track.tick = g_game.tick/5 % 8;

  Draw(&test);

}