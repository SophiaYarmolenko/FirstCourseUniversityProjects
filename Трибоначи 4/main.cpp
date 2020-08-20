//main.cpp
#include <iostream>
#include "loopSearch1.hpp"
#include <fstream>
#include "howmuch.hpp"

using namespace std;

int main()
{
    int m;
    ofstream LengsHtml;
    LengsHtml.open("howmutch1.html");
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
    LengsHtml << "<tr>";
    LengsHtml << "<td style=\"width: 30px;\">" << "M" << "</td>";
    LengsHtml << "<td style=\"width: 30px;\">" << "L" << "</td>";
    for(int i=0; i<50; i++)
        LengsHtml << "<td> " <<"<img src = \" фон2.png\" alt = \'"<<i<<"\' title = \'"<<i<<"\' >"<<"</td>";
    LengsHtml << "</tr>";

    for(int m = 2; m <= 50; m++)
        {
            cycle len = cycle(m);
            LengsHtml << "<tr>";
            LengsHtml << "<td> " <<"<img src = \" фон2.png\" alt = \'"<<m<<"\' title = \'"<<m<<"\' >"<<"</td>"<< "<td> " <<"<img src = \" фон2.png\" alt = \'"<<len.lengsOfCycle()<<"\' title = \'"<<len.lengsOfCycle()<<"\' >"<<"</td>";
            for(int i = 0; i < m; i++)
                {

                    howmuch how = howmuch(m, i);
                    int resalt = how.HowMuch();
                   LengsHtml
                        << "<td style=\"background-color:  rgb("
                        <<255 - resalt*5
                        << ","
                       <<225 - resalt*20
                       <<","
                        <<225 - resalt*20
                       <<");\"> ";
                      LengsHtml
                        <<"<img src = \" фон.jpg\" alt = \'"<<resalt<<"\' title = \'"<<resalt<<"\'>"
                        <<"</td>";
                }
            LengsHtml << "</tr>";
       }
       LengsHtml.close();
     return 0;
}
