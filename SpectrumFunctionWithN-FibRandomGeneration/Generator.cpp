//
// Created by Sophia on 30.03.2020.
//
#include <iostream>
#include "Generator.h"

using namespace std;
int Generator::mode = 0;
int Generator::n = 0;
int * Generator::grid = NULL;
int Generator::sum=0;
int Generator::i=0;
Generator::Generator()
{
    cout<<"Please, enter the number of Fibonacci numbers we use to generate the data\n"<< "n =  ";
    cin>>n;
    mode = 2;
    grid = new int [n];
    sum = 0;
    i = n-1;
    grid[0] = 0;
    grid[1] = 1;
    sum = 1;

    for(int i = 2; i < n ; i++)
    {
        grid[i] = grid[i-1] + grid[i-2];
        sum += grid[i];
    }

}

int Generator::sumOfFib()
{
  if( i == n-1 )
  {
      i = 0 ;
      int a = grid[ i ] ;
      grid[ i ] == sum ;
      int sum1 = sum ;
      sum = sum + sum1 - a ;
      return sum1 ;
  }
  else
  {
      i ++ ;
      int a = grid[i] ;
      grid[i] == sum ;
      int sum1 = sum ;
      sum = sum + sum1 - a ;
      return sum1 ;
  }
}

int Generator::rnd()
{
    return sumOfFib() % mode ;
}
