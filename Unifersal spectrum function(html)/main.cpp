#include <iostream>
#include <fstream>
#include "universalspectrum.hpp"
#include "random"
#include <cmath>


using namespace std;
int rnd(int maxF)
{
    int resalt = rand()%(maxF)+1;

    return resalt;
}

int main()
{
    int length;
    int maxF;
    int axes;
    cout<<endl<<"Enter the max element in your generating"<<endl;
    cin>>maxF;
    cout<<endl<<"Enter the length of your generating"<<endl;
    cin>>length;
    cout<<endl<<"Enter the number of axes"<<endl;
    cin>>axes;
    cout<<endl;

int size = pow(maxF+1, axes);
    int spectrArray[size];
    for(int i = 0; i < pow(maxF+1, axes); i++)
    {
        spectrArray[i]=0;
    }

    us us1 = us( rnd, length, maxF, axes, spectrArray);

    ofstream Html;
    Html.open("Universal spectrum.html");
    Html << "<!DOCTYPE html>\
    <html>\
<head>\
	<title>Universal TD, function colspan</title>\
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
		}\
	</style>\
</head>\
<body>\
	<table>";

    for ( int i = 1 ; i <= axes ; i++)
    {
        Html << "<tr>";
        for(int j = 0; j < pow(maxF+1,i-1); j++)
        {
            for(int k=0; k < maxF+1; k++)
            {
                Html << "<td style=\"background-color:  rgb(" << 255 - k*20 << "," <<225 - k*20 <<","<<225 - k*20<<");\" colspan = \"" << pow(maxF + 1, axes - i ) << "\"  > " << k << " </td>";
            }
        }
        Html << " </tr>";
    }
    Html << " <tr> ";
    for(int i=0; i < pow(maxF+1, axes); i++)
    {
        Html << " <td colspan = \"1\"> ";
        Html<<spectrArray[i];
    }
    Html << " </tr>";
    return 0;
}
