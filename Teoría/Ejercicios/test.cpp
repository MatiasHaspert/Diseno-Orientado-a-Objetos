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
        void set_Nombre(string n){nombre = n;}
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
Oferta oferta_mayor(vector<Oferta>);

int main()
{
    Subasta subasta;
    vector<Oferta> ofertantes;
    int cant_ofertantes, nro_lote;
    string nombre, nombre_lote;
    float monto;
    int j;
    bool i(true);

    cout<<"\t*****SUBASTA*****"<<endl;
    while(i)
    {
        cout<<"\n1. Agregar lote: "<<endl;
        cout<<"0. Finalizar subasta."<<endl;
        cout<<"> ";
        cin>>i;

        if(i)
        {
            info_lote(nro_lote,nombre_lote);
            cout<<"\nTeclee la cantidad de ofertantes: ";
            cin>>cant_ofertantes;
    
            for (j = 0; j < cant_ofertantes; j++)
            {
                cout<<"\nOfertante #"<<j+1<<endl;
                cout<<"Nombre: ";cin>>nombre;
                Persona p(nombre);
                cout<<"Oferta: ";cin>>monto;
                Oferta oferta(monto, p);
                ofertantes.push_back(oferta);   
            }
            Oferta of = oferta_mayor(ofertantes);
            cout<<"\nSubasta finalizada, se llevo el lote:"<<endl;
            Lote l(nro_lote,nombre_lote,of);
            l.mostrar_lote();
            subasta.agregar_lote(l);

            // limpio el vector ofertantes para la proxima subasta
            ofertantes.clear();
        }
    }

    cout<<"\nSUBASTA FINALIZADA."<<endl;
    cout<<"\nLOTES SUBASTADOS: "<<subasta.cant_lotes()<<endl;
    cout<<"SON LOS SIGUIENTES: "<<endl;
    subasta.print_subasta();
    
    return EXIT_SUCCESS;
}

void info_lote (int &nro, string &nombre)
{
    cout<<"\nIngresa el numero del lote: ";cin>>nro;
    cout<<"\nIngresa el nombre del lote: ";cin>>nombre;
}


Oferta oferta_mayor(vector<Oferta> ofertantes)
{
    if (ofertantes.empty()) {
        // Si no hay ofertas, devolvemos una oferta vacía
        return Oferta (0.0, Persona("Ninguno"));
    }
    float montoSuperior = ofertantes[0].get_oferta();
    Oferta of = ofertantes[0];
    for (size_t i = 1; i < ofertantes.size(); i++)
    {
        if(montoSuperior < ofertantes[i].get_oferta())
        {
            montoSuperior = ofertantes[i].get_oferta();
            of = ofertantes[i];
        }
    }

    return of;
}