/*
Crear un programa en C++ que tenga la siguiente jerarquía de clases: Animal(Clase Padre) 
- Humano(Clase Hija) - Perro(Clase Hija), y hacer polimorfismo con el metodo comer().
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Animal
{
    private:
        string nombre;
    public:
        Animal(string);
        virtual void comer();
};

class Humano : public Animal
{
    private:
        int edad;
    public:
        Humano(string, int);
        void comer();
};

class Perro : public Animal
{
    private:
        string raza;
    public:
        Perro(string, string);
        void comer();
};

Animal::Animal(string n)
{
    nombre = n;
}

Humano::Humano(string n, int e) : Animal(n)
{
    edad = e;
}

Perro::Perro(string n, string r) : Animal(n)
{
    raza = r;
}
    
void Animal::comer()
{
    cout<<" "<<nombre<<" esta comiendo."<<endl;
}

void Humano::comer()
{
    Animal::comer();
    cout<<"Y tiene "<<edad<<" años."<<endl;
}

void Perro::comer()
{
    Animal::comer();
    cout<<"Y su raza es "<<raza<<endl;
}


int main()
{
    Humano h1("Matias",20);
    Perro p1("Pluto","Doberman");

    cout<<"Humano:"<<endl;
    h1.comer();
    cout<<"\nPerro:"<<endl;
    p1.comer();

    return EXIT_SUCCESS;
}