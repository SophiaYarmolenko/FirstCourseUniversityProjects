#include <iostream>
#include <fstream>
#include "universalspectrum.hpp"
#include "random"
#include <cmath>
#include <string>
#include "Generator.h"
#include "windows.h"

using namespace std;
int rnd(int maxF)
{
    int resalt = rand()%(maxF)+1;

    return resalt;
}

void consol()
{
    int length = 40;
    int maxF = 7;
    int axes = 3;
    Generator generate;

    int spectrArray[(maxF+1)*(maxF+1)];
    for(int i = 0; i < (maxF+1)*(maxF+1); i++)
    {
        spectrArray[i]=0;
    }


    us us1 = us( rnd, length, maxF, axes, spectrArray);

    for(int i=0; i < (maxF+1)*(maxF+1); i++)
    {
        cout<<spectrArray[i]<<" ";
    }
}

void html(int don)
{
    if(don == 1)
    {
        int length=40;
    int maxF=7;
    int axes=4;
    /*cout<<endl<<"Enter the max element in your generating"<<endl;
    cin>>maxF;
    cout<<endl<<"Enter the length of your generating"<<endl;
    cin>>length;
    cout<<endl<<"Enter the number of axes"<<endl;
    cin>>axes;
    cout<<endl;*/

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
    WinExec(R"("C:\Program Files (x86)\Google\Chrome\Application\chrome.exe" "Universal spectrum.html")", SW_SHOWNORMAL);
    }
else
    cout<<"Your parameters aren't correct";
}

void htmlerror(int don)
{
    if(don == 1)
    {
        int length=1000;
        int maxF=100;
        int axes=100;
        /*cout<<endl<<"Enter the max element in your generating"<<endl;
        cin>>maxF;
        cout<<endl<<"Enter the length of your generating"<<endl;
        cin>>length;
        cout<<endl<<"Enter the number of axes"<<endl;
        cin>>axes;
        cout<<endl;*/

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
        WinExec(R"("C:\Program Files (x86)\Google\Chrome\Application\chrome.exe" "Universal spectrum.html")", SW_SHOWNORMAL);
    }
    else
        cout<<"Your parameters aren't correct";
}

int main()
{
    while(1)
    {
        cout << "Please, enter what do you want" << endl;
        cout << "   Show with ";
        string show;
        cin >> show;
        if (show == "consol")
            consol();
        else if (show == "html")
            html(1);
        else if (show == "both") {
            consol();
            html(1);
        } else if (show == "error1")
            html(0);
        else if (show == "error2")
            htmlerror(1);
        else
            cout << "You can choose only one of this commands:\n  \"consol\" - show function with consol"
                    "\n   \"html\" - show function with html"
                    "\n   \"both\" - show function both with consol and html"
                    "\n   \"error1\" - show how function works with parameters error"
                    "\n   \"error2\" - show how function works with system error"
                    "\n   \"help\" - show instructions ";
    }
    return 0;
}
