//
// Created by Sophia on 20.05.2020.
//

#ifndef CLL_HISTORY_H
#define CLL_HISTORY_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class History
{
private:
    vector <string> history;
    bool on_of = 0;
    bool clear = 0;
public:
    void setClear(bool clear);

public:
    void setOnOf( bool onOf );
    void PushBack( string command );
    void Clear();
};


#endif //CLL_HISTORY_H
