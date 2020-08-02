//Generation.cpp
#include "Generation.hpp"

Rnd::Rnd( int m )
{
    mod=m;
}

int Rnd::nextRnd( int a1, int b1 )
{
    return ( a1 + b1 )%mod;
}
