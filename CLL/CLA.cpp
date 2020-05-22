//
// Created by Sophia on 20.05.2020.
//

#include <sstream>
#include <ctime>
#include "CLA.h"
CLA::CLA()
{
    ///Add all command to vector with all function-command to form trie in another class
    functions.push_back(&CLA::help);
    functions.push_back(&CLA::quit);
    functions.push_back(&CLA::logOn);
    functions.push_back(&CLA::Exit);
    functions.push_back(&CLA::save);
    functions.push_back(&CLA::load);
    functions.push_back(&CLA::logFile);
    functions.push_back(&CLA::list);
    functions.push_back(&CLA::logOff);
    functions.push_back(&CLA::logAppend);
    functions.push_back(&CLA::logNew);
    functions.push_back(&CLA::logClearHistory);

}

void CLA::greeting()
{

    cout<<
        "Hi)\n"
        "Choose what command do you want\n"
        "For more details press \"help\"\n";
}

void CLA::help()
{
    cout<<
        "Commands:\n"
        "help - show instruction\n"//////////
        "quit - exit without save\n"//////////
        "exit - exit with save\n"
        "save - save command history\n"
        "load - open file with history\n"
        "logfile - show file name\n"
        "logfile(\"new pass\") - show file name and change it\n"
        "list - show your history\n"
        "log on - start record history\n"////////////
        "log off - stop record history\n"///////////
        "log append - record your history to the back\n"/////////
        "log new - clear and start record new history\n"/////////
        "log clear history - clear your history\n";///////////
}

void CLA::quit()
{
    exit(0);
}

void CLA::logOn()
{
    history.setOnOf(1);
}

void CLA::logOff()
{
    history.setOnOf(0);
}

void CLA::logAppend()
{
    history.setClear(0);
}

void CLA::logNew()
{
    history.setClear(1);
}


string CLA::TimeToString()
{
    time_t now = time(nullptr);
    tm time = *std::localtime(&now);
    stringstream result;
    result << 1900 + time.tm_year << ".";  
    result << (time.tm_mon  < 9 ? "0": "") << 1 + time.tm_mon << ".";
    result << (time.tm_mday < 10? "0": "") << time.tm_mday << " ";
    result << (time.tm_hour < 10? "0": "") << time.tm_hour << ":";
    result << (time.tm_min  < 10? "0": "") << time.tm_min  << ":";
    result << (time.tm_sec  < 10? "0": "") << time.tm_sec;
    return result.str();
}


