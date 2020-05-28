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
    static vector <string> history;
    static bool on_of;
    static bool clear;
public:
    History();
    static void setClear(bool clear);
    static void Save();
    static void setOnOf(bool onOf );
    static void PushBack(string command );
    static void Clear();
   // static ifstream file;
};


#endif //CLL_HISTORY_H
