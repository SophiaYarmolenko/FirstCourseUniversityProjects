//main.cpp
#include <iostream>
#include "loopSearch1.hpp"
#include <fstream>
#include "howmuch.hpp"
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
   int d = 1;
   a[f][d] = 1;
   int b = 1;
   int c = rnd1.nextRnd(d, b);
   a[b][c] = 1;
   int c1 = rnd1.nextRnd(b, c);
   for(int i = 0; i < (length-3)/2; i++)
    {
        d = c;
        b = c1;
        c = rnd1.nextRnd(d, b);
        a[c1][c] = 1;
         c1 = rnd1.nextRnd(b, c);
        //a[c][c1] = 1;
    }

    ofstream LengsHtml ;
    LengsHtml.open("BlackAndWhite.html");


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
            if(a[i][j] == 1){
                LengsHtml
                        << "<td style=\"background-color:  rgb("
                        <<0
                        << ","
                       <<0
                       <<","
                        <<0
                       <<");\"> "
                        <<a[i][j]
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
                        <<a[i][j]
                        <<"</td>";}
       // cout<<a[i][j]<<" ";
        }
        LengsHtml << "</tr>";

    }

     return 0;
}
