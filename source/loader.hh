#ifndef LOADER_HH
#define LOADER_HH

#include <esat/sprite.h>
#include "structs/mask.hh"
#include "structs/track.hh"

extern u1 g_current_palette;

enum CentipedeTrackDirection {
  kCentipedeTrack_Left,
  kCentipedeTrack_DownLeft,
  kCentipedeTrack_UpLeft,
  kCentipedeTrack_Right,
  kCentipedeTrack_DownRight,
  kCentipedeTrack_UpRight,
  kCentipedeTrack_Down,
  kCentipedeTrack_Up
};

const int kCentipedeSheetInfo[8][3] = {
  { 0, 0, 8 }, // Left // Donde esta, cuanto mide
  { 6, 1, 2 }, // DL
  { 4, 1, 2 }, // UL
  { 8, 0, 8 }, // R
  { 14, 1, 2 }, // DR
  { 12, 1, 2 }, // UR
  { 0, 1, 4 }, // D
  { 8, 1, 4 } // U
};

struct Assets_t {
  esat::SpriteHandle palette;

  Track_t centipede[16];
  Track_t mushroom[2];
};

extern Assets_t g_assets;

void LoadAssets();
void ReleaseAssets();

void ReadPalette(u1 i, u1 out_RGBA[4]);

#endif // LOADER_HH