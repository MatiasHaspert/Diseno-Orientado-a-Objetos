#include "header.h"

int main()
{
    Subasta *subasta = new Subasta();
    int cant_participantes;
    string nombre;
    float monto;

    //Creo los lotes que se van a subastar 
    subasta->iniciar_subasta(1,"Electrodomesticos");
    subasta->iniciar_subasta(2,"Automoviles");
    
    
    cout<<"***BIENVENIDO AL SISTEMA DE SUBASTA***"<<endl;
    
    cout<<"INGRESE LA CANTIDAD DE PARTICIPANTES> ";
    cin>>cant_participantes;
    
    cout<<endl<<"**COMIENZA LA SUBASTA***"<<endl;
    
    for (int i = 0; i < subasta->get_cantidad_lotes(); i++)
    {
        cout<<endl<<"Lote #"<<i+1<<endl;
        cout<<subasta->get_lote(i);


        for (int j = 0; j < cant_participantes; j++)
        {
            cout<<endl<<"Parcipante #"<<j+1;
            cout<<endl<<"Nombre: "; 
            cin>>nombre;
            cout<<"Monto: ";
            cin>>monto;

            subasta->ofertaLote(i,nombre,monto);
        }

        cout<<endl<<"Ganador del lote #"<<i+1<<endl;
        cout<<subasta->get_lote(i);
        cout<<subasta->oferta_mayor(i);
    }
    
    
    cout<<endl<<"***SUBASTA FINALIZADA***"<<endl;
    cout<<"HISTORIAL DE LA SUBASTA"<<endl;
    subasta->print_lotes();
    delete(subasta);
    
    return 0;
}