#include <stdio.h>

#include "loader.hh"

#include "cirno.hh"


extern u1 g_current_palette = 0;

Assets_t g_assets = {};

void LoadAssets() {
  int i, j; // Iteradores
  u1 length;

  g_assets.palette = esat::SpriteFromFile("../../assets/sprites/palette.png");

  // Screen Text
  Track_t *text_track = &g_assets.text;
  length = 38;

  text_track->length = length; 
  for (i = 0; i < length; i++) {
    FromFile(&text_track->frame[i], "../../assets/sprites/text.png",
      { i * 8, 0 }, { 8, 8 }
    );
  }

  // Player
  Track_t *plr_track = &g_assets.player;
  plr_track->length = 3;
  for (i = 0; i < 2; i++) {
    FromFile(&plr_track->frame[i], "../../assets/sprites/player.png",
      { i * 7, 0 }, { 7, 10 }
    );
  }
  FromFile(&plr_track->frame[2], "../../assets/sprites/player.png",
    { 14, 0 }, { 1, 6 }
  );
  
  // Centipede
  Track_t *centi_track;
  Track_t *centibody_track;
  for (i = 0; i < 8; i++) {
    length = kCentipedeSheetInfo[i][2];

    centi_track = &g_assets.centipede[i];
    centibody_track = &g_assets.centipede[i + 8];

    centi_track->length = length;
    centibody_track->length = length;

    for (j = 0; j < length; j++) {
      FromFile(&centi_track->frame[j], "../../assets/sprites/centipede.png",
       { (j + kCentipedeSheetInfo[i][0]) * 8, kCentipedeSheetInfo[i][1] * 8 },
       { 8, 8 }
      );

      FromFile(&centibody_track->frame[j], "../../assets/sprites/centipede.png",
       { (j + kCentipedeSheetInfo[i][0]) * 8, (kCentipedeSheetInfo[i][1] + 2) * 8 },
       { 8, 8 }
      );
    }
  }

  // Mushroom
  Track_t *mush_track = &g_assets.mushroom[0];
  Track_t *pmush_track = &g_assets.mushroom[1];
  length = 4;

  mush_track->length = length;
  pmush_track->length = length;

  for (i = 0; i < length; i++) {
    FromFile(&mush_track->frame[i], "../../assets/sprites/mushroom.png",
      { i * 8, 0}, { 8, 8 }
    );

    FromFile(&pmush_track->frame[i], "../../assets/sprites/mushroom.png",
      { i * 8, 8}, { 8, 8 }
    );
  }

  // Explosion
  Track_t *expl_track = &g_assets.explosion;
  length = 6;
  expl_track->length = length;
  for (i = 0; i < length; i++) {
    FromFile(&expl_track->frame[i], "../../assets/sprites/explosion.png",
      { i * 8, 0 }, { 8, 8 }
    );
  }
}

void ReadPalette(u1 i, u1 out_RGBA[4]) {
  esat::SpriteGetPixel(g_assets.palette, i, g_current_palette, out_RGBA);
}

void ReleaseAssets() {
  esat::SpriteRelease(g_assets.palette);
}