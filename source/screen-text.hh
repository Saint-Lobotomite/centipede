#ifndef SCREEN_TEXT_HH
#define SCREEN_TEXT_HH

#include "cirno.hh"

void PutChar(char c, u1 x, u1 y);


void PutText(const char *txt, u1 x, u1 y);

void PutNumber(unsigned int n, u1 x, u1 y);


#endif // SCREEN_TEXT_HH