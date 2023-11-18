#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream fichero("Clientes.txt", ios::out);

    if(fichero.fail())
    {
        cerr<<"Ouch!";
        exit(EXIT_FAILURE);
    }

    int cuenta;
    char nombre[30];
    float saldo;

    cout << "Escriba la cuenta, nombre y saldo." << endl
    << "Escriba fin de archivo para terminar la entrada."<<endl; //ctrl d
    cout<<"> ";

    while(cin>>cuenta>>nombre>>saldo)
    {
        fichero<<cuenta<<" "<<nombre<<" "<<saldo<<" "<<endl; 
        cout<<"\n> ";   
    }

    fichero.close();

    return EXIT_SUCCESS; // el destructor de ofstream cierra el archivo 
}