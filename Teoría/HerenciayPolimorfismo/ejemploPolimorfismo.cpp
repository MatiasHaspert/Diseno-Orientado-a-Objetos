#include <iostream>
#include <stdlib.h>

using namespace std;

class Persona
{
    private:
        string nombre;
        int edad;
    public:
        Persona(string, int);
        virtual void print();
};

class Alumno : public Persona
{
    private:
        string facultad;
    public:
        Alumno(string, int, string);
        void print(); // polimorfismo (enviando el mismo metodo pero lo aplican distinto)
};

Persona::Persona(string _n, int _e)
{
    nombre = _n;
    edad = _e;
}

Alumno::Alumno (string _n, int _e, string f) : Persona(_n,_e)
{
    facultad = f;
}

void Persona::print()
{
    cout<<"\nNombre: "<<nombre;
    cout<<"\nEdad: "<<edad<<endl;
}

void Alumno::print()
{
    Persona::print();
    cout<<"Facultad: "<<facultad<<endl;
}

int main()
{
    Persona *vector[3];

    vector[0] = new Alumno("Matias Haspert", 20, "UNR");

    vector[0]->print();

    return EXIT_SUCCESS;
}