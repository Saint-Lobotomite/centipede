#include "loader.hh"

#include "../cirno.hh"

g_assets = {};

void LoadAssets() {
  u1 i, j; // Iteradores

  Track_t *centi_track;
  Track_t *centibody_track;
  for (i = 0; i < 8; i++) {
    centi_track = &g_assets.centipede[i];
    centibody_track = &g_assets.centipede[i + 8];

    for (j = 0; j < kCentipedeSheetInfo[i][3]; j++) {
      FromFile(&centi_track->frame[j], "../assets/centipede.png",
       { kCentipedeSheetInfo[i][0] * 8, kCentipedeSheetInfo[i][1] * 8 },
       { 8, 8 }
      );

      FromFile(&centibody_track->frame[j], "../assets/centipede.png",
       { kCentipedeSheetInfo[i][0] * 8, (kCentipedeSheetInfo[i][1] + 2) * 8 },
       { 8, 8 }
      );
    }
  }


}