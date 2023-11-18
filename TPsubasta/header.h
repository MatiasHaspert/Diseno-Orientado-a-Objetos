/*
La idea es que una subasta consiste en un conjunto de items ofertados para la venta.
Estos items son llamados lotes. Las Personas ingresan ofertas para los lotes y la mas elevada es la que se registra en el Lote.
Ni la Persona ni la Oferta inicia la actividad en la subasta.
La persona solo posee un nombre. Y la oferta guarda el monto y el ofertante.
El lote, tiene un numero y un nombre, ademas se guarda la oferta mas grande.
La subasta guarda la coleccion de lotes y la cantidad de los mismos.
*/

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Persona
{
    private:
        string nombre;
    public:
        Persona(){};
        Persona(string n) : nombre(n){};
        string get_Persona()
        {
            return nombre;
        }
};

class Oferta
{
    private:
        float monto;
        Persona ofertante;
    public:
        Oferta(){};
        Oferta(float m, Persona o) : monto(m), ofertante(o){};
        void set_oferta(float m){monto = m;}
        void set_ofertante(Persona p){ofertante = p;}
        float get_oferta()
        {
            return monto;
        }
        Persona get_Ofertante()
        {
            return ofertante;
        }
};

class Lote 
{
    private:
        int nro;
        string nombre;
        Oferta of_superior;
    public:
        Lote(){};
        Lote(int nu, string n, Oferta o) : nro(nu), nombre(n), of_superior(o){};
        void mostrar_lote()
        {
            cout<<"\nLOTE: "<<nombre<<endl;
            cout<<"Número: "<<nro<<endl;
            cout<<"Ofertante: "<<of_superior.get_Ofertante().get_Persona()<<endl;
            cout<<"Oferta: $"<<of_superior.get_oferta()<<endl;
        }
};

class Subasta
{
    private:
        vector<Lote>coleccion_lotes;
    public:
        Subasta(){};
        int cant_lotes()
        {
            return coleccion_lotes.size();
        }
        void agregar_lote(Lote &l)
        {
            coleccion_lotes.push_back(l);
        }
        void print_subasta()
        {
            for (int i = 0; i < cant_lotes(); i++)
            {
                coleccion_lotes[i].mostrar_lote();
            }
        }
};

void info_lote (int &, string &);
Oferta oferta_mayor(vector<Oferta> );