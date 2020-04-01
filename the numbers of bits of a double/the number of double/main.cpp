#include <iostream>
#include <cmath>

using namespace std;

int SizeOfDouble ()
{
    double mantisa = 0.5;
    double order = 0.5;
    int n = 0, m = 0 ;

    while(order)
    {
        order /= 2;
        n++ ;
    }

    while (mantisa < 1)
    {
        mantisa = mantisa/2+0.5;
        m++ ;
    }

    return m + log2(n) + 1;
}
int main()
{
    cout << SizeOfDouble();
    return 0;
}
