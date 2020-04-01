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
   int a = 1;
   int b = 1;
   int c = rnd1.nextRnd(a, b);
   int lengs = 1;
   while(a != 0 || b != 1 || c != 1)
    {
        a = b;
        b = c;
        c = rnd1.nextRnd(a, b);
        lengs++;
    }

    return lengs;
};



