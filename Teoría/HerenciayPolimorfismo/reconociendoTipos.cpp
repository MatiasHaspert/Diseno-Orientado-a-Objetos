#include <iostream>
#include <stdlib.h>

using namespace std;

class Persona
{
    int edad;
    public:
    Persona(int e){edad = e;}
    virtual void hablar();
    void caminar();
};

class Estudiante : public Persona
{
    int legajo;
    public:
    Estudiante(int e, int l) : Persona(e) {legajo = l;}
    virtual void hablar();
    void estudiar();
};

class Docente : public Persona
{
    int cuil;
    public:
    Docente(int e, int c) : Persona(e) {cuil = c;}
    virtual void hablar();
    void catedra();
};

void Docente::catedra()
{
    cout<<"\nCatedra matematica.\n";
}

int main()
{
    Persona *p= new Docente(35, 5345);

    cout<< typeid(p).name()<<endl;// Persona
    cout<< typeid(*p).name()<<endl;// Docente
    cout<< (typeid(p) == typeid(Docente*))<< endl; // Falso
    cout<< (typeid(p) == typeid(Persona*))<< endl; // Verdadero
    
    /*
    if (typeid(*p) == typeid(Docente))
    {
        Docente *d = (Docente*)p;
        d->catedra();
    }
    */

    if (dynamic_cast<Docente*>(p)) // Verifica si p apunta a un objeto de tipo Docente
    {
        Docente *d = dynamic_cast<Docente*>(p); //conversion
        d->catedra();
    }
    return 0;

}