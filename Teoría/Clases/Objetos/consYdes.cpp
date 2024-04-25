// Constructores y destructores

#include <iostream>
#include <stdlib.h>

using namespace std;

class Punto
{
    private:
        int x;
        int y;
    public:
        Punto() // constructor1
        {
            x = 0;
            y = 0;
            cout<<"Objeto inicializado"<<endl;
        }
        Punto(int, int); // constructor 2
};

/*
Poligono() : NoPuntos(0), aPuntos(NULL) {}
es equivalente a 
Poligono(){NoPuntos = 0; aPuntos = NULL;}
*/
class Poligono 
{
    int NoPuntos;
    Punto* aPuntos;
    public:
    Poligono() : NoPuntos(0), aPuntos(NULL) {}
    Poligono(int);
    ~Poligono();  // destructor
};

Poligono::~Poligono() 
{
    if(aPuntos != NULL)
    delete[]aPuntos;
}

Punto::Punto(int _x, int _y)
{
    x = _x;
    y = _y;
}

int main()
{
    Punto p1;
    Punto *p;

    p = new Punto(5, 6); //reservo memoria para un objeto

    delete p; //liberamos el espacio en memoria del objeto

    return EXIT_SUCCESS;
}