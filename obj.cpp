#include "obj.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "Random number.hpp"
#include "Generation.hpp"
#include "RND.hpp"
#include <vector>
#include <iomanip>
#ifndef Width
#define Width 7
#endif // Width
#ifndef Height
#define Height 11
#endif // Height
using namespace std;

double EnergyRecuperator = 0;
double EnergySystem = 5000000000000;
double BagVolume = 10000000;
double BagMass = 400000000000;
double cAnother;
double a = 9;
double b = 2;
double c;
double BagTemperature;// градуси Кельві
double WorkEnergy;
double Volume;
double Mass;
double EnergyMelt;
double deltaT;
double EnergyHeatUp;
int m = 10;
int time1 = 0;
std::vector <double> f;
obj::obj()
{

}
 void obj::turn()
{

    if ( (WorkEnergy - EnergyTurn) > 0)
        {
            double b1;
            b1 = b;
            b = c;
            c = b1;
            WorkEnergy -= EnergyTurn;
            resalt += "Turn\n";
                    if( a > Width || b > Height)
                        rotate1();
                            else
                                cut();
        }
    else
        BadDrop();
}

void obj::rotate1()
{
    if( (WorkEnergy - EnergyRotate) > 0)
        {

            double b1;
            b1 = b;
            b = a;
            a = b1;

            WorkEnergy -= EnergyRotate;
            resalt += "Rotate\n ";

                    if(a > Width || b > Height)
                        {
                            turn();
                        }
                        else
                            {
                                cut();
                            }

        }
        else
            BadDrop();

}

void obj::cut()
{
    Volume = a*b*c;
    Mass = Volume*Density;
    cAnother = 0;
    EnergyMelt = d*Mass;
    deltaT = MeltTemperature - StartTemperature;
    EnergyHeatUp = C*Mass*deltaT;

    double c1;
    double c2;
    double c3;

    if(BagMass - Mass >= 0
       && BagVolume - Volume >= 0
       && (WorkEnergy - (EnergyMelt + EnergyHeatUp) > 0 || EnergyRecuperator - (EnergyMelt + EnergyHeatUp) > 0))
    {
       if(BagMass - Mass == 0 || BagVolume - Volume == 0)
       {
            cout<<"Sorry, bag is full, we need to fly";
            BagMass -= a*b*c*Density;
            BagVolume -= a*b*c;
        }
            else
                {
                    BagMass -= a*b*c*Density;
                    BagVolume -= a*b*c;
                    Finish();
                }
    }
    else
        {
            if( (WorkEnergy - EnergyCut) > 0)
                    {
                        WorkEnergy -= EnergyCut;
                            if (BagMass >= Mass) c1 = c; else
                                                            c1 = BagMass/(Density*a*b);
                            if (BagVolume >= Volume) c2 = c; else
                                                            c2 = BagVolume/(a*b);
                            if(EnergyRecuperator>0)
                                {
                                    if( EnergyRecuperator - EnergyMelt - EnergyHeatUp >= 0 )
                                        c3 = c;
                                            else
                                                {
                                                    c3 = EnergyRecuperator/(a*b*C*deltaT + a*b*d);
                                                }
                                }
                                else
                                    {
                                        if( WorkEnergy - EnergyMelt - EnergyHeatUp > 0 ) c3 = c;
                                            else
                                                c3 = WorkEnergy/(a*b*(C*deltaT + d));
                                    }


    if( c1<=c2 && c1<=c3 )
        {
            cAnother = 0;
            c = c1;
            BagMass -= a*b*c*Density;
            BagVolume -= a*b*c;
            resalt += "\nCut\n";
        }
            else
                if( c2<=c1 && c2<=c3 )
                    {
                        cAnother = 0;
                        c = c2;
                        resalt += "\nCut\n";
                        BagMass -= a*b*c*Density;
                    BagVolume -= a*b*c;
                    }
                        else
                            if( c3<=c1 && c3<=c2 )
                                {
                                    cAnother = c - c3;
                                    c = c3;
                                    resalt += "\nCut\n";
                                    BagMass -= a*b*c*Density;
                                    BagVolume -= a*b*c;
                                }

        if(BagMass == 0 || BagVolume == 0)
            cout<<"Sorry, bag is full, we need to fly";
                else
                    if(BagMass < 0 || BagVolume < 0)
                        GoodDrop();
                            else
                                {
                                    Finish();
                                }
        }
    else
        BadDrop();

    }
}

void obj::GoodDrop()
{
    if( EnergySystem-EnergyGoodDrop>0 )
            {
                EnergySystem -= EnergyGoodDrop;
                cout << "Sorry, Good drop. The current energy of the system =" << EnergySystem << endl;
                put();
            }
        else cout << "Sorry, little energy, we need to fly" ;
}

