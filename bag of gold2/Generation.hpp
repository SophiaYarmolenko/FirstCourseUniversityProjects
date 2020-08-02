#ifndef GENERATION_HPP_INCLUDED
#define GENERATION_HPP_INCLUDED

class Rnd
{
public:
    int mod;
    Rnd( int m );
    int nextRnd( int a, int b );
};

#endif // GENERATION_HPP_INCLUDED
