#include <iostream>
#include <stdlib.h>

using namespace std;

// clase abstracta Animal
class Animal
{
    public:
        string nombre;
        string especie;
        string habitad;
        virtual string get_nombre() = 0;
        virtual string get_especie() = 0;
        virtual string get_habitad() = 0;
        virtual void set_nombre(string n) = 0;
        virtual void set_especie(string e) = 0;
        virtual void set_habitad(string h) = 0;
};

class Caballo : public Animal
{
    private:
        string color;
        int edad;
    public:
        Caballo(string nombre, string especie, string habitad, int edad, string color);
        void set_nombre(string n);
        void set_especie(string e);
        void set_habitad(string h);
        void set_color(string c);
        void set_edad(int e);
        string get_nombre();
        string get_especie();
        string get_habitad();
        int get_edad();
        string get_color();
};

Caballo::Caballo(string nombre, string especie, string habitad, int edad, string color)
{
    this->nombre = nombre;
    this->especie = especie;
    this->habitad = habitad;
    this->edad = edad;
    this->color = color;
}

void Caballo::set_nombre(string n)
{
    this->nombre = n;
}

void Caballo::set_especie(string e)
{
    this->especie = e;
}

void Caballo::set_habitad(string h)
{
    this->habitad = h;
}

void Caballo::set_color(string c)
{
    this->color = c;
}

void Caballo::set_edad(int e)
{
    this->edad = e;
}

string Caballo::get_nombre()
{
    return nombre;
}

string Caballo::get_especie()
{
    return especie;
}

string Caballo::get_habitad()
{
    return habitad;
}

string Caballo::get_color()
{
    return color;
}

int Caballo::get_edad()
{
    return edad;
}

int main()
{
    //instancio un objeto caballo
    Caballo c1("Brunello", "Equino", "Campos", 6, "Marron");

    return EXIT_SUCCESS;
}