#include <iostream>
#include <stdlib.h>

using namespace std;

class Persona
{
    private:
        int edad;
    public:
        Persona(int x){ edad = x;}
        virtual void hablar();
        void caminar();
};

class Estudiante : public Persona
{
    private:
        int legajo;
    public:
        Estudiante(int e,int l) : Persona(e){legajo = l;}
        virtual void hablar();
        void estudiar();
};

class Docente : public Persona
{
    private:
        int cuit;
    public:
        Docente(int e, int c) : Persona(e){cuit = c;}
        virtual void hablar();
        void explica();
};

void Persona::hablar()
{
    cout<<"Hola\n\n";
}

void Estudiante::hablar()
{
    cout << "Hola, soy un estudiante\n\n";
}

void Docente::hablar()
{
    cout << "Hola, soy un docente\n\n";
}

int main()
{
    Persona **p = new Persona*[2];

    p[0] = new Estudiante(22, 434);
    p[1] = new Docente(45, 5345345);

    for (size_t i = 0; i < 2; i++)
    {
        p[i]->hablar();
    }
    
    return EXIT_SUCCESS;
}