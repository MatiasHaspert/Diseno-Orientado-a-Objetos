#include <iostream>
#include <stdlib.h>

using namespace std;

class Persona
{
    //encapsulamiento de los atributos
    private:
        int edad;
        string nombre;
    
    public: // metodos
        Persona(int, string); //constructor de la clase, capaz de inicializar los atributos
        void leer(); // estos metodos son los unicos que pueden acceder a los atributos privados
        void correr();
};

//inicializamos los atributos
Persona::Persona(int _edad, string _nombre)
{
    edad = _edad;
    nombre = _nombre;
}

void Persona::leer()
{
    cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
}
// definimos los metodos
void Persona::correr()
{
    cout<<"Soy "<<nombre<<" y estoy corriendo una maraton y mi edad es "<<edad<<endl;
}

int main()
{
    Persona p1 = Persona(20,"Matias"); // creamos un objeto p1
    Persona p2(41,"Laura"); // creamos un objeto p2

    p1.leer();
    p2.correr();


    return EXIT_SUCCESS;
}