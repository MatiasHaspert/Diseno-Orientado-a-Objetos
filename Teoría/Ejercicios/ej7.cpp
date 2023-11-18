#include <iostream>
#include <stdlib.h>

using namespace std;

class Punto
{
    private:
        int cordX;
        int cordY;
    public:
        Punto();
        void set(int, int);
        void print();
        bool valida(int);
};

class Rectangulo
{
    private:
        Punto tope_izq;
        Punto inf_der;
    public:
        Rectangulo(int, int, int, int);
        void print();
};

//inicializo los atributos
Punto::Punto()
{
    cordX = 0;
    cordY = 0;
}

bool Punto::valida(int valor)
{
    if(valor < 0)
    {
       return false;
    }
    else
    {
        return true;
    }
}

void Punto::set(int x, int y)
{
    if(valida(x) && valida(y))
    {
        cordX = x;
        cordY = y;
    }
    else
    {
        cout<<"Dato negativo.\n";
        exit(EXIT_FAILURE);
    }
}

void Punto::print()
{
    cout<<"\nCordenada x: "<<cordX<<endl;
    cout<<"Cordeanada y: "<<cordY<<endl;
}


Rectangulo::Rectangulo(int x, int y, int z, int w)
{
    tope_izq.set(x,y);
    inf_der.set(z,w);

}

void Rectangulo::print()
{
    tope_izq.print();
    inf_der.print();
}

int main()
{
    Rectangulo r1(5,4,9,2);

    r1.print();

    return EXIT_SUCCESS;
}