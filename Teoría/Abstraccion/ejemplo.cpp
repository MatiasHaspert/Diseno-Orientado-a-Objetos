// ejemplo sensor de temperatura
#include <iostream>

using namespace std;

// Temperatura en grados centigrados
typedef float Temperatura;

// Numero que define la posicion de un sensor
typedef int Posicion;

//Numero denotando el dia del año
typedef unsigned int Dia;

//Numero denotando la hora del dia
typedef unsigned int Hora;

//Tipo booleano
enum Luces{OFF, ON};

// Numero denotando la acidez en una escala del 1 al 14
typedef float pH;

//Numero denotando la concentracion porcentual del 0 al 100
typedef float Concentracion;

enum Booleano{FALSE, TRUE};

//Tipo de produccion
typedef unsigned int Produccion;

//Estructura que denota las condiciones relevantes para el plan
struct Condicion
{
    Temperatura temperatura;
    Luces iluminacion;
    pH acidez;
    Concentracion concentracion;   
};

class PlanCultivo
{
public:
    //constructores
    PlanCultivo(char *nombre);
    virtual~PlanCultivo();

    //modificadores
    void borrar();
    //una funcion virtual significa que a la hora de heredar esta clase habilite el polimorfismo, es decir, cambiar la funcion desde la clase hija
    virtual void establecer(Dia, Hora, const Condicion&);

    //selectores
    const char * nombre() const;
    const Condicion& condicionesDeseadas(Dia, Hora) const; 
};

//Herencia simple
class PlanCultivoFrutas : PlanCultivo
{
public:
    PlanCultivoFrutas(char *nombre);
    virtual ~PlanCultivoFrutas();
    
    virtual void establecer(Dia, Hora, const Condicion&);
    void planificarConsecha(Dia, Hora);

    Booleano yaCosechado() const;
    unsigned diasHastaCosecha() const;
    Produccion producionEstimada() const;

protected: //objetos miembros
    Booleano repCosechado;
    Produccion repProduccion;
};

class Planta
{
public:
    Planta(char *nombre, char *especie);
    ~Planta();

    void fijarFechaSiembra(Dia);
    virtual void establecerCondiciones(const Condicion &); //esperamos que se especialize en las subclases

    const char * nombre() const;
    const char * especie() const;
    Dia fechaSiembra() const;

protected:
    char *repNombre;
    char *repEspecie;
    Dia repSiembra;
};

//clase aditiva porque se mezclara con otra para hacer nuevas subclases
class FrutaHortalizaAditiva
{
public:
    FrutaHortalizaAditiva(Dia momentoFlorecer, Dia siembra);
    ~FrutaHortalizaAditiva();

    Dia momentoRecoleccion() const;
};

class FlorAditiva
{
public:
    FlorAditiva(Dia momentoFlorecer, Dia siembra);
    ~FlorAditiva();

    Dia momentoFlorecimiento() const;
    Dia momentoSiembra() const;
};

// herencia multiple
class Rosa : public Planta, public FlorAditiva{};
class zanahoria : public Planta, public FrutaHortalizaAditiva{};
class Cerezo : public Planta, public FlorAditiva, public FrutaHortalizaAditiva{};

/* 
    Colisiones entre nombres de superclases: Las colisiones se dan cuando dos o mas superclases suministrar un campo u operacion con
    el mismo nombre o prototipo, en c+ se soluciona con calificacion explicita
   
    Herencia repetida: ocurre cuando dos o mas superclases hermanas comparten una superclase comun, en c++ se utilizan clases bases
    virtuales para denotar la comparticion de estructuras repetidas, mientras que las clases bases no virtuales resultan en aparicion de
    copias duplicadas en la subclase(requiriendose calificacion explicita para distinguir entre las copias).

    Pueden reducirse trapas de herencia multiple mal formadas a una sola superclase mas la agregacion de las otras clases por parte
    de la subclase

    Ejemplo de jerarquia: agregacion, mientras las jerarquias <es un> denotan relaciones de generalizacion/especificacion, las
    jerarquias <parte de> describen relaciones de agregacion.
*/

class Huerta
{
public:
    Huerta();
    virtual ~Huerta();

protected:
    Planta *repPlantas[100];
    PlanCultivo repPlan;

};
/*
    Niveles de abstraccion: en terminos de su jerarquias <de clases>, una abstraccion de alto nivel esta generalizada y una de bajo
    nivel esta especializada. Por tanto se dice que una clase Flor esta a nivel mas alto de abstraccion que de una clase planta.
    En terminos de se jerarquia <parte de> una clase esta a nivel mas alto de abstraccion que cualquiera de las clases que constituyen
    su implantacion, Asi la clase Huerta esta a un nivel mas alto que la clase Planta sobre el que se construye.
*/


