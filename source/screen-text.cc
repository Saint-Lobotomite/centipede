#include "screen-text.hh"

#include <stdio.h>

#include "loader.hh"
#include "structs/mushroom.hh"

char GetCharIndex(char c) {
  if (c == 'C') return 36;
  if (c == 'P') return 37;
  c -= 48;
  if (0 <= c && c <= 9) return c;
  c -= 48;
  if (0 <= c && c <= 25) return 9 + c;

  return -1; // No existe
}

void PutChar(char c, u1 x, u1 y) {
  c = GetCharIndex(c);
  if (c > -1 && IsValidMushroom(x, y)) {
    Mushroom_t *mush = &kMushroom_registry[x][y];
    
    mush->active = true;
    mush->health = 5;

    mush->body.position = { x*8, y*8 };

    mush->body.track = g_assets.text;
    mush->body.track_tick = c;
  }
}


void PutText(const char *txt, u1 x, u1 y) {
  for (u1 i = 0; txt[i] != '\0'; i++) {
    PutChar(txt[i], x+i, y);
  }
}

void PutNumber(unsigned int n, u1 x, u1 y) {
  n = clamp(n, 0, 999999);
  
  char txt[7] = {0};
  sprintf(txt, "%06d", n);

  for (u1 i = 0; i < 4; i++) {
    if (txt[i] == '0') txt[i] = ' ';
    else i = 4;
  }

  PutText(&txt[0], x, y);
}

void PutTinyNumber(u1 n, u1 x, u1 y) {
  n = clamp(n, 0, 99);

  char txt[3] = {'0', '0', 0};
  
  sprintf(txt, "%02d", n);

  PutText(&txt[0], x, y);
}