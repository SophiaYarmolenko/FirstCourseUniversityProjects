//
// Created by Sophia on 30.03.2020.
//

#ifndef NFIB_GENERATOR_H
#define NFIB_GENERATOR_H

#include "UniversalspectrumlibraryOOP.h"

class Generator
{
private:
    static int mode;
    static int n;
    static int * grid;
    static int sum;
    static int i;

public:
    Generator();
    static int rnd();
    static int sumOfFib();
};

#endif //NFIB_GENERATOR_H
