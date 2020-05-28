//
// Created by Sophia on 20.05.2020.
//

#ifndef CLL_CLA_H
#define CLL_CLA_H

#include <iostream>
#include "History.h"
#include <vector>
#include "windows.h"
#include <sstream>
#include <ctime>
using namespace std;

class CLA : public History
{
public:
    static void greeting();
    static void help();
    static void quit();
    static void logOn();
    static void logOff();
    static void logAppend();
    static void logNew();
    static void Exit();
    static void save();
    static void load();
    static void logFile();
    static void list();
    static void logClearHistory();
    static string TimeToString();
};


#endif //CLL_CLA_H