void obj::BadDrop()
{
        if( EnergySystem-EnergyBadDrop>0 )
            {
                EnergySystem -= EnergyBadDrop;
                cout << "Sorry, Bad drop. The current energy of the system =" << EnergySystem << endl;
                put();
            }
            else
                cout << "Sorry, little energy, we need to fly" ;
}

void obj::Finish()
{
      double e = C*a*b*c*Density*deltaT + d*a*b*c*Density;
       BagTemperature = 4 - 273;

       if(cAnother==0)
        {
            if(EnergyRecuperator - e > 0)
                {
                    EnergyRecuperator -= e;
                    EnergySystem = WorkEnergy;
                }
                    else
                    {
                        if(WorkEnergy - e > 0)
                            {
                                WorkEnergy -= e;
                                EnergySystem = WorkEnergy;
                            }
                        else BadDrop();
                    }
            resalt += "Melt\nAccept\n";
            EnergyRecuperator += C*a*b*c*Density*deltaT+d*a*b*c*Density;
            cout<<resalt<<"One piece is ready\n";
            cout<<"The Parameters of the piece remaining on the conveyor:\n";
            cout<<a<<" "<<b<<" "<<cAnother<<endl<<endl;
            resalt = "";
            put();


        }
        else
        {
            if(EnergyRecuperator - e > 0)
                {
                    EnergyRecuperator -= e;
                    EnergySystem = WorkEnergy;
                }
                    else
                    {
                        if(WorkEnergy - e > 0)
                            {
                                WorkEnergy -= e;
                                EnergySystem = WorkEnergy;
                            }
                        else BadDrop();
                    }
            resalt += "Melt \nAccept\n";
            cout<<resalt<<"One piece is ready\n  "<<endl;
            resalt = "";
            cout<<"The energy of system = "<<EnergySystem<<endl;
            cout<<"The energy of recuperator = "<<EnergyRecuperator<<endl;
            cout<<"The Parameters of the piece remaining on the conveyor:\n";
            cout<<a<<" "<<b<<" "<<c<<endl<<endl;
            cut();
        }


}
void obj::put()
 {
     f.push_back(EnergySystem);
     time1++;
     if(time1<=25){
           if(BagMass <= 0 || BagVolume <= 0)
            cout<<"Sorry, bag is full, we need to fly";else{
    cout<<fixed;
    cout<<"         The initial energy of the system = "<<EnergySystem << endl;
    cout<<"         The energy you need to fly = "<< EnergyFly << endl;
    cout<<"         The energy of recuperator = "<<EnergyRecuperator<<endl;
    cout<<"         The max mass of the bag = "<<BagMass<<endl;
    cout<<"         The max volume of the bag = "<<BagVolume<<endl;

    WorkEnergy = EnergySystem - EnergyFly - EnergyAccept ;

    if((WorkEnergy - EnergyPut) > 0)
        {
            EnergySystem -= EnergyPut;
            cout << "Put:"<<endl;
            cout << "   Please, give me three parameters" << endl;
            cout<<"a = ";
            while(1){
            Rnd random1 = Rnd(m);
            a = random1.nextRnd(a, b);
            if (a!=0)break;
            b++;}
            cout<<a;
            cout<<endl;
            cout<<"b = ";
            while(1){
            Rnd random1 = Rnd(m);
            b = random1.nextRnd(a, b);
            if (b!=0)break;
            b++;}
            cout<<b;
            cout<<endl<<"c = ";
            while(1){
            Rnd random1 = Rnd(m);
            c = random1.nextRnd(a, b);
            if (c!=0)break;
            c++;
            break;}
            cout<<c<<endl;

                if( a>Width && b>Width && c>Width
                   || a>Height && b>Height && c>Height
                   || a>Width && b>Width && a>Height && b>Height
                   || b>Width && c>Width && b>Height && c>Height
                   || a>Width && c>Width && a>Height && c>Height)
                        GoodDrop();
                else
                    if(a>Width)
                        {
                            rotate1();
                        }
                        else
                            if(b>Height)
                                {
                                    turn();
                                }
                                else
                                    {
                                        cut();
                                    }

        }

    else
        cout << "Sorry, little energy, we need to fly" ;
}}else{
    ofstream Grafic;
    Grafic.open("графік енергії.txt");
    int l = 25;
    for(int i =0; i<=l; i++){
            Grafic<<f[i]<<fixed<<setprecision(0)<<endl;}
    Grafic.close();
cout<<"Sorry, we are bored";
}
}



