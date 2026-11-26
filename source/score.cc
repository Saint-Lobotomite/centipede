#include "score.hh"

#include "cirno.hh"
#include "game.hh"

unsigned int g_highestscore = 16543;

ScoreboardEntry_t g_scoreboard[8] = {
  {"EJD", 16543},
  {"DFT", 15432},
  {"CAD", 14320},
  {"DCB", 13210},
  {"ED ", 13010},
  {"DEW", 12805},
  {"DFW", 12201},
  {"GJR", 12102}
};

void PlaceInScoreboard(ScoreboardEntry_t entry) {
  ScoreboardEntry_t *placed;
  unsigned int aux = 0;
  char caux = ' ';

  for (u1 i = 0; i < 8; i++) {
    placed = &g_scoreboard[i];

    if (placed->score < entry.score) {
      aux = placed->score;
      placed->score = entry.score;
      entry->score = aux;

      caux = placed->name[0];
      placed->name[0] = entry->name[0];
      entry->name[0] = caux;

      caux = placed->name[1];
      placed->name[1] = entry->name[1];
      entry->name[1] = caux;

      caux = placed->name[2];
      placed->name[2] = entry->name[2];
      entry->name[2] = caux;
    }

  }

  g_highestscore = g_scoreboard[0].score;
}

void Score(unsigned int n) {
  if (g_game.current_player_n != 2) {
    g_game.current_player->score += n;

    if (g_game.current_player->score > g_highestscore)
      g_highestscore = g_game.current_player->score;
  }
}