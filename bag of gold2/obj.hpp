#ifndef OBJ_HPP_INCLUDED
#define OBJ_HPP_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class obj
{
private:
    double EnergyAccept = 100000;//��
    double EnergyFly = 5000;//��
    double EnergyPut = 1000000;//��
    const double EnergyTurn = 100000;//��
    const double EnergyRotate = 1000000;//��
    const double Density = 19320;//��/�^3
    const double EnergyCut = 100000;//��
    const double d = 66200; //������ ������� ��������� ��/��
    const double C = 130;//������ ���������� ��������� ��/(�� * ������ ������)
    const double MeltTemperature = 1064;//������� ������
 const double StartTemperature = 9;//������� ������
 const double EnergyBadDrop = 100000;//��
 const double EnergyGoodDrop = 100000;//��
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
