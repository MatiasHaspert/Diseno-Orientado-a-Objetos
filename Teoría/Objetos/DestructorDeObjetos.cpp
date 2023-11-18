#include <iostream>
#include <stdlib.h>

using namespace std;

class Perro
{
    private:
        string nombre, raza;
    public:
        Perro(string, string); // constructor
        ~Perro(); // destructor
        void datos();
};

Perro::Perro(string _nombre, string _raza)
{
    nombre = _nombre;
    raza = _raza;
}

Perro::~Perro()
{
    cout<<"\nObjeto eliminado\n";
}

void Perro::datos()
{
    cout<<"\nNombre del perro: "<<nombre<<endl;
    cout<<"Raza: "<<raza<<endl;
}

int main()
{
    Perro p1("Pluto","Pitbull");

    p1.datos();
    //p1.~Perro(); // eliminando el objeto 

    return EXIT_SUCCESS;
}