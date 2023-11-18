#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void agrego_final ();

int main()
{
    agrego_final();

    return EXIT_SUCCESS;
}

void agrego_final ()
{
    ofstream archivo; 

    archivo.open("prueba.txt",ios::app); // abro el archivo para escribir al final del archivo

    archivo<<"daleeeeee";

    archivo.close();
}