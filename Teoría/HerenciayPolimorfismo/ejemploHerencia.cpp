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

//la clase Alumno hereda de la clase Persona todo lo public 
class Alumno : public Persona
{
    private:
        string facultad;
        float notaFinal;
    public:
        Alumno(string, int, string, float);
        void print_alumno();
};

//constructor de la clase Persona (Padre)
Persona::Persona(string _n, int _e)
{
    nombre = _n;
    edad = _e;
}

//constructor de la clase Alumno(Hija)
Alumno::Alumno (string _n, int _e, string f, float n) : Persona(_n,_e)
{
    facultad = f;
    notaFinal = n;
}

void Persona::print_persona()
{
    cout<<"\nNombre: "<<nombre;
    cout<<"\nEdad: "<<edad;
}

void Alumno::print_alumno()
{
    print_persona();
    cout<<"\nFacultad: "<<facultad<<endl;
    cout<<"Nota final: "<<notaFinal<<endl;
}

int main()
{
    Alumno a1("Matias Haspert", 20, "IPS", 7);

    a1.print_alumno();
    
    return EXIT_SUCCESS;
}