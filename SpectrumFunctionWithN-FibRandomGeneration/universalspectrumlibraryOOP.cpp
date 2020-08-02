//
// Created by Sophia on 20.05.2020.
//

#include "universalspectrumlibraryOOP.h"

/**
 * Functions of another class can be as parameters of functions from this class
Class, which take parameters such as
                                    another function f, that generate int;
                                    length(number of digits, that we generate;
                                    maxF(the max element in our generating);
                                    axes(the number of axes)
                                    spectrArray (grid, that we change)
It include such functions:
        usF, that return number of none zero elements in spectrArray after all changes
        oneDimensionalGrid, that use f for generate coordinates and change spectrArray
        oneDimensionalIndex, that generate one coordinate from many

*/
#include <algorithm>
#include <iostream>

using namespace std;

//(function that gives numbers for input arr,
//length of function cycle,
//max element in function,
//the number of measurements,
//the resultant arr)


us::us(int length, int maxF, int axes, int * spectrArray)
{
    Length = length;
    MaxF = maxF;
    Axes = axes;
    Generator generator;
    rnd = generator.rnd;
    if ( Length <= 0 || MaxF < 0 || Axes <= 0 )
    {
        cout<<"Parameters aren`t correct";
    }
    else
    {
        Q = maxF + 1;//size of spectrumArray
        Newlength = length*axes / __gcd (length, axes);
        InputGrid = new int *[Newlength/Axes];
        for (int i = 0; i < Newlength/Axes; i++ )
        {
            InputGrid[i] = new int[Axes];
            for(int j = 0; j < Axes; j++)
            {
                InputGrid[i][j] = rnd();

            }
        }
        usF(spectrArray);
    }
}

//universal spectrum function
int us::usF(int * spectrArray)
{
    //check some exceptions
    if ( Length <= 0 || MaxF < 0 || Axes <= 0 )
    {
        cout<<"Parameters aren`t correct";
        return -1;
    }
    else
    {
        oneDimensionalGrid(spectrArray);
        return NzElements;
    }
}

//function, that use f for generate coordinates and change spectrArray
void us::oneDimensionalGrid(int * spectrArray)
{
    for (int i = 0; i < Newlength/Axes ; i++)
    {
        int index = oneDimensionalIndex(InputGrid[i]);
        if( spectrArray[index] == 0 )
        {
            spectrArray[index]++;
            NzElements++;
        }
        else
        {

            spectrArray[index]++;

        }
    }

}

//function that generate one-dimensional coordinates from grid of many-dimensional arguments
//( the max number of coordinate, the number of spectrum axes, the grid of many - dimensional coordinates )
int us::oneDimensionalIndex (int *ijk)
{
    int index = ijk[0];

    for (int i = 1; i < Axes; i++)
    {
        index = ijk[i-1]*Q+ijk[i];
    }

    return index;
}
