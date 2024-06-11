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

   

};


void Subasta::iniciar_subasta()
{
    int numeroLote;
    string nombre;

    fstream lotesSubasta(nombre_archivo1, ios::in);

    if(!lotesSubasta)
    {
        cerr<<"No se pudo abrir el archivo";
        exit(EXIT_FAILURE);
    }

    while(!lotesSubasta.eof())
    {
        lotesSubasta >> numeroLote >> nombre;
        lotes.push_back(new Lote(numeroLote,nombre));
    }

    lotesSubasta.close();
}

void Subasta::ofertaLote(int numeroLote, string nombre, float monto)
{
    Lote *lote = get_lote(numeroLote);
    lote->set_oferta(new Oferta(nombre,monto));
}

void Subasta::finaliza_subasta(int numeroLote)
{
    fstream finaliza_subasta(nombre_archivo2, ios::out);

    if(!finaliza_subasta)
    {
        cerr<<"No se pudo abrir el archivo";
        exit(EXIT_FAILURE);
    }

    Lote *lote = get_lote(numeroLote);
    Oferta *oferta = lote->get_oferta();

    finaliza_subasta << lote->get_numero() << " " <<lote->get_nombre() << " " << oferta->get_NombreOfertante() << " " << oferta->get_monto() <<endl;

    finaliza_subasta.close();

    oferta->~Oferta();
    lote->~Lote();
    delete lotes[numeroLote];
    lotes.erase(lotes.begin()+(numeroLote));

    fstream lotesSubasta(nombre_archivo1,ios::out);
    
    if(!lotesSubasta)
    {
        cerr<<"No se pudo abrir el archivo";
        exit(EXIT_FAILURE);
    }

    for(auto it : lotes)
    {
        lotesSubasta << it->get_numero() << " " << it->get_nombre() <<endl;
    }

    lotesSubasta.close();
}


int main()
{
    Subasta *subasta = new Subasta();
    int cant_participantes;
    string nombre;
    float monto;
    int numLote = 1;
    Lote *lote;

    subasta->iniciar_subasta();
    
    cout<<"***BIENVENIDO AL SISTEMA DE SUBASTA***"<<endl;
    
    cout<<"INGRESE LA CANTIDAD DE PARTICIPANTES> ";
    cin>>cant_participantes;
    
    while(numLote != 0)
    {
        cout<<endl<<"ELIJE EL LOTE A SUBASTAR(X #Lote): ";
        cout<<endl<<"TECLEE 0 PARA FINALIZAR SUBASTA"<<endl;
        
        for (int i = 0; i < subasta->get_cantidad_lotes(); i++)
        {
            lote = subasta->get_lote(i);
            if(lote->get_oferta() == NULL) // Si el lote no tiene ofertas lo muestro
            {
                cout<<endl<<"Lote #"<<i+1<<endl;
                cout<<*(subasta->get_lote(i)); 
            }
        }

        do
        {   //Usuario elije el lote que se subasta
            cout<<endl<<"> ";
            cin>>numLote;
            
            if(numLote == 0)
                exit(EXIT_SUCCESS);

        } while (numLote < 0 || numLote > subasta->get_cantidad_lotes());
    

        cout<<endl<<"**COMIENZA LA SUBASTA***"<<endl;
    
        cout<<*(subasta->get_lote(numLote-1));
        
        for (int j = 0; j < cant_participantes; j++)
        {
            cout<<endl<<"Parcipante #"<<j+1;
            cout<<endl<<"Nombre: "; 
            cin>>nombre;
            cout<<"Monto: ";
            cin>>monto;

            subasta->ofertaLote(numLote-1,nombre,monto);
        }

        subasta->finaliza_subasta(numLote-1);
    }
    

    delete(subasta);
    
    return EXIT_SUCCESS;
}