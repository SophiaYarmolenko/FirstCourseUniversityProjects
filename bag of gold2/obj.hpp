#ifndef OBJ_HPP_INCLUDED
#define OBJ_HPP_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class obj
{
private:
    double EnergyAccept = 100000;//Дж
    double EnergyFly = 5000;//Дж
    double EnergyPut = 1000000;//Дж
    const double EnergyTurn = 100000;//Дж
    const double EnergyRotate = 1000000;//Дж
    const double Density = 19320;//кг/м^3
    const double EnergyCut = 100000;//Дж
    const double d = 66200; //питома теплота плавлення ДЖ/кг
    const double C = 130;//питома теплоємність нагрівання Дж/(кг * градус Цельсія)
    const double MeltTemperature = 1064;//градуси Цельсія
 const double StartTemperature = 9;//градуси Цельсія
 const double EnergyBadDrop = 100000;//Дж
 const double EnergyGoodDrop = 100000;//Дж
    string resalt="";

public:

    obj();

    void put();
    void turn();
    void rotate1();
    void cut();
    void GoodDrop();
    void BadDrop();
    void Finish();



};


#endif // OBJ_HPP_INCLUDED
