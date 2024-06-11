#include "header.h"

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
    fstream finaliza_subasta(nombre_archivo2, ios::out | ios::app);

    if(!finaliza_subasta)
    {
        cerr<<"No se pudo abrir el archivo";
        exit(EXIT_FAILURE);
    }

    Lote *lote = get_lote(numeroLote);
    Oferta *oferta = lote->get_oferta();


    finaliza_subasta << lote->get_numero() << " " <<lote->get_nombre() << " " << oferta->get_NombreOfertante() << " " << oferta->get_monto() <<endl;

    finaliza_subasta.close();

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


    subasta->iniciar_subasta();
    
    cout<<"***BIENVENIDO AL SISTEMA DE SUBASTA***"<<endl;
    
    cout<<"INGRESE LA CANTIDAD DE PARTICIPANTES> ";
    cin>>cant_participantes;
    
    while(numLote != 0)
    {
        cout<<endl<<"°°ELIJE EL LOTE A SUBASTAR(X -> #Lote): ";
        cout<<endl<<"°°TECLEE 0 PARA FINALIZAR SUBASTA"<<endl;
        
        subasta->mostrar_lotes();

        do
        {   
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
    
    cout<<endl<<"°°SUBASTA FINALIZADA"<<endl;
    delete(subasta);
    
    return EXIT_SUCCESS;
}