class sensorTemperatura
{
public:
    sensorTemperatura(Posicion);
    ~sensorTemperatura();

    void calibrar(Temperatura temperaturaFijada);

    Temperatura temperaturaActual() const; // El const significa que no modificara el estado interno del objeto
};

class sensorTemperaturaActivo
{
public:
    sensorTemperaturaActivo(Posicion, void (*f)(Posicion, Temperatura)); //(*f) es una funcion callback, ahora lo que hace es informar la 
                                                                         // temperatura actual cuando cambia, no cuando se le pregunta sobre ella
    void calibrar(Temperatura temperaturaFijada);
    void establecerPuntoReferencia(Posicion puntoReferencia,Temperatura incremento);
    Temperatura temperaturaActual() const;
};

class Calentador
{
public:
    Calentador(Posicion);
    ~Calentador();

    void activar();
    void desactivar();

    Booleano encendido();

protected: // protected son visibles solo para la clase y sus subclases
    const Posicion repPosicion;
    Booleano repEncendido;
    PuertoSerie* repPuerto;
};
//puede haber funciones amigas: clases que solo comparten entre si sus datos privados

class PuertoSerie
{
public:
    PuertoSerie();
    ~PuertoSerie();

    void escribir(char *);
    void escribir(int);

    static PuertoSerie puertos[10];
};

Calentador::Calentador(Posicion p) : repPosicion(p), repEncendido(FALSE), repPuerto(&PuertoSerie::puertos[p]) {}

Calentador::~Calentador(){}

void Calentador::activar()
{
    if(!repEncendido)
    {
        repPuerto->escribir("*");
        repPuerto->escribir(repPosicion);
        repPuerto->escribir(1);
        repEncendido = TRUE;
    }
}

void Calentador::desactivar()
{
    if(repEncendido)
    {
        repPuerto->escribir("*");
        repPuerto->escribir(repPosicion);
        repPuerto->escribir(0);
        repEncendido = FALSE;
    }
}

Booleano Calentador::encendido()
{
    return repEncendido;
}

// Numero que denota el nivel de 0 a 100 por cien 
typedef float Nivel;

class TanqueAlmacen
{
public:
    TanqueAlmacen();
    virtual ~TanqueAlmacen();

    virtual void llenar();
    virtual void empezarDesaguar();
    virtual void pararDesaguar();

    Booleano estaVacio() const;
    Nivel nivel() const;
};

class TanqueAgua : public TanqueAlmacen
{
public:
    TanqueAgua();
    virtual ~TanqueAgua();
    
    virtual void llenar();
    virtual void empezarDesaguar();
    virtual void pararDesaguar();

    void empezarCalentar();
    void pararCalentar();

    Temperatura temperaturaActual() const;
};

class TanqueNutrientes : public TanqueAlmacen
{
public:
    TanqueNutrientes();
    virtual ~TanqueNutrientes();

    virtual void llenar();
    virtual void empezarDesaguar();
};

/*
    Se supone que se necesita la abstraccion de un inventario de invernadero, que recoge todos los bienes materiales asociados a
    un invernadero particular. Se utiliza una clase contenedor que almacena punteros a void(o una clase aditiva), que representan a objetos de tipo
    indefinido.
*/

class Inventario
{
public:
    Inventario();
    ~Inventario();

    void añadir(void *); //Es un iterador, permitira trabajar sobre la coleccion de elementos.
    void eliminar(void *); // Se pueden añadir y eliminar punteros a objetos de diferentes clases

    void * masReciente() const;
    void aplicar(Booleano (*)(void *));

    //Si llega a recibir un bien no material como un PlanCultivo habria un problema, se solucionaria creando una clase aditiva
    //por ejemplo BienMaterial(se usaria para todas las clases que representan un bien material) y remplazarla por los punteros void 
};

int main()
{
    Temperatura temperatura;

    sensorTemperatura sensorInvernadero1(1);
    sensorTemperatura sensorInvernadero2(2);

    PlanCultivoFrutas planManzana("Manzana");
    
    temperatura = sensorInvernadero1.temperaturaActual();

    sensorInvernadero2.calibrar(5);

    TanqueAlmacen t1, t2; //instancias de la clase TanqueAlmacen denotada por la variable t1.
    TanqueAgua a;
    TanqueNutrientes n;
}

