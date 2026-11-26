#ifndef SCORE_HH
#define SCORE_HH

struct ScoreboardEntry_t {
	char name[3];
	unsigned int score = 0;
}

extern unsigned int g_highestscore;
extern ScoreboardEntry_t g_scoreboard[8];

void PlaceInScoreboard(ScoreboardEntry_t entry);
void Score(unsigned int n);

#endif // SCORE_HH