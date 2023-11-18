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
        void print_persona();
};

class Estudiante : public Persona
{
    private:
        string facultad;
    public:
        Estudiante(string, int, string);
        void print_estudiante();
};

class Empleado : public Persona
{
    private:
        string rubro;
        float sueldo;
    public:
        Empleado(string, int, string, float);
        void print_empleado();  
};

class Universitario : public Estudiante
{
    private:
        string carrera;
        float nota;
    public:
        Universitario(string, int, string, string, float);
        void print_universitario();
};

Persona::Persona(string _n, int _e)
{
    nombre = _n;
    edad = _e;
}

Empleado::Empleado(string n, int e, string r, float s) : Persona(n, e)
{
    rubro = r;
    sueldo = s;
}
Estudiante::Estudiante(string _n, int _e, string f) : Persona(_n, _e)
{
    facultad = f;
}


Universitario::Universitario(string n, int e, string f, string c, float _nota) : Estudiante(n, e, f) 
{
    carrera = c;
    nota = _nota;
}

void Persona::print_persona()
{
    cout<<"\nNombre: "<<nombre;
    cout<<"\nEdad: "<<edad<<endl;
}


void Estudiante::print_estudiante()
{
    print_persona();
    cout<<"Facultad: "<<facultad<<endl;
}

void Empleado::print_empleado()
{
    print_persona();
    cout<<"Rubro: "<<rubro<<endl;
    cout<<"Sueldo: $"<<sueldo<<endl;
}

void Universitario::print_universitario()
{
    print_estudiante();
    cout<<"Carrera: "<<carrera<<endl;
    cout<<"Nota final: "<<nota<<endl;
}

int main()
{
    Empleado e1("Juan Haspert", 50, "Fideero", 200000);
    Universitario u1("Matias Haspert", 20, "UNR", "Analista universitario en sistemas", 7);

    cout<<"Empleado:"<<endl;
    e1.print_empleado();
    cout<<"\nUniversitario:"<<endl;
    u1.print_universitario();

    return EXIT_SUCCESS;
}