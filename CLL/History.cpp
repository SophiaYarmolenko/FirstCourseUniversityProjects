//
// Created by Sophia on 20.05.2020.
//

#include "History.h"
bool History::on_of = false;
bool History::clear = false;
ifstream file("history.txt");

vector <string> History::history = {};

History::History()
{
    on_of = 0;
    clear = 0;
}

void History::setOnOf(bool onOf)
{
    on_of = onOf;
}

void History::setClear(bool clear)
{
   clear = clear;
}

void History::PushBack(string command)
{
    if(on_of == 1)
    {
        if( clear == 1 )
        {
            history.clear();
            file.clear();
            history.push_back(command);
        }
        else
            history.push_back(command);
    }
}
void History::Clear()
{
    history.clear();
    file.clear();
}

void History::Save()
{
    for(string s:history)
    {
        for(char c:s)
        {
            file.putback(c);
        }
    }

}

