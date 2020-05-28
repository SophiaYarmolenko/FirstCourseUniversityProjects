//
// Created by Sophia on 20.05.2020.
//

#include "CLA.h"

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
        "exit - exit with save\n"///////////
        "save - save command history\n"/////////
        "load - open file with history\n"/////////////
        "logfile - show file name\n"/////////////
        "list - show your history\n"////////////
        "logOn - start record history\n"////////////
        "logOff - stop record history\n"///////////
        "logAppend - record your history to the back\n"/////////
        "logNew - clear and start record new history\n"/////////
        "logClearHistory - clear your history\n";///////////
}

void CLA::quit()
{
    exit(0);
}

void CLA::logOn()
{
    setOnOf(1);
    PushBack(TimeToString()+" > log on");
}

void CLA::logOff()
{
   PushBack(TimeToString()+" > log off");
   setOnOf(0);
}

void CLA::logAppend()
{
    PushBack(TimeToString()+" > log append");
    setClear(0);
}

void CLA::logNew()
{
    setClear(1);
    PushBack(TimeToString()+" > log new");
}
void CLA::save()
{
    PushBack(TimeToString()+" > save");
    Save();
}

void CLA::Exit()
{
    Save();
    exit(0);
}

void CLA::load()
{
    WinExec(R"(C:\Users\Sophia\Desktop\CLL\history.txt)", SW_SHOWNORMAL);
}

void CLA::logFile()
{
    cout<<"C:\\Users\\Sophia\\Desktop\\CLL\\history.txt";
}

void CLA::list()
{
    WinExec(R"(C:\Users\Sophia\Desktop\CLL\history.txt)", SW_SHOWNORMAL);
}
void CLA::logClearHistory()
{
    Clear();
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

