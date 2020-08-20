//loopSearch1.cpp
#include "loopSearch1.hpp"
#include "Rnd.hpp"

cycle::cycle(int m)
{
    mod=m;
};

int cycle::lengsOfCycle()
{
   Rnd rnd1 = Rnd(mod);
   int a = 0;
   int b = 1;
   int c = 1;
   int d = rnd1.nextRnd(a, b, c);
   int lengs = 1;
   while(a != 0 || b != 0 || c != 1 || d != 1)
    {
        a = b;
        b = c;
        c = d;
        d = rnd1.nextRnd(a, b, c);
        lengs++;
    }

    return lengs;
};



