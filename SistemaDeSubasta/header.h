#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
        ofertante->set_nombre(nombre);
    }

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

    string get_ofertante()
    {
        return ofertante->get_nombre();
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
    ~Lote(){delete(oferta);}
    Lote(int numero, string nombre)
    {
        this->numero = numero;
        this->nombre = nombre;
        oferta = NULL;
    }

    friend ostream& operator<<(ostream&,Lote);
    
    void set_oferta(Oferta *oferta)
    {
        if(oferta->get_monto() > this->oferta->get_monto())
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
    vector<Lote> lotes;    
    

public:
    Subasta() : lotes(0){};
    ~Subasta(){};
    
    void iniciar_subasta(int numeroLote, string nombre)
    {
        lotes.push_back(Lote(numeroLote,nombre));
    }

    void ofertaLote(int numeroLote, string nombre, float monto)
    {
        Lote& lote = get_lote(numeroLote);
        lote.set_oferta(new Oferta(nombre,monto));
    }

    Lote& get_lote(int i)
    {
        return lotes[i];
    }

    int get_cantidad_lotes()
    {
        return lotes.size();
    }

    Oferta* oferta_mayor(int numLote)
    {
        Lote& lote = get_lote(numLote);
        return lote.get_oferta();
    }

    void print_lotes()
    {
        for(auto a : lotes)
        {
            cout<<endl<<"Lote:"<<endl<<a<<"Se llevo el lote:"<<endl<<a.get_oferta();
        }
    }


};

