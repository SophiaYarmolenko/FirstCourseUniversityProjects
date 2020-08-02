#ifndef RANDOM_NUMBER_HPP_INCLUDED
#define RANDOM_NUMBER_HPP_INCLUDED
#include "Generation.hpp"

class cycle
{
private:
    int mod;
public:
    cycle( int m );
    int lengsOfCycle();
};
#endif // RANDOM_NUMBER_HPP_INCLUDED
