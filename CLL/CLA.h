//
// Created by Sophia on 20.05.2020.
//

#ifndef CLL_CLA_H
#define CLL_CLA_H

#include <iostream>;
#include "History.h"
#include "Command.h"
#include <vector>
using namespace std;

class CLA
{
private:
    History history;
    Command commands;

public:
    CLA();

    int numberFunction = 0;//number of function to form trie
    typedef void (CLA::*Function)();
    std::vector<Function> functions;

    void greeting();
    void help();
    void quit();
    void logOn();
    void logOff();
    void logAppend();
    void logNew();
    void Exit();
    void save();
    void load();
    void logFile();
    void list();
    void logClearHistory();
    string TimeToString();
};


#endif //CLL_CLA_H




/*
    int i = 0;
    (obj.*obj.functions[0])(i);
    (obj.*obj.functions[1])(i);
    (obj.*obj.functions[2])(i);
*/
