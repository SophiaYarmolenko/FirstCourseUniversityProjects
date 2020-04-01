//Rnd.cpp
#include "Rnd.hpp"

Rnd::Rnd( int m )
{
    mod=m;
}

int Rnd::nextRnd( int a1, int b1, int c1 )
{
    return ( a1 + b1 + c1 )%mod;
}
