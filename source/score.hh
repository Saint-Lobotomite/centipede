#ifndef SCORE_HH
#define SCORE_HH

struct ScoreboardEntry_t {
	char name[4]; // Contiene el string ender \0
	unsigned int score = 0;
};

extern unsigned int g_highestscore;
extern ScoreboardEntry_t g_scoreboard[8];

void PlaceInScoreboard(ScoreboardEntry_t entry);
void Score(unsigned int n);

void PutScoreboard();

#endif // SCORE_HH