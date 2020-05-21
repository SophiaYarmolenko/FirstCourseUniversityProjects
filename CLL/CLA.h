//
// Created by Sophia on 20.05.2020.
//

#ifndef CLL_CLA_H
#define CLL_CLA_H

#include <iostream>;
#include "History.h"
#include "Command.h"

using namespace std;

class CLA:Command
{
private:
    History history;
    Command commands;

public:
    CLA();
    void greeting();
    void help();
    void quit();
    void logOn();
    void logOf();
    void logAppend();
    void logNew();
    string TimeToString();
};


#endif //CLL_CLA_H
