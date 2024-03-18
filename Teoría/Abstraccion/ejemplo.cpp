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

//estructura que denota las condiciones relevantes para el plan
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



int main()
{
    Temperatura temperatura;

    sensorTemperatura sensorInvernadero1(1);
    sensorTemperatura sensorInvernadero2(2);

    
    
    temperatura = sensorInvernadero1.temperaturaActual();

    sensorInvernadero2.calibrar(5);

}

