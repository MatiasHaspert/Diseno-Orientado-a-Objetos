#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangulo
{
    private: //atributos
        float largo;
        float ancho;
    
    public:
        Rectangulo(float, float); //constructor
        void perimetro();
        void area();
};

//inicializamos los atributos
Rectangulo::Rectangulo(float _largo, float _ancho)
{
    largo = _largo;
    ancho = _ancho;
}

void Rectangulo::perimetro()
{
    cout<<"\nEl perimetro del rectangulo es: "<<(ancho+largo)*2;
}

void Rectangulo::area()
{
    cout<<"\nEl area del rectaculo es: "<<(ancho*largo);
}

int main()
{
    Rectangulo rec1(6,7); //objeto rec1

    rec1.perimetro();
    rec1.area();

    return EXIT_SUCCESS;
}