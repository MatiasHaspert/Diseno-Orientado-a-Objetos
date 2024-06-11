#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Persona
{
private:
    string nombre;

public:
    Persona() : nombre(""){};
    Persona(string nombre)
    {
        this->nombre = nombre;
    }
    void set_nombre(string nombre)
    {
        this->nombre = nombre;
    }

    string get_nombre()
    {
        return nombre;
    } 
};

class Oferta
{
private:
    float monto;
    Persona *ofertante;

public:
    Oferta() : monto(0), ofertante(NULL){};
    Oferta(string nombre, float monto)
    {
        this->monto = monto;
        ofertante = new Persona(nombre);
    }
    ~Oferta(){delete ofertante;}
    
    void set_monto(float monto)
    {
        this->monto = monto;
    }

    void set_ofertante(string nombre)
    {
        ofertante->set_nombre(nombre);
    }

    float get_monto()
    {
        return monto;
    }

    string get_NombreOfertante()
    {
        return ofertante->get_nombre();
    }

    Persona* get_ofertante()
    {
        return ofertante;
    }

    friend ostream& operator<<(ostream&,Oferta);
};

ostream& operator<<(ostream &os, Oferta o)
{
    os<<"Ofertante: "<<o.get_ofertante()<<endl<<"Monto: "<<o.get_monto()<<"$"<<endl;
    return os;
}

class Lote
{
private:
    int numero;
    string nombre;
    Oferta *oferta;

public:
    Lote(): numero(0), nombre(""), oferta(NULL){};
    ~Lote(){delete oferta;}
    Lote(int numero, string nombre)
    {
        this->numero = numero;
        this->nombre = nombre;
        oferta = NULL;
    }

    friend ostream& operator<<(ostream&,Lote);
    
    void set_oferta(Oferta *oferta)
    {
        if(this->oferta == NULL || oferta->get_monto() > this->oferta->get_monto())
        {
            this->oferta = oferta;
            cout<<"OFERTA MAYOR!"<<endl;
        }
        else
        {
            cout<<"OFERTA INSUFICIENTE, OFERTA MAYOR: "<<this->oferta->get_monto()<<"$"<<endl;
        }
    }

    Oferta* get_oferta()
    {
        return oferta;
    }

    string get_nombre()
    {
        return nombre;
    }

    int get_numero()
    {
        return numero;
    }


};

ostream& operator << (ostream &os, Lote l)
{
    os<<"Numero: "<<l.get_numero()<<endl<<"Nombre: "<<l.get_nombre()<<endl;
    return os;
}


class Subasta
{
private:
    vector<Lote*> lotes;    
    string nombre_archivo1 = "lotesSubasta.txt";
    string nombre_archivo2 = "finalizaSubasta.txt";

public:
    Subasta() : lotes(0){};
    ~Subasta()
    {
        for(auto a : lotes)
        {
            delete a;
        }
    }
    
    void iniciar_subasta();

    void ofertaLote(int numeroLote, string nombre, float monto);

    void finaliza_subasta(int numeroLote);
        
    Lote* get_lote(int i)
    {
        return lotes[i];
    }

    int get_cantidad_lotes()
    {
        return lotes.size();
    }

    void mostrar_lotes()
    {
        int i = 1;

        for(auto lote : lotes)
        {
            if(lote->get_oferta() == NULL)
            {
                cout<<endl<<"-> Lote #"<<i<<endl;
                cout<<*lote;
                i++;
            }
        }
    }
};

