#include "Interval.h"

// Constructors for Interval
Interval::Interval(int s, int e): st(s), en(e), snd(0) {}
Interval::Interval(int s, int e, int sd): st(s), en(e), snd(sd) {}

int Interval::overlap(int st1, int en1)
{
  if (en1 < st)
  {
    return -1;
  }
  else if (st1 > en)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool operator < (const Interval &L, const Interval &R)
{
  return L.en < R.st;
}

bool operator > (const Interval &L, const Interval &R)
{
  return L.st > R.en;
}