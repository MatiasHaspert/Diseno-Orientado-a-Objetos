//con objetos
#include<iostream>

using namespace std;

class Camion;

class Auto
{
    int pasajeros, velocidad;   
    public:
    Auto(int cant, int vel):pasajeros(cant), velocidad(vel){}
    //friend int operator-(const Auto& a, const Camion& c);
    int operator-(const Camion& c) const;
};

class Camion
{
    int peso, velocidad;
    public:
    Camion(int p, int v):peso(p), velocidad(v){}
    //friend int operator-(const Auto& a, const Camion& c);
    friend int Auto::operator-(const Camion& c)const;
};

/*
int operator-(const Auto &a, const Camion &c)
{
    return a.velocidad - c.velocidad;
}*/

int Auto::operator-(const Camion& c)const
{
    return velocidad - c.velocidad;
}

int main()
{
    Auto a1(4, 230);
    Camion c1(2, 180);

    cout<<" "<< a1 - c1<<endl; //50

    return EXIT_SUCCESS;
}