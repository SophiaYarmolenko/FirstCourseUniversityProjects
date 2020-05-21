//
// Created by Sophia on 20.05.2020.
//

#include "History.h"

void History::setOnOf(bool onOf)
{
    on_of = onOf;
}

void History::setClear(bool clear)
{
    History::clear = clear;
}

void History::PushBack(string command)
{
    if(on_of == 1)
    {
        if( clear == 1 )
        {
            history.clear();
            history.push_back(command);
        }
        else
            history.push_back(command);
    }
}
void History::Clear()
{
    history.clear();
}


