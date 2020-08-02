//
// Created by Sophia on 20.05.2020.
//

#ifndef NFIB_UNIVERSALSPECTRUMLIBRARYOOP_H
#define NFIB_UNIVERSALSPECTRUMLIBRARYOOP_H

#include "Generator.h"

class us
{
private:

public:
    us(int length, int maxF, int axes, int * spectrArray);
    int Length;
    int MaxF;
    int Axes;
    int Newlength;
    int ** InputGrid;
    int Q;
    int NzElements = 0;
    int (*rnd)();


    int usF(int * spectrArray);
    void oneDimensionalGrid(int * spectrArray);
    int oneDimensionalIndex(int *ijk);
};



#endif //NFIB_UNIVERSALSPECTRUMLIBRARYOOP_H
