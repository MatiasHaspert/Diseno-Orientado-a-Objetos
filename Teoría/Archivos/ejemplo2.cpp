#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void leer_archivo ();

int main()
{
    leer_archivo();

    return EXIT_SUCCESS;
}

void leer_archivo ()
{
    ifstream archivo; //declaro un archivo para lectura
    string texto;

    archivo.open("prueba.txt",ios::in); // abro el archivo para lectura

    while(!archivo.eof()) // mientras no sea el final del archivo
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }

    archivo.close();
}