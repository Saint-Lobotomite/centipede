#ifndef MASK_HH
#define MASK_HH 1

#include "../cirno.hh"

const u1 kMask_WordCount = 32;

struct Mask_t {
    Vector2_t size;

    u1 matrix[kMask_WordCount] = {0};
};

void FromFile(Mask_t *mask, const char *path, 
  Vector2_t sub_position = {0,0},
  Vector2_t sub_size = {0,0}
);

int GetIndex(Mask_t *mask, int x, int y);
bool IsValidPosition(Mask_t *mask, int x, int y);

u1 ReadPair(u1 word, u1 i);
void WritePair(u1 *word, u1 i, u1 v);

u1 ReadPair(Mask_t *mask, int x, int y);
void WritePair(Mask_t *mask, int x, int y, u1 v);

#endif // MASK_HH