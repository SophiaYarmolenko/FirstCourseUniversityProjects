//howmuch.hpp
#ifndef HOWMUCH_HPP_INCLUDED
#define HOWMUCH_HPP_INCLUDED
#include "Rnd.hpp"

class howmuch
{
private:
       int mod;
       int num;
public:
    howmuch(int m, int n);
    int HowMuch();
};

#endif // HOWMUCH_HPP_INCLUDED
