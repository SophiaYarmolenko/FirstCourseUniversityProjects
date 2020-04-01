#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "Rnd.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
double R1;// radius c.
double L2;//довжина квадрата
using namespace std;

int main()
{

ofstream Grafic;
Grafic.open("графік енергії.txt");

L2 = 35;
R1 = 12;
    for(int n = 15; n<50; n++){
    int por = 0;
    double SPC = 0;
    double STC = 3.14*R1*R1;//////////////////////////
    double STT = L2*L2;

    int m;
    m = L2;
        vector <vector<int>> s(L2, vector <int> (L2, 0));

Rnd rnd1 = Rnd(m);

   int f = 0;
   int d = 0;
   s[f][d] = 1;
   por++;
   int b = 1;
   int c = rnd1.nextRnd(f, d, b);
   s[b][c] = 1;
   por++;
   int c1 = rnd1.nextRnd(d, b, c);
   int c2 = rnd1.nextRnd(b, c, c1);
   s[c1][c2] = 1;
   por++;
   for(int i = 0; i < n; i++)
    {
       d = c;
       b = c1;
       c = c2;

       c1 = rnd1.nextRnd(d, b, c);

        c2 = rnd1.nextRnd(b, c, c1);
        s[c1][c2] =1;
        por++;
    }

    s[ (L2-1)/2 ][ (L2-1)/2 ] += 1;
    ofstream LengsHtml ;
    LengsHtml.open("BlackAndWhite2.html");


        LengsHtml << "<!DOCTYPE html>\
    <html>\
<head>\
	<title>Numbers</title>\
	<style type=\"text/css\">\
		td\
		{\
			border: 2px solid rgb(155, 125, 125);\
			padding: 5px;\
			font-family: Century Gothic, sans-serif;\
		}\
		table\
		{\
			margin-left: auto;\
			margin-right: auto;\
			margin-top: 100px;\
			table-layout: fixed;\
		}\
	</style>\
</head>\
<body>\
	<table>";

    for(int i = 0; i<L2; i++)
        {
            for(int j = 0; j<L2; j++)
            {
                if(  sqrt ( pow((L2-1)/2 - i, 2) + pow((L2-1)/2 - j,2)) == R1 && s[i][j]!=0 )
                    {
                        SPC+=0.3;
                    }
                else if(  sqrt ( pow((L2-1)/2 - i, 2) + pow((L2-1)/2 - j,2)) < R1&& s[i][j]!=0)
                    {
                        SPC+=1;
                }
            }
        }
        cout<<STC<<" "<<SPC<<" "<<por<<endl;
        Grafic<<((STC-SPC*STC/por)/STC)*100/STC<<fixed<<endl;
        }

     return 0;
}
