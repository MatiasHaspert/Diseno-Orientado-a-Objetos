#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <limits> 

using namespace std;

void escribir ();

int main()
{
    escribir();


    return EXIT_SUCCESS;
}

void escribir ()
{
    ofstream archivo; // declaro un archivo
    string nombre_archi, frase;
    int n;

    if(archivo.fail())
    {
        cout<<"Error";
        exit(1);
    }

    cout<<"\nNombre para el archivo: ";
    getline(cin,nombre_archi);

    archivo.open(nombre_archi.c_str(),ios::out); // creo y abro el archivo

    cout<<"\nIngresa la cantidad de frases que desee escribir en el archivo: ";
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //limpio el buffer

    for(int i = 0; i < n; i++)
    {
        cout<<"\nEscribe una frase en el archivo: ";
        getline(cin,frase);
        archivo<<frase<<endl;
    }

    archivo.close(); //cierro el archivo
}   