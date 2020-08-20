//
// Created by Sophia on 04.03.2020.
//

#include "Generator.h"
#include "random"

int Generator::rnd(int mod)
{
        int resalt = rand()%(mod)+1;

        return resalt;
}
