//fib.cpp
#include "fib.hpp"

static int f0=0;
static int f1=1;

fib::fib()
{
    reset(0, 1);
}

int fib::next()
{
    f1=f0+f1;
    f0=f1;
    return f0;
}

void fib::reset(int f00, int f11)
{
    f0=f00;
    f1=f11;
}


