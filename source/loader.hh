#ifndef LOADER_HH
#define LOADER_HH

#include "structs/mask.hh"
#include "structs/track.hh"

enum CentipedeTrackN {
  kCentipedeTrack_Left,
  kCentipedeTrack_DownLeft,
  kCentipedeTrack_Down,
  kCentipedeTrack_DownRight,
  kCentipedeTrack_Right,
  kCentipedeTrack_UpLeft,
  kCentipedeTrack_Up,
  kCentipedeTrack_UpRight
};

const int kCentipedeSheetInfo[8][3] = {
  { 0, 0, 8 }, // Left // Donde esta, cuanto mide
  { 6, 0, 2 }, // DL
  { 0, 1, 4 }, // D
  { 14, 1, 2 }, // DR
  { 8, 0, 8 }, // R
  { 4, 1, 2 }, // UL
  { 8, 1, 4 }, // U
  { 12, 1, 2 } // UR
}

struct Assets_t {
  Track_t centipede[16];
};

extern Assets_t g_assets;

void LoadAssets();

#endif // LOADER_HH