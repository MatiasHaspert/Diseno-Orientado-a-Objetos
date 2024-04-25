#include <iostream>
#include <stdlib.h>

using namespace std;

struct Punto
{
    int x, y;
    Punto() : x(0), y(0){}
    Punto(int valorX, int valorY) : x(valorX), y(valorY){}
};

class ElementoPantalla
{
    public:
    ElementoPantalla();
    ElementoPantalla(const Punto &posicion);
    ElementoPantalla(const ElementoPantalla&); //Constructor copia
    virtual ~ElementoPantalla();

    virtual ElementoPantalla& operator = (const ElementoPantalla&); //Operador de asignacion
    virtual int operator == (const ElementoPantalla&) const; //Operador de igualdad
    int operator != (const ElementoPantalla&) const;    //Operador de desigualdad

    virtual void dibujar();
    virtual void seleccionar();
    virtual void borrar(); 
    virtual void quitarSeleccion();
    virtual void mover(const Punto &posicion);

    int estaSeleccionado() const;
    Punto posicion() const;
    int estaBajo(const Punto &posicion) const;

    protected: 
};

int main()
{
    ElementoPantalla elemento1;
    ElementoPantalla *elemento2 = new ElementoPantalla(Punto(50,54));
    ElementoPantalla *elemento3 = new ElementoPantalla(Punto(100,75));
    ElementoPantalla *elemento4 = 0;
    
    return EXIT_SUCCESS;
}