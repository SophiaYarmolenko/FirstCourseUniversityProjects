#include <iostream>

using namespace std;



double sun0=0;


double sun(double x)
{
    double k=2;
    double fact0=1;
    double gip0=1;
    double pov0=x;
    while (sun0<3.129)
    {
        fact0 *= (2*k-2)*(2*k-1);
        gip0 +=1/k;
        pov0 = pov0*x;
        sun0+=gip0*pov0/fact0;
        cout<<sun0<<endl;
        cout<<'\n'<<endl;
        k++;

    }
    return sun0;
}
int main()
{
    double x;
    cin>>x;
    sun0=x;
    cout<<'\n'<<endl;
    sun(x);
    return sun0;
}
