#include <stdio.h>

#include "loader.hh"

#include "cirno.hh"

extern u1 g_current_palette = 0;

Assets_t g_assets = {};

void LoadAssets() {
  int i, j; // Iteradores

  g_assets.palette = esat::SpriteFromFile("../../assets/sprites/palette.png");

  Track_t *centi_track;
  Track_t *centibody_track;
  u1 length;
  for (i = 0; i < 8; i++) {
    printf("%d\n", i);

    length = kCentipedeSheetInfo[i][2];

    centi_track = &g_assets.centipede[i];
    centibody_track = &g_assets.centipede[i + 8];

    centi_track->length = length;
    centibody_track->length = length;

    for (j = 0; j < length; j++) {
      printf("I %d\n", j);

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
}

void ReadPalette(u1 i, u1 out_RGBA[4]) {
  esat::SpriteGetPixel(g_assets.palette, i, g_current_palette, out_RGBA);
}

void ReleaseAssets() {
  esat::SpriteRelease(g_assets.palette);
}