//main.cpp
#include <iostream>
#include "loopSearch1.hpp"
#include <fstream>
#include <vector>
#include "Rnd.hpp"
#include <iostream>
using namespace std;

int main()
{
    int m;
    cin>>m;
    vector <vector <int> > a( m , vector <int> (m , 0));

Rnd rnd1 = Rnd(m);

   cycle len = cycle(m);
   int length = len.lengsOfCycle();
   int f = 0;
   int d = 0;
   a[f][d] ++;
   cout<<f<<" "<<d<<endl;
   int b = 1;
   int c = rnd1.nextRnd(f, d, b);
   a[b][c] ++;
   cout<<b<<" "<<c<<endl;
   int c1 = rnd1.nextRnd(d, b, c);
   int c2 = rnd1.nextRnd(b, c, c1);
   a[c1][c2] ++;
   cout<<c1<<" "<<c2<<endl;

   for(int i = 0; i < length/2-3; i++)
    {
       d = c;
       b = c1;
       c = c2;

       c1 = rnd1.nextRnd(d, b, c);

        c2 = rnd1.nextRnd(b, c, c1);
        a[c1][c2] ++;
        cout<<c1<<" "<<c2<<endl;
    }
    ofstream LengsHtml ;
    LengsHtml.open("BlackAndWhite1.html");


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


for(int i = 0; i< m; i++)
    {
    for(int j = 0; j< m ; j++)
        {
            if(a[j][i] != 0){
                LengsHtml
                        << "<td style=\"background-color:  rgb("
                        <<180
                        << ","
                       <<150
                       <<","
                        <<150
                       <<");\"> "
                        <<a[j][i]
                        <<"</td>";}
                        else
                        {
                        LengsHtml
                        << "<td style=\"background-color:  rgb("
                        <<255
                        << ","
                       <<255
                       <<","
                        <<255
                       <<");\"> "
                        <<a[j][i]
                        <<"</td>";}
       // cout<<a[i][j]<<" ";
        }
        LengsHtml << "</tr>";

    }

     return 0;
}
