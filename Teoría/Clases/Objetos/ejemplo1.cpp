#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Estudiante
{
    private:
        char *nombre;
        int edad;
        float promedio;
    public:
        Estudiante(const char *, int, float);
        ~Estudiante();
        void print();
};

Estudiante::Estudiante(const char *n, int e, float p)
{
    this->nombre = new char[strlen(n) + 1];
    strcpy(this->nombre, n);
    this->edad = e;
    this->promedio = p;
}

Estudiante::~Estudiante()
{
    delete(nombre);
}

void Estudiante::print()
{
    cout<<"Nombre: "<<nombre<<endl<<"Edad: "<<edad<<endl<<"Promedio: "<<promedio<<endl;
}

int main()
{
    Estudiante e1("Pablo", 28, 8.8);
    Estudiante *e2;

    e1.print();

    e2 = new Estudiante("Matias",20, 7.4);
    e2->print();
    delete(e2);

    return EXIT_SUCCESS;
}