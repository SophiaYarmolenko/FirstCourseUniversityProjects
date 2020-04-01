//howmuch.cpp
#include "howmuch.hpp"
#include "Rnd.hpp"
#include "loopSearch1.hpp"
howmuch::howmuch( int m, int n )
{
    mod = m;
    num = n;
}

int howmuch::HowMuch()
{
    Rnd rnd1 = Rnd(mod);
    int a = 0;
    int b = 1;
    int c = rnd1.nextRnd(a, b);
    int howMuch;

    if( num == 0)
        howMuch = 1;
    else
        if( num == 1)
        howMuch = 2;
    else
        howMuch = 0;
    cycle len1 = cycle(mod);
    for(int i = 4; i <= len1.lengsOfCycle(); i++)
        {
        a = b;
        b = c;
        c = rnd1.nextRnd(a, b);
        if(c == num)
        howMuch++;
        }

    return howMuch;
}
