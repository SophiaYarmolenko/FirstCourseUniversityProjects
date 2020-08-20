#ifndef UNIVERSALSPECTRUM_UNIVERSALSPECTRUM_HPP
#define UNIVERSALSPECTRUM_UNIVERSALSPECTRUM_HPP

class us
{
public:
    us(int (&f) (int), int length, int maxF, int axes, int * spectrArray);
    int Length;
    int MaxF;
    int Axes;
    int Newlength;
    int ** InputGrid;
    int Q;
    int NzElements = 0;

    int usF(int * spectrArray);
    void oneDimensionalGrid(int * spectrArray);
    int oneDimensionalIndex(int *ijk);
};

#endif //UNIVERSALSPECTRUM_UNIVERSALSPECTRUM_HPP
