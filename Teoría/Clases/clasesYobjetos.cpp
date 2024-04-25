#include <iostream>

using namespace std;

/*
struct RegistroPersonal
{
    char *nombre;
    int numseguridadsocial;
    char *departamento;
    float salario;
};

RegistroPersonal ema, manuel; Son objetos de la clase RegistroPersonal
Es buena practica encapsular el estado de un objeto
*/

class RegistroPersonal
{
public:
    char * nombreEmpleado() const;
    int numseguridadsocial() const;
    char * departamentoEmpleado() const;

protected:
    char *nombre;
    int numseguridadsocial;
    char *departamento;
    float salario;
};

/*
Los tres tipos mas comunes de operaciones son:

Modificador/Setters : una operacion que altera el estado de un objeto.
Selector/Getters : una operacion que accede al estado de un objeto, sin alterarlo.
Iterador : una operacion que permite acceder a todas las partes de un objeto, con un orden perfectamente establecido.
*/

template<class Elemento> //Argumento plantilla o modelo, instanciacion
class Cola
{
public:
    Cola();
    Cola(const Cola<Elemento>&);
    virtual ~Cola();

    virtual Cola<Elemento>& operator=(const Cola<Elemento>&);
    virtual int operator==(const Cola<Elemento>&) const;
    int operator!=(const Cola<Elemento>&) const;

    //Modificadores
    virtual void borrar();
    virtual void añadir(const Elemento&); // Se puede añadir objetos de cualquier clase
    virtual void extraer();
    virtual void eliminar(int donde);

    //Selectores
    virtual int longitud() const;
    virtual int estaVacia() const;
    virtual const Elemento*cabecera() const;
    virtual int posicion (const void *);
};

Cola<int> colaEnteros;

/*
//Funcion no miembro
void copiarHastaEncontrarlo(Cola<int> &fuente, Cola<int> &destino, Elemento&)
{
    while(!fuente.estaVacia() && fuente.cabecera() != elemento)
    {
        destino.añadir(fuente.cabecera());
        fuente.extraer();
    }
}
*/

int main()
{
    RegistroPersonal ema, manuel;



}