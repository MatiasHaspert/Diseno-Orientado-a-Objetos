#include "header.h"

